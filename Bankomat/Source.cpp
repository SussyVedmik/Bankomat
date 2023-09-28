#include "bankomat.h"

int main() {
    ATM myATM("ATM001", 5000, 100, 5000);
    int denomination;
    int numberBills;
    int userhoice;
    int amountMoney;
    cout << "Balance 5000 minimum amount for withdrawal 100 \nmaximum amount for withdrawal 5000" << endl;
    do
    {
        cout << endl << "0 - End ATM operation" << endl;
        cout << "1 - Load money into an ATM" << endl;
        cout << "2 - Withdraw money from an ATM" << endl;
        cout << "3 - Clear the console" << endl;
        cout << "4 - Method toString (Balance)" << endl << endl;

        cout << "Pick a point: ";
        cin >> userhoice;

        switch (userhoice)
        {
        case 0:
        {
            cout << "Goodbye" << endl;
            break;
        }
        case 1:
        {
            do
            {
                cout << "Enter the denomination: ";
                cin >> denomination;
                if (denomination < 0)
                    cout << "The nominal value cannot be less than 0" << endl;
            } while (denomination < 0);

            do
            {
                cout << "Enter the number of bills: ";
                cin >> numberBills;
                if (numberBills <= 0)
                    cout << "The number of bills cannot be less than 0" << endl;
            } while (numberBills <= 0);

            myATM.loadMoney(denomination, numberBills);
            break;
        }
        case 2:
        {
            do
            {
                cout << "Enter the amount: ";
                cin >> amountMoney;
                if (amountMoney < 0)
                    cout << "The sum cannot be less than 0" << endl;
            } while (amountMoney < 0);

            int withdrawalAmount = amountMoney;
            if (myATM.withdrawMoney(withdrawalAmount)) {
                cout << "Suma " << withdrawalAmount << " was taken out" << endl;
            }

            break;
        }
        case 3:
        {
            system("cls");
            break;
        }
        case 4:
        {
            cout << myATM.toString() << endl;
            break;
        }
        default:
        {
            cout << "I don't have that item" << endl;
        }
        }

    } while (userhoice != 0);
    return 0;
}