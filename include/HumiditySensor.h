// HumiditySensor.h
#pragma once
#include "Sensor.h"

class HumiditySensor : public Sensor {
public:
    HumiditySensor(const std::string& name) : Sensor(name) {}
    //HumiditySensor(const nlohmann::json& config) : Sensor(config) {}
    explicit HumiditySensor(const nlohmann::json& config);
    std::string generateData() override;
    void start() override;
    void stop() override;
    bool isRunning() const override;
    std::string readData() const override;

};

