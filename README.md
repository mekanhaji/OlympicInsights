# Olympic Medal Analytics

## Project Overview

Olympic Medal Analytics is a C program designed to track and analyze medal counts for various countries in the Olympics. This project allows users to input medal data for multiple countries and provides analysis based on total medals, points, and rankings.

## Features

- Input medal data (gold, silver, bronze) for multiple countries
- Calculate total medals and points for each country
- Rank countries based on their performance
- Provide detailed analysis of medal distribution
- Display top performers in various categories
- Generate simple ASCII-based charts for visual representation

## File Structure

The project consists of the following files:

1. `main.c` - Main program file
2. `lib/medal_analysis.h` - Header file for analysis functions
3. `lib/medal_analysis.c` - Implementation of analysis functions

## How to Compile and Run

1. Ensure you have a C compiler installed (e.g., GCC).
2. Open a terminal and navigate to the project directory.
3. Compile the program using the following command:

   ```bash
   gcc main.c ./lib/medal_analysis.c -o OlympicInsights
   ```

   Run the build:

   ```bash
   ./OlympicInsights
   ```

   Or use the provided Makefile:

   Use the following command to compile the program:

   ```bash
   make
   ```

   Run the build:

   ```bash
   make run
   ```

   Clear the build directory:

   ```bash
   make clean
   ```

4. Run the compiled program:
   ```
   ./main
   ```

## Usage

1. When prompted, enter the country name and the number of gold, silver, and bronze medals for each country.
2. Type 'y' to add another country or 'n' to finish entering data.
3. The program will display a sorted medal table and provide an analysis of the results.

## Analysis Provided

- Total medals awarded (gold, silver, bronze)
- Top performers in various categories:
  - Most gold medals
  - Most silver medals
  - Most bronze medals
  - Most total medals
  - Highest points
- Medal distribution for the top 5 countries (using ASCII charts)

## Points System

- Gold medal: 3 points
- Silver medal: 2 points
- Bronze medal: 1 point

## Limitations

- The program currently supports a maximum of 100 countries (defined by MAX_COUNTRIES).
- Country names are limited to 49 characters.

## Future Improvements

- Add more detailed statistical analysis
- Enhance visualization with more advanced charting libraries

## Contributing

I'm not accepting any contributions as this is my college assignment. However, if you have any suggestions or improvements, feel free to open an issue or submit a pull request. I'll be happy to review and discuss any changes. Also, you can fork the repository and make your own changes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
