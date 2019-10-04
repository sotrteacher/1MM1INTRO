EXE:=test_EvalContinua.exe
EXE1:=test_EvalContinua_Intro.exe
OBJETOS:=EvalContinua.o test_EvalContinua.o reactivos_dummy.o reactivos_intro_attrib.o ctors.o
FUENTES1:=EvalContinua.c test_EvalContinua.c reactivos.c reactivos_intro_attrib.c ctors.c
OBJETOS1:=EvalContinua.o test_EvalContinua.o reactivos.o reactivos_intro_attrib.o ctors.o
CC=gcc
CXX=g++
#CFLAGS += -DNUMDREAC=4 -DLONGDREAC=2048
#CXXFLAGS += -DNUMDREAC=3 -DLONGDREAC=2048
all:$(EXE1)
$(EXE):$(OBJETOS)
	$(CC) $^ -o $@
$(EXE1):$(FUENTES1)
	$(CXX) -DNUMDREAC=3 -DLONGDREAC=2048 $^ -o $@
#clean:
#	rm -v $(OBJETOS) $(OBJETOS1) $(EXE) $(EXE1)
clean:
	rm -v $(EXE) $(EXE1)
