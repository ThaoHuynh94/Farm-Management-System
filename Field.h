#ifndef FIELD_H
#define FIELD_H

#include "Crop.h"
#include <sstream>

/**
 * @class Field
 * @brief Models a field that contains a single crop and its size in acres.
 */
class Field {
private:
    Crop crop;  ///< A Crop object representing the type of crop grown in the field.
    double sizeInAcres;  ///< Size of the field in acres.

public:
    /**
     * @brief Constructs a Field with specified crop details and field size.
     * @param cropName Name of the crop.
     * @param harvestTime Number of days required for the crop to be ready for harvest.
     * @param yield Yield per acre of the crop (units produced per acre).
     * @param price Price per unit of the crop yield.
     * @param sizeInAcres Size of the field in acres.
     */
    Field(std::string cropName, int harvestTime, double yield, double price, double sizeInAcres);

    /**
     * @brief Provides a summary of the field's details, including crop information, total yield, and total value.
     * @return A string summarizing the field's information.
     */
    std::string toString() const;

    /**
     * @brief Calculates the total yield for the field based on its size and crop yield per acre.
     * @return The total yield (in units) for the field.
     */
    double totalYield() const;

    /**
     * @brief Calculates the total value of the field's crop based on total yield and price per unit.
     * @return The total value (in dollars) of the field's crop.
     */
    double totalValue() const;

    /**
     * @brief Destructor for Field. Cleans up resources if necessary (none in this case).
     */
    ~Field() {}
};

#endif // FIELD_H
