CFILES=$(wildcard *.c)
obj=$(CFILES:.c=.o)
COMPILER=gcc
COPTIONS=-std=c99 -Wall
OUTPUT=lox
DOPTIONS=-g

lox: ${obj}
	$(COMPILER) $(COPTIONS) $(CFILES) -o $(OUTPUT)

debug:
	$(COMPILER) $(COPTIONS) $(DOPTIONS) $(CFILES) -o $(OUTPUT)

.PHONY: clean
clean:
	rm -f $(obj) $(output) 
