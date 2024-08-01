#include "LogMessageConsumer.h"
#include <iostream>

LogMessageConsumer::LogMessageConsumer() {
}

LogMessageConsumer::~LogMessageConsumer() {
}

void LogMessageConsumer::consume(const std::vector<std::string>& messages) {
    for (const auto& message : messages) {
        std::cout << "LogMessageConsumer received: " << message << std::endl;
    }
}
