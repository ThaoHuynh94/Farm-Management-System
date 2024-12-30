#ifndef PIG_H
#define PIG_H
#include "Animal.h"
#include <sstream>

const double MIXED_FEED_PER_KG =  0.05; ///<Requires 0.05 kg of mixed feed per kg of body weight

class Pig: public Animal{
public:
    /**
     * @brief Constructs a Pig object.
     *
     * @param name The name of the pig.
     * @param weight The weight of the pig in kilograms.
     */
    Pig(std::string name, double weight);

    /**
     * @brief Returns a string representation of the pig's details.
     *
     * @return A string containing the animal type, name, and weight.
     */
    std::string toString() const override;

    /**
     * @brief Provides the dietary requirements for the pig.
     *
     * @return A string describing the dietary requirements of the pig.
     */
    std::string dietaryRequirements() const override;

    /**
     * @brief Destructor for the Cow class.
     */

    ~Pig() override {}

};

#endif // PIG_H
