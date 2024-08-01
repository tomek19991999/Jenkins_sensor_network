// LogMessageConsumer.h
#pragma once
#include "MessageConsumer.h"

class LogMessageConsumer : public MessageConsumer {
public:
    LogMessageConsumer();
    ~LogMessageConsumer();

    void consume(const std::vector<std::string>& messages) override;
};
