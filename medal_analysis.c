#include "medal_analysis.h"

void printHorizontalChart(const char* label, int value, int max_value) {
    printf("%-20s ", label);
    int chart_width = (value * MAX_CHART_WIDTH) / max_value;
    for (int i = 0; i < chart_width; i++) {
        printf("%s", "|");
    }
    printf(" %d\n", value);
}

void analyzeResults(struct Country countries[], int count) {
    int total_gold = 0, total_silver = 0, total_bronze = 0;
    int max_gold = 0, max_silver = 0, max_bronze = 0, max_total = 0, max_points = 0;
    struct Country* top_gold = NULL, * top_silver = NULL, * top_bronze = NULL, * top_total = NULL, * top_points = NULL;

    for (int i = 0; i < count; i++) {
        total_gold += countries[i].gold;
        total_silver += countries[i].silver;
        total_bronze += countries[i].bronze;

        if (countries[i].gold > max_gold) {
            max_gold = countries[i].gold;
            top_gold = &countries[i];
        }
        if (countries[i].silver > max_silver) {
            max_silver = countries[i].silver;
            top_silver = &countries[i];
        }
        if (countries[i].bronze > max_bronze) {
            max_bronze = countries[i].bronze;
            top_bronze = &countries[i];
        }
        if (countries[i].total > max_total) {
            max_total = countries[i].total;
            top_total = &countries[i];
        }
        if (countries[i].points > max_points) {
            max_points = countries[i].points;
            top_points = &countries[i];
        }
    }

    printf("\n===== Medal Analysis =====\n");
    printf("Total Medals Awarded:\n");
    printHorizontalChart("Gold", total_gold, total_gold + total_silver + total_bronze);
    printHorizontalChart("Silver", total_silver, total_gold + total_silver + total_bronze);
    printHorizontalChart("Bronze", total_bronze, total_gold + total_silver + total_bronze);

    printf("\nTop Performers:\n");
    printf("Most Gold Medals: %s (%d)\n", top_gold->name, top_gold->gold);
    printf("Most Silver Medals: %s (%d)\n", top_silver->name, top_silver->silver);
    printf("Most Bronze Medals: %s (%d)\n", top_bronze->name, top_bronze->bronze);
    printf("Most Total Medals: %s (%d)\n", top_total->name, top_total->total);
    printf("Highest Points: %s (%d)\n", top_points->name, top_points->points);

    printf("\nMedal Distribution (Top 5):\n");
    for (int i = 0; i < 5 && i < count; i++) {
        printf("%s:\n", countries[i].name);
        printHorizontalChart("Gold", countries[i].gold, max_gold);
        printHorizontalChart("Silver", countries[i].silver, max_silver);
        printHorizontalChart("Bronze", countries[i].bronze, max_bronze);
        printf("\n");
    }
}