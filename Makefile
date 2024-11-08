
all:
	g++ -o pantallote pantallote.cpp -lsfml-graphics -lsfml-window -lsfml-system

clean:
	@rm -rf pantallote
