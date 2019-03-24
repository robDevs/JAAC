set -e    # if error, stop the build
cc -g -std=c99 -c -I /opt/raylib/src src/main.c -o main.o
cc -g -std=c99 -c -I /opt/raylib/src src/common.c -o common.o
cc -g -std=c99 -c -I /opt/raylib/src src/menu.c -o menu.o
cc -o JAAC  main.o common.o menu.o -s -Wall -std=c99 -I/opt/raylib/src -L/opt/raylib/release/libs/linux -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./JAAC
