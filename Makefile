APP_NAME = OlympicInsight
CC = gcc
CFLAGS = -Wall -Wextra -Werror
BUILD_DIR = build
TARGET = $(BUILD_DIR)/$(APP_NAME)
SRC = main.c ./lib/medal_analysis.c ./lib/file_db.c
HEADERS = ./lib/medal_analysis.h ./lib/file_db.h

main: main.c ./lib/medal_analysis.c ./lib/medal_analysis.h ./lib/file_db.h
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: main
	./$(TARGET)

clean:
	rm -f *.exe *.o $(BUILD_DIR)/*