EXE:=s2f.exe
PRE:=segundos_a_formato.prep
CC=gcc
all:$(EXE) $(PRE)
$(EXE):segundos_a_formato.c
	$(CC) $^ -o $@
$(PRE):segundos_a_formato.c
	$(CC) -E $^ -o $@
clean:
	rm -v $(EXE) $(PRE)
