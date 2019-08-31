EXE:=testmcd1.exe
EJECUTABLE:=ejecutable.exe
OBJETOS:=mcd.o main.o otro.o
FUENTES:=mcd.c main.c otro.c
CC=gcc
#CFLAGS+=-std=c++14
LDFLAGS+=-lm

#all:$(EXE) $(EJECUTABLE)
all:$(EXE) 
$(EXE):$(OBJETOS)
	$(CC) $(LDFLAGS) $(OBJETOS) -o $@
$(OBJETOS):$(FUENTES)
	$(CC) -DPRELIMINAR -c $^

$(EJECUTABLE):main.o file.o
	$(CC) main.o file.o -o $@
por_valor_y_por_referencia.exe:porvalor_porreferencia.c
	$(CC) $< -o $@
clean:
	rm -v $(OBJETOS) $(EXE) $(EJECUTABLE) file.o

