main: main.c ./lib/medal_analysis.c ./lib/medal_analysis.h
	mkdir -p build
	gcc -Wall -Wextra -Werror -o build/main main.c ./lib/medal_analysis.c

run: main
	./build/main

clean:
	rm -f *.exe *.o build/*