#pragma once
#include <iostream>
#include <string>
using namespace std;

class ATM {
private:
    string atmID;
    int balance;
    int minWithdrawal;
    int maxWithdrawal;
    int denominations[10] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000 };
public:
    ATM(string id, int initialBalance, int minWithdraw, int maxWithdraw);
    void loadMoney(int denomination, int count);
    bool withdrawMoney(int amount);
    string toString();
};

