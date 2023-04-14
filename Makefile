# rm: remove file
clean:
	rm breadboard

compile:
	gcc main.c board.c -o breadboard -Wall

run: compile
	./breadboard