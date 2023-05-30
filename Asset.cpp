#include "Headers/Asset.h"

Asset::Asset(const std::string& assetId, const std::vector<double>& assetReturns)
    : id(assetId), returns(assetReturns) {}

void Asset::setId(const std::string& assetId) {
    id = assetId;
}

void Asset::setReturns(const std::vector<double>& assetReturns) {
    returns = assetReturns;
}

std::string Asset::getId() const {
    return id;
}

std::vector<double> Asset::getReturns() const {
    return returns;
}
