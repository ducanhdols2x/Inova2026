
---

# 📦 Hệ thống Nhận diện Sản phẩm sử dụng RFID MFRC522 với Arduino

Dự án này sử dụng module đọc thẻ RFID **MFRC522** kết hợp với vi điều khiển Arduino để đọc mã UID của thẻ/móc khóa RFID, từ đó nhận diện và phân loại sản phẩm (Sản phẩm A hoặc Sản phẩm B) dựa trên danh sách UID đã được định nghĩa sẵn trong chương trình.

---

## 🛠️ Linh kiện cần chuẩn bị

1. **Vi điều khiển Arduino** (Arduino Uno, Nano, Mega,...)
2. **Module đọc RFID MFRC522** (kèm thẻ hoặc móc khóa MIFARE Classic 1K)
3. **Dây cắm breadboard** (Male to Female, Male to Male)
4. **Cáp kết nối USB** (để nạp code và kết nối Serial Monitor)

---

## 🔌 Sơ đồ kết nối chân (Wiring)

| Module MFRC522 | Arduino Uno / Nano | Chức năng |
| --- | --- | --- |
| **RST** | Pin 9 | Chân Reset |
| **SDA (SS)** | Pin 10 | Chân Slave Select |
| **MOSI** | Pin 11 | Giao tiếp SPI |
| **MISO** | Pin 12 | Giao tiếp SPI |
| **SCK** | Pin 13 | Xung nhịp SPI |
| **GND** | GND | Nguồn âm |
| **3.3V** | 3.3V | Nguồn dương (**Lưu ý: Không dùng cổng 5V vì có thể làm cháy module**) |

> *Lưu ý mở rộng:* Trong chương trình, chân `4` và `5` đã được cấu hình là `OUTPUT` (`pinMode(4, OUTPUT)`, `pinMode(5, OUTPUT)`), bạn có thể tận dụng để điều khiển LED hoặc Relay khi quét đúng sản phẩm tương ứng.

---

## 📚 Thư viện yêu cầu

Trước khi nạp code, bạn cần cài đặt thư viện **MFRC522** trong Arduino IDE:

1. Mở Arduino IDE.
2. Vào **Tools** > **Manage Libraries...** (hoặc nhấn `Ctrl + Shift + I`).
3. Tìm kiếm từ khóa **`MFRC522`** (bởi *GithubCommunity* hoặc *Miguel Balboa*).
4. Nhấn **Install**.
5. Thư viện `SPI.h` là thư viện có sẵn, không cần cài đặt thêm.

---

## ⚙️ Cấu hình Mã UID Sản phẩm

Trong mã nguồn, bạn có thể thay đổi mã UID của sản phẩm cho phù hợp với thẻ thực tế của bạn bằng cách chỉnh sửa mảng `spA` và `spB`:

```cpp
int spA[4] = {0x4C, 0x16, 0x27, 0x07}; // UID sản phẩm A
int spB[4] = {0x56, 0xA9, 0x26, 0x07}; // UID sản phẩm B

```

---

## 🚀 Hướng dẫn Sử dụng

1. Kết nối phần cứng Arduino với module MFRC522 theo bảng sơ đồ phía trên.
2. Mở **Arduino IDE**, copy đoạn code của bạn vào và chọn đúng cổng **Board** và **Port**.
3. Nhấn **Upload** để nạp chương trình vào Arduino.
4. Mở **Serial Monitor** trên Arduino IDE và chỉnh tốc độ baud về **`9600`**.
5. Đưa thẻ RFID lại gần module MFRC522:
* Nếu thẻ thuộc **Sản phẩm A**, màn hình sẽ hiển thị: `Day la san pham A`
* Nếu thẻ thuộc **Sản phẩm B**, màn hình sẽ hiển thị: `Day la san pham B`
* Nếu thẻ mới chưa định nghĩa, chương trình sẽ in ra mã Hex của thẻ để bạn dễ dàng cấu hình thêm.



---
