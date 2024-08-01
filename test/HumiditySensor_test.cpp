#include <gtest/gtest.h>
#include "HumiditySensor.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

TEST(HumiditySensorTest, GenerateData) {
    std::string sensorName = "HumiditySensor";
    HumiditySensor sensor(sensorName);
    sensor.start();
    std::string data = sensor.generateData();
    EXPECT_FALSE(data.empty());
}

TEST(HumiditySensorTest, ReadData) {
    std::string sensorName = "HumiditySensor";
    HumiditySensor sensor(sensorName);
    sensor.start();
    std::string data = sensor.readData();
    EXPECT_FALSE(data.empty());
}
