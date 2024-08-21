#ifndef INVESTMENT_H_
#define INVESTMENT_H_

#include <iostream>
#include <iomanip>
#include <memory>

class Investment {
public:
    Investment(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterestRate, int t_years);

    void display_input_data() const;
    void calculate_without_monthly_deposits() const;
    void calculate_with_monthly_deposits() const;

private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterestRate;
    int m_years;
};

#endif // INVESTMENT_H_
