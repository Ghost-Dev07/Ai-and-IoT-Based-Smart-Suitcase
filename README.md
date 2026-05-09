![Language](https://img.shields.io/badge/Language-Embedded%20C-blue)
![Python](https://img.shields.io/badge/Language-Python-green)
![MCU](https://img.shields.io/badge/MCU-Arduino%20UNO-orange)
![MCU](https://img.shields.io/badge/MCU-ESP8266-red)
![Platform](https://img.shields.io/badge/Platform-Raspberry%20Pi-purple)
![Domain](https://img.shields.io/badge/Domain-Embedded%20Systems-lightgrey)
![Feature](https://img.shields.io/badge/Feature-Face%20Recognition-brightgreen)
![Communication](https://img.shields.io/badge/Communication-IoT-yellow)

# 🧳 AI and IoT Based Smart Suitcase

## 🚀 Overview

A multi-controller smart suitcase system designed to improve security, tracking, and usability by integrating embedded systems, AI-based authentication, IoT connectivity, and sensor monitoring.

---

## 🧠 Problem Statement

Traditional suitcases lack:

* Advanced authentication mechanisms
* Real-time location tracking
* Intelligent access control
* Load monitoring capabilities
* Remote security management

---

## 💡 Solution

This project introduces a smart suitcase with:

* 🔐 Multi-layer authentication (RFID, Face Recognition, Manual Key)
* 🌐 IoT-based remote access validation
* 📍 Real-time GPS tracking
* ⚖️ Load monitoring system
* 📦 Lid open/close detection

---

## 🏗️ System Architecture

The system is built using multiple controllers working together:

* Raspberry Pi → Face recognition
* Arduino UNO → Core control logic
* ESP8266 → IoT communication and GPS handling

```text id="u8u7lb"
              +------------------------+
              |   Raspberry Pi 3B+     |
              |  (Face Recognition)    |
              +-----------+------------+
                          |
                          | GPIO (Authentication Signal)
                          |
+----------------+        v         +----------------------+
|  RFID Module   | ---> Arduino UNO <--- Load Cell + HX711 |
+----------------+   (Main Controller)   +------------------+
                          |
                          | Serial / GPIO
                          v
                  +------------------+
                  |    ESP8266       |
                  | (IoT + GPS Node) |
                  +--------+---------+
                           |
                           | Wi-Fi
                           v
                  +------------------+
                  | Arduino IoT Cloud|
                  +------------------+

Additional Modules:
- 4x IR Sensors → AND Gate → Lid Status Detection
- MPU6050 → Orientation Correction for Load Accuracy
- CLCD → System Display Output
```

---

## 🔧 Hardware Components

* Arduino UNO
* ESP8266
* Raspberry Pi 3B+
* RFID Module
* Neo-6M GPS Module
* Load Cell + HX711
* MPU6050
* IR Sensors
* CLCD Display

---

## 💻 Software Stack

* Embedded C
* Python (OpenCV + Haar Cascade)
* Arduino IoT Cloud
* Serial Communication

---

## 🔄 System Workflow

### 🔐 Authentication System

The suitcase supports three authentication methods:

* RFID-based access
* Face recognition using Raspberry Pi
* Manual key-based backup access

### 🌐 IoT Security Logic

* RFID authentication is validated through Arduino IoT Cloud
* If password mismatch occurs, access is blocked
* Remote cloud-based override is required to re-enable access

### 📍 GPS Tracking

* ESP8266 receives GPS data from the Neo-6M module
* Location is transmitted to the IoT dashboard

### ⚖️ Load Monitoring

* Load cell measures suitcase weight
* MPU6050 is used to improve measurement stability based on orientation

### 📦 Lid Detection

* Four IR sensors are placed at the suitcase corners
* AND gate logic determines lid open/close status

---

## ⚡ Key Features

* Multi-controller embedded architecture
* AI-based authentication
* IoT-enabled remote access validation
* GPS-based tracking
* Sensor-based load monitoring
* Hybrid online/offline functionality

---

## 🎥 Video links

* [RFID linked with IoT based password mechanism](https://drive.google.com/file/d/1WFukvt_SyvQUtBGksHZiEwvq7AYkh2YX/view?usp=sharing)
  -> In this video, we can see that the correct RFID tag(White tag) can be used to unlock the suitcase(LED in the video). For security purposes, if the correct RFID tag is stolen/threatened, the user can change the password using the IoT app. Once changed, the suitcase will not open even with correct RFID tag. The user can switch back to normal mode only by the app given to the user.
  
* [Real time suitcase open/close montioring](https://drive.google.com/file/d/1NJcHaoXW2CDzF00FsdXsu2UkE0Il3hD2/view?usp=sharing)
  -> In this video, The status of the lid of the suitcase is being reflected on the app in real time.

---

## 📸 Images

### 🧳 Block diagram of the project
![Block diagram](images/Suitcase1.jpg)

### 🧳 1st Prototype

![Setup Image](images/First-Prototype-implemented-with-a-box.jpg)

### 🔧 Final system implementation

![Internal Image](images/Suitcase-image-3.jpg)

### 🔧 Final system implementation with Labels

![Internal Image](images/Suitcase-image-2.jpg)



---

## 📊 Results

* Successfully implemented multi-layer authentication
* Achieved real-time GPS tracking and monitoring
* Reliable communication established between controllers
* Load monitoring implemented with partial calibration limitations

---

## ⚠️ Engineering Challenges

* Load cell calibration instability under dynamic conditions
* Synchronization between multiple controllers
* Reliable communication between ESP8266 and Arduino UNO
* Power management using portable power sources

---


## 🧠 What I Learned

* Multi-microcontroller communication
* Embedded system integration
* Sensor fusion concepts
* IoT-based authentication logic
* Real-world hardware debugging and limitations
