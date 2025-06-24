// GroceryTracker.cpp
// Implements GroceryTracker methods declared in GroceryTracker.h

#include "GroceryTracker.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

// Constructor: attempt to load input, then backup; catch and report any I/O errors.
GroceryTracker::GroceryTracker(const std::string& inputFilename,
                               const std::string& backupFilename) {
    try {
        loadInputFile(inputFilename);
    } catch (const std::ios_base::failure& ex) {
        std::cerr << "Error loading '" << inputFilename << "': "
                  << ex.what() << "\n";
    }

    try {
        writeBackupFile(backupFilename);
    } catch (const std::ios_base::failure& ex) {
        std::cerr << "Error writing '" << backupFilename << "': "
                  << ex.what() << "\n";
    }
}

// Read each word (item) from the file and increment its count
void GroceryTracker::loadInputFile(const std::string& filename) {
    std::ifstream in;
    in.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    in.open(filename);
    std::string item;
    while (in >> item) {
        ++frequencyMap[item];
    }
    in.close();
}

// Write all item→count pairs to the backup file
void GroceryTracker::writeBackupFile(const std::string& backupFilename) const {
    std::ofstream out;
    out.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    out.open(backupFilename);
    for (const auto& pair : frequencyMap) {
        out << pair.first << " " << pair.second << "\n";
    }
    out.close();
}

// Return the count for a single item, or 0 if not found
int GroceryTracker::getItemFrequency(const std::string& item) const {
    auto it = frequencyMap.find(item);
    return (it != frequencyMap.end()) ? it->second : 0;
}

// Print each item and its frequency
void GroceryTracker::printAllFrequencies() const {
    for (const auto& pair : frequencyMap) {
        std::cout << pair.first << " " << pair.second << "\n";
    }
}

// Print a text-based histogram for each item
void GroceryTracker::printHistogram() const {
    for (const auto& pair : frequencyMap) {
        std::cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}
