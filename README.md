# CHIP-8 Emulator

A complete CHIP-8 emulator implementation written in C++ with SDL2 and OpenGL rendering.

![Demo](./example.gif)

## About CHIP-8

CHIP-8 is an interpreted programming language developed in the 1970s for early microcomputers. It was designed to make game programming easier by providing a simple virtual machine with 35 opcodes. This emulator accurately replicates the CHIP-8 system, allowing you to run classic CHIP-8 programs and games.

## Features

- Full implementation of all 35 CHIP-8 opcodes
- 64x32 monochrome display with configurable scaling
- 16-key hexadecimal keypad input
- Configurable CPU cycle delay for game speed control
- SDL2-based graphics rendering
- Cross-platform support

## Dependencies

- CMake 3.14 or higher
- C++17 compatible compiler
- SDL2
- GLUT (OpenGL Utility Toolkit)
- ImGui (included in external/)

### Installing Dependencies

**macOS:**
```bash
brew install sdl2 cmake
```

**Ubuntu/Debian:**
```bash
sudo apt-get install libsdl2-dev cmake freeglut3-dev
```

**Fedora:**
```bash
sudo dnf install SDL2-devel cmake freeglut-devel
```

## Building

```bash
mkdir build
cd build
cmake ..
make
```

This will create an executable named `main` in the build directory.

## Usage

```bash
./main <scale> <delay> <rom>
```

**Arguments:**
- `scale`: Video scale factor (e.g., 10 for 640x320 window)
- `delay`: CPU cycle delay in milliseconds (lower = faster, typical: 1-5)
- `rom`: Path to CHIP-8 ROM file

**Example:**
```bash
./main 10 2 ../chip8-test-rom.ch8
```

## Keyboard Controls

The CHIP-8 keypad is mapped to your keyboard as follows:

```
CHIP-8 Keypad       Keyboard Layout
┌───┬───┬───┬───┐   ┌───┬───┬───┬───┐
│ 1 │ 2 │ 3 │ C │   │ 1 │ 2 │ 3 │ 4 │
├───┼───┼───┼───┤   ├───┼───┼───┼───┤
│ 4 │ 5 │ 6 │ D │   │ Q │ W │ E │ R │
├───┼───┼───┼───┤   ├───┼───┼───┼───┤
│ 7 │ 8 │ 9 │ E │   │ A │ S │ D │ F │
├───┼───┼───┼───┤   ├───┼───┼───┼───┤
│ A │ 0 │ B │ F │   │ Z │ X │ C │ V │
└───┴───┴───┴───┘   └───┴───┴───┴───┘
```

Press `ESC` to quit the emulator.

## Project Structure

```
chip-8/
├── includes/
│   ├── chip8.h          # CHIP-8 CPU and memory definitions
│   └── platform.h       # SDL2 platform layer
├── src/
│   ├── chip8.cpp        # CHIP-8 emulator core implementation
│   └── platform.cpp     # Platform-specific rendering and input
├── external/
│   └── imgui/           # ImGui library files
├── main.cpp             # Entry point and main loop
├── CMakeLists.txt       # Build configuration
├── chip8-test-rom.ch8   # Test ROM
└── README.md
```

## Technical Details

- **Memory**: 4KB RAM (4096 bytes)
- **Display**: 64x32 pixels, monochrome
- **Registers**: 16 8-bit general-purpose registers (V0-VF)
- **Stack**: 16 levels for subroutine calls
- **Timers**: 60Hz delay and sound timers
- **Instruction Set**: 35 opcodes with table-based dispatch

## Resources

- [CHIP-8 Test ROM](chip8-test-rom.ch8) - Included test ROM for verification
- [More CHIP-8 Games](https://github.com/dmatlack/chip8/tree/master/roms/games)
- [CHIP-8 Technical Reference](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM)

## License

This project is open source and available for educational purposes.
