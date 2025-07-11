# 42_CSE-A_Biradar-Maroti
# IoT-Based Patient Health Monitoring System

This project is an **IoT-based patient health monitoring system** using **ESP8266 NodeMCU**, **MAX30100 (Heart Rate, SpO₂), LM35 (Body Temperature), and MPU6050 (Fall Detection, Motion Analysis)** sensors with **Firebase and Blynk** for **real-time monitoring, cloud storage, and alerting**.

---

## 🩺 Features
- **Heart Rate & SpO₂ Monitoring:** using MAX30100, real-time updates to **Blynk mobile app**.
- **Body Temperature Monitoring:** using LM35, logged and visualized via **Firebase Dashboard**.
- **Fall Detection & Motion Monitoring:** using MPU6050, with alerts via Firebase.
- **Real-Time Alerts:** automated email or app notifications on abnormal health parameters.
- **Remote Monitoring:** caregivers and doctors can monitor patients from anywhere.
- **Data Logging & Visualization:** charts, logs, and real-time status for trend analysis.
- **Low-cost, scalable, and practical for rural and elderly care.**

---

## 🛠️ Hardware Used
- **ESP8266 NodeMCU**
- **MAX30100 Sensor** – Heart rate & SpO₂
- **LM35 Temperature Sensor** – Body temperature
- **MPU6050 Sensor** – Fall detection & motion analysis
- Breadboard and jumper wires
- Regulated 3.3V power supply

---

## ☁️ Platforms Used
- **Firebase:** for storing LM35 and MPU6050 data with real-time database and dashboard.
- **Blynk:** for real-time monitoring of heart rate and SpO₂ on mobile.
- **IFTTT / Gmail Alerts:** for automated health threshold notifications.

---

## ⚙️ How It Works
- **MAX30100 data ➔ Blynk:** Displays heart rate and SpO₂ in real time on a mobile app.
- **LM35 & MPU6050 ➔ Firebase:** Sends body temperature and motion data to Firebase for dashboard visualization and alerts.
- **ESP8266 Wi-Fi Connectivity:** Enables real-time data transfer to cloud platforms.
- **Alerting Mechanism:** Triggers email alerts if abnormal heart rate, SpO₂, or falls are detected.
- **Dashboard:** Built with HTML, CSS, JS + Chart.js to visualize trends in real time.

---

## 📈 Applications
- Elderly care with fall detection.
- Remote patient monitoring.
- Chronic illness management (heart, respiratory, etc.)
- Home quarantine health monitoring.
- Hospital overflow reduction.

---

## 🚀 Getting Started

1. **Hardware Setup:**
   - Connect sensors to the ESP8266 (MAX30100 on I2C, LM35 on A0, MPU6050 on I2C).
   - Ensure stable 3.3V regulated power.
   - Use breadboard for testing and prototyping.

2. **Firmware:**
   - Use **Arduino IDE** to upload the firmware.
   - Initialize Wi-Fi credentials, Firebase keys, and Blynk authentication tokens.
   - Calibrate sensors for accurate readings.

3. **Cloud Setup:**
   - Create a **Firebase Realtime Database** with structured paths for sensor data and alerts.
   - Setup **Blynk Project** on mobile and note down the authentication token.
   - Configure **IFTTT / Blynk Events** for email alerting.

4. **Dashboard:**
   - Deploy the web dashboard using HTML/CSS/JavaScript.
   - Use Chart.js for real-time graphing of temperature and motion data from Firebase.
   - View real-time health statuses and alerts on the Blynk app.




## 🤝 Contributing
Contributions are welcome! Feel free to fork this repository, open issues, and submit pull requests to improve or expand this system.

---


## 🌟 Acknowledgments
- Firebase for real-time cloud storage
- Blynk IoT for mobile-based visualization
- Arduino community for library support

---

> **This system aims to improve healthcare accessibility by leveraging IoT for real-time, remote, and affordable patient health monitoring.**
