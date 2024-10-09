#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "medal_analysis.h"

#define MAX_COUNTRIES 2  // Increased maximum number of countries
#define MAX_NAME_LENGTH 50 // Maximum length for country names

// struct Country {
//     char name[MAX_NAME_LENGTH];
//     int gold;
//     int silver;
//     int bronze;
//     int total;
//     int rank;
//     int points;
// };

int calculateTotal(const struct Country* country) {
    return country->gold + country->silver + country->bronze;
}

int calculatePoints(const struct Country* country) {
    return country->gold * 3 + country->silver * 2 + country->bronze;
}

void printCountry(const struct Country countries[], int count) {
    printf("\n%-20s%-10s%-10s%-10s%-15s%-10s%-10s\n", "Country", "Gold", "Silver", "Bronze", "Total Medals", "Points", "Rank");
    printf("----------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s%-10d%-10d%-10d%-15d%-10d%-10d\n",
            countries[i].name,
            countries[i].gold,
            countries[i].silver,
            countries[i].bronze,
            countries[i].total,
            countries[i].points,
            countries[i].rank);
    }
}

void getCountry(struct Country* country) {
    printf("Enter country name: ");
    scanf("%49s", country->name);  // Limit input to 49 characters
    printf("Enter number of gold medals: ");
    scanf("%d", &country->gold);
    printf("Enter number of silver medals: ");
    scanf("%d", &country->silver);
    printf("Enter number of bronze medals: ");
    scanf("%d", &country->bronze);

    country->total = calculateTotal(country);
    country->points = calculatePoints(country);
}

int compareCountries(const void* a, const void* b) {
    const struct Country* countryA = (const struct Country*)a;
    const struct Country* countryB = (const struct Country*)b;

    if (countryB->points != countryA->points)
        return countryB->points - countryA->points;

    // If points are equal, sort by gold medals
    if (countryB->gold != countryA->gold)
        return countryB->gold - countryA->gold;

    // If gold medals are equal, sort by silver medals
    if (countryB->silver != countryA->silver)
        return countryB->silver - countryA->silver;

    // If silver medals are equal, sort by bronze medals
    return countryB->bronze - countryA->bronze;
}

void assignRanks(struct Country countries[], int count) {
    for (int i = 0; i < count; i++) {
        if (i > 0 && countries[i].points == countries[i - 1].points &&
            countries[i].gold == countries[i - 1].gold &&
            countries[i].silver == countries[i - 1].silver &&
            countries[i].bronze == countries[i - 1].bronze) {
            countries[i].rank = countries[i - 1].rank;
        }
        else {
            countries[i].rank = i + 1;
        }
    }
}


int main() {
    struct Country countries[MAX_COUNTRIES];
    int count = 0;
    char choice;

    do {
        if (count >= MAX_COUNTRIES) {
            printf("Maximum number of countries reached.\n");
            break;
        }

        getCountry(&countries[count]);
        count++;

        printf("Do you want to add another country? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    qsort(countries, count, sizeof(struct Country), compareCountries);
    assignRanks(countries, count);

    printf("\nMedal Table (Sorted by Points, then Gold, Silver, and Bronze):\n");
    printCountry(countries, count);

    // Call the new analysis function
    analyzeResults(countries, count);

    return 0;
}