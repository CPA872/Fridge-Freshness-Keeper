## Fridge-Freshness-Keeper

**A Georgia Tech CDAIT IoT Challenge Project**

**Design Team**
- Zechuan Ding, School of ECE, zding72@gatech.edu
- Yue Pan, School of ECE, ypan331@gatech.edu
- Yihua, Xu, School of Math and School of History and Sociology, yxu604@gatech.edu

**Links**
- [Demo Video](https://youtu.be/w1Gjtki0x8E)
- [Project Report](https://docs.google.com/document/d/1jFisFSvs9kEznSA4-92oM_S1GHq3HtN5IAoPb1JMBIw/edit?usp=sharing)
- [Github Repository](https://github.com/CPA872/Fridge-Freshness-Keeper)  (Refer here for reproducing our project)

## TLDR

Fridge-Freshness-Keeper is a fridge managing and food tracking system. It consists of a Raspberry Pi mounted on the fridge, a mobile app installed on an Android device, and an Alexa Skill. Users will be able to look up and manage their fridge conten through the three aspects. 

## Motivation

As we have a tremendous amount of food being wasted on a daily basis, it is integral for us to stay vigilant and attentive to food’s shelf life in case they are discarded for food spoilage. To tackle the problem of food wastage and let people optimize their food utilization, we propose the Fridge-Freshness-Keeper: a smart IoT system that can track the shelf-life of foods stored in the fridge and alert users about expiring items. 

In particular, Fridge-Freshness-Keeper attempts to solve the following two difficulties with traditional fridge management:
- It is hard to keep track of shelf lives of foods, because with regards to a particular item in the fridge, people may fail to recall it’s purchase date, or are reluctant to locate and check the expiration date on its package. Our IoT design enables users to save food’s shelf life in the IoT system and conveniently look them up through multiple sources.
- It is easy to forget what is put into the fridge. Furthermore, items in the fridge are often stacked, making identifying all items at a glance challenging. Our system helps users to remember such trivial things. By either voice-inputting or typing on the screen after each purchase, users can easily keep track of foods inside their refrigerator. 

## Overview of Solution
<img src="images/Emoticons/cool.png" alt="solution overview" class="inline"/>
![solution overview](https://github.com/CPA872/Fridge-Freshness-Keeper/blob/main/gh_rsc/sol.png)

As shown above, three phases are implemented to solve the problem of fridge food waste. On the input side, there are two ways for adding purchased items into the system. The Alexa Skill + voice recognition allows users simultaneously put items into the fridge and log items to our system. The typed input via Raspberry Pi touchscreen allows users to log food items using the on-screen keyboard. After input items are logged, they are combined using Boto3 into a shared DynamoDB database. 

On the input side, there are two ways for adding purchased items into the system. The Alexa Skill + voice recognition allows users simultaneously put items into the fridge and log items to our system. The typed input via Raspberry Pi touchscreen allows users to log food items using the on-screen keyboard. After input items are logged, they are combined using Boto3 into a shared DynamoDB database. 

On the output side, the Raspberry Pi mounted on the refrigerator shows a list of food inside the fridge, as well as their quantities and shelf lives. Moreover, it monitors the humidity and temperature inside the fridge. The Android App connected to DynamoDB using AWS AppSync and AWS Amplify displays the food information pulled from the cloud. The Android App can also push notifications to users alerting approaching food expiration dates. 

## Next Steps
- The GUI interfaces can be designed better. We lack necessary skills on UI design principles and methods. Therefore, the designed Raspberry Pi GUI and Android App only meet the functional goal. A better looking UI will greatly enhance the user experience. 
- The Refrigeration Gas Sensor (model ZMOD4450) can be integrated into our IoT. During the prototyping process, we find it very challenging to work with the sensor because there are very few references online since the sensor is a proprietary product. With the addition of the sensor, once gas released by spoiled food is detected from the fridge, alerts can be sent to users asking for attention.
- A mobile app targeting the iOS platform is a good choice for expanding the user body.
- Methods to integrate the IoT hardware with existing fridges, such as mounting the screen and Pi onto the fridge door, should be developed when the product enters mass production. The power cables for the Pi and screen should also be integrated to reduce the overhead for setting up the system. 
