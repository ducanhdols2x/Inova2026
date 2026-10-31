
---

# 📦 RFID MFRC522 Product Identification System with Arduino

This project uses the **MFRC522** RFID reader module combined with an Arduino microcontroller to read the UID code of RFID tags/key fobs, thereby identifying and classifying products (Product A or Product B) based on a pre-defined list of UIDs in the code.

---

## 🛠️ Required Components

1. **Arduino Microcontroller** (Arduino Uno, Nano, Mega, etc.)
2. **MFRC522 RFID Reader Module** (with MIFARE Classic 1K tag or key fob)
3. **Jumper Wires** (Male-to-Female, Male-to-Male)
4. **USB Cable** (for power supply, uploading code, and Serial Monitor debugging)

---

## 🔌 Pin Wiring Setup

| MFRC522 Module | Arduino Uno / Nano | Function |
| --- | --- | --- |
| **RST** | Pin 9 | Reset Pin |
| **SDA (SS)** | Pin 10 | Slave Select Pin |
| **MOSI** | Pin 11 | SPI Communication |
| **MISO** | Pin 12 | SPI Communication |
| **SCK** | Pin 13 | SPI Clock |
| **GND** | GND | Ground |
| **3.3V** | 3.3V | Power Supply (**Note: Do NOT use the 5V pin as it can damage the module**) |

> *Note:* In the code, digital pins `4` and `5` are configured as outputs (`pinMode(4, OUTPUT)`, `pinMode(5, OUTPUT)`). You can connect LEDs or Relays to these pins to trigger actions when a specific product is scanned.

---

## 📚 Required Libraries

Before uploading the code, install the **MFRC522** library in the Arduino IDE:

1. Open Arduino IDE.
2. Go to **Tools** > **Manage Libraries...** (or press `Ctrl + Shift + I`).
3. Search for **`MFRC522`** (by *GithubCommunity* or *Miguel Balboa*).
4. Click **Install**.
5. The `SPI.h` library comes built-in with the Arduino IDE, so no separate installation is required.

---

## ⚙️ Configuring Product UIDs

You can customize the product UIDs to match your actual RFID tags by modifying the `spA` and `spB` arrays in the source code:

```cpp
int spA[4] = {0x4C, 0x16, 0x27, 0x07}; // Product A UID
int spB[4] = {0x56, 0xA9, 0x26, 0x07}; // Product B UID

```

---

## 🚀 How to Use

1. Wire the Arduino to the MFRC522 module according to the pinout table above.
2. Open **Arduino IDE**, paste the code, and select the correct **Board** and **Port**.
3. Click **Upload** to upload the program to your Arduino board.
4. Open the **Serial Monitor** in Arduino IDE and set the baud rate to **`9600`**.
5. Swipe an RFID tag near the MFRC522 module:
* If the tag matches **Product A**, the monitor displays: `Day la san pham A`
* If the tag matches **Product B**, the monitor displays: `Day la san pham B`
* If a new or unassigned tag is detected, the program will print its Hex UID so you can add it to your program easily.



---
