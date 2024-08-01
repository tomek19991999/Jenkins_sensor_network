// MessageConsumer.h
#pragma once

#include <vector>
#include <string>

class MessageConsumer {
public:
    virtual ~MessageConsumer() = default;

    virtual void consume(const std::vector<std::string>& messages) = 0;
};
