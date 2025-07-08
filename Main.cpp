#include <iostream>
#include "Helper.h"

int main() {
    char userInput[100];

    std::cout << "Enter an integer: ";
    std::cin.getline(userInput, 100);
    if (Helper::IsInteger(userInput)) {
        int val = std::atoi(userInput);
        std::cout << "You entered a valid integer: " << val << "\n";
        std::cout << "Binary representation:\n";
        Helper::PrintIntegerBinary(&val);
    }
    else {
        std::cout << "Invalid integer input.\n";
    }

    int nums[] = { 42, 17, 8, 99, 5 };
    Helper::BubbleSort(nums, 5);
    std::cout << "Sorted numbers: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << "\n";

    Helper::PauseConsoleWindow();
    return 0;
}
