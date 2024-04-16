# ICU

## [1. Gitlab](#1)
## [2. Chone LE SDK](#2)
## [3. git command](#3) 
## [4 turbox sdkmanager](#4) 
## [5. Connect USB devices under Windows Subsystem for Linux](#5) 
## [6. Build image](#6)
## [7. Minicom](#7)
## [8. CM2290](#8)
### [8.1 SIM card slot](#8-1)
### [8.2 HDMI Component](#8-2)

#
## <a id="1"></a> 1. Gitlab 
## <a id="2"></a> 2. Chone LE SDK 
```sh
repo init -u https://partner.thundercomm.com/sdkgit/a/manifest -b SDK.Turbox-Snapdragon_Mid_2021_LE_CSS.SPF.1.0 -m turbox-cm2290-le1.0-dev.release.ES.r000002.xml --repo-url=https://partner.thundercomm.com/sdkgit/a/tools/repo --repo-branch=stable --no-repo-verify --reference=.
```
**Note:** 
- machine partner.thunder.comm.com login 
- echo "machine partner.thundercomm.com login
- vietanh@tecotec.com.vn password Tech@2023 > ~/.netrc
**Username*
```sh
vietanh@tecotec.com.vn
```
**Password**
```sh
Tech@2023
```

## <a id="3"></a> 3. git command 
```sh
repo forall -vc "git reset --hard" git pull --all
```
**What everything mean here ?**
	- the repo forall will execute for all repos.
	- the -v is verbose, so it will print the output of the command
	- the -c "COMMAND TO EXECUTE" is the actual command you want
```sh
repo sync -c -j4 --no-tags
```
## <a id="4"></a> 4 turbox sdkmanager 
**Environment Setup:**
- sudo apt-get update
- sudo apt-get install ca-certificates curl gnupg lsb-release
- sudo mkdir -p /etc/apt/keyrings
- curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
- echo "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
- sudo apt-get update
- sudo apt-get install docker-ce docker-ce-cli containerd.io docker-compose-plugin
**Install and Run sdkmanager:**
- sudo apt-get install wget
- sudo wget https://sdkgit.thundercomm.com/api/v4/projects/4649/repository/files/turbox-sdkmanager-setup.sh/raw?ref=main -O /usr/bin/turbox-sdkmanager-setup.sh
- sudo chmod +x /usr/bin/turbox-sdkmanager-setup.sh

**Open turbox sdkmanager:**
```sh
turbox-sdkmanager-setup.sh --os-version 18.04
```
- Refer: https://docs.thundercomm.com/turbox_doc/tools/turbox-sdkmanager-user-guide

## <a id="5"></a> 5. Connect USB devices under Windows Subsystem for Linux 
Connect USB devices under Windows Subsystem for Linux
- If the installed kernel version is older than 5.10.60.1, then it can be updated using the following commands:
	- wsl --shutdown
	- wsl --update
- In addition to the release page on GitHub, you can install and update the app using Windows Package Manager CLI (aka winget).
	- winget install --interactive --exact dorssel.usbipd-win

- Install the user space tools for USB/IP and a database of USB hardware identifiers. If you're running Ubuntu on WSL, execute the following commands:
	- sudo apt install linux-tools-virtual hwdata
	- sudo update-alternatives --install /usr/local/bin/usbip usbip `ls /usr/lib/linux-too
- Open a new Terminal instance as Administrator and type the following command to list all the USB devices connected to Windows.
	- usbipd list
	- usbipd bind --busid <busid>
	- usbipd attach --wsl --busid <busid>
Refer: https://www.xda-developers.com/wsl-connect-usb-devices-windows-11/
       https://learn.microsoft.com/en-us/windows/wsl/connect-usb#attach-a-usb-device
       
## <a id="6"></a> 6. Build image
```sh
    - sudo apt-get install uuid-dev
    Build debug version: 
    ./turbox_build.sh -a -l -v debug
    Build perf version:
    ./turbox_build.sh -a -l -v perf
```

## <a id="7"></a> 7. Minicom
```sh
    - sudo apt-get install minicom
    - ls -lR /dev/serial
    - sudo minicom -s
```
=> Go to Serial port setup and press A. Change the serial device to the port that the FTDI is connected to 
(for example: /dev/ttyUSB1). Press Enter after typing the serial port name, and type F to set the Hardware Flow Control to No. 
Ensure that the baud rate in E is 115200.
Moniter: 
```sh
    - sudo minicom
```
- Press Ctrl A + Z
- Press Shift + L for start recording
- Waiting for writing output
- Press Shift + L for stop recording
- Check file minicom.cap – it’s a text file and you can open using any text editor

## <a id="8"></a> 8. CM2290
### <a id="8-1"></a> 8.1 SIM card slot
**Commands**
```sh
adb root
adb shell
netmgrd & ifconfig rmnet_data0 up
dsi_netctrl_test
```

**Note**
- If the IP address cannot be obtained, the partition data related to the modem needs to be
erased. You can enter the following commands to erase the relevant partition data
```sh
adb root
adb reboot bootloader
fastboot erase fsc
fastboot erase modemst1
fastboot erase modemst2
fastboot reboot
```

**Add apn:**
```sh
echo -e "at+cgdcont=1,\"IPV4V6\",\"icu\",\"0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0\",0,0,0,1\r\n" >dev/smd7
```
**Check SIM is OK ?**
```sh
echo -e "AT+CPIN?\r\n" > /dev/smd7
```
```sh
echo -e "AT+CFUN?\r\n" > /dev/smd7
```
```sh
echo -e "AT+CFUN=0\r\n" > /dev/smd7
```
```sh
echo -e "AT+CFUN=1\r\n" > /dev/smd7
```
```sh
echo -e "AT+COPS?\r\n" > /dev/smd7
```
### <a id="8-2"></a> 8.2 HDMI Component
```sh
adb root
```
```sh
adb reboot bootloader
```
```sh
fastboot oem select-display-panel truly_ext_hd_plus_vid
```
```sh
fastboot reboot
```
