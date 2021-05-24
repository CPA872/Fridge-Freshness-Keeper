package com.example.ffkmobile;

public class ListItem implements Comparable<ListItem> {
    private String name;
    private String purchaseDate;
    private String shelfLife;
    private String count;

    private int intShelfLife;
    private int intCount;

    public ListItem(String name, String purchaseDate, int shelfLife, int count) {
        this.name = name;
        this.purchaseDate = purchaseDate;
        this.shelfLife = "Shelf life: " + String.valueOf(shelfLife) + " days";
        this.count = "Remaining: " + String.valueOf(count);

        this.intShelfLife = shelfLife;
        this.intCount = count;
    }


    public String getPurchaseDate() {
        return purchaseDate;
    }

    public void setPurchaseDate(String purchaseDate) {
        this.purchaseDate = purchaseDate;
    }

    public String getShelfLife() {
        return shelfLife;
    }

    public void setShelfLife(String shelfLife) {
        this.shelfLife = shelfLife;
    }

    public String getCount() {
        return count;
    }

    public void setCount(String count) {
        this.count = count;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String toString() {
        return name + " " + purchaseDate + " " + shelfLife + " " + count;
    }

    public int getIntCount() {
        return intCount;
    }

    public int getIntShelfLife() {
        return intShelfLife;
    }

    @Override
    public int compareTo(ListItem o) {
        return 0;
    }
}
