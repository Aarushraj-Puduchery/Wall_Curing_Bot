# Wall_Curing_Bot

This is the project titled **‘Wall Curing Bot’** by **P. Aarushraj, P. Madhavi, M. Ankitha, K. Bharath chandra and B. Rajmohan**. 
This is a record of the project work carried out by us, during the year **2022-2023** as part of **POST INDUCTION** under the guidance and supervision of **Mr D.P. Naga Ajay Kumar & Ms P. Tapaswini** (Technical Heads) and **Mr T. Bharat Kumar** (The President of THE ROBOTICS CLUB)

## Abstract
To automate the process of curing concrete. Curing plays an important role in the strength development and durability of concrete. The project provides an efficient way to cure concrete during the construction of buildings which reduces the labour and time

## Introduction
Curing is the process of controlling moisture loss from concrete that has already been placed. Curing ensures the hydration of the cement, which in turn enhances its strength and durability. Curing takes place immediately after placing the concrete and deals with the maintenance of the desired temperature and moisture for extended periods. Proper curing helps to prevent grazing, dusting, surface disintegration and scaling. Adequate curing reduces shrinkage, gives better resistance to wear and improves long-term appearance. To automate this process of curing in the purpose of this project.

## Problem Statement
A lot of manpower and time is invested in curing concrete during construction. The time spent in curing can be directed elsewhere if the process of curing is automated. This project aims to automate the process of curing concrete. 

## Images of the Bot
| ![IMG-20221219-WA0006](https://github.com/Aarushraj-Puduchery/Wall_Curing_Bot/assets/97360295/5aefaf1e-bd80-44a8-8717-73583ca8f290)| ![IMG-20230118-WA0001](https://github.com/Aarushraj-Puduchery/Wall_Curing_Bot/assets/97360295/077a519a-9a36-4c0e-9da7-fcba774dc757)|
|---|---|
|||

## Working Video

### During Setup we enter the dimensions and then set the bot with minimum distance to the wall.
https://github.com/Aarushraj-Puduchery/Wall_Curing_Bot/assets/97360295/61d4c426-2e37-4ae1-bfb8-ab3b4de85028

### At the corner take a turn and spray Full Wall
https://github.com/Aarushraj-Puduchery/Wall_Curing_Bot/assets/97360295/7045942b-859f-478f-bfbd-24ad49cd40a3

### When there is no Wall, it will spray only at the top
https://github.com/Aarushraj-Puduchery/Wall_Curing_Bot/assets/97360295/00e3eaae-f1a5-47c7-a2c8-484672d98502

## Circuit Diagram
![Schematic_wall-curing-bot_2024-04-09](https://github.com/Aarushraj-Puduchery/Wall_Curing_Bot/assets/97360295/79327396-45b6-450d-b2dd-b4159e2c7b6b)

## Working
The working of the Wall Curing Bot is simple. First, it takes input from the user about the number of sides in the room and the dimensions of each side. After taking the input, the bot starts moving using the ultrasonic sensors to sense the wall and while moving it cures the wall using the pipe attached to it by moving the water pipe vertically up and down twice. After a single revolution, the bot halts and its function is fulfilled.

## Source Code 
Check the file uploading in this repository

## Component List
|S.No|Name|Quantity|Price(in Rupees)|
|---|---|---|---|
|1|Arduino Mega|1|1000|
|2|Servo Motor|1|100|
|3|HCSR04 ultrasonic sensor|3|195|
|4|Holders for HCSR04|3|125|
|5|L298N motor driver|2|240|
|6|LCD DISPLAY 16X2|1|120|
|7|4x4 Keypad|1|70|
|8|12v DC motor|4|560|
|9|Chasis|1|220|
|10|Speed Measuring Sensor|1|40|
|11|5V 1 Channel Relay|1|80|
|12|Submersible Mini Water Pump 12v DC|1|70|
|13|Buzzer|1|20|
|14|Wheels|4|300|
|15|12V 1.2Ah Rechargeable Sealed Lead Acid Battery|1|600|

## Future Enhancements
1. We can Add a more powerful motor to pull the water pipe.
2. Replace the Ultrasonic Sensor with a sharp IR Sensor for faster sensor reading and add more sensors for better movement.
3. Add a LIDAR system for Mapping the room and use that for navigation.


