

using namespace std;
# include <iostream>
# include <string>
class BankCustomer {
    string name;
    int balance;
    int pinNum;

public:
    BankCustomer (string n, int bal, int pin) {
        name = n;
        balance=bal;
        pinNum=pin;
    }

    BankCustomer () {
        name = "";
        balance=0;
        pinNum=0;
    }

    bool isValidPin(int p) {
        if (p==pinNum) {
            return true;
        } else {
            return false;
        }
    }

    void deposit(int amount) {
        balance=balance+amount;
        cout<<balance<<endl;
    }

    void withdraw(int amount) {
        balance = balance-amount;
    }
    int getBalance() {return balance;}
    string getName() {return name;}
};

int transfer(BankCustomer *customer){
    int pin;

    // c1 goes to atm
    cout << "Type pin " << endl;
    cin >> pin;

    int action;

    int placerW;

    int placerD;

    if (customer->isValidPin(pin)==true) {
        cout <<" Your pin is valid, you can withdraw/deposit."<< endl;
        cout << " Would you like to withdraw or deposit. Press 1 for withdrawals, and 2 for desposits" << endl;
        cin >> action;
        if (action==1) {
            cout << "How much do you want to withdraw?" << endl;
            cin >> placerW;
            customer->withdraw(placerW);
            cout<<"Your balance is "<<customer->getBalance()<<endl;
        }else if (action==2) {
            cout << "How much do you want to deposit?" << endl;
            cin >> placerD;
            customer->deposit(placerD);

            cout<<"Your balance is "<<customer->getBalance()<<endl;

        }else{
            cout<< "Sorry. Please press either 1 or 2 to make and action.";
            cout<<"Your balance is "<<customer->getBalance()<<endl;

        }

    } else {
        cout <<" Your pin is not valid, you cannot withdraw/deposit" << endl;
        exit;

    }
}

BankCustomer inputCustomerDetails() {
    string name;
    int balance;
    int pin;
    cout<<"****"<<endl;
    cout<<"Name of the customer: ";
    cin >> name;
    cout <<" Enter pin: ";
    cin >>pin;
    cout<<"Enter balance: ";
    cin >> balance;
    cout<<"Customer added, thank you!" <<endl;
    return BankCustomer(name,balance,pin);
}

BankCustomer* getCustomer(BankCustomer customers[100], int numCustomer, string name) {
    for (int i=0; i<numCustomer; i++) {
        if (customers[i].getName() == name) {
            return &customers[i];
        }
    }
    return NULL;
}

int main() {
    BankCustomer customers[100];
    int numCustomer;
    cout<<"How many customers are there? ";
    cin>>numCustomer;

    for (int i=0;i<numCustomer;i++) {
        customers[i] = inputCustomerDetails();
    }

    cout<<"Bank Session."<< endl;
    string name;
    while (true) {

        cout<<"What is your name:" << endl;
        cin>>name;

        BankCustomer* c = getCustomer(customers, numCustomer, name);

        if (c== NULL) {
            cout << "You don't exist in bank. You're fault for not joining us."<< endl;
            cout << "TRY AGAIN."<< endl;
        } else {
            transfer(c);
        }
    }
}
