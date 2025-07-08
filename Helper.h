#pragma once

#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstring>
#include <cctype>

namespace Helper {

    static bool IsInteger(const char* input) {
        if (input == nullptr || *input == '\0') return false;
        int i = 0;
        if (input[0] == '-' || input[0] == '+') i = 1;

        for (; input[i] != '\0'; ++i) {
            if (!std::isdigit(input[i])) return false;
        }
        return true;
    }

    static bool isPositiveInteger(const char* input) {
        if (!IsInteger(input)) return false;
        int value = std::atoi(input);
        return value > 0;
    }

    static void PrintIntegerBinary(int* num) {
        if (!num) return;
        for (int i = 31; i >= 0; --i) {
            std::cout << ((*num >> i) & 1);
        }
        std::cout << "\n";
    }

    static void BubbleSort(int* arr, int size) {
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

    static void ClearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    static void PauseConsoleWindow() {
        std::cout << "Press Enter to continue...";
        std::cin.get();
    }
}
