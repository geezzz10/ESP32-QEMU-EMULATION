# ESP32 QEMU Emulation Project

A complete ESP32 emulation environment using QEMU.

## Project Overview
- **LED Blink Demo**: GPIO toggling with console status messages
- **Temperature Sensor Demo**: Simulated temperature readings 
- **Full QEMU Setup**: Custom compiled ESP32 emulator

## Start- 
# Build and run temperature sensor
cd my_temperature
idf.py build
idf.py qemu

##project structure

esp32_emu_workspace/
├── report.md          # Complete documentation
├── my_temperature/    # ESP32 projects
├── qemu/             # Custom QEMU build
└── screenshots/      # Demo proofs

 *See report.md for full setup instructions and challenges*
