// PerformanceMonitor.h
#pragma once

#ifdef __linux__
#include <sys/sysinfo.h>
#else
#error "Unsupported platform"
#endif

class PerformanceMonitor {
public:
    void displayPerformanceMetrics();
};
