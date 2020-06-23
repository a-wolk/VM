# Virtual Machine

Virtual Machine with customizable ISA (Intsruction Set Architecture) and registers to some extent, and basic screen.

## Getting Started

Run `make all` to build vm, or `make debug` to build vm with debug symbols and output.

### Prerequisites

- [SDL2](https://www.libsdl.org/download-2.0.php)
- [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/)

## Instructions

Instruction on how to configure vm can be find in INST.md

## Example

In folder /example you can find two files:
- [vm_config](/example/vm_config) (contains example configuration of vm: registers, operations, screen)
- exe (executable file for vm, contains binary data, which encodes opcodes followed by its arguments, which were defined in vm_config)

## Documentation

Folder /docs contains documentation generated by Doxyfile, but also [overview](/docs/overview), where architecture of vm is described.

## Authors

* **Arkadiusz Wołk** - [ArcziPT](https://github.com/ArcziPT)
