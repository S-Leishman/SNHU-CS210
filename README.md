# Grocery App (CS-210 Project 3)

> **Southern New Hampshire University – CS 210 Programming Languages**  
> *Author: <Scott_Leishman>* | *Term: <June 2025>*

---

## 📜 Project Summary
This console-based C++17 program tracks how often each grocery item is purchased.  
It **reads** an input file of item names (one per line), **counts** occurrences with an unordered_map, and allows the user to:

1. Display the frequency of a specific item  
2. Print all items with their purchase counts  
3. Generate a simple text histogram (`*` bars) to a file for visualization  

The goal is to demonstrate file I/O, associative containers, functions, and clean user interaction in C++.

---

## ✅ What I Did Well
* **Clear modular design** – one function per task (`LoadData`, `PrintMenu`, `FindItemCount`, `WriteHistogram`), which keeps `main()` tidy.  
* Used `unordered_map` for O(1) average look-ups instead of nested loops.  
* Added robust input validation so the menu doesn’t crash on bad entries.  
* In-line Doxygen-style comments and consistent naming make the code easy to read.

---

## 🔧 Possible Enhancements
| Area | Improvement | Benefit |
|------|-------------|---------|
| Performance | Reserve bucket count for `unordered_map` | Fewer rehashes for large files |
| Security | Replace plain text input file with CSV and sanitize commas | Prevent malformed data injection |
| Testing | Add Catch2 unit tests for each function | Safer future refactors |
| UX | Color-code the histogram with ANSI escapes | Friendlier terminal output |

These tweaks would tighten runtime efficiency, harden the program against bad data, and improve maintainability.

---

## 🚩 Most Challenging Part & How I Solved It
*Challenge:* Parsing an arbitrary-length file while keeping memory use low.  
*Solution:*  
1. Sketched the flow on paper to avoid nested loops.  
2. Learned `std::getline` + `std::string` trimming from **cppreference**.  
3. Stepped through with the VS Code debugger and watched the map grow.  
Now streaming 100 K lines stays under a few MB of RAM.

Tools I added to my toolkit: **cppreference.com**, VS Code “Watch” window, and Reddit’s r/cpp for quick tips.

---

## 🔄 Transferable Skills
* Practical Git workflow (branch, commit, push)  
* Writing self-documenting C++ with header/implementation separation  
* Using STL containers & algorithms instead of manual loops  
* Defensive programming (input checks, exception handling)

These apply directly to data-processing tasks in other courses or real-world jobs.

---

## 🛠️ Maintainability, Readability, Adaptability
* **Single-responsibility functions** keep code short and testable.  
* All magic numbers are named constants at the top.  
* The data file path is read from one variable, so moving to SQL or JSON later means changing a single point.  
* Comments follow /** … */ Doxygen conventions for potential auto-doc generation.

---

