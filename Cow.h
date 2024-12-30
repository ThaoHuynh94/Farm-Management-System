#ifndef COW_H
#define COW_H

#include "Animal.h"
#include <sstream>

const double GRASS_PER_KG =  2.5; ///<Requires 2.5 kg of grass per kg of body weight


/**
 * @class Cow
 * @brief Represents a cow that inherits from the Animal class.
 *
 * This class models a cow with specific attributes like name and weight.
 * It provides functionality to display the cow's information and dietary requirements.
 */
class Cow : public Animal {
public:
    /**
     * @brief Constructs a Cow object.
     *
     * @param name The name of the cow.
     * @param weight The weight of the cow in kilograms.
     */
    Cow(std::string name, double weight);

    /**
     * @brief Returns a string representation of the cow's details.
     *
     * @return A string containing the animal type, name, and weight.
     */
    std::string toString() const override;

    /**
     * @brief Provides the dietary requirements for the cow.
     *
     * @return A string describing the dietary requirements of the cow.
     */
    std::string dietaryRequirements() const override;

    /**
     * @brief Destructor for the Cow class.
     */
    ~Cow() override {}
};

#endif // COW_H
