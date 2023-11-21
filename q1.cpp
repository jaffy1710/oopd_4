#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // for std::for_each
#include"csvreader.h"
#include"helper.h"

int main() {
    std::vector<Person> people;
    std::string filename = "q1.csv"; // Change this to your actual file name
    readPeople(filename,people);
    int choice;

    do {
        // Display menu
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Person\n";
        std::cout << "2. Delete Person by Vehicle Number\n";
        std::cout << "3. Edit Address by Vehicle Number\n";
        std::cout << "4. Print All Information\n";
        std::cout << "5. Save and Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addPerson(people);
                break;
            case 2:
                deletePersonByVehicleNumber(people);
                break;
            case 3:
                editAddressByVehicleNumber(people);
                break;
            case 4:
                printAll(people);
                break;
            case 5:
                saveToFile(people, filename);
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
