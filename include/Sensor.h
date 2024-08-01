// Sensor.h
#pragma once
#include <string>
#include <random>
#include "nlohmann/json.hpp"
#include "InterThreadComm.h"

class Sensor {
public:
    Sensor(const std::string& name) : name_(name) {}
    Sensor(const nlohmann::json& config) : config_(config) {}
    virtual ~Sensor() = default;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual bool isRunning() const = 0;
    virtual std::string generateData() = 0;
    void setCommunicationChannel(InterThreadComm* commChannel);
    void sendData(int value);
    void sendData();
    virtual std::string readData() const = 0;
protected:
    std::string name_;
    InterThreadComm* commChannel_ = nullptr;
    bool running_ = false;

private:
    nlohmann::json config_;
    
};
