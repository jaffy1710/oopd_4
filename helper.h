#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
// #include"csvreader.h"

// Function to add vehicle information
void addPerson(std::vector<Person>& people) {
    Person person;
    std::cout << "Enter Vehicle: ";
    std::cin >> person.vehicle;
    std::cout << "Enter Number: ";
    std::cin >> person.number;
    std::cout << "Enter First Name: ";
    std::cin >> person.firstName;
    std::cout << "Enter Last Name: ";
    std::cin >> person.lastName;
    std::cout << "Enter Age: ";
    std::cin >> person.age;
    std::cout << "Enter Gender: ";
    std::cin >> person.gender;
    std::cout << "Enter Address: ";
    std::cin.ignore(); // Clear the newline from the buffer
    std::getline(std::cin, person.address);
    people.push_back(person);
    std::cout << "Person added successfully!" << std::endl;
}

// Function to delete information based on vehicle number
void deletePersonByVehicleNumber(std::vector<Person>& people) {
    std::string vehicleNumber;
    std::cout << "Enter Vehicle Number to delete: ";
    std::cin >> vehicleNumber;
    
    auto it = std::remove_if(people.begin(), people.end(), [vehicleNumber](const Person& p) {
        return p.vehicle + p.number == vehicleNumber;
    });

    if (it != people.end()) {
        people.erase(it, people.end());
        std::cout << "Deleted successfully!" << std::endl;
    } else {
        std::cout << "Person not found." << std::endl;
    }
}

// Function to edit address based on vehicle number
void editAddressByVehicleNumber(std::vector<Person>& people) {
    std::string vehicleNumber;
    std::cout << "Enter Vehicle Number to edit address: ";
    std::cin >> vehicleNumber;

    auto it = std::find_if(people.begin(), people.end(), [vehicleNumber](const Person& p) {
        return p.vehicle + p.number == vehicleNumber;
    });

    if (it != people.end()) {
        std::cout << "Enter new Address: ";
        std::cin.ignore(); // Clear the newline from the buffer
        std::getline(std::cin, it->address);
        std::cout << "Address edited successfully!" << std::endl;
    } else {
        std::cout << "Person not found." << std::endl;
    }
}

// Function to print all information
void printAll(const std::vector<Person>& people) {
    std::cout << "All People Information:\n";
    std::for_each(people.begin(), people.end(), [](const Person& p) {
        std::cout << "-----------------------" << std::endl;
        std::cout << "Concatenated: " << p.vehicle + p.number << std::endl;
        std::cout << "Name: " << p.firstName << " " << p.lastName << std::endl;
        std::cout << "Age: " << p.age << std::endl;
        std::cout << "Gender: " << p.gender << std::endl;
        std::cout << "Address: " << p.address << std::endl;
    });
}

// CAR REPORTS

void addCarReport(std::vector<CarReport>& carReports) {
    CarReport carReport;
    std::cout << "Enter Car Number (e.g., EC,905571): ";
    std::string carNumberPart1;
    std::cin >> carNumberPart1;
    // carReport.carNumber = carNumberPart1 + carNumberPart2;
    std::cout << "Enter Type of Report: ";
    std::cin >> carReport.typeOfReport;
    std::cout << "Enter Report Location: ";
    std::cin >> carReport.reportLocation;
    carReports.push_back(carReport);
    std::cout << "Record added successfully!" << std::endl;
}

// Function to delete a record based on car number
void deleteCarReport(std::vector<CarReport>& carReports) {
    std::string carNumberToDelete;
    std::cout << "Enter Car Number to delete: ";
    std::cin >> carNumberToDelete;

    auto it = std::remove_if(carReports.begin(), carReports.end(),
                             [carNumberToDelete](const CarReport& carReport) {
                                 return carReport.carNumber == carNumberToDelete;
                             });

    if (it != carReports.end()) {
        carReports.erase(it, carReports.end());
        std::cout << "Record deleted successfully!" << std::endl;
    } else {
        std::cout << "Record not found." << std::endl;
    }
}

// Function to print all car reports
void printCarReports(const std::vector<CarReport>& carReports) {
    std::cout << "All Car Reports:\n";
    for (const auto& carReport : carReports) {
        std::cout << "-----------------------" << std::endl;
        std::cout << "Concatenated Car Number: " << carReport.carNumber << std::endl;
        std::cout << "Type of Report: " << carReport.typeOfReport << std::endl;
        std::cout << "Report Location: " << carReport.reportLocation << std::endl;
    }
}