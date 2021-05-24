package com.example.ffkmobile;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.NotificationCompat;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.ListView;

import com.amazonaws.amplify.generated.graphql.ListFfkSyncsQuery;
import com.amazonaws.mobile.config.AWSConfiguration;
import com.amazonaws.mobileconnectors.appsync.AWSAppSyncClient;
import com.amazonaws.mobileconnectors.appsync.fetcher.AppSyncResponseFetchers;
import com.apollographql.apollo.GraphQLCall;
import com.apollographql.apollo.api.Response;
import com.apollographql.apollo.exception.ApolloException;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

import javax.annotation.Nonnull;

import static java.lang.Thread.sleep;

public class MainActivity extends AppCompatActivity {
    protected int notificationChannelID;
    private ArrayList<ListItem> foodList;
    private ListView lv;

    private AWSAppSyncClient mAWSAppSyncClient;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        mAWSAppSyncClient = AWSAppSyncClient.builder()
                .context(getApplicationContext())
                .awsConfiguration(new AWSConfiguration(getApplicationContext()))
                // If you are using complex objects (S3) then uncomment
                //.s3ObjectManager(new S3ObjectManagerImplementation(new AmazonS3Client(AWSMobileClient.getInstance())))
                .build();

        this.foodList = new ArrayList<>();
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
//        ArrayList<ListItem> userList = generateExampleData();
        lv = (ListView) findViewById(R.id.user_list);

//        generateExampleData();
        ArrayList<ListItem> userList = new ArrayList<>(this.foodList);
        setDisplayList(userList);
    }

    public void query() {
        mAWSAppSyncClient.query(ListFfkSyncsQuery.builder().build())
                .responseFetcher(AppSyncResponseFetchers.CACHE_AND_NETWORK)
                .enqueue(todosCallback);

    }

    private GraphQLCall.Callback<ListFfkSyncsQuery.Data> todosCallback = new GraphQLCall.Callback<ListFfkSyncsQuery.Data>() {
        private ArrayList<ListItem> listToBeDisplayed = new ArrayList<>();

        @Override
        public void onResponse(@Nonnull Response<ListFfkSyncsQuery.Data> response) {
            foodList.clear();
            Log.i("Results", response.data().listFfkSyncs().items().toString());

            List<ListFfkSyncsQuery.Item> remoteList = response.data().listFfkSyncs().items();
            for (ListFfkSyncsQuery.Item item : remoteList) {
                ListItem newItem = new ListItem(item.food_item(), "XXXX", Integer.parseInt(item.shelf_life()), Integer.parseInt(item.food_quantities()));
                foodList.add(newItem);
                listToBeDisplayed.add(newItem);
                Log.i("Results", newItem.toString());
            }
//            setDisplayList(listToBeDisplayed); // Only the original thread that created a view hierarchy can touch its views
        }

        public ArrayList<ListItem> getListToBeDisplayed() {
            return listToBeDisplayed;
        }

        @Override
        public void onFailure(@Nonnull ApolloException e) {
            Log.e("ERROR", e.toString());
        }
    };

    private void setDisplayList(ArrayList<ListItem> userList) {
        lv.setAdapter(new CustomListAdapter(this, userList));
    }

    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.game_menu, menu);
        return true;
    }

    private void sendNotification(String bigContentTitle, String summaryText) {
        this.notificationChannelID++;

//        NotificationCompat.Builder mBuilder =
//                new NotificationCompat.Builder(this.getApplicationContext(), String.valueOf(this.notificationChannelID));
//        Intent ii = new Intent(this.getApplicationContext(), this.getClass());
//        PendingIntent pendingIntent = PendingIntent.getActivity(this, 0, ii, 0);
//
//        NotificationCompat.BigTextStyle bigText = new NotificationCompat.BigTextStyle();
////        bigText.setBigContentTitle(bigContentTitle);
////        bigText.setSummaryText(summaryText);
//
//        mBuilder.setContentIntent(pendingIntent);
//        mBuilder.setSmallIcon(R.mipmap.ic_launcher_round);
//        mBuilder.setContentTitle(bigContentTitle);
//        mBuilder.setContentText(summaryText);
//        mBuilder.setPriority(Notification.PRIORITY_MAX);
//        mBuilder.setStyle(bigText);
        Notification notification = new NotificationCompat.Builder(this.getApplicationContext(), String.valueOf(this.notificationChannelID))
                .setSmallIcon(R.mipmap.ic_launcher_round)
                .setContentTitle(bigContentTitle)
                .setContentText(summaryText)
                .setStyle(new NotificationCompat.BigTextStyle()
                        .bigText(summaryText))
                .build();

        NotificationManager mNotificationManager =
                (NotificationManager) this.getSystemService(Context.NOTIFICATION_SERVICE);

        mNotificationManager.notify(0, notification);
//
//        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
//            NotificationChannel channel = new NotificationChannel("notify_001",
//                    "Channel human readable title",
//                    NotificationManager.IMPORTANCE_DEFAULT);
//            mNotificationManager.createNotificationChannel(channel);
//        }
//
//        mNotificationManager.notify(0, mBuilder.build());
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        ArrayList newList = sortShelfLife();

        // Handle item selection-+
        switch (item.getItemId()) {
            case R.id.sortA_Z:
                newList = sortA_Z();
                setDisplayList(newList);
                return true;

            case R.id.sortZ_A:
                newList = sortZ_A();
                setDisplayList(newList);
                return true;

            case R.id.refresh:
//                sendNotification("Refresh FFK", "refresh pending");
                try {
                    query();
                    sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
//                checkShelfLife();
//                return true;
                // NOTE: THIS FALLTHROUGH IS DELIBERATE

            case R.id.sortShelfLife:
                newList = sortShelfLife();
                setDisplayList(newList);
//                sendNotification("sort shelf life", "sortin");
                checkShelfLife();
                return true;

            default:
                return super.onOptionsItemSelected(item);
        }
    }

    private void checkShelfLife() {
        ArrayList<String> passedExpiration = new ArrayList<>();
        ArrayList<String> expiringToday = new ArrayList<>();
        ArrayList<String> expiringTomorrow = new ArrayList<>();
        for (int i = 0; i < this.lv.getAdapter().getCount(); i++) {
            ListItem item = (ListItem) this.lv.getAdapter().getItem(i);
            Log.e("check", item.toString());

            switch (item.getIntShelfLife()) {
                case 1:
                    expiringTomorrow.add(item.getName());
                    break;
                case 0:
                    expiringToday.add(item.getName());
                    break;
                default:
                    if (item.getIntShelfLife() < 0) {
                        passedExpiration.add(item.getName());
                    }
                    break;
            }
        }
        if (passedExpiration.isEmpty() && expiringToday.isEmpty() && expiringTomorrow.isEmpty()) {
            return;
        }

        String bigText = "FFK Expiration Alert";
        String summaryText = "";
        if (!passedExpiration.isEmpty()) {
            summaryText += "Foods Expired: ";
            for (int j = 0; j < passedExpiration.size(); j++) {
                summaryText += passedExpiration.get(j);
                if (j < passedExpiration.size() - 1) {
                    summaryText += ", ";
                }
            }
        }

        if (!expiringToday.isEmpty()) {
            summaryText += "\nExpiring Today: ";
            for (int j = 0; j < expiringToday.size(); j++) {
                summaryText += expiringToday.get(j);
                if (j < expiringToday.size() - 1) {
                    summaryText += ", ";
                }
            }
        }

        if (!expiringTomorrow.isEmpty()) {
            summaryText += "\nExpiring Tomorrow: ";
            for (int j = 0; j < expiringTomorrow.size(); j++) {
                summaryText += expiringTomorrow.get(j);
                if (j < expiringTomorrow.size() - 1) {
                    summaryText += ", ";
                }
            }
        }

        this.sendNotification(bigText, summaryText);
    }

    private ArrayList generateExampleData() {
        ArrayList<ListItem> results = new ArrayList<>();
        ListItem i1 = new ListItem("apples", "3/11/2021", 3,  9);
        ListItem i2 = new ListItem("Cpples", "3/19/2022", 4,  15);
        ListItem i3 = new ListItem("dpples", "3/15/2022", 5,  12);
        ListItem i4 = new ListItem("epples", "3/11/2022", 2,  13);
        ListItem i5 = new ListItem("fpples", "3/11/2022", 6,  14);
        ListItem i6 = new ListItem("gpples", "3/11/2022", 7,  4);
        ListItem i7 = new ListItem("hpples", "3/11/2022", 8,  6);
        ListItem i8 = new ListItem("ipples", "3/11/2022", 1,  11);
        ListItem i9 = new ListItem("Jpples", "3/11/2022", 3,  15);
        ListItem i10 = new ListItem("Kpples", "3/11/2022", 7,  15);
        this.foodList.add(i1);
        this.foodList.add(i2);
        this.foodList.add(i3);
        this.foodList.add(i4);
        this.foodList.add(i5);
        this.foodList.add(i6);
        this.foodList.add(i7);
        this.foodList.add(i8);
        this.foodList.add(i9);
        this.foodList.add(i10);
        return results;
    }

    private ArrayList generateExampleData2() {
        ArrayList<ListItem> results = new ArrayList<>();
        ListItem i1 = new ListItem("apples", "3/11/2021", 3,  9);
        ListItem i2 = new ListItem("Bpples", "3/11/2022", 3,  15);
        ListItem i3 = new ListItem("Bpples", "3/11/2022", 3,  15);
        results.add(i1);
        results.add(i2);
        results.add(i3);
        return results;
    }

    private ArrayList sortA_Z() {
        Collections.sort(this.foodList, NAME_A_Z_ORDER);
        return this.foodList;
    }

    private ArrayList sortZ_A() {
        Collections.sort(this.foodList, NAME_Z_A_ORDER);
        return this.foodList;
    }

    private ArrayList sortShelfLife() {
        Collections.sort(this.foodList, SHELF_LIFE_ORDER);
        return this.foodList;
    }

    static final Comparator<ListItem> SHELF_LIFE_ORDER = new Comparator<ListItem>() {
        public int compare(ListItem a, ListItem b) {
            int sl1 = a.getIntShelfLife();
            int sl2 = b.getIntShelfLife();
            return Integer.compare(sl1, sl2);
        }
    };

    static final Comparator<ListItem> NAME_A_Z_ORDER = new Comparator<ListItem>() {
        public int compare(ListItem a, ListItem b) {
            return a.getName().compareToIgnoreCase(b.getName());
        }
    };

    static final Comparator<ListItem> NAME_Z_A_ORDER = new Comparator<ListItem>() {
        public int compare(ListItem a, ListItem b) {
            return b.getName().compareToIgnoreCase(a.getName());
        }
    };
}