main: main.c medal_analysis.c medal_analysis.h
	mkdir -p build
	gcc -Wall -Wextra -Werror -o build/main main.c medal_analysis.c

run: main
	./build/main

clean:
	rm -f *.exe *.o build/*