#include <gtest/gtest.h>
#include "TemperatureSensor.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

TEST(TemperatureSensorTest, GenerateData) {
    std::string sensorName = "TemperatureSensor";
    TemperatureSensor sensor(sensorName);
    sensor.start();
    std::string data = sensor.generateData();
    EXPECT_FALSE(data.empty());
}

TEST(TemperatureSensorTest, ReadData) {
    std::string sensorName = "TemperatureSensor";
    TemperatureSensor sensor(sensorName);
    sensor.start();
    std::string data = sensor.readData();
    EXPECT_FALSE(data.empty());
}
