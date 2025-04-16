# Weather Data Processing and Sorting

## Overview

This project is a C++ program designed to process and sort weather data from a text file. It reads weather information, filters it based on specified criteria, sorts the filtered data by date, and then writes the sorted data to a binary file and a formatted text file.

## Features

*   **Data Reading:** Reads weather data (date, temperature, humidity, wind speed, and sunny status) from a text file named "Prognoz.txt".
*   **Data Filtering:** Filters the data based on the following criteria:
    *   Temperature between -10°C and 25°C.
    *   Humidity between 30% and 50%.
    *   Wind speed less than or equal to 5.5 m/s.
    *   Sunny status is true.
*   **Data Sorting:** Sorts the filtered data by date in ascending order using a bubble sort algorithm.
*   **Binary File Output:** Writes the sorted data to a binary file named "sort.bin".
*   **Formatted Text Output:** Reads the sorted data from the binary file and writes it to a formatted text file named "out.txt" for easy readability.
*   **Date Comparison:** Includes a custom function `compareDates` to correctly compare dates in the format DD-MM-YYYY.

## Technologies Used

*   C++
*   Standard Template Library (STL) for file input/output (`fstream`)

## File Structure

*   `Prognoz.txt`: Input text file containing raw weather data.
*   `sort.bin`: Output binary file containing sorted weather data.
*   `out.txt`: Output text file containing formatted, sorted weather data.
*   `#1.cpp`: The main source file containing the program logic.

## Prerequisites

*   A C++ compiler
*   Text editor or IDE for writing and editing code

## Installation and Usage

1.  **Compile the Code:**

    ```bash
    g++ №1.cpp -o weather_sort
    ```

2.  **Prepare Input Data:**

    *   Create a text file named `Prognoz.txt` in the same directory as the compiled executable.
    *   Populate `Prognoz.txt` with weather data in the following format, separated by spaces:
        `DD-MM-YYYY temperature humidity windspeed sunny`
        *   `DD-MM-YYYY`: Date (e.g., 01-01-2023)
        *   `temperature`: Temperature in Celsius (e.g., 20)
        *   `humidity`: Humidity in percent (e.g., 40)
        *   `windspeed`: Wind speed in m/s (e.g., 3.5)
        *   `sunny`: Boolean value (true/false or 1/0) indicating whether it's sunny.

    Example `Prognoz.txt` content:

    ```
    01-01-2023 10 40 3.5 true
    02-01-2023 20 35 4.0 true
    03-01-2023 -5 60 6.0 false
    04-01-2023 22 45 5.0 true
    ```

3.  **Run the Program:**

    ```bash
    ./weather_sort
    ```

4.  **View the Output:**

    *   The program will filter and sort the data.
    *   The sorted data will be written to `sort.bin` and `out.txt`.
    *   Open `out.txt` to see the formatted, sorted weather data.

## Project Structure and Code Explanation

*   **`WeatherData` struct:** Defines a structure to store weather data.
*   **`compareDates` function:** Compares two dates (DD-MM-YYYY) and returns -1, 0, or 1 to indicate the order.
*   **`main` function:**
    *   Opens input and output files.
    *   Reads weather data from `Prognoz.txt`.
    *   Filters the data based on the specified criteria.
    *   Sorts the filtered data using a bubble sort.
    *   Writes the sorted data to a binary file (`sort.bin`).
    *   Reads data from the binary file and writes it to a formatted text file (`out.txt`).

## Contact
antonpanin2006@gmail.com
