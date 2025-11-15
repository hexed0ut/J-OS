# 🧵 J-OS - Work in Progress

J-OS is a small experimental operating system built for learning and exploration.
It’s currently incomplete, but it **boots**, **switches to protected mode**, **runs a tiny C kernel**, and even **starts a basic shell**.

## 🚀 Current Capabilities

Right now, J-OS can:

* Boot on bare metal (via **QEMU**)
* Run its own **bootloader**
* Switch from **real mode → protected mode**
* Jump cleanly into the **kernel entry point**
* Execute **C code after assembly** setup
* Print a greeting from the kernel

More features are planned.

---

## 🎯 Project Goals

This project exists to understand low-level systems concepts:

* Bootloaders & BIOS
* x86 segmentation
* Protected mode
* Linking assembly + C
* Basic shell and command handling
* Gradually building up a real OS architecture

It’s not meant to be production-ready — just a fun and educational playground.

---

## 🛠️ Build & Run

Make sure you have **QEMU** installed and **i686-cross-compiler** setup.

⚙️ Build Process (Summary)

The build system creates the operating system in four steps:

1. Assemble the Bootloader

The bootloader is converted into a raw 512-byte binary.
This becomes the first sector of the disk image and is what the CPU executes immediately after power-on.

2. Assemble and Compile the Kernel

The kernel is built in two parts:

An assembly file that handles low-level setup

A C file that contains the main kernel logic

Both pieces are compiled into object files and then linked together into one flat binary image the bootloader can load.

3. Construct the OS Disk Image

A disk image is created by placing the bootloader in the very first sector and placing the kernel directly after it in the following sectors.
Together, these form a minimal bootable operating system image.

4. Run the OS in an Emulator

The final disk image is launched in an x86 emulator (such as QEMU).
This lets you test the OS as if it were running on real hardware.

```bash
nasm -f bin boot.asm -o $BUILD_PATH/boot.bin

nasm -f elf32 kernel.asm -o $BUILD_PATH/kernel_asm.o
i686-elf-gcc -Wno-int-conversion -c kernel.c -o $BUILD_PATH/kernel_c.o
i686-elf-ld --oformat=binary -T linker.ld $BUILD_PATH/kernel_asm.o $BUILD_PATH/kernel_c.o -o $BUILD_PATH/kernel.bin

dd if=$BUILD_PATH/boot.bin of=$BUILD_PATH/bare_os.img count=1 bs=512 conv=notrunc

dd if=$BUILD_PATH/kernel.bin of=$BUILD_PATH/bare_os.img count=10 bs=512 seek=1 conv=notrunc

qemu-system-x86_64 -drive format=raw,file=bare_os.img
```


## 🗺️ Roadmap

Planned next steps:

* [ ] Keyboard input
* [ ] Better shell commands
* [ ] Basic memory management
* [ ] Proper interrupt handling (IDT, PIC/APIC)
* [ ] Paging
* [ ] Simple filesystem
* [ ] More kernel services

---

## ⚠️ Status

This project is **incomplete**, under active development, and may break as things change.
Expect missing features, experimental code, and the occasional intentional hack.

---

## 🤝 Contributing

Feedback, suggestions, and small improvements are welcome.
This project is mostly for fun and learning, so feel free to explore!

---

## 📝 License

MIT License.

---

