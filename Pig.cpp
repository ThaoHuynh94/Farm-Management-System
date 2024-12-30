#include "Pig.h"

// Constructor
Pig::Pig(std::string name, double weight) : Animal(name, weight) {}

// toString Method
std::string Pig::toString() const {
    std::stringstream ss;
    ss << "Pig: " << Animal::getName() << ", Weight: " << Animal::getWeight() << " kg\n"; // Ensure consistent formatting
    return ss.str();
}

// Dietary Requirements Method
std::string Pig::dietaryRequirements() const {

    double mixedFeedRequired = MIXED_FEED_PER_KG * Animal::getWeight();

    std::stringstream ss;

    ss << "Requires " << mixedFeedRequired << " kg of mixed feed\n";

    return ss.str();
}
