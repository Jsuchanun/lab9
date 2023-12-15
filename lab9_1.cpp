#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double initialLoan, interestRate, paymentPerYear;

    cout << "Enter initial loan: ";
    cin >> initialLoan;

    cout << "Enter interest rate per year (%): ";
    cin >> interestRate;

    cout << "Enter amount you can pay per year: ";
    cin >> paymentPerYear;

    cout << setw(13) << left << "EndOfYear#";
    cout << setw(13) << left << "PrevBalance";
    cout << setw(13) << left << "Interest";
    cout << setw(13) << left << "Total";
    cout << setw(13) << left << "Payment";
    cout << setw(13) << left << "NewBalance";
    cout << "\n";

    cout << fixed << setprecision(2);

    double prevBalance = initialLoan;
    int year = 1;

    while (prevBalance > 0) {
        double interest = (interestRate / 100) * prevBalance;
        double total = prevBalance + interest;
        double actualPayment = min(paymentPerYear, total);

        cout << setw(13) << left << year;
        cout << setw(13) << left << prevBalance;
        cout << setw(13) << left << interest;
        cout << setw(13) << left << total;
        cout << setw(13) << left << actualPayment;

        prevBalance = total - actualPayment;
        
        cout << setw(13) << left << prevBalance;
        cout << "\n";

        year++;
    }

    return 0;
}