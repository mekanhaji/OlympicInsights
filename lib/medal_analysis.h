#ifndef MEDAL_ANALYSIS_H
#define MEDAL_ANALYSIS_H

#include <stdio.h>

#define MAX_CHART_WIDTH 10
#define MAX_COUNTRIES 50  // Increased maximum number of countries
#define MAX_NAME_LENGTH 50 // Maximum length for country names

struct Country {
    char name[50];
    int gold;
    int silver;
    int bronze;
    int total;
    int rank;
    int points;
};

void printHorizontalChart(const char* label, int value, int max_value);
void analyzeResults(struct Country countries[], int count);

#endif