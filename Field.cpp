#include "Field.h"

Field::Field(std::string cropName, int harvestTime, double yield, double price, double sizeInAcres)
        : crop(cropName, harvestTime, yield, price), sizeInAcres(sizeInAcres) {}

std::string Field::toString() const {
    std::stringstream ss;

    ss << "Field size: " << sizeInAcres << " acres\n"
       << crop.displayInfo() << "\n"
       << "Total Value: $ " << totalValue() << "\n";

    return ss.str();
}

double Field::totalYield() const {
    return crop.getYieldPerAcre() * sizeInAcres;
}

double Field::totalValue() const {
    return crop.getPricePerUnit() * totalYield();
}
