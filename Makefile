PROJECTNAME = anysplat
OUTPUT_DIR = build

INCLUDE_DIRS = -I include/SDL2 -I include/imgui
LIB_DIRS = -L lib

LIBS = -l mingw32 -l SDL2main -l SDL2

SRC = $(wildcard src/*.cpp) $(wildcard imgui/*.cpp)

default:
	g++ $(SRC) -o $(OUTPUT_DIR)/$(PROJECTNAME) $(INCLUDE_DIRS) $(LIB_DIRS) $(LIBS)
	