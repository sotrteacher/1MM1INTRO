EXE:=testmcd1.exe
EJECUTABLE:=ejecutable.exe
OBJETOS:=mcd.o main.o otro.o
CC=gcc
LDFLAGS+=-lm

all:$(EXE) $(EJECUTABLE)
$(EXE):$(OBJETOS)
	$(CC) $(LDFLAGS) $(OBJETOS) -o $@

$(EJECUTABLE):main.o file.o
	$(CC) main.o file.o -o $@

clean:
	rm -v $(OBJETOS) $(EXE)

