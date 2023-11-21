#include <iostream>
#include <vector>
#include <algorithm>
#include "csvreader.h"  // Assuming you have the CSV reading functions in this header
#include "helper.h"  // Assuming you have the functions for adding, deleting, and editing in this header
#include "report.h"  // Assuming you have a Report class with appropriate methods

void createReportsForSelectedVehicles(const std::vector<Person>& people,
                                      const std::vector<CarReport>& carReports,
                                      std::vector<Report>& reportList,
                                      const std::vector<std::string>& selectedVehicles) {
    // Iterate through each person
    for (const auto& person : people) {
        // Check if the current person's vehicle is in the selected list
        if (std::find(selectedVehicles.begin(), selectedVehicles.end(),
                      person.vehicle + person.number) != selectedVehicles.end()) {
            // Search for the corresponding car report
            auto it = std::find_if(carReports.begin(), carReports.end(),
                                   [&person](const CarReport& carReport) {
                                       return carReport.carNumber == person.vehicle + person.number;
                                   });

            // Create a report object
            Report report;
            report.setVehicle(person.vehicle + person.number);
            report.setWitness("jafreen");  // Set witness as 'jafreen'

            // Check if a matching car report is found
            if (it != carReports.end()) {
                // Set Type_of_report and Report_Location as evidence
                report.setEvidence("Type_of_report: " + it->typeOfReport +
                                   " Report_Location: " + it->reportLocation);
                report.setResponse("Found Guilty.");
            } else {
                report.setEvidence("");
                report.setResponse("Not Guilty");
            }

            // Add the report to the list
            reportList.push_back(report);
        }
    }
}

int main() {
    std::vector<Person> people;
    std::vector<CarReport> carReports;
    std::vector<Report> reportList;

    // Assuming your file paths
    std::string personFilePath = "q1.csv";
    std::string carReportFilePath = "q2_new.csv";

    // Read data from CSV files
    readPeople(personFilePath, people);
    readCarReports(carReportFilePath, carReports);

    // Get user input for selected vehicles
    std::vector<std::string> selectedVehicles;
    std::string userInput;
    std::cout << "Enter vehicle numbers (separated by ';'): ";
    std::getline(std::cin, userInput);

    // Tokenize the user input
    std::istringstream ss(userInput);
    std::string token;
    while (std::getline(ss, token, ';')) {
        selectedVehicles.push_back(token);
    }

    // Create reports for selected vehicles
    createReportsForSelectedVehicles(people, carReports, reportList, selectedVehicles);

    // Display the reports
    for (const auto& report : reportList) {
        report.displayReport();
    }

    return 0;
}
