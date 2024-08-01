#pragma once
#include <memory>
#include "Sensor.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class SensorFactory {
public:
	std::shared_ptr<Sensor> createSensor(const json& sensor_config);

private:
	std::shared_ptr<Sensor> createTemperatureSensor(const json& sensor_config);
	std::shared_ptr<Sensor> createHumiditySensor(const json& sensor_config);
};
