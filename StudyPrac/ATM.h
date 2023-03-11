#pragma once

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class ATM {

private:
    unordered_map<string, int> bills;
    const string billNames[6] = { "5000", "2000", "1000", "500", "200", "100" };

public:
    ATM(int billsQuantity[]) {
        for (int i = 0; i < 6; i++) {
            bills[billNames[i]] = billsQuantity[i];
        }
    }

    void changeBillQuantity(string bill, int newValue) {
        bills[bill] = newValue;
    }

    int getBalance() {
        int balance = 0;

        for (const auto& billName : billNames) {
            int billValue = 0;

            try {
                billValue = stoi(billName);
            }
            catch (const exception& ex) {
                cout << ex.what() << endl;
            }

            balance += bills[billName] * billValue;
        }

        return balance;
    }
};