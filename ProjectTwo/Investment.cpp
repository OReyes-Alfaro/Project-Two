#include "Investment.h"

using namespace std;

Investment::Investment(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterestRate, int t_years)
    : m_initialInvestment(t_initialInvestment), m_monthlyDeposit(t_monthlyDeposit),
    m_annualInterestRate(t_annualInterestRate), m_years(t_years) {}

void Investment::display_input_data() const {
    cout << fixed << setprecision(2);
    cout << "Initial Investment Amount: $" << m_initialInvestment << endl;
    cout << "Monthly Deposit: $" << m_monthlyDeposit << endl;
    cout << "Annual Interest: " << m_annualInterestRate << "%" << endl;
    cout << "Number of Years: " << m_years << endl;
}

void Investment::calculate_without_monthly_deposits() const {
    cout << "\n\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << "=======================================================\n";
    cout << "Year     Year End Balance     Year End Earned Interest\n";
    cout << "-------------------------------------------------------\n";

    double year_end_balance = m_initialInvestment;
    double earned_interest;

    for (int i = 1; i <= m_years; ++i) {
        earned_interest = year_end_balance * (m_annualInterestRate / 100);
        year_end_balance += earned_interest;
        cout << i << setw(15) << "$" << year_end_balance << setw(20) << "$" << earned_interest << "\n";
    }
}

void Investment::calculate_with_monthly_deposits() const {
    cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
    cout << "====================================================\n";
    cout << "Year     Year End Balance     Year End Earned Interest\n";
    cout << "------------------------------------------------------\n";

    double year_end_balance = m_initialInvestment;
    double monthly_interest_rate = (m_annualInterestRate / 100) / 12;
    double total_interest;

    for (int i = 1; i <= m_years; ++i) {
        total_interest = 0.0;

        for (int j = 0; j < 12; ++j) {
            double interest = (year_end_balance + m_monthlyDeposit) * monthly_interest_rate;
            total_interest += interest;
            year_end_balance += m_monthlyDeposit + interest;
        }

        cout << i << setw(15) << "$" << year_end_balance << setw(20) << "$" << total_interest << "\n";
    }
}
