#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

/**
 * @class Animal
 * @brief Represents a base class for all animals.
 *
 * This class serves as an abstract base class for specific animal types.
 * It defines common attributes such as name and weight, and declares
 * pure virtual functions that derived classes must implement.
 */
class Animal {
private:
    std::string name; ///< The animal’s name
    double weight;    ///< Weight of the animal in kilograms

public:
    /**
     * @brief Constructs an Animal object.
     *
     * @param name The name of the animal.
     * @param weight The weight of the animal in kilograms.
     */
    Animal(std::string name, double weight);

    /**
     * @brief Returns a string representation of the animal.
     *
     * This is a pure virtual function that must be implemented in derived classes.
     * @return A string containing the details of the animal.
     */
    virtual std::string toString() const = 0;

    /**
     * @brief Provides the dietary requirements for the animal.
     *
     * This is a pure virtual function that must be implemented in derived classes.
     * @return A string describing the dietary requirements of the animal.
     */
    virtual std::string dietaryRequirements() const = 0;

    /**
     * @brief Gets the name of the animal.
     *
     * @return The name of the animal.
     */
    std::string getName() const;

    /**
     * @brief Gets the weight of the animal.
     *
     * @return The weight of the animal in kilograms.
     */
    double getWeight() const; // Return type is double

    /**
     * @brief Destructor for the Animal class.
     *
     * The destructor is virtual to ensure proper cleanup of derived classes.
     */
    virtual ~Animal() {}
};

#endif // ANIMAL_H
