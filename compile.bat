@echo off
g++ -I ./dependencies/include/SDL2 -L ./dependencies/lib -I ./src src/*.cpp ./src/application/*.cpp ./src/imgui/*.cpp -o ./debug/run -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer
pause
exit