#pragma once

#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstring>
#include <cctype>

namespace Helper {

    // Validates a char* string to ensure it is a valid integer (positive or negative)
    static bool IsInteger(const char* input) {
        if (input == nullptr || *input == '\0') return false;

        int i = 0;
        if (input[0] == '-' || input[0] == '+') i = 1;

        for (; input[i] != '\0'; ++i) {
            if (!std::isdigit(input[i])) return false;
        }

        return true;
    }

    // Validates that input is a strictly positive integer (no zero)
    static bool isPositiveInteger(const char* input) {
        if (!IsInteger(input)) return false;
        int value = std::atoi(input);
        return value > 0;
    }

    // Print the full 32-bit binary representation of an integer
    static void PrintIntegerBinary(int* num) {
        if (!num) return;

        for (int i = 31; i >= 0; --i) {
            std::cout << ((*num >> i) & 1);
            if (i % 8 == 0 && i != 0) std::cout << " ";
        }
        std::cout << "\n";
    }

    // Sorts an integer array using Bubble Sort algorithm
    static void BubbleSort(int* arr, int size) {
        if (!arr || size < 2) return;

        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // Clears any remaining characters in the input buffer
    static void ClearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Clears the console using platform-specific commands
    static void ClearConsoleWindow() {
#if defined(_WIN32) || defined(_WIN64)
        system("cls");
#else
        system("clear");
#endif
    }

    // Pauses program until the user presses Enter
    static void PauseConsoleWindow() {
        std::cout << "Press Enter to continue...";
        std::cin.get();
    }
}
