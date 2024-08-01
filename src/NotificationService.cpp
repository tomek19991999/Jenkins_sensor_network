#include "NotificationService.h"

NotificationService::NotificationService(size_t buffer_size) : buffer_size_(buffer_size) {}

void NotificationService::registerSensor(const std::shared_ptr<Sensor>& sensor) {
    sensors_.push_back(sensor);
}

void NotificationService::notifyMessageConsumers() {
    buffer_.clear();

    for (const auto& sensor : sensors_) {
        buffer_.push_back(sensor->readData());
    }
}

std::vector<std::string> NotificationService::getBufferData() {
    return buffer_;
}
