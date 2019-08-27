EXE:=testmcd1.exe
EJECUTABLE:=ejecutable.exe
OBJETOS:=mcd.o main.o otro.o
FUENTES:=mcd.c main.c otro.c
CC=gcc
LDFLAGS+=-lm

all:$(EXE) $(EJECUTABLE)
$(EXE):$(OBJETOS)
	$(CC) $(LDFLAGS) $(OBJETOS) -o $@
$(OBJETOS):$(FUENTES)
	$(CC) -DPRELIMINAR -c $^

$(EJECUTABLE):main.o file.o
	$(CC) main.o file.o -o $@
clean:
	rm -v $(OBJETOS) $(EXE) $(EJECUTABLE) file.o

