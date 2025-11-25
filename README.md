# ESP32 QEMU Emulation Project

A complete ESP32 emulation environment using QEMU, developed for the FOSSEE Winter Internship screening task. This project demonstrates full ESP32 virtualization without physical hardware and lays the foundation for automated code evaluation systems.

## Project Overview
- **LED Blink Demo**: GPIO toggling with console status messages
- **Temperature Sensor Demo**: Simulated temperature readings 
- **Full QEMU Setup**: Custom compiled ESP32 emulator
- 
## 📋 Project Demos
### 1. LED Blink Program
- Emulates GPIO pin toggling using ESP32's GPIO subsystem
- Prints "LED ON" / "LED OFF" status messages to console with 1-second intervals
- Demonstrates basic embedded systems programming and hardware simulation

### 2. Temperature Sensor Program  
- Simulates temperature readings between 20.0°C and 30.0°C with 0.1°C increments
- Prints periodic temperature updates every 2 seconds using FreeRTOS task delays
- Shows sensor data processing, console I/O, and real-time system capabilities

## Technical Implementation

- **QEMU Version**: Espressif fork (custom compiled with ESP32 support)
- **ESP-IDF Version**: v5.1.2
- **Target Architecture**: Xtensa ESP32
- **Build System**: ESP-IDF + CMake + Ninja
- **Development Platform**: Ubuntu 22.04 (WSL2)
- **Emulation Method**: Full-system virtualization with SPI flash simulatio

  ## Project Structure 

| Directory   | Description |
|---------------|-------------|
| `report.md` | Complete project documentation & technical report |
| `README.md` | Project overview and setup guide |
| `my_temperature/` | Main ESP32 project with both demos |
| `my_temperature/main/hello_world_main.c` | LED Blink & Temperature sensor code |
| `my_temperature/build/` | Compiled binaries and flash images |
| `qemu/` | Custom compiled QEMU with ESP32 support |
| `screenshots/` | Demonstration proofs |
| `screenshot_blink.png` | LED Blink program running |
| `screenshot_temp.png` | Temperature sensor running |

### Prerequisites
```bash
# Essential dependencies
sudo apt update && sudo apt install -y git wget flex bison gperf python3 \
  python3-pip python3-venv cmake ninja-build ccache libffi-dev libssl-dev \
  dfu-util libusb-1.0-0 build-essential

# QEMU specific dependencies
sudo apt install -y libgcrypt20-dev libslirp-dev libglib2.0-dev libpixman-1-dev
# Setup ESP-IDF environment
cd esp-idf
. ./export.sh
cd ../my_temperature

# Build the project
idf.py build

# Critical: Create proper flash image
esptool.py --chip esp32 merge_bin -o build/flash_image.bin \
  --flash_mode dio --flash_freq 40m --flash_size 4MB \
  0x1000 build/bootloader/bootloader.bin \
  0x8000 build/partition_table/partition-table.bin \
  0x10000 build/hello_world.bin --fill-flash-size 4MB

# Execute in QEMU emulator
qemu-system-xtensa -nographic -machine esp32 \
  -serial mon:stdio -drive file=build/flash_image.bin,if=mtd,format=raw
```
# Technical Challenges & Solutions -

Challenge 1: QEMU ESP32 Cryptographic Module Compilation

Problem: Initial QEMU compilation failed with unknown type 'misc.esp32.rsa' error due to missing cryptographic libraries.

Solution:

· Researched Espressif's build configuration and discovered `libgcrypt20-dev` dependency
· Used --enable-gcrypt flag during QEMU configuration
· Verified crypto module compilation in meson.build files

Challenge 2: Flash Image Creation

Problem: Direct .bin file execution failed; QEMU required proper flash image structure.

Solution:

· Implemented esptool.py merge_bin approach with proper partition layout
· Created 4MB flash images with bootloader at 0x1000, partition table at 0x8000, and application at 0x10000
· Used --fill-flash-size parameter for correct image sizing

Challenge 3: Dependency Management

Problem: Multiple compilation failures due to incomplete dependency chain.

Solution:

· Systematic installation of 20+ development packages
· Comprehensive dependency resolution for successful QEMU compilation

Challenge 4: WSL2 Environment

Problem: Ubuntu 22.04 on WSL2 had library version constraints and resource limitations.

Solution:

· Adapted build process for WSL2 constraints
· Used conservative compilation parameters
· Verified architecture-specific dependencies

## Results

Both demos successfully execute in the QEMU emulator with:

· LED Blink: Consistent "LED ON/OFF" console output at 1-second intervals
· Temperature Sensor: Stable temperature readings incrementing from 20.0°C to 30.0°C
· Boot Process: Complete ESP32 boot sequence with partition table loading
· System Stability: Continuous operation without crashes or memory issues

# Demonstration
· Screenshots Available: screenshot_blink.png and screenshot_temp.png show both programs running successfully
· Complete Project Archive: esp32_qemu_project.zip contains all source code, documentation, and build files
· Live Demonstration: Project can be reproduced using the provided setup instructions

Yaksh Integration
This ESP32 QEMU emulation setup provides the complete technical foundation for integrating embedded systems evaluation into the Yaksh platform:

Hardware-Free Assessment: No physical ESP32 devices required

Safe Execution: QEMU provides complete isolation from host system

Scalable Evaluation: Multiple QEMU instances run concurrently

Cost-Effective: Eliminates hardware procurement and maintenance

Real ESP32 Environment: Students learn actual ESP-IDF development

Complete setup instructions, detailed challenge analysis, and implementation methodology available in report.md.

# Now I'm gonna watch big bang theory , but y'all enjoy setting up this environment , BYEEE!

Submitted for: FOSSEE Winter Internship

