BUILD_PATH='../build'
BOOT_PATH='../bootloader'
KERNEL_PATH='../kernel'

mkdir $BUILD_PATH

nasm -f bin $BOOT_PATH/boot.asm -o $BUILD_PATH/boot.bin

nasm -f elf32 $KERNEL_PATH/kernel.asm -o $BUILD_PATH/kernel_asm.o
i686-elf-gcc -Wno-int-conversion -c $KERNEL_PATH/kernel.c -o $BUILD_PATH/kernel_c.o
i686-elf-ld --oformat=binary -T $KERNEL_PATH/linker.ld $BUILD_PATH/kernel_asm.o $BUILD_PATH/kernel_c.o -o $BUILD_PATH/kernel.bin

dd if=$BUILD_PATH/boot.bin of=$BUILD_PATH/bare_os.img count=1 bs=512 conv=notrunc

dd if=$BUILD_PATH/kernel.bin of=$BUILD_PATH/bare_os.img count=10 bs=512 seek=1 conv=notrunc