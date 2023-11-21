#include <iostream>
#include <string>

class Report {
private:
    std::string vehicle;
    std::string witness;
    std::string evidence;
    std::string response;

public:
    // Setter methods
    void setVehicle(const std::string& value) {
        vehicle = value;
    }

    void setWitness(const std::string& value) {
        witness = value;
    }

    void setEvidence(const std::string& value) {
        evidence = value;
    }

    void setResponse(const std::string& value) {
        response = value;
    }

    // Getter methods (optional)
    std::string getVehicle() const {
        return vehicle;
    }

    std::string getWitness() const {
        return witness;
    }

    std::string getEvidence() const {
        return evidence;
    }

    std::string getResponse() const {
        return response;
    }

    // Display method
    void displayReport() const {
        std::cout << "Report for Vehicle: " << getVehicle() << std::endl;
        std::cout << "Witness: " << getWitness() << std::endl;
        std::cout << "Evidence: " << getEvidence() << std::endl;
        std::cout << "Response: " << getResponse() << std::endl;
        std::cout << "-----------------------" << std::endl;
    }
};
