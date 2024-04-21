# Seat-Heater-Control-System
Implementation of a seat heater control system for the front two seats in the car (driver seat and passenger  seat) using FreeRTOS on TivaC

Each seat shall consist of:
1. The button that is used to take the input level required to set the seat temperature.
2. Temperature sensor to monitor the temperature value.
3. Heating element to control the temperature value based on the desired level using a variable intensity
power as input.
4. Shared screen between both seats to show the current state of the system. 
System features:
1. Heating level shall have one value of the following:
a. Off: The feature is off, and the temperature is not controlled.
b. Low: the desired temperature is 25°C.
c. Medium: the desired temperature is 30°C.
d. High: the desired temperature is 35°C.
2. System shall control the temperature to be set within the range of the desired temperature +/- 3°C.
3. Diagnostics shall be present in case of failure of the temperature sensor.
a. If the temperature sensor gives a value out of its range this is considered as a failure in the 
sensor.
b. The range of the temperature sensor shall be 5°C-40°C.
c. Such issues shall be logged in the memory according to the requirements.
4. All the data required to be presented to the user shall be shown on the screen of the car.
5. System contains 3 different buttons as shown in the images:
a. 2 buttons in the car's middle console where each button is used to control one of the two seat
heaters.
b. 1 extra button in the steering wheel to control the driver seat heater to make the usage of the 
heater easier for the driver.
![image](https://github.com/Seif-Gama1/Seat-Heater-Control-System/assets/126584186/3b7e8fea-806a-47f3-b322-1468f6fd91ce)
