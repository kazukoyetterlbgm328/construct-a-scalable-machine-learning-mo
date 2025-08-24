#ifndef MQ3O_CONSTRUCT_A_SCA_H
#define MQ3O_CONSTRUCT_A_SCA_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <mutex>

class ModelMonitor {
public:
    ModelMonitor(std::string modelName, int interval);
    ~ModelMonitor();

    void addMetric(std::string metricName, double value);
    void removeMetric(std::string metricName);
    void updateModelStatus(std::string status);
    void triggerAlert(std::string alertMessage);

    std::string getModelName() const;
    int getInterval() const;
    std::map<std::string, double> getMetrics() const;
    std::string getModelStatus() const;

private:
    std::string modelName_;
    int interval_;
    std::map<std::string, double> metrics_;
    std::string modelStatus_;
    std::mutex mtx_;

    void reportMetrics() const;
    void sendAlert(std::string alertMessage) const;
};

#endif // MQ3O_CONSTRUCT_A_SCA_H