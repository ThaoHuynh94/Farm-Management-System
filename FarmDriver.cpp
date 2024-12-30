#include "Pig.h"
#include "Cow.h"
#include "Chicken.h"
#include "Animal.h"
#include "Farm.h"
#include "Field.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Function prototypes
/**
 * @brief Reads crop data from a CSV file and adds each crop field to the provided Farm object.
 *
 * This function opens a CSV file specified by `filename`, reads each line,
 * extracts crop details (such as crop name, harvest time, yield per acre, price per unit, and field size),
 * and creates a `Field` object for each row. Each `Field` is then added to the `farm` object.
 *
 * @param filename The name of the CSV file containing crop data.
 * @param farm A reference to a `Farm` object where each `Field` will be added.
 *
 * @note The CSV file should have crop information in the following order per line:
 *       crop name, harvest time (days), yield per acre (units), price per unit ($), field size (acres).
 *       Each field should be separated by commas.
 */
void readCropsFromFile(const std::string& filename, Farm& farm);

/**
 * @brief Reads animal data from a CSV file and dynamically creates and adds each animal to the provided Farm object.
 *
 * This function opens a CSV file specified by `filename`, reads each line,
 * extracts animal details (such as animal type, name, and weight),
 * and dynamically allocates a `Cow`, `Chicken`, or `Pig` object based on the type.
 * The created animal is added to the `farm` object.
 *
 * @param filename The name of the CSV file containing animal data.
 * @param farm A reference to a `Farm` object where each created `Animal` will be added.
 *
 * @note The CSV file should have animal information in the following order per line:
 *       animal type (Cow, Chicken, Pig), animal name, weight (kg).
 *       Each field should be separated by commas.
 */
void readAnimalsFromFile(const std::string& filename, Farm& farm);

int main() {
    // Step 1: Create a Farm object
    Farm farm;

    // Step 2: Call readCropsFromFile() to populate the farm with fields
    readCropsFromFile("data/crops.csv", farm);

    // Step 3: Call readAnimalsFromFile() to add animals to the farm
    readAnimalsFromFile("data/animals.csv", farm);

    // Step 4: Print the farm summary using farm.toString()
    std::cout << farm.toString();

    // Step 5: Display the total farm yield using farm.totalFarmYield()
    std::cout << "\nTotal Farm Yield: " << farm.totalFarmYield() << " units\n";

    // Step 6: delete the animal pointers to avoid memory leak
    for (Animal* animal : farm.getAnimals()) {
        delete animal;  // Free memory allocated for each animal
    }


    return 0;
}

// Function to read crop data from CSV and add fields to the farm
void readCropsFromFile(const std::string& filename, Farm& farm) {
    // ifstream stands for input file stream
    // It is a file stream class from the <fstream> library used to read files
    // By passing filename to myCropFile object, the file opens in read-only mode.

    std::ifstream myCropFile(filename);

    // The is_open() method is a member function of the ifstream class
    // Returns true if the file is open, false otherwise.

    if (!myCropFile.is_open()) {
        std::cerr << "Could not open file " << filename << std::endl;
        return;
    }

    // Variable to store each line of the file
    std::string line;

    // std::getline() is a free function (standalone function) in the C++ Standard Library
    // which works with any input stream, including std::ifstream
    // It reads a line from myCropFile and stores it in line
    // This process continues until std::getline can no longer read lines

    // after each iteration of the statement std::getline(myCropFile, line),
    // the variable "line" contains one line of text from myCropFile

    while (std::getline(myCropFile, line)) {

        // initializes ss with the contents of line, which holds one line of data from the CSV file.
        std::stringstream ss(line);

        std::string cropName;
        int harvestTime;
        double yieldPerAcre, pricePerUnit, fieldSize;

        // Example (for the second iteration): Corn,120,150.0,2.5,10.0
        // line = "Corn,120,150.0,2.5,10.0"

        // The ss (stringstream) is initialized with this string, so it contains all the characters from the "line"

        if (std::getline(ss, cropName, ',')
            // std::getline(ss, cropName, ',') is used specifically to extract the cropName

            && ss >> harvestTime && ss.ignore()
            // Reads the next value from ss and tries to assign it to the variable harvestTime
            // ss.ignore(): ignore the comma (,) after the harvestTime value

            && ss >> yieldPerAcre && ss.ignore()
            // ss >> yieldPerAcre reads the next part of the string "150.0" from ss and assigns it to yieldPerAcre
            // ss.ignore(): ignore the comma (,) after the yieldPerAcre value

            && ss >> pricePerUnit && ss.ignore()
            // ss >> pricePerUnit reads the next part of the string "2.5" from ss and assigns it to pricePerUnit.
            // ss.ignore(): ignore the comma (,) after the pricePerUnit value

            && ss >> fieldSize) {
            // ss >> fieldSize reads the next part of the string "10.0" from ss and assigns it to fieldSize.

            // If all extractions are successful, create a Field object and add it to the farm

            Field field(cropName, harvestTime, yieldPerAcre, pricePerUnit, fieldSize);

            farm.addField(field);
        }
    }

    // Once done, close the file
    myCropFile.close();
}

