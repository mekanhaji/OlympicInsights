#ifndef FILE_DB_H
#define FILE_DB_H

#include "medal_analysis.h"
#define FILE_NAME "countries.csv"

void saveToFile(const struct Country countries[], int count);
int loadFromFile(struct Country countries[]);

#endif // FILE_DB_H