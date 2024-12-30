#include "Cow.h"

// Constructor
Cow::Cow(std::string name, double weight) : Animal(name, weight) {}

// toString Method
std::string Cow::toString() const {

    std::stringstream ss;

    ss << "Cow: " << Animal::getName() << ", Weight: " << Animal::getWeight() << " kg\n";

    return ss.str();
}

// Dietary Requirements Method
std::string Cow::dietaryRequirements() const {

    double grassRequired = GRASS_PER_KG * Animal::getWeight();

    std::stringstream ss;

    ss << "Requires " << grassRequired << " kg of grass\n";

    return ss.str();
}