// Function to read animal data from CSV and add animals to the farm
void readAnimalsFromFile(const std::string& filename, Farm& farm) {
    // By passing filename to myAnimalFile object, the file opens in read-only mode.
    std::ifstream myAnimalFile(filename);

    // check if the file was opened successfully
    if (!myAnimalFile) {
        std::cerr << "Could not open file " << filename << std::endl;
        return;
    }

    // Variable to store each line of the file
    std::string line;

    // Iterate over each line of the file
    // std::getline reads one line from the file into the 'line' variable



    while (std::getline(myAnimalFile, line)) {
        // Use stringstream to process the line

        std::stringstream ss(line);

        std::string animalType, name;

        double weight;

        // Example (for the second iteration): Pig,Snorty,186.4

        Animal* animal = nullptr;


        if (std::getline(ss, animalType, ',')
            // std::getline(ss, animalType, ',') is used specifically to extract the animalType

            && std::getline(ss, name, ',')
            // This function continues to read characters from the stringstream until it encounters a comma ","
            // and stores the result in the name variable.
            // Result: name = "Snorty"

            && ss >> weight) {
            // ss >> weight reads the next part of the string "186.4" from ss and assigns it to weight
            // Result: weight = 186.4

            // If all extractions are successful, create an animal pointer


            // Determine the type of animal based on animalType
            // and create the corresponding Animal subclass object

            if (animalType == "Cow") {
                animal = new Cow(name, weight);
            } else if (animalType == "Chicken") {
                animal = new Chicken(name, weight);
            } else if (animalType == "Pig") {
                animal = new Pig(name, weight);
            }

            // add the animal pointer into the farm

            if (animal) {
                farm.addAnimal(animal);

            }

        }

    }

    // Once done, close the file
    myAnimalFile.close();

}

