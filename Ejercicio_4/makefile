CXX = g++
CXXFLAGS = -std=c++17 -I../Ejercicio_2/interfaces -I../Ejercicio_3 -I../Ejercicio_2/armas -I../Ejercicio_2/personajes

SRC = main.cpp ../Ejercicio_3/ejercicio3.cpp \
    ../Ejercicio_2/armas/ItemMagico.cpp \
    ../Ejercicio_2/armas/ArmaCombate.cpp \
    ../Ejercicio_2/personajes/Mago.cpp \
    ../Ejercicio_2/personajes/Guerrero.cpp

OBJ = $(SRC:.cpp=.o)
BIN = pelea

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(BIN)

clean:
	rm -f $(OBJ) $(BIN)