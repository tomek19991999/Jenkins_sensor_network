#include "SensorFactory.h"
#include "TemperatureSensor.h"
#include "HumiditySensor.h"

std::shared_ptr<Sensor> SensorFactory::createSensor(const json& sensor_config) {
    std::string type = sensor_config["type"];

    if (type == "temperature") {
        return createTemperatureSensor(sensor_config);
    }
    else if (type == "humidity") {
        return createHumiditySensor(sensor_config);
    }

    return nullptr;
}

std::shared_ptr<Sensor> SensorFactory::createTemperatureSensor(const json& sensor_config) {
    return std::make_shared<TemperatureSensor>(sensor_config);
}

std::shared_ptr<Sensor> SensorFactory::createHumiditySensor(const json& sensor_config) {
    return std::make_shared<HumiditySensor>(sensor_config);
}
