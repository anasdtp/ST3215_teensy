# ST3215 Servo with Teensy 4.1

This PlatformIO project serves as a base to use the ST3215 Servo with the Teensy 4.1 microcontroller. The project is fully functional and provides a starting point for further development.

## Requirements

- PlatformIO
- Teensy 4.1
- ST3215 Servo
- Extern alimentation

## Installation

1. Clone this repository:
    ```sh
    git clone https://github.com/anasdtp/ST3215_teensy
    ```
2. Open the project with PlatformIO.

## Usage

1. Connect the ST3215 Servo to the Teensy 4.1 according to :
        Teensy 4.1                     ST3215
        ------------                   ------
        Pin 1  (TX1) ---->[1 kΩ]------> DATA
        Pin 0 (RX1) <------------------ DATA
        GND --------------------------- GND
                                        Vcc <------------------------- 7V à 12V externe
2. Build and upload the project to the Teensy 4.1 using PlatformIO.
3. The servo should now be operational.

## Contributing

Feel free to submit issues or pull requests if you find any bugs or have suggestions for improvements.

