# ST3215 Servo with Teensy 4.1

This PlatformIO project serves as a base to use the ST3215 Servo with the Teensy 4.1 microcontroller. The project is fully functional and provides a starting point for further development.

## Requirements

- PlatformIO
- Teensy 4.1
- ST3215 Servo
- Extern alimentation

## Installation

1. Clone this repository:
    ```console
    git clone https://github.com/anasdtp/ST3215_teensy
    ```
2. Open the project with PlatformIO.

## Usage

1. Connect the ST3215 Servo to the Teensy 4.1 according to :
```console
Teensy 4.1                     ST3215
------------                   ------
Pin 1  (TX1) ---->[1 kΩ]------> DATA<->|
Pin 0 (RX1) <------------------ DATA<->|
GND --------------------------- GND
                                Vcc <------------------------- 7V à 12V externe
```
2. Build and upload the project to the Teensy 4.1 using PlatformIO.
3. The servo should now be operational.

## Contributing

Feel free to submit issues or pull requests if you find any bugs or have suggestions for improvements.


## P.S : If you can't upload the project to the Teensy 4.1

If you can't upload the project to the Teensy 4.1, you should have an error like :
```console
Opening Teensy Loader...
Teensy did not respond to a USB-based request to enter program mode.
Please press the PROGRAM MODE BUTTON on your Teensy to upload your sketch.
*** [upload] Error 1
=========================================== [FAILED] Took 7.77 seconds ===========================================

*  The terminal process "platformio 'run', '--target', 'upload', '--environment', 'teensy41'" terminated with exit code: 1. 
*  Terminal will be reused by tasks, press any key to close it.
```
Or maybe something like :
```console
Building .pio/build/teensy41/firmware.hex
Configuring upload protocol...
AVAILABLE: jlink, teensy-cli, teensy-gui
CURRENT: upload_protocol = teensy-cli
Rebooting...
Uploading .pio/build/teensy41/firmware.hex
Teensy Loader, Command Line, Version 2.2
Read ".pio/build/teensy41/firmware.hex": 27648 bytes, 1.4% usage
Found device but unable to open
Error opening USB device: Resource temporarily unavailable
Waiting for Teensy device...
(hint: press the reset button)
Found device but unable to open
```

## What you must do to be able to upload the project to the Teensy 4.1

1. Download the Linux udev rules (from https://www.pjrc.com/teensy/td_download.html)
```console
wget https://www.pjrc.com/teensy/00-teensy.rules
sudo mv 00-teensy.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules
sudo udevadm trigger
```

2. To allow platformIO to have access to the COM Ports without admin right so you must do this :

```console
sudo usermod -aG dialout $USER
```

3. Reboot your pc
