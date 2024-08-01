#include <iostream>
#include <fstream>
#include <thread>
#include "nlohmann/json.hpp"
#include "PerformanceMonitor.h"
#include "NotificationService.h"
#include "SensorFactory.h"
#include "LogMessageConsumer.h"

using json = nlohmann::json;

int main(){
    std::ifstream config_file("config.json");
    if (!config_file.is_open()) {
        std::cerr << "Error opening configuration file" << std::endl;
        return 1;
    }

    json config;
    config_file >> config;

    size_t buffer_size = config["buffer_size"];
    int notification_interval = config["notification_interval"];

    SensorFactory sensor_factory;
    std::vector<std::shared_ptr<Sensor>> sensors;

    for (const auto& sensor_config : config["sensors"]) {
        auto sensor = sensor_factory.createSensor(sensor_config);
        if (sensor) {
            sensors.push_back(sensor);
        }
    }

    PerformanceMonitor performanceMonitor;

    NotificationService notification_service(buffer_size);
    for (const auto& sensor : sensors) {
        notification_service.registerSensor(sensor);
    }

    LogMessageConsumer message_consumer;

    //while (true) { //loop for endless check
        std::this_thread::sleep_for(std::chrono::seconds(notification_interval));
        notification_service.notifyMessageConsumers();
        message_consumer.consume(notification_service.getBufferData());
        performanceMonitor.displayPerformanceMetrics();

        std::this_thread::sleep_for(std::chrono::seconds(1));
    //}

    return 0;
}
