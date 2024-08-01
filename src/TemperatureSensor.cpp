// TemperatureSensor.cpp
#include "TemperatureSensor.h"

using json = nlohmann::json;

std::string TemperatureSensor::generateData() {
    // Generate random temperature data
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-50.0, 50.0);
    double temperature = dis(gen);

    return "Temperature: " + std::to_string(temperature) + " �C";
}

void TemperatureSensor::start() {
    running_ = true;
    // Add code to start the sensor
}

void TemperatureSensor::stop() {
    running_ = false;
    // Add code to stop the sensor
}

bool TemperatureSensor::isRunning() const {
    return running_;
}


TemperatureSensor::TemperatureSensor(const json& config) : Sensor(config) {
    // Initialize TemperatureSensor with the provided configuration
    // If you need to extract additional information from config, do it here.
}

std::string TemperatureSensor::readData() const {
    // Implement temperature data reading logic here
    return "Temperature: 25C"; // Example value
}
