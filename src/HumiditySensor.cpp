// HumiditySensor.cpp
#include "HumiditySensor.h"

using json = nlohmann::json;

std::string HumiditySensor::generateData() {
    // Generate random humidity data
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 100.0);
    double humidity = dis(gen);

    return "Humidity: " + std::to_string(humidity) + " %";
}

void HumiditySensor::start() {
    running_ = true;
    // Add code to start the sensor
}

void HumiditySensor::stop() {
    running_ = false;
    // Add code to stop the sensor
}

bool HumiditySensor::isRunning() const {
    return running_;
}


HumiditySensor::HumiditySensor(const json& config) : Sensor(config) {
    // Initialize HumiditySensor with the provided configuration
    // If you need to extract additional information from config, do it here.
}

std::string HumiditySensor::readData() const {
    // Implement humidity data reading logic here
    return "Humidity: 55%"; // Example value
}
