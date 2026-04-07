# 🎬 ESP32 OLED Video Player (128x64)

Project ini memungkinkan kamu untuk memutar animasi atau video secara mulus di layar OLED 128x64 (SSD1306) menggunakan mikrokontroler ESP32. 

Alih-alih menggunakan `delay()` yang bikin sistem nge-lag, program ini menggunakan metode `millis()` untuk *timing* frame yang presisi, serta melakukan *overclock* pada jalur I2C hingga 800 kHz agar pengiriman data gambar ke layar OLED bisa super ngebut tanpa patah-patah! 🚀

## ✨ Fitur Utama
* **Web-based Frame Extractor:** Konversi video apapun (.mp4, .webm, dll) menjadi array C++ 1-bit (PROGMEM) langsung dari browser secara *offline*!
* **Non-Blocking FPS Control:** Memakai `millis()` untuk menjaga Frame Per Second (FPS) tetap stabil sesuai video aslinya.
* **I2C Overclocking:** Kecepatan transfer I2C dinaikkan dari 100 kHz (default) menjadi 800 kHz.
* **Serial Monitor Tracking:** Melacak status frame dan waktu *real-time* langsung dari Serial Monitor.

## 🛠️ Perangkat Keras yang Dibutuhkan
1. **ESP32** (NodeMCU/WROOM)
2. **Display OLED 128x64** (Chip SSD1306, Komunikasi I2C)
3. Kabel Jumper secukupnya

### Konfigurasi Pin (Wiring)
| OLED Pin | ESP32 Pin |
| :---: | :---: |
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

## 📦 Kebutuhan Software (Library)
Pastikan kamu sudah menginstal library berikut di Arduino IDE:
* `Adafruit GFX Library`
* `Adafruit SSD1306`

## 🚀 Cara Penggunaan

### 1. Ekstrak Video menjadi Kode (Bikin VideoFrame.h)
1. Buka file `Vid2Oled.html` menggunakan browser (Chrome/Edge direkomendasikan).
2. Masukkan video yang ingin kamu tampilkan.
3. Atur target FPS dan Threshold (kontras Hitam/Putih).
4. Klik **Mulai Extract Frame-by-Frame** dan tunggu hingga selesai.
5. Klik **Copy Code ke Clipboard**.
6. Buat file baru di Arduino IDE, beri nama `VideoFrame.h`, lalu *paste* kode tersebut di sana.

### 2. Upload ke ESP32
1. Pastikan file program utama (`.ino`) dan `VideoFrame.h` berada di dalam folder yang sama.
2. Buka file `.ino` di Arduino IDE.
3. **PENTING:** Karena array video memakan memori Flash yang cukup besar, masuk ke menu **Tools > Partition Scheme** dan ubah menjadi **"Huge APP (3MB No OTA/1MB SPIFFS)"**.
4. Klik **Upload**.
5. Buka **Serial Monitor** (Baud rate: 115200) untuk melihat laporan berjalannya frame.

## 👨‍💻 Kreator
Dikembangkan oleh **Tri Wahyu**.
* Instagram: [@Triwahyu45](https://instagram.com/Triwahyu45)
* YouTube: [Tri Wahyu](https://youtube.com/@Triwahyu45)

Jika project ini bermanfaat buat kamu, jangan lupa kasih ⭐ (Star) di repository ini ya!
