#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int prize_money;
    cin >> prize_money;

    double tax_1 = prize_money * 0.22;
    double received_1 = prize_money - tax_1;

    double recognized_expense = prize_money * 0.8;
    double tax_2 = (prize_money - recognized_expense) * 0.22;
    double received_2 = recognized_expense + (prize_money - recognized_expense) - tax_2;

    cout << fixed << setprecision(0) << received_1 << " " << received_2 << endl;

    return 0;
}