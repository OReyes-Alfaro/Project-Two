#include <iostream>
#include <memory>

#include "Investment.h"

using namespace std;

// Function to get validated double input
double get_validated_double_input(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        // Check if input is a valid number
        if (cin.fail() || value < 0) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a positive number.\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any remaining input
            return value;
        }
    }
}

// Function to get validated integer input
int get_validated_integer_input(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        // Check if input is a valid number
        if (cin.fail() || value < 0) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a positive integer.\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any remaining input
            return value;
        }
    }
}


int main() {
    double initial_investment, monthly_deposit, annual_interest_rate;
    int years;
    string user_response;

    do {
        cout << "Data Input\n";
        cout << "==============================\n";
        cout << "Enter Initial Investment Amount: ";
            
        // Get validated inputs
        initial_investment = get_validated_double_input("Enter Initial Investment Amount: ");
        monthly_deposit = get_validated_double_input("Enter Monthly Deposit: ");
        annual_interest_rate = get_validated_double_input("Enter Annual Interest Rate (%): ");
        years = get_validated_integer_input("Enter Number of Years: ");

        auto investment = make_unique<Investment>(initial_investment, monthly_deposit, annual_interest_rate, years);

        cout << "\nInvestment Data\n";
        cout << "===============\n";
        investment->display_input_data();

        cout << "\nPress any key to continue...";
        cin.get();    // Wait for user to press a key

        investment->calculate_without_monthly_deposits();
        investment->calculate_with_monthly_deposits();        

        cout << "\nDo you want to quit? (yes to quit, any other key to enter new investment): ";
        cin >> user_response;

    } while (user_response != "yes");

    cout << "Application quit.\n";

    return EXIT_SUCCESS;
}
