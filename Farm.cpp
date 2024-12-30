#include "Farm.h"

void Farm::addField(Field const &field) {

    fields.push_back(field);

}

void Farm::addAnimal(Animal *animal) {
    animals.push_back(animal);
}

// Returns a string summarizing all the fields and animals on the farm.
std::string Farm::toString() const {
    std::stringstream ss;

    ss << "Farm Details:\n"; // Add newline for better formatting

    if (fields.empty() && animals.empty()) {
        ss << "The farm is empty!\n";
    } else {
        // Output field details
        for (const Field &field : fields) {
            ss << field.toString() << "\n";
        }

        // Add a newline before listing animals
        ss << "\nAnimals:\n";

        if (animals.empty()) {
            ss << "No animals on the farm!\n";
        } else {
            for (const Animal *animal : animals) {
                ss << animal->toString();
                ss << "Dietary Requirements: " << animal->dietaryRequirements() << "\n";
            }
        }
    }

    return ss.str();
}


double Farm::totalFarmYield() const {
    double totalFarmYield = 0.0;

    for (const Field &field : fields) {
        totalFarmYield += field.totalYield();
    }

    return totalFarmYield; //Calculates and returns the total yield from all fields.

}

//    Function to get all animals in the farm (returns a reference to the vector)
const std::vector<Animal*>& Farm::getAnimals() const {
    return animals;
}

