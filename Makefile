main: main.c medal_analysis.c medal_analysis.h
	gcc -Wall -Wextra -Werror -o main main.c medal_analysis.c

run: main
	./main

clean:
	rm -f main