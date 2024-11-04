main: main.c ./lib/medal_analysis.c ./lib/medal_analysis.h ./lib/file_db.h
	mkdir -p build
	gcc -Wall -Wextra -Werror -o build/main main.c ./lib/medal_analysis.c ./lib/file_db.c  

run: main
	./build/main

clean:
	rm -f *.exe *.o build/*