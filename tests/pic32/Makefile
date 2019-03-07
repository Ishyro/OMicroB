include ../../etc/Makefile.conf

SOURCES := led.ml
TARGETS := led.byte led.c led.elf led.pic32_elf led.hex

all: $(TARGETS)

$(TARGETS): $(SOURCES)
	$(BIN)/omicrob -v -device fubarino-mini $^ -mlopt -verbose -stack-size 200 -heap-size 200

flash: led.hex
	$(BIN)/omicrob -flash -device fubarino-mini $<

clean:
	@rm -f *.cmo *.cmi
	@rm -f sketch.ld.*
	@rm -f $(TARGETS)

.PHONY: all flash clean
