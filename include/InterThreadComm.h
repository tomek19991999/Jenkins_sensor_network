// InterThreadComm.h
#pragma once
#include <string>
#include <queue>
#include <mutex>

class InterThreadComm {
public:
    void send(const std::string& message);
    std::string receive();
    bool isEmpty() const;

private:
    std::queue<std::string> messageQueue_;
    mutable std::mutex mutex_;
};

