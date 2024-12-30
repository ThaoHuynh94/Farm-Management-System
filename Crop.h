#ifndef CROP_H
#define CROP_H

#include <iostream>
#include <sstream>

/**
 * @class Crop
 * @brief Models a crop with relevant attributes like name, harvest time, yield per acre, and price per unit.
 */
class Crop {
private:
    std::string name;         ///< Name of the crop (e.g., "Corn")
    int harvestTime;          ///< Number of days required for harvest
    double yieldPerAcre;      ///< Units produced per acre
    double pricePerUnit;      ///< Price per unit of yield

public:
    /**
     * @brief Default Constructor that initializes the crop with default values.
     */
    Crop() : name(" "), harvestTime(0), yieldPerAcre(0.0), pricePerUnit(0.0) {}

    /**
     * @brief Parameterized constructor to initialize the crop with specific values.
     * @param name The name of the crop.
     * @param harvestTime The number of days required to harvest the crop.
     * @param yieldPerAcre The units produced per acre for this crop.
     * @param pricePerUnit The price per unit of yield for this crop.
     */
    Crop(std::string name, int harvestTime, double yieldPerAcre, double pricePerUnit);

    /**
     * @brief Provides a summary of the crop's details.
     * @return A string summarizing the crop's details, including name, harvest time, yield per acre, and price per unit.
     */
    std::string displayInfo() const;

    /**
     * @brief Gets the yield per acre for the crop.
     * @return The yield per acre as a double.
     */
    double getYieldPerAcre() const;

    /**
     * @brief Gets the price per unit of the crop's yield.
     * @return The price per unit as a double.
     */
    double getPricePerUnit() const;

    /**
     * @brief Default Destructor.
     */
    ~Crop() {}
};

#endif // CROP_H
