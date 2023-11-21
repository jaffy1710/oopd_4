#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


struct Person {
    std::string vehicle;
    std::string number;
    std::string firstName;
    std::string lastName;
    std::string age;
    std::string gender;
    std::string address;
};

struct CarReport {
    std::string carNumber;
    std::string typeOfReport;
    std::string reportLocation;
};


struct PersonalInfo {
    std::string firstName;
    std::string lastName;
    std::string age;
    std::string gender;
    std::string address;
};

// Function to read data from CSV file for Person records
void readPeople(const std::string& filename, std::vector<Person>& people) {
    std::ifstream inputFile(filename);

    if (inputFile.is_open()) {
        std::string line;
        while (getline(inputFile, line)) {
            std::istringstream iss(line);
            Person person;

            getline(iss, person.vehicle, ',');
            getline(iss, person.number, ',');
            getline(iss, person.firstName, ',');
            getline(iss, person.lastName, ',');
            getline(iss, person.age, ',');
            getline(iss, person.gender, ',');
            getline(iss, person.address);

            people.push_back(person);
        }

        inputFile.close();
        std::cout << "Data loaded from file successfully!" << std::endl;
    } else {
        std::cerr << "Error opening file for reading!" << std::endl;
    }
}

// Function to read data from CSV file for CarReport records
void readCarReports(const std::string& filename, std::vector<CarReport>& carReports) {
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::string line;
    while (getline(inputFile, line)) {
        std::istringstream iss(line);
        CarReport carReport;

        // Read "EC" and "905571" and concatenate them into a single field
        std::string carNumberPart1;
        getline(iss, carNumberPart1, ',');
        // getline(iss, carNumberPart2, ',');
        // carReport.carNumber = carNumberPart1 + carNumberPart2;

        getline(iss, carReport.typeOfReport, ',');
        getline(iss, carReport.reportLocation);

        carReports.push_back(carReport);
    }

    inputFile.close();
}

void writeCarReports(const std::string& filename, const std::vector<CarReport>& carReports) {
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    for (const auto& carReport : carReports) {
        outputFile << carReport.carNumber << ',' << carReport.typeOfReport << ',' << carReport.reportLocation << '\n';
    }

    outputFile.close();
}

void saveToFile(const std::vector<Person>& people, const std::string& filename) {
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    for (const auto& person : people) {
        outputFile << person.vehicle << ',' << person.number << ',' << person.firstName << ','
                   << person.lastName << ',' << person.age << ',' << person.gender << ','
                   << person.address << '\n';
    }

    outputFile.close();
    std::cout << "Data saved to file successfully!" << std::endl;
}

void readPersonalInfo(const std::string& filename, std::vector<PersonalInfo>& personalInfos) {
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::string line;
    std::getline(inputFile, line); // Ignore the header

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        PersonalInfo personalInfo;

        std::getline(iss, personalInfo.firstName, ',');
        std::getline(iss, personalInfo.lastName, ',');
        std::getline(iss, personalInfo.age, ',');
        std::getline(iss, personalInfo.gender, ',');
        std::getline(iss, personalInfo.address);

        personalInfos.push_back(personalInfo);
    }

    inputFile.close();
}

