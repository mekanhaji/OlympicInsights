#include "file_db.h"

void saveToFile(const struct Country countries[], int count) {
    FILE* file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%d,%d,%d,%d,%d,%d\n",
            countries[i].name,
            countries[i].gold,
            countries[i].silver,
            countries[i].bronze,
            countries[i].total,
            countries[i].points,
            countries[i].rank);
    }

    fclose(file);
}

int loadFromFile(struct Country countries[]) {
    FILE* file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%49[^,],%d,%d,%d,%d,%d,%d\n",
        countries[count].name,
        &countries[count].gold,
        &countries[count].silver,
        &countries[count].bronze,
        &countries[count].total,
        &countries[count].points,
        &countries[count].rank) == 7) {
        count++;
        if (count >= MAX_COUNTRIES) {
            printf("Maximum number of countries reached while loading from file.\n");
            break;
        }
    }

    fclose(file);
    return count;
}