#ifndef CHICKEN_H
#define CHICKEN_H

#include "Animal.h"
#include <sstream>

const double GRAIN_PER_KG =  0.1; ///<Requires 0.1 kg of grain per kg of body weight


/**
 * @class Chicken
 * @brief Represents a chicken that inherits from the Animal class.
 *
 * This class models a chicken with specific attributes like name and weight.
 * It provides functionality to display the chicken's information and dietary requirements.
 */
class Chicken : public Animal {
public:
    /**
     * @brief Constructs a Chicken object.
     *
     * @param name The name of the chicken.
     * @param weight The weight of the chicken in kilograms.
     */
    Chicken(std::string name, double weight);

    /**
     * @brief Returns a string representation of the chicken's details.
     *
     * @return A string containing the animal type, name, and weight.
     */
    std::string toString() const override;

    /**
     * @brief Provides the dietary requirements for the chicken.
     *
     * @return A string describing the dietary requirements of the chicken.
     */
    std::string dietaryRequirements() const override;

    /**
     * @brief Destructor for the Chicken class.
     */
    ~Chicken() override {}
};

#endif // CHICKEN_H
