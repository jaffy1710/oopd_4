#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include"csvreader.h"
#include"helper.h"

int main() {
    std::vector<CarReport> carReports;
    std::string filename = "q2_new.csv"; // Change this to your actual file name

    // Read data from CSV file
     readCarReports(filename, carReports);

    int choice;

     do {
        // Display menu
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Car Report\n";
        std::cout << "2. Delete Car Report by Car Number\n";
        std::cout << "3. Print All Car Reports\n";
        std::cout << "4. Save and Exit\n";
        std::cout << "Enter your choice: ";

        // if (!(std::cin >> choice)) {
        //     std::cin.clear();  // Clear the fail state
        //     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
        //     std::cout << "Invalid input. Please enter a number.\n";
        //     continue;
        // }
        std::cin >> choice;

        switch (choice) {
            case 1:
                addCarReport(carReports);
                break;
            case 2:
                deleteCarReport(carReports);
                break;
            case 3:
                printCarReports(carReports);
                break;
            case 4:
                // Save and exit
                writeCarReports(filename, carReports);
                std::cout << "Data saved to file successfully!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
     } while (choice != 4);

    return 0;
}
