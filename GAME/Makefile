cc = gcc
as = nasm
asfl = -f elf32
cflags = -m32 -masm=intel -ffreestanding -fno-stack-protector -fno-pic -fno-pie \
         -mno-sse -mno-sse2 -mno-mmx \
          -fno-builtin \
         -Wall -Wextra -O0
ld = ld

srcs_c = $(wildcard *.c)
srcs_gr = $(wildcard Gr/*.c)
srcs_asm = $(wildcard ASM/*.asm)

objs_c = $(srcs_c:%.c=%.o)
objs_asm = $(srcs_asm:ASM/%.asm=%.o)
objs_gr = $(srcs_gr:Gr/%.c=%.o)

boot = Boot.bin
boot_bin = Boot.bin
krnl = kernel.bin

%.o: %.c
	$(cc) $(cflags) -c $< -o $@
%.o: Gr/%.c
	$(cc) $(cflags) -c $< -o $@

%.o: ASM/%.asm
	$(as) $(asfl)  $< -o $@
	
$(krnl): $(objs_c) $(objs_gr) $(objs_asm)
	$(ld) -m elf_i386 -T linker.ld --oformat binary -o $(krnl) KMain.o $(filter-out KMain.o, $(objs_c) $(objs_gr) $(objs_asm)) -nostdlib

disk: $(boot) $(krnl)
	dd if=$(boot) of=game.img conv=notrunc
	dd if=$(krnl) of=game.img seek=1 conv=notrunc #CL = 2
boot:
	nasm -f bin Boot.asm -o Boot.bin
qemu:
	qemu-system-x86_64 -cpu IvyBridge -drive format=raw,file=game.img,index=0,media=disk -audiodev pa,id=speaker \
	-machine pcspk-audiodev=speaker
qemu_dbg:
	qemu-system-x86_64 -cpu IvyBridge -drive format=raw,file=game.img,index=0,media=disk -audiodev pa,id=speaker \
	-machine pcspk-audiodev=speaker -d int
clean:
	rm -f *.o
