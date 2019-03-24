set -e    # if error, stop the build
cc -g -std=c99 -c -I /opt/raylib/src src/main.c -o main.o
cc -o JAAC  main.o -s -Wall -std=c99 -I/opt/raylib/src -L/opt/raylib/release/libs/linux -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./JAAC
