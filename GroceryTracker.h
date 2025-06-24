// GroceryTracker.h
// Author: Scott Leishman
// Course: CS210 – Programming Languages (C++)
// School: Southern New Hampshire University
// Date: June 19, 2025
// Project: CS210 Project Three – Corner Grocer Tracker
//
// Declaration of GroceryTracker, which reads an input file of grocery items,
// counts frequencies, writes a backup, and provides query/display methods.

#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <string>
#include <map>

class GroceryTracker {
private:
    // Map from item name → purchase count
    std::map<std::string, int> frequencyMap;

    // Load each word from 'filename' into frequencyMap (throws on I/O errors)
    void loadInputFile(const std::string& filename);

    // Write frequencyMap contents to 'backupFilename' (throws on I/O errors)
    void writeBackupFile(const std::string& backupFilename) const;

public:
    // Constructor: loads data then writes backup
    GroceryTracker(const std::string& inputFilename,
                   const std::string& backupFilename);

    // Return how many times 'item' appears (0 if not present)
    int  getItemFrequency(const std::string& item) const;

    // Print every item–count pair on its own line
    void printAllFrequencies() const;

    // Print a histogram: item name followed by '*' repeated count times
    void printHistogram() const;
};

#endif // GROCERY_TRACKER_H
