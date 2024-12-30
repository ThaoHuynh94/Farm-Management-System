#include "Chicken.h"

// Constructor
Chicken::Chicken(std::string name, double weight) : Animal(name, weight) {}

// toString Method
std::string Chicken::toString() const {
    std::stringstream ss;
    ss << "Chicken: " << Animal::getName() << ", Weight: " << Animal::getWeight() << " kg\n";
    return ss.str();
}

// Dietary Requirements Method
std::string Chicken::dietaryRequirements() const {
    double grainRequired = GRAIN_PER_KG * Animal::getWeight();

    std::stringstream ss;

    ss << "Requires " << grainRequired << " kg of grain \n";

    return ss.str();
}
