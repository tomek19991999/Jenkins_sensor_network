// InterThreadComm.cpp
#include "InterThreadComm.h"

void InterThreadComm::send(const std::string& message) {
    std::unique_lock<std::mutex> lock(mutex_);
    messageQueue_.push(message);
}

std::string InterThreadComm::receive() {
    std::unique_lock<std::mutex> lock(mutex_);
    if (messageQueue_.empty()) {
        return "";
    }

    std::string message = messageQueue_.front();
    messageQueue_.pop();
    return message;
}

bool InterThreadComm::isEmpty() const {
    std::unique_lock<std::mutex> lock(mutex_);
    return messageQueue_.empty();
}
