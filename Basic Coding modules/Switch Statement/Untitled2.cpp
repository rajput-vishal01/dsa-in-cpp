#include <iostream>

int main() {
    // Total amount of money needed
    int amount = 1550;

    // Initialize variables to count notes
    int count_100 = 0, count_50 = 0, count_20 = 0, count_10 = 0, count_1 = 0;

    // Calculate the number of each denomination needed
    while (amount > 0) {
        switch (amount) {
            case 1330:
                count_100 = amount / 100;
                amount -= count_100 * 100;
                break;
            case 1230 ... 1329:
                count_50 = amount / 50;
                amount -= count_50 * 50;
                break;
            case 1210 ... 1229:
                count_20 = amount / 20;
                amount -= count_20 * 20;
                break;
            case 121 ... 1209:
                count_10 = amount / 10;
                amount -= count_10 * 10;
                break;
            default:
                count_1 = amount;
                amount = 0;
                break;
        }
    }

    // Output the result
    std::cout << "Number of $100 notes: " << count_100 << std::endl;
    std::cout << "Number of $50 notes: " << count_50 << std::endl;
    std::cout << "Number of $20 notes: " << count_20 << std::endl;
    std::cout << "Number of $10 notes: " << count_10 << std::endl;
    std::cout << "Number of $1 notes: " << count_1 << std::endl;

    return 0;
}
