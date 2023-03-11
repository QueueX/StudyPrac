#pragma once

#include <string>

using namespace std;

class User {
private:
    string cartId;
    int pin;
    int balance;

public:
    User(string cartId, int pin, int balance) {
        this->cartId = cartId;
        this->pin = pin;
        this->balance = balance;
    }

    string getCartId() const {
        return cartId;
    }

    int getPin() const {
        return pin;
    }

    int getBalance() const {
        return balance;
    }

    void setPin(int newPin) {
        pin = newPin;
    }

    void setBalance(int newBalance) {
        balance = newBalance;
    }
};

