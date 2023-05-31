#include <iostream>
#include <vector>
#include "Headers/TargetReturns.h"

TargetReturns::TargetReturns() {
    // Initialize with default target returns
    targetReturns.push_back(0.0);
    targetReturns.push_back(0.005);
    targetReturns.push_back(0.01);
    targetReturns.push_back(0.015);
    targetReturns.push_back(0.02);
    targetReturns.push_back(0.025);
    targetReturns.push_back(0.03);
    targetReturns.push_back(0.035);
    targetReturns.push_back(0.04);
    targetReturns.push_back(0.045);
    targetReturns.push_back(0.05);
    targetReturns.push_back(0.055);
    targetReturns.push_back(0.06);
    targetReturns.push_back(0.065);
    targetReturns.push_back(0.07);
    targetReturns.push_back(0.075);
    targetReturns.push_back(0.08);
    targetReturns.push_back(0.085);
    targetReturns.push_back(0.09);
    targetReturns.push_back(0.095);
}

void TargetReturns::addTargetReturn(double targetReturn) {
    targetReturns.push_back(targetReturn);
}

void TargetReturns::deleteTargetReturn(int index) {
    if (index < targetReturns.size()) {
        targetReturns.erase(targetReturns.begin() + index);
    }
}

void TargetReturns::setTargetReturn(int index, double targetReturn) {
    if (index < targetReturns.size()) {
        targetReturns[index] = targetReturn;
    }
}

const std::vector<double>& TargetReturns::getTargetReturns() const {
    return targetReturns;
}
