# Compilador y banderas
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Iheaders
LDFLAGS = 

# Directorios
SRC_DIR = src
ARMAS_DIR = $(SRC_DIR)/armas
PERSONAJES_DIR = $(SRC_DIR)/personajes
OBJ_DIR = obj
BIN_DIR = .

# Archivos fuente
ARMAS_SRC = $(wildcard $(ARMAS_DIR)/*.cpp)
PERSONAJES_SRC = $(wildcard $(PERSONAJES_DIR)/*.cpp)
MAIN_SRC = main.cpp
SOURCES = $(ARMAS_SRC) $(PERSONAJES_SRC) $(MAIN_SRC)

# Archivos objeto
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(ARMAS_SRC) $(PERSONAJES_SRC)) \
          $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(MAIN_SRC))

# Ejecutable
EXEC = $(BIN_DIR)/programa

# Regla principal
all: $(EXEC)

# Vinculación
$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# Compilación de main.cpp
$(OBJ_DIR)/main.o: main.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilación de archivos en src/armas/
$(OBJ_DIR)/armas/%.o: $(ARMAS_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)/armas
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilación de archivos en src/personajes/
$(OBJ_DIR)/personajes/%.o: $(PERSONAJES_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)/personajes
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

# Limpiar y recompilar
rebuild: clean all

# Phony targets
.PHONY: all clean rebuild