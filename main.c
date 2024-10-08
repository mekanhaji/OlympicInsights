#include "stdio.h"
#include "string.h"

#define MAX_COUNTRIES 2  // Maximum number of countries

struct Country {
    char name[50];    // Country name
    int gold;         // Number of gold medals
    int silver;       // Number of silver medals
    int bronze;       // Number of bronze medals
    int total;        // Total medals (gold + silver + bronze)
    int ranks;        // Rank
    int points;       // 3 Points for gold, 2 Points for silver and 1 Points for bronze
};

/* Function to calculate total medals for a country */
int calculateTotal(const struct Country* country) {
    return (country->gold + country->silver + country->bronze);
}

int calculatePoints(const struct Country* country) {
    return (country->gold * 3 + country->silver * 2 + country->bronze);
}

struct Country createCountry(char* name, int gold, int silver, int bronze) {
    struct Country newCountry;

    // Using strncpy to safely copy the name into the struct (limit to 49 chars + null terminator)
    strncpy(newCountry.name, name, sizeof(newCountry.name) - 1);
    newCountry.name[sizeof(newCountry.name) - 1] = '\0'; // Ensures null termination

    newCountry.gold = gold;
    newCountry.silver = silver;
    newCountry.bronze = bronze;

    newCountry.total = calculateTotal(&newCountry);

    return newCountry;
}

/* Function to display country medal details in a tabular format */
void printCountry(const struct Country countries[]) {
    // Print the table header
    printf("\n%-20s%-10s%-10s%-10s%-15s%-10s%-10s\n", "Country", "Gold", "Silver", "Bronze", "Total Medals", "Points", "Rank");
    printf("----------------------------------------------------------------------------------------\n");

    // Print the table body with each country's details
    for (int i = 0; i < MAX_COUNTRIES; i++) {
        printf("%-20s%-10d%-10d%-10d%-15d%-10d%-10d\n",
            countries[i].name,
            countries[i].gold,
            countries[i].silver,
            countries[i].bronze,
            countries[i].total,
            countries[i].points,
            countries[i].ranks);
    }
}

/* Get country from user */
void getCountry(struct Country* country) {
    printf("Enter country name: ");
    scanf("%s", &country->name);

    printf("Enter number of gold won: ");
    scanf("%d", &country->gold);

    printf("Enter number of silver won: ");
    scanf("%d", &country->silver);

    printf("Enter number of bronze won: ");
    scanf("%d", &country->bronze);
}

/* Function to sort countries based on points (descending order) */
void sortCountriesByPoints(struct Country countries[]) {
    for (int i = 0; i < MAX_COUNTRIES - 1; i++) {
        for (int j = 0; j < MAX_COUNTRIES - i - 1; j++) {
            if (countries[j].points < countries[j + 1].points) {
                // Swap countries[j] and countries[j + 1]
                struct Country temp = countries[j];
                countries[j] = countries[j + 1];
                countries[j + 1] = temp;
            }
        }
    }
}

/* Function to assign ranks based on sorted points */
void assignRanks(struct Country countries[]) {
    for (int i = 0; i < MAX_COUNTRIES; i++) {
        countries[i].ranks = i + 1; // Rank starts from 1
    }
}

int main() {
    struct Country countries[MAX_COUNTRIES];

    // Get input for all countries
    for (int i = 0; i < MAX_COUNTRIES; i++) {
        getCountry(&countries[i]);
        countries[i].total = calculateTotal(&countries[i]);
        countries[i].points = calculatePoints(&countries[i]);
    }

    // Sort the countries by points in descending order
    sortCountriesByPoints(countries);

    // Assign ranks based on points
    assignRanks(countries);

    // Display the sorted list with ranks
    printf("\nMedal Table (Sorted by Points):\n");
    printCountry(countries);

    return 0;
}