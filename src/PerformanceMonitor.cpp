// PerformanceMonitor.cpp
#include "PerformanceMonitor.h"
#include <iostream>

#ifdef __linux__

void PerformanceMonitor::displayPerformanceMetrics() {
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        std::cout << "System uptime: " << (info.uptime) / 60 << " minutes" << std::endl;
        std::cout << "Total RAM: " << info.totalram / (1024 * 1024) << " MB" << std::endl;
        std::cout << "Free RAM: " << info.freeram / (1024 * 1024) << " MB" << std::endl;
        std::cout << "CPU Load: " << (1.0 - (double)info.loads[0] / (double)info.loads[1]) * 100 << "%" << std::endl;
    }
    else {
        std::cerr << "Failed to retrieve system information." << std::endl;
    }
}

#else
#error "Unsupported platform"
#endif
