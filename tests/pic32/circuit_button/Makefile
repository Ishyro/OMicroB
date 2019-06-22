include ../../../etc/Makefile.conf

SOURCES := test.ml
TARGETS := test.byte test.c test.elf test.pic32_elf test.hex

all: $(TARGETS)

$(TARGETS): $(SOURCES)
	$(BIN)/omicrob -v -flash -device fubarino-mini -circuitppx $^ -mlopt -verbose -stack-size 200 -heap-size 200

clean:
	@rm -f *.cmo *.cmi
	@rm -f sketch.ld.*
	@rm -f $(TARGETS)

.PHONY: all clean
