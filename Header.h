#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <sstream>
#include <iomanip>

/*
 Author: Scott Leishman
 Course: SNHU CS210 – Programming Languages
 Assignment: Project One – Chada Tech Clocks
 Date: 2025-05-21

 Defines the base Clock class and two derived classes (Clock12 and Clock24)
 for displaying times in 12-hour and 24-hour formats.
*/

class Clock {
public:
    int hours;   // hours component
    int minutes; // minutes component
    int seconds; // seconds component

    // Initialize to h:m:s
    Clock(int h, int m, int s);
    virtual ~Clock() = default;
};

class Clock12 : public Clock {
public:
    std::string meridian; // "AM" or "PM"

    // Build from 24-hour time
    Clock12(int h, int m, int s);

    // Add delta hours/minutes/seconds (default = 1)
    void addHour(int delta = 1);
    void addMinute(int delta = 1);
    void addSeconds(int delta = 1);

    // Return formatted "HH:MM:SS AM/PM"
    std::string getTime() const;
};

class Clock24 : public Clock {
public:
    // Build from 24-hour time
    Clock24(int h, int m, int s);

    void addHour(int delta = 1);
    void addMinute(int delta = 1);
    void addSeconds(int delta = 1);

    // Return formatted "HH:MM:SS"
    std::string getTime() const;
};

#endif // HEADER_H
#pragma once
