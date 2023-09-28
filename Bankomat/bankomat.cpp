#include "bankomat.h"

ATM::ATM(string id, int initialBalance, int minWithdraw, int maxWithdraw) {
    atmID = id;
    balance = initialBalance;
    minWithdrawal = minWithdraw;
    maxWithdrawal = maxWithdraw;
}

void ATM::loadMoney(int denomination, int count) {
    if (denomination < 1 || denomination > 1000 || count < 0) {
        cout << "Incorrect denomination or number of bills" << endl;
        return;
    }
    int index = -1;
    for (int i = 0; i < 10; i++) {
        if (denomination == denominations[i]) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Unsupported rating" << endl;
        return;
    }
    balance += denomination * count;
    cout << "Banknotes in denominations " << denomination << " added to the ATM" << endl;
}

bool ATM::withdrawMoney(int amount) {
    if (amount < minWithdrawal || amount > maxWithdrawal || amount > balance) {
        cout << "Insufficient funds or incorrect amount entered" << endl;
        return false;
    }
    int remainingAmount = amount;
    for (int i = 9; i >= 0; i--) {
        int numNotes = remainingAmount / denominations[i];
        if (numNotes > 0) {
            cout << "Issuance " << numNotes << " banknotes in denominations " << denominations[i] << endl;
            remainingAmount -= numNotes * denominations[i];
            balance -= numNotes * denominations[i];
        }
    }
    return true;
}

string ATM::toString() {
    return "ATM balance " + atmID + ": " + to_string(balance) + " UAH";
}
