#include "Animal.h"

Animal::Animal(std::string name, double weight): name(name), weight(weight){}


std::string Animal:: getName() const{
    return name;

}
double Animal:: getWeight() const{
    return weight;
}
