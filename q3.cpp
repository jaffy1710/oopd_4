#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // for std::for_each
#include"csvreader.h"
#include"helper.h"

void sendChalan(const Person& person) {
    // This is a placeholder implementation, modify this function according to your actual requirements.
    std::cout << "Sending violation message to: " << person.firstName << " " << person.lastName << std::endl;
}

// Declaration of the sendChalanToAll function
void sendChalanToAll(const std::vector<Person>& people) {
    // Iterate through the vector and send a violation message to each person
    for (const auto& person : people) {
        sendChalan(person);
    }
}

bool addressExistsInVector(const std::vector<PersonalInfo>& personalInfos, const std::string& address) {
    for (const auto& person : personalInfos) {
        if (person.address == address) {
            return true;  // Address found in the vector
        }
    }
    return false;  // Address not found in the vector
}

int main() {
    std::vector<Person> people;
    std::vector<CarReport> carReports;
    std::vector<PersonalInfo>personalInfos;


    // Assuming your file names
    std::string personFilename = "q1.csv";
    std::string carReportFilename = "q2_new.csv";
    std::string addressfilename="q3.csv";

    // Read data from CSV files
    readPeople(personFilename, people);
    readCarReports(carReportFilename, carReports);
    readPersonalInfo(addressfilename,personalInfos);

    // Fetch the car number from q2_new.csv
    std::string carNumberToSearch;
    std::cout << "Enter Car Number to search: ";
    std::cin >> carNumberToSearch;

    // Search for the car number in q1.csv
    auto it = std::find_if(people.begin(), people.end(), [carNumberToSearch](const Person& p) {
        return p.vehicle + p.number == carNumberToSearch;
    });

    if (it != people.end()) {
        // Person record found, print the details
        std::cout << "Person Record Found:\n";
        std::cout << "-----------------------" << std::endl;
        std::cout << "Concatenated: " << it->vehicle + it->number << std::endl;
        std::cout << "Name: " << it->firstName << " " << it->lastName << std::endl;
        std::cout << "Age: " << it->age << std::endl;
        std::cout << "Gender: " << it->gender << std::endl;
        std::cout << "Address: " << it->address << std::endl;
        if (!addressExistsInVector(personalInfos, it->address)) {
            // Address does not match, update the address
            editAddressByVehicleNumber(people);
             // Send violation message
            sendChalan(*it);
        } else {
            std::cout << "Address matches with q3.csv." << std::endl;
        }
    } else {
        std::cout << "Person Record not found for the given Car Number." << std::endl;
    }

    // Send violation message to everyone
    sendChalanToAll(people);

    return 0;
}