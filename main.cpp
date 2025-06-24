// main.cpp
// Presents a menu for querying grocery purchase frequencies

#include "GroceryTracker.h"
#include <iostream>
#include <limits>
#include <cctype>

// Display the menu options
void showMenu() {
    std::cout << "\n--- Corner Grocer Tracker ---\n"
              << "1. Find frequency of a single item\n"
              << "2. Print all item frequencies\n"
              << "3. Print histogram\n"
              << "4. Exit\n"
              << "Choose an option (1-4): ";
}

// Loop until the user enters a valid choice (1-4)
int getValidatedChoice() {
    int choice;
    while (true) {
        if (std::cin >> choice && choice >= 1 && choice <= 4) {
            return choice;
        }
        std::cout << "Invalid choice. Please enter 1, 2, 3, or 4: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Loop until the user enters a non-empty, alphabetic item name
std::string getValidatedItem() {
    std::string item;
    while (true) {
        std::cin >> item;
        bool valid = !item.empty();
        for (char c : item) {
            if (!std::isalpha(static_cast<unsigned char>(c))) {
                valid = false;
                break;
            }
        }
        if (valid) {
            return item;
        }
        std::cout << "Invalid item. Please enter letters only: ";
    }
}

int main() {
    // Match your actual input filename in the project
    const std::string inputFile  = "Grocery.txt";
    const std::string backupFile = "frequency.dat";

    // Construct the tracker (handles file exceptions internally)
    GroceryTracker tracker(inputFile, backupFile);

    int choice;
    do {
        showMenu();
        choice = getValidatedChoice();

        switch (choice) {
            case 1: {
                std::cout << "Enter item to search: ";
                std::string item = getValidatedItem();
                int freq = tracker.getItemFrequency(item);
                std::cout << item << " appears " << freq << " times.\n";
                break;
            }
            case 2:
                tracker.printAllFrequencies();
                break;
            case 3:
                tracker.printHistogram();
                break;
            case 4:
                std::cout << "Goodbye!\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

