#include "Sensor.h"
void Sensor::setCommunicationChannel(InterThreadComm* commChannel) {
    commChannel_ = commChannel;
}

void Sensor::sendData() {
    if (commChannel_ == nullptr) {
        return;
    }

    // ...
    std::string data; 
    /* prepare data to be sent */
    commChannel_->send(data);
    // ...
}

void Sensor::sendData(int value) {
    std::string stringValue = std::to_string(value);
    commChannel_->send(stringValue);
}
