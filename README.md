
========================================================================

# ESP32-S3 — Multi-Core Peripheral Experiments
  
========================================================================

  # Nama  : Aria Alvanza Angzola Adi
  
  # NRP   : 3223600012
  
  # Kelas : 3 D4 Teknik Komputer A
  
--------------------------------------------------------

  Deskripsi:
  Repositori ini berisi kumpulan percobaan menggunakan
  ESP32-S3 untuk menguji berbagai peripheral dan menjalankan
  setiap program di core 0 dan core 1 menggunakan FreeRTOS.
  Tujuannya untuk memahami cara kerja multi-core pada ESP32-S3
  serta bagaimana setiap perangkat I/O dijalankan secara paralel.

--------------------------------------------------------

  Daftar Percobaan (Total 8 Program):
  1. OLED 
  2. LED
  3. Buzzer
  4. Servo
  5. Push Button
  6. Potensiometer
  7. Rotary Encoder
  8. Stepper

--------------------------------------------------------

  Langkah Percobaan:
  1. Hubungkan semua peripheral ke board ESP32-S3 sesuai pin.
  2. Buat program terpisah untuk setiap I/O.
  3. Jalankan tiap program di core 0 dan core 1
     menggunakan fungsi xTaskCreatePinnedToCore().
  4. Amati hasil dan perbedaan kinerja antar core.
  5. Dokumentasikan langkah, gambar rangkaian, dan video hasil.
  6. Upload ke GitHub dan kumpulkan link di Ethol.

--------------------------------------------------------

  Struktur Folder:
  
  ESP32S3-MultiCore/
  
  ├── BUZZER/
  
  ├── LED/
  
  ├── OLED/
  
  ├── POTENSIOMETER/
  
  ├── PUSHBUTTON/
  
  ├── ROTARYENCORE/
  
  ├── SERVO/
  
  └── STEPPER/

--------------------------------------------------------

  Tools:
  - Board     : ESP32-S3
  - IDE       : WOKWIK
  - Framework : FreeRTOS
  - Bahasa    : C / C++

========================================================

