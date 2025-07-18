CC=gcc
CFLAGS=-Iapp\h_files

all: app.exe

app.exe: app\app.c app\c_files\engine_control.c
	$(CC) $(CFLAGS) -o app\app.exe app\app.c app\c_files\engine_control.c

clean:
	del /Q app\app.exe 2> nul
