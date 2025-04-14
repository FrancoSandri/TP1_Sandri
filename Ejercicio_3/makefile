# Compilador y banderas
CXX = g++
CXXFLAGS = -std=c++14 -Wall -I../Ejercicio_1/headers -I../Ejercicio_2
LDFLAGS =

# Directorios
E1_SRC_DIR = ../Ejercicio_1/src
E1_PERSONAJES_DIR = $(E1_SRC_DIR)/personajes
E1_ARMAS_DIR = $(E1_SRC_DIR)/armas
E2_SRC_DIR = ../Ejercicio_2
OBJ_DIR = obj
BIN_DIR = .

# Archivos fuente
E3_SRC = main.cpp ejercicio3.cpp
E2_SRC = $(E2_SRC_DIR)/ejercicio2.cpp
E1_PERSONAJES_SRC = $(wildcard $(E1_PERSONAJES_DIR)/*.cpp)
E1_ARMAS_SRC = $(wildcard $(E1_ARMAS_DIR)/*.cpp)
SOURCES = $(E3_SRC) $(E2_SRC) $(E1_PERSONAJES_SRC) $(E1_ARMAS_SRC)

# Archivos objeto
OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(E3_SRC)) \
          $(patsubst $(E2_SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(E2_SRC)) \
          $(patsubst $(E1_SRC_DIR)/personajes/%.cpp, $(OBJ_DIR)/personajes/%.o, $(E1_PERSONAJES_SRC)) \
          $(patsubst $(E1_SRC_DIR)/armas/%.cpp, $(OBJ_DIR)/armas/%.o, $(E1_ARMAS_SRC))

# Ejecutable
EXEC = $(BIN_DIR)/programa

# Regla principal
all: $(EXEC)

# Vinculación
$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# Compilación de archivos en Ejercicio_3
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilación de archivos en Ejercicio_2
$(OBJ_DIR)/%.o: $(E2_SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilación de archivos en Ejercicio_1/src/personajes
$(OBJ_DIR)/personajes/%.o: $(E1_PERSONAJES_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)/personajes
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilación de archivos en Ejercicio_1/src/armas
$(OBJ_DIR)/armas/%.o: $(E1_ARMAS_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)/armas
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

# Limpiar y recompilar
rebuild: clean all

# Phony targets
.PHONY: all clean rebuild