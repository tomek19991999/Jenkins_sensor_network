#pragma once
#include <vector>
#include <memory>
#include "Sensor.h"
#include "MessageConsumer.h"

class NotificationService {
public:
    NotificationService(size_t buffer_size);
    void registerSensor(const std::shared_ptr<Sensor>& sensor);
    void notifyMessageConsumers();
    std::vector<std::string> getBufferData();

private:
    size_t buffer_size_;
    std::vector<std::shared_ptr<Sensor>> sensors_;
    std::vector<std::string> buffer_;
};
