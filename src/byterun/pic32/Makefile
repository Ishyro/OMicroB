CC = ~/.arduino15/packages/chipKIT/tools/pic32-tools/1.43-pic32gcc/bin/pic32-gcc
CHEX = ~/.arduino15/packages/chipKIT/tools/pic32-tools/1.43-pic32gcc/bin/pic32-bin2hex
CFLASH = ~/.arduino15/packages/chipKIT/tools/pic32prog/v2.1.46/pic32prog

CORE = cores/core_no_main.a
#-Wl,--save-gld=sketch.ld,-Map=ld/sketch.map,--gc-sections utile pour la place, divise par 2 environ
ELFFLAGS = -w -Os -Wl,--save-gld=sketch.ld,-Map=ld/sketch.map,--gc-sections -mdebugger -mno-peripheral-libs -nostartfiles -mprocessor=32MX250F128D #/home/ishyro/.arduino15/packages/chipKIT/hardware/pic32/2.0.6/cores/pic32/cpp-startup.S
ELFLINKS = -lm -T ld/chipKIT-application-32MX250F128.ld -T ld/chipKIT-application-COMMON.ld

MIPSFLAGS = -c -g1 -O2 -Wa,--gdwarf-2 -mprocessor=32MX250F128D -DF_CPU=48000000L -DARDUINO=10808 -D_BOARD_FUBARINO_MINI_ -DMPIDEVER=16777998 -DMPIDE=150 -DIDE=Arduino -G1024 -D__USB_ENABLED__ -D__USB_CDCACM__ -D__SERIAL_IS_USB__
DATAFLAGS = -c -g -O2 -w -std=gnu++11 -DARDUINO_ARCH_PIC32 -mno-smart-io -ffunction-sections -fdata-sections -mdebugger -Wcast-align -fno-short-double -ftoplevel-reorder -fno-exceptions -mprocessor=32MX250F128D -DF_CPU=48000000L -DARDUINO=10808 -D_BOARD_FUBARINO_MINI_ -DMPIDEVER=16777998 -DMPIDE=150 -DIDE=Arduino -G1024 -D__USB_ENABLED__ -D__USB_CDCACM__ -D__SERIAL_IS_USB__
#-MMD
SOURCE = test.c
SMIPS = $(wildcard *.S)
#SMIPS = cpp-startup.S
TMIPS = $(patsubst %.S,%.o,$(SMIPS))
TELF = $(patsubst %.c,%.elf,$(SOURCE))
THEX = $(patsubst %.c,%.hex,$(SOURCE))

all: $(TELF) $(THEX) flash

%.o: %.c
	$(CC) $(DATAFLAGS) $(ELFSOURCE) $^ -o $@

#%.o: %.S
#	$(CC) -o $@ $< $(MIPSFLAGS) $(ELFSOURCE) -L./cores

%.elf: %.c $(SMIPS) $(CORE)
	$(CC) $(ELFFLAGS) -o $@ $^ -L./cores $(ELFLINKS)

%.hex: %.elf
	$(CHEX) -a $<

flash: $(THEX)
	$(CFLASH) -d /dev/ttyACM0 -b 115200 $<

clean:
	rm -f Board_Data.o exceptions.o test.o $(TMIPS) $(TELF) $(THEX)
	rm -f sketch.ld.* Board_Data.d exceptions.d test.d
