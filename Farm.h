#ifndef FARM_H
#define FARM_H

#include "Chicken.h"
#include "Cow.h"
#include "Pig.h"
#include "Animal.h"
#include "Crop.h"
#include "Field.h"
#include <sstream>
#include <vector>

/**
 * @brief The Farm class represents a farm that can contain various fields and animals.
 *
 * This class manages the addition of fields and animals,
 * and provides a summary of the farm's details.
 * computes the total yield from all the fields,
 */

class Farm {
private:

    std::vector<Field> fields; ///< Composition: Fields are part of the farm and will be automatically destroyed when the farm is destroyed.

    std::vector<Animal *> animals; ///< Aggregation: Animals are not owned by the farm and can exist independently
///<                               ///< The farm does not manage their destruction.

public:
    /**
     * @brief Adds a field to the farm.
     *
     * @param field A reference to the Field object to be added to the farm.
     */
    void addField(Field const &field);

    /**
     * @brief Adds an animal to the farm.
     *
     * @param animal A pointer to the Animal object to be added to the farm.
     */
    void addAnimal(Animal *animal);

    /**
     * @brief Returns a string summarizing all the fields and animals on the farm.
     *
     * This string includes details about each field and the animals present
     *
     * @return A string containing the farm's details (all the fields and animals on the farm)
     */
    std::string toString() const;

    /**
     * @brief Calculates the total yield of the farm.
     *
     * This method iterates through all the fields and sums their yields to provide
     * the total farm yield.
     *
     * @return The total yield of the farm as a double.
     */
    double totalFarmYield() const;


    /**
     * @brief Retrieves the vector of animal pointers added to the farm.
     *
     * This function provides access to the internal list of animals stored in the farm.
     * The vector returned is a reference to the farm's internal storage, and its contents should not be modified.
     *
     * @return A constant reference to the vector of animal pointers.
     */
    const std::vector<Animal*>& getAnimals() const;


    /**
     * @brief Destructor for the Farm class.
     *
     */
    ~Farm(){}
};

#endif // FARM_H
