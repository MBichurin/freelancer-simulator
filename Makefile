SDL_DEVELOPMENT_INC := ./resource/Frameworks/SDL2.framework/Headers
SDL_DEVELOPMENT_DIR := ./resource/Frameworks

SDL_IMAGE_INC := ./resource/Frameworks/SDL2_image.framework/Headers
SDL_IMAGE_DIR := ./resource/Frameworks

OBJ := endgame

SRC_FILES := src/main.c src/mx_draw.c src/mx_events1.c src/mx_events2.c src/mx_load.c src/audio.c

CFLAGS = -Wall -Werror -Wextra -Wpedantic -pedantic -Wshadow -Wstrict-aliasing -Wstrict-overflow -g0
INCLUDE := -I$(SDL_IMAGE_INC) -I$(SDL_DEVELOPMENT_INC) -Iinc/

LIBRARY_IMAGE := -Wl,-rpath,@executable_path/$(SDL_IMAGE_DIR) -F$(SDL_IMAGE_DIR) -framework SDL2_image

all: install clean

install: 
	clang -g0 -std=c11 -O2 $(SRC_FILES) $(INCLUDE) -o $(OBJ) -Wl,-rpath,@executable_path/$(SDL_DEVELOPMENT_DIR) -F$(SDL_DEVELOPMENT_DIR) -framework SDL2 $(LIBRARY_IMAGE)

uninstall: clean
	rm -rf $(OBJ)
clean:
	rm -rf inc/.DS_Store
	rm -rf src/.DS_Store
	rm -rf resource/.DS_Store
	rm -rf resource/Frameworks/.DS_Store
	rm -rf resource/img/.DS_Store
	rm -rf resource/sounds/.DS_Store
reinstall: uninstall install
