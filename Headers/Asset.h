#ifndef ASSET_H
#define ASSET_H

#include <string>
#include <vector>

class Asset {
private:
    std::string id;
    std::vector<double> returns;

public:
    Asset(const std::string& assetId, const std::vector<double>& assetReturns);

    void setId(const std::string& assetId);
    void setReturns(const std::vector<double>& assetReturns);

    std::string getId() const;
    std::vector<double> getReturns() const;
};

#endif // ASSET_H
