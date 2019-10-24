EXE:=TestPlaneacionBasadaNCalendar.exe
EXE1:=CalendarTestDriver.exe
OBJETOS:=Calendario.o Asignacion.o Dia.o
OBJETOSA:=CalendarioA.o AsignacionA.o DiaA.o
CC=g++
#CXXFLAGS +=-DUSING_ARREGLO
CXXFLAGS +=-DCAL_GREGORIANO
MYCXXFLAGS=-DUSING_ARREGLO
all:$(EXE) $(EXE1)
$(EXE):$(OBJETOS) InVdOpS_AD2019.o 
	$(CC) $(MYCXXFLAGS) $^ -o $@
Calendario.o:../CommonFiles/Calendario.cpp
	$(CC) $(MYCXXFLAGS) -c $^ -o $@
Asignacion.o:../CommonFiles/Asignacion.cpp
	$(CC) $(MYCXXFLAGS) -c $^ -o $@
Dia.o:../CommonFiles/Dia.cpp
	$(CC) $(MYCXXFLAGS) -c $^ -o $@
InVdOpS_AD2019.o:InVdOpS_AD2019.cpp
	$(CC) $(MYCXXFLAGS) -c $^ -o $@
$(EXE1):$(OBJETOSA) test_Calendario.o
	$(CC) $^ -o $@
CalendarioA.o:../CommonFiles/Calendario.cpp
	$(CC)  -c $^ -o $@
AsignacionA.o:../CommonFiles/Asignacion.cpp
	$(CC)  -c $^ -o $@
DiaA.o:../CommonFiles/Dia.cpp
	$(CC)  -c $^ -o $@
#test_Calendario.o:test_Calendario.cpp
#	$(CC)  -c $^ -o $@
clean:
	rm -v *.o *.exe
