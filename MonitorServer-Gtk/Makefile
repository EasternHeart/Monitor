GTK_CFLAGS=`pkg-config --cflags gtk+-3.0`
GTK_LIBS=`pkg-config --libs gtk+-3.0`

all: main

main.o: main.c
	$(CXX) $(CXXFLGAS) $(GTK_CFLAGS) -c main.c -o main.o
main: main.o
	$(CXX) $(CXXFLAGS) $(LIBS) $(GTK_LIBS) main.o -o main
