#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib/medal_analysis.h"
#include "lib/file_db.h"


int calculateTotal(const struct Country* country) {
    return country->gold + country->silver + country->bronze;
}

int calculatePoints(const struct Country* country) {
    return country->gold * 3 + country->silver * 2 + country->bronze;
}

void printCountry(const struct Country countries[], int count) {
    printf(
        "\n%-10s%-20s%-10s%-10s%-10s%-15s%-10s\n",
        "Rank", "Country", "Gold", "Silver", "Bronze", "Total Medals", "Points"
    );
    printf("----------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d%-20s%-10d%-10d%-10d%-15d%-10d\n",
            countries[i].rank,
            countries[i].name,
            countries[i].gold,
            countries[i].silver,
            countries[i].bronze,
            countries[i].total,
            countries[i].points
        );
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

void clrscr() {
    system("@cls||clear");
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

void printMenu(const int count) {
    printf("\n\n===========================================\n");
    printf("|| Welcome to the Medal Analysis Program ||\n");
    printf("===========================================\n\n");
    printf(" Total Countries: %d\n", count);
    printf(" Main Menu\n");
    printf(" 1. Add a country\n");
    printf(" 2. View countries\n");
    printf(" 3. Show Analytics\n");
    printf(" 4. Clear Screen\n");
    printf(" 5. Exit\n");
}

int main() {
    struct Country countries[MAX_COUNTRIES];
    int count = 0;
    char choice;

    // Load data from file
    count = loadFromFile(countries);

    clrscr();
    printMenu(count);

    while (1) {
        printf("\nEnter your choice (1..5) > ");
        choice = getchar();

        if (choice == '1') {
            if (count >= MAX_COUNTRIES) {
                printf("Maximum number of countries reached.\n");
                continue;
            }

            getCountry(&countries[count]);
            count++;

            // Save data to file
            saveToFile(countries, count);
        }
        else if (choice == '2') {
            qsort(countries, count, sizeof(struct Country), compareCountries);
            assignRanks(countries, count);

            printf("\nMedal Table (Sorted by Points, then Gold, Silver, and Bronze):\n");
            printCountry(countries, count);

        }
        else if (choice == '3') {
            analyzeResults(countries, count);
        }
        else if (choice == '4') {
            clrscr();
            printMenu(count);
        }
        else if (choice == '5') {
            break;
        }

        while (getchar() != '\n');  // Clear input buffer
    }


    return 0;
}