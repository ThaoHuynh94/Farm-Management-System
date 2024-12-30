#include "Crop.h"


//Parameterized constructor
Crop::Crop(std::string name,int harvestTime, double  yieldPerAcre, double pricePerUnit):
name(name), harvestTime(harvestTime), yieldPerAcre(yieldPerAcre), pricePerUnit(pricePerUnit){}


//Returns a string summarizing the crop's details.

std::string Crop::displayInfo() const {
    std::stringstream ss;
    ss << "Crop: " << name
       << ", Harvest Time: " << harvestTime << " days"
       << ", Yield: " << yieldPerAcre << " units per acre"
       << ", Price: $" << pricePerUnit << " per unit";

    return ss.str();
}


double Crop:: getYieldPerAcre() const{

    return  yieldPerAcre;

}

double Crop:: getPricePerUnit() const{
    return pricePerUnit;
}