//OUTPUT:
/*
Farm Details:
Field size: 10 acres
Crop: Corn, Harvest Time: 120 days, Yield: 150 units per acre, Price: $2.5 per unit
Total Value: $ 3750

Field size: 5 acres
Crop: Wheat, Harvest Time: 90 days, Yield: 100 units per acre, Price: $1.8 per unit
Total Value: $ 900

Field size: 8 acres
Crop: Barley, Harvest Time: 100 days, Yield: 110 units per acre, Price: $2 per unit
Total Value: $ 1760

Field size: 12 acres
Crop: Soybean, Harvest Time: 130 days, Yield: 200 units per acre, Price: $3 per unit
Total Value: $ 7200

Field size: 6 acres
Crop: Rice, Harvest Time: 150 days, Yield: 180 units per acre, Price: $1.5 per unit
Total Value: $ 1620

Field size: 4 acres
Crop: Oats, Harvest Time: 80 days, Yield: 90 units per acre, Price: $2.2 per unit
Total Value: $ 792

Field size: 7 acres
Crop: Rye, Harvest Time: 75 days, Yield: 85 units per acre, Price: $2.1 per unit
Total Value: $ 1249.5

Field size: 9 acres
Crop: Canola, Harvest Time: 140 days, Yield: 130 units per acre, Price: $2.8 per unit
Total Value: $ 3276

Field size: 11 acres
Crop: Millet, Harvest Time: 70 days, Yield: 95 units per acre, Price: $1.9 per unit
Total Value: $ 1985.5

Field size: 3 acres
Crop: Sorghum, Harvest Time: 85 days, Yield: 105 units per acre, Price: $2.3 per unit
Total Value: $ 724.5

Field size: 10 acres
Crop: Peas, Harvest Time: 60 days, Yield: 70 units per acre, Price: $2.7 per unit
Total Value: $ 1890

Field size: 8 acres
Crop: Lentils, Harvest Time: 95 days, Yield: 80 units per acre, Price: $2 per unit
Total Value: $ 1280

Field size: 15 acres
Crop: Cotton, Harvest Time: 180 days, Yield: 300 units per acre, Price: $4 per unit
Total Value: $ 18000

Field size: 20 acres
Crop: Sugarcane, Harvest Time: 200 days, Yield: 500 units per acre, Price: $3.5 per unit
Total Value: $ 35000

Field size: 13 acres
Crop: Tobacco, Harvest Time: 160 days, Yield: 250 units per acre, Price: $5 per unit
Total Value: $ 16250

Field size: 5 acres
Crop: Maize, Harvest Time: 110 days, Yield: 140 units per acre, Price: $2.4 per unit
Total Value: $ 1680

Field size: 6 acres
Crop: Sunflower, Harvest Time: 125 days, Yield: 160 units per acre, Price: $2.6 per unit
Total Value: $ 2496

Field size: 3 acres
Crop: Coffee, Harvest Time: 210 days, Yield: 60 units per acre, Price: $10 per unit
Total Value: $ 1800

Field size: 4 acres
Crop: Cocoa, Harvest Time: 230 days, Yield: 50 units per acre, Price: $15 per unit
Total Value: $ 3000

Field size: 7 acres
Crop: Tea, Harvest Time: 240 days, Yield: 45 units per acre, Price: $8 per unit
Total Value: $ 2520


Animals:
Pig: Snorty, Weight: 186.4 kg
Dietary Requirements: Requires 9.32 kg of mixed feed

Pig: Chops, Weight: 170.4 kg
Dietary Requirements: Requires 8.52 kg of mixed feed

Cow: MooMoo, Weight: 503.9 kg
Dietary Requirements: Requires 1259.75 kg of grass

Pig: Piglet, Weight: 197 kg
Dietary Requirements: Requires 9.85 kg of mixed feed

Cow: Clarabelle, Weight: 638 kg
Dietary Requirements: Requires 1595 kg of grass

Cow: Buttercup, Weight: 553.4 kg
Dietary Requirements: Requires 1383.5 kg of grass

Pig: Porky, Weight: 171.1 kg
Dietary Requirements: Requires 8.555 kg of mixed feed

Pig: Wilbur, Weight: 186.5 kg
Dietary Requirements: Requires 9.325 kg of mixed feed

Pig: Gordy, Weight: 176.1 kg
Dietary Requirements: Requires 8.805 kg of mixed feed

Chicken: Fluffy, Weight: 2.6 kg
Dietary Requirements: Requires 0.26 kg of grain

Chicken: Goldie, Weight: 1.9 kg
Dietary Requirements: Requires 0.19 kg of grain

Chicken: Coco, Weight: 3.1 kg
Dietary Requirements: Requires 0.31 kg of grain

Pig: Porky, Weight: 173.1 kg
Dietary Requirements: Requires 8.655 kg of mixed feed

Cow: Marigold, Weight: 727.2 kg
Dietary Requirements: Requires 1818 kg of grass

Pig: Porky, Weight: 119.6 kg
Dietary Requirements: Requires 5.98 kg of mixed feed

Pig: Truffle, Weight: 143.3 kg
Dietary Requirements: Requires 7.165 kg of mixed feed

Chicken: Feathers, Weight: 2 kg
Dietary Requirements: Requires 0.2 kg of grain

Chicken: Pecky, Weight: 2.6 kg
Dietary Requirements: Requires 0.26 kg of grain

Pig: Truffle, Weight: 157.6 kg
Dietary Requirements: Requires 7.88 kg of mixed feed

Pig: Porky, Weight: 140.5 kg
Dietary Requirements: Requires 7.025 kg of mixed feed

Chicken: Clucky, Weight: 1.9 kg
Dietary Requirements: Requires 0.19 kg of grain

Cow: Ginger, Weight: 674.2 kg
Dietary Requirements: Requires 1685.5 kg of grass

Cow: Rosie, Weight: 735.1 kg
Dietary Requirements: Requires 1837.75 kg of grass

Cow: Ginger, Weight: 596 kg
Dietary Requirements: Requires 1490 kg of grass

Pig: Porky, Weight: 139.3 kg
Dietary Requirements: Requires 6.965 kg of mixed feed

Cow: Ginger, Weight: 588.8 kg
Dietary Requirements: Requires 1472 kg of grass

Pig: Porky, Weight: 183.8 kg
Dietary Requirements: Requires 9.19 kg of mixed feed

Chicken: Polly, Weight: 2.3 kg
Dietary Requirements: Requires 0.23 kg of grain

Chicken: Eggsy, Weight: 2.5 kg
Dietary Requirements: Requires 0.25 kg of grain

Cow: Daisy, Weight: 630.3 kg
Dietary Requirements: Requires 1575.75 kg of grass

Chicken: Goldie, Weight: 2.7 kg
Dietary Requirements: Requires 0.27 kg of grain

Cow: Rosie, Weight: 708.8 kg
Dietary Requirements: Requires 1772 kg of grass

Chicken: Chirpy, Weight: 1.7 kg
Dietary Requirements: Requires 0.17 kg of grain

Pig: Piglet, Weight: 161.9 kg
Dietary Requirements: Requires 8.095 kg of mixed feed


Total Farm Yield: 31290 units
 */
