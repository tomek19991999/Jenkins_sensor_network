#include <gtest/gtest.h>
#include "Sensor.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class MockSensor : public Sensor {
public:
    MockSensor(const std::string& name) : Sensor(name) {}
    
    void start() override { running_ = true; }
    void stop() override { running_ = false; }
    bool isRunning() const override { return running_; }
    std::string generateData() override { return "Mock data"; }
    std::string readData() const override { return "Mock read data"; }
};

TEST(SensorTest, SensorRunningState) {
    MockSensor sensor("TestSensor");
    EXPECT_FALSE(sensor.isRunning());
    sensor.start();
    EXPECT_TRUE(sensor.isRunning());
    sensor.stop();
    EXPECT_FALSE(sensor.isRunning());
}

TEST(SensorTest, SensorGenerateData) {
    MockSensor sensor("TestSensor");
    EXPECT_EQ(sensor.generateData(), "Mock data");
}

TEST(SensorTest, SensorReadData) {
    MockSensor sensor("TestSensor");
    EXPECT_EQ(sensor.readData(), "Mock read data");
}
