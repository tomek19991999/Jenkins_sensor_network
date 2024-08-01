// TemperatureSensor.h
#pragma once
#include "Sensor.h"

class TemperatureSensor : public Sensor {
public:
    //TemperatureSensor(const std::string& name) : Sensor(name) {}
    //TemperatureSensor(const nlohmann::json& config) : Sensor(config) {}
    std::string generateData() override;
    void start() override;
    void stop() override;
    bool isRunning() const override;
    explicit TemperatureSensor(const nlohmann::json& config);
    std::string readData() const override;

};


