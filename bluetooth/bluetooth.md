# Bluetooth BLE

## Table of Contents
- [1. Bluetooth Classic vs BLE](#1-bluetooth-classic-vs-ble)
- [2. Layers (Các lớp)](#2-layers-các-lớp)
- [3. GATT (Generic Attribute Profile)](#3-gatt-generic-attribute-profile)
- [4. ATT (Attribute Protocol)](#4-att-attribute-protocol)
- [5. GAP (Generic Access Profile)](#5-gap-generic-access-profile)
  - [5.1 GAP Connectionless](#51-gap-connectionless-trao-đổi-không-cần-kết-nối)
  - [5.2 GAP Connection-Oriented](#52-gap-connection-oriented-trao-đổi-có-kết-nối)
- [6. SMP and L2CAP](#6-smp-and-l2cap-giao-thức-bảo-mật-và-lớp-liên-kết-logic)
- [7. SPP and RFCOMM](#7-spp-and-rfcomm)


## 1. Bluetooth Classic vs BLE
| Tính năng (Feature)           | Bluetooth Classic (BR/EDR)                      | Bluetooth Low Energy (BLE)                              |
|------------------------------|--------------------------------------------------|----------------------------------------------------------|
| Ra đời (Introduced)          | Original version *(phiên bản gốc)*              | Introduced in 2010 (Bluetooth 4.0) *(ra đời năm 2010)*  |
| Mục đích (Purpose)           | Continuous, high-rate data (e.g., audio) *(truyền dữ liệu liên tục, tốc độ cao – ví dụ âm thanh)* | Low-power, intermittent data (e.g., sensors) *(tiết kiệm năng lượng, truyền dữ liệu ngắt quãng – ví dụ cảm biến)* |
| Tốc độ truyền (Data Rate)    | Up to ~3 Mbps (EDR) *(tối đa khoảng 3 Mbps)*     | Up to ~1 Mbps *(tối đa khoảng 1 Mbps)*                  |
| Tiêu thụ năng lượng (Power Consumption) | Higher *(tiêu thụ năng lượng cao hơn)*          | Extremely low *(rất thấp)*                              |
| Thời lượng pin (Battery Life) | Hours to a few days *(vài giờ đến vài ngày)*     | Months to years *(vài tháng đến vài năm)*               |
| Ứng dụng phổ biến (Typical Use Cases) | Headphones, speakers, audio streaming *(tai nghe, loa, truyền âm thanh)* | Smartwatches, fitness bands, sensors, beacons *(đồng hồ thông minh, thiết bị đeo, cảm biến, beacon)* |
| Mô hình giao tiếp (Communication Model) | Serial Port Profile (SPP), UART-like *(giao tiếp kiểu UART qua SPP)* | GATT (client/server model) *(mô hình client/server dùng GATT)* |
| Số kênh tần số (Frequency Channels) | 79 channels *(79 kênh tần số)*                  | 40 channels *(40 kênh tần số)*                          |
| Băng thông mỗi kênh (Channel Bandwidth) | 1 MHz *(băng thông mỗi kênh là 1 MHz)*          | 2 MHz *(băng thông mỗi kênh là 2 MHz)*                  |
| Kết nối nhiều thiết bị (Multi-device Connections) | Limited *(hạn chế kết nối cùng lúc)*            | Better (depending on role) *(tốt hơn – tùy vai trò)*    |
| Kích thước gói dữ liệu (Packet Size) | Larger (~1021 bytes) *(gói dữ liệu lớn hơn)*     | Smaller (~251 bytes) *(gói dữ liệu nhỏ hơn)*           |
| Tương thích ngược (Backward Compatibility) | Doesn’t support BLE *(không hỗ trợ BLE)*        | Can coexist with Classic (dual-mode chip like ESP32) *(có thể hoạt động song song với Classic – ví dụ chip ESP32)* |

![bluetooth_structure](bluetooth_structure.png)

## 2. Layers (Các lớp)

### Controller (Bộ điều khiển):
- Encompasses the radio hardware-related aspects, such as controlling the transceiver, modulation, frequency channel selection, initial packet structuring, and direct communication.  
  *(Bao gồm các khía cạnh liên quan đến phần cứng vô tuyến, như điều khiển bộ thu phát, điều chế, chọn kênh tần số, cấu trúc gói dữ liệu ban đầu và giao tiếp trực tiếp).*

### Host (Bộ xử lý chính):
- Provides the actual Bluetooth functionality to an application.  
  *(Cung cấp chức năng Bluetooth thực tế cho ứng dụng).*

> **Note (Ghi chú):**  
> Separation in host and controller enabling implementation on different chips. Nowadays, typically single-chip solution.  
> *(Việc tách rời giữa host và controller cho phép triển khai trên các vi mạch khác nhau. Ngày nay, thường sử dụng giải pháp tích hợp một chip duy nhất).*

## 3. GATT (Generic Attribute Profile)

- **Generic Attribute Profile (GATT)**  
  *(Hồ sơ thuộc tính chung – GATT)*

- **Defines services and attributes (characteristics) provided by a GATT server.**  
  *(Định nghĩa các dịch vụ và thuộc tính (characteristic) được cung cấp bởi máy chủ GATT.)*

- **Predefined services and characteristics identified by a unique 16-bit UUID.**  
  *(Các dịch vụ và characteristic được định nghĩa sẵn có định danh duy nhất dạng UUID 16-bit.)*

- **For example, Environmental Sensing Service (ESS) has the UUID 0x181A**  
  *(Ví dụ, Dịch vụ cảm biến môi trường (ESS) có UUID là 0x181A)*

  - **Characteristics:**  
    - **Pressure:** `0x2A6D` *(Áp suất)*  
    - **Temperature:** `0x2A6E` *(Nhiệt độ)*  
    - **Humidity:** `0x2A6F` *(Độ ẩm)*

## 4. ATT (Attribute Protocol)

- **The Attribute Protocol (ATT) enables the exchange of attributes.**  
  *(Giao thức thuộc tính - ATT cho phép trao đổi các thuộc tính.)*

- **An attribute is a composition of four components:**  
  *(Một thuộc tính bao gồm bốn thành phần:)*  
  - **Attribute type:** a 128-bit UUID *(loại thuộc tính – một UUID 128-bit)*  
  - **Attribute reference:** handle *(tham chiếu thuộc tính – handle)*  
  - **Attribute rights:** read, write *(quyền truy cập thuộc tính – đọc, ghi)*  
  - **Attribute value:** byte array *(giá trị thuộc tính – mảng byte)*  
  - *The attribute value can be a byte array of any length.*  
    *(Giá trị thuộc tính có thể là mảng byte có độ dài bất kỳ.)*

- **ATT is used to exchange the characteristics (attributes) defined in the GATT server.**  
  *(ATT được sử dụng để trao đổi các characteristic (thuộc tính) được định nghĩa trong máy chủ GATT.)*

## 5. GAP (Generic Access Profile)

- **Generic Access Profile (GAP)**  
  *(Hồ sơ truy cập chung – GAP)*

- **Responsible for the connection setup and the type of connection.**  
  *(Chịu trách nhiệm thiết lập kết nối và xác định loại kết nối.)*

- **Allows connectionless and connection-oriented data exchange.**  
  *(Cho phép trao đổi dữ liệu không cần kết nối và có kết nối.)*

### 5.1 GAP Connectionless (Trao đổi không cần kết nối)

**Connectionless exchange:**  
*(Trao đổi dữ liệu không cần thiết lập kết nối)*

- **GATT server sends its data periodically via broadcast (advertising).**  
  *(Máy chủ GATT gửi dữ liệu định kỳ qua hình thức quảng bá – advertising.)*

- **GATT server acting as the Broadcaster**  
  *(GATT server đóng vai trò là bộ phát quảng bá dữ liệu – Broadcaster)*

- **Client acting as Observer.**  
  *(Thiết bị client đóng vai trò là thiết bị quan sát – Observer)*

- **Suitable for applications where data needs to be regularly updated, and low latency is not critical.**  
  *(Phù hợp cho các ứng dụng cần cập nhật dữ liệu thường xuyên và không yêu cầu độ trễ thấp.)*

### 5.2 GAP Connection-Oriented (Trao đổi có kết nối)

**Connection-oriented exchange:**  
*(Trao đổi dữ liệu có thiết lập kết nối)*

- **The GATT server acting as Peripheral.**  
  *(Máy chủ GATT đóng vai trò là thiết bị ngoại vi – Peripheral)*

- **Client assumes the role of the Central.**  
  *(Thiết bị client đóng vai trò là trung tâm – Central)*

- **Peripheral initially advertises the services it offers.**  
  *(Thiết bị ngoại vi quảng bá các dịch vụ mà nó cung cấp)*

- **When a Central is interested in establishing a connection, it sends a connection request to the Peripheral.**  
  *(Khi thiết bị trung tâm muốn thiết lập kết nối, nó sẽ gửi yêu cầu kết nối đến thiết bị ngoại vi.)*

![Bluetooth Comparison](bluetooth_exam_1.png)

## 6. SMP and L2CAP (Giao thức bảo mật và lớp liên kết logic)

### SMP:
- **The Security Manager Protocol (SMP).**  
  *(Giao thức Quản lý Bảo mật – SMP)*

- **Provides various services for a secure connection.**  
  *(Cung cấp các dịch vụ khác nhau để đảm bảo kết nối an toàn.)*

### L2CAP:
- **Logical Link Control and Adaption Layer Protocol (L2CAP).**  
  *(Giao thức điều khiển liên kết logic và lớp thích nghi – L2CAP)*

- **Distributes the packets to corresponding protocols above (multiplexing)**  
  *(Phân phối các gói dữ liệu đến các giao thức tương ứng ở tầng trên – ghép kênh)*

- **Fragments large data packets and reassembles them.**  
  *(Phân mảnh các gói dữ liệu lớn và lắp ráp lại thành gói hoàn chỉnh.)*

## 7. SPP and RFCOMM

### 🔶 SPP – Serial Port Profile

- SPP (Serial Port Profile) is a Bluetooth profile that emulates serial communication like the RS-232 (UART) standard.  
  *(SPP là một profile Bluetooth mô phỏng giao tiếp cổng nối tiếp giống như chuẩn RS-232 (UART).)*

- It uses RFCOMM to transmit data between two Bluetooth devices.  
  *(Nó sử dụng RFCOMM để truyền dữ liệu giữa hai thiết bị Bluetooth.)*

- Allows devices to send byte-based data as if using a typical COM port.  
  *(Cho phép các thiết bị truyền dữ liệu dạng byte như khi sử dụng cổng COM thông thường.)*

- ➤ Common applications: data transfer between PC and external peripherals (e.g., GPS, Bluetooth printers, sensors).  
  *(➤ Ứng dụng phổ biến: truyền dữ liệu giữa máy tính với thiết bị ngoại vi như GPS, máy in Bluetooth, cảm biến.)*

---

### 🔶 RFCOMM – Radio Frequency Communication

- RFCOMM is a transport-layer protocol in the Bluetooth stack.  
  *(RFCOMM là một giao thức ở tầng truyền tải (transport) trong ngăn xếp Bluetooth.)*

- Its goal is to provide a UART-like interface for applications.  
  *(Mục tiêu của RFCOMM là cung cấp một giao diện giống UART cho các ứng dụng.)*

- It emulates point-to-point communication and serves as the transport layer for profiles like SPP.  
  *(Nó mô phỏng kết nối điểm-điểm và là lớp truyền dữ liệu cho các profile như SPP.)*

- RFCOMM operates on top of L2CAP, bridging the logical and radio layers.  
  *(RFCOMM hoạt động trên L2CAP, đóng vai trò cầu nối giữa tầng logic và tầng truyền thông radio.)*

