#ifndef TARGETRETURNS_H
#define TARGETRETURNS_H

#include <vector>

class TargetReturns {
private:
    std::vector<double> targetReturns;

public:
    TargetReturns();

    void addTargetReturn(double targetReturn);
    void deleteTargetReturn(int index);
    void setTargetReturn(int index, double targetReturn);

    const std::vector<double>& getTargetReturns() const;
};

#endif 
