# 🧳 AI + IoT Based Smart Suitcase

## 🚀 Overview

A multi-layer intelligent suitcase system designed to enhance security, tracking, and usability by integrating AI, IoT, and embedded systems.

---

## 🧠 Problem Statement

Traditional suitcases lack:

* Advanced security
* Real-time tracking
* Smart access control
* Load monitoring

---

## 💡 Solution

This project introduces a smart suitcase with:

* 🔐 Multi-mode authentication (RFID, Face Recognition, Manual key)
* 🌐 IoT-based remote access control
* 📍 GPS tracking
* ⚖️ Load monitoring system
* 📦 Lid status detection

---

## 🏗️ System Architecture

Raspberry Pi (Face Recognition)
↓
Arduino UNO (Core Control Unit)
↓
ESP8266 (IoT + GPS + Cloud Communication)

```
              +------------------------+
              |   Raspberry Pi 3B+     |
              |  (Face Recognition)    |
              +-----------+------------+
                          |
                          | GPIO (Auth Signal)
                          |
+----------------+        v         +----------------------+
|  RFID Module   | ---> Arduino UNO <--- Load Cell + HX711 |
+----------------+   (Main Controller)   +------------------+
                          |
                          | Serial / GPIO
                          v
                  +------------------+
                  |    ESP8266       |
                  |  (IoT + GPS)     |
                  +--------+---------+
                           |
                           | Wi-Fi
                           v
                  +------------------+
                  | Arduino IoT Cloud|
                  +------------------+

Additional:
- 4x IR Sensors → AND Gate → Lid Status
- MPU6050 → Orientation for Load Accuracy
- CLCD → Display Output
```


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

* Embedded C (Arduino)
* Python (OpenCV - Haar Cascade)
* Arduino IoT Cloud
* Serial Communication

---

## 🔄 Working

### 🔐 Authentication System

* RFID-based access with dynamic password validation via IoT
* Face recognition using Raspberry Pi
* Manual key backup system

### 🌐 IoT Security Logic

* Password mismatch blocks RFID access
* Cloud-based override required to unlock

### 📍 Tracking

* GPS module sends location to IoT dashboard

### ⚖️ Load Monitoring

* Load cell measures weight
* MPU6050 ensures accurate reading orientation

### 📦 Lid Detection

* 4 IR sensors → AND gate logic → detects closed/open state

---

## ⚡ Key Features

* Multi-controller communication (Arduino + ESP8266 + RPi)
* Redundant security layers
* Offline + online hybrid system
* Real-time monitoring

---

## 📸 Images

## 📸 Images

![Setup](images/suitcase-image-1.jpg)
![Internal](images/suitcase-image-2.jpg)

---

## 📊 Results

* Successfully implemented multi-layer security
* Real-time suitcase monitoring achieved
* Load cell faced calibration challenges

---

## 🔮 Future Improvements

* Replace load cell with higher precision sensor
* Mobile app instead of IoT dashboard
* Compact PCB-based design

---

## 🧠 What I Learned

* Multi-microcontroller communication
* System-level integration
* Sensor fusion challenges
* Real-world hardware limitations
