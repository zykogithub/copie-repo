#include <iostream>
using namespace std;

class bank_account {
public:
    bank_account(float b) : balance(b) {}

    void ba_deposit(float x) {
        balance += x;
    }

    void ba_withdraw(float x) {
        if (x <= balance) {
            balance -= x;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    float ba_get() {
        return balance;
    }

private:
    float balance;
};

int main() {
    bank_account first_account(0.0);
    bank_account second_account(100.0);
    first_account.ba_deposit(100.0);
    first_account.ba_withdraw(50.0);
    second_account.ba_deposit(100.0);
    second_account.ba_withdraw(50.0);
    cout << "First Account Balance: " << first_account.ba_get() << endl;
    cout << "Second Account Balance: " << second_account.ba_get() << endl;
    return 0;
}
