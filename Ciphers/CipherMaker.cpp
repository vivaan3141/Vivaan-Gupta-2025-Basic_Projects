// In this program, you can assign symbols to each letter (or how many letters you want), and make a cipher, which we can encode and decode.
// Make your own cipher!!!
using namespace std;
# include <iostream>
# include <string>

string lower="abcdefghiklmnopqrstuvwxyz";
string upper= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int locNum(char ch) {
    for (int i = 0; i < lower.length(); i++) {
        if (lower[i] == ch || upper[i] == ch) {
            return i;
        }
    }
}

string encode(char cipher[], int size, string code) {
    char result[size];
    int numSet[size];
    for (int i=0; i<size; i++) {
        numSet[i]=locNum(code[i]);
        result[i]=cipher[numSet[i]];
    }
    return result;
}


int symNum(char ch, char cipher[]) {
    for (int i = 0; i < lower.length(); i++) {
        if (cipher[i] == ch) {
            return i;
        }
    }
}

string decode(char cipher[], int size, string code) {
    char result[size];
    int numSet[size];
    for (int i=0; i<size; i++) {
        numSet[i]=symNum(code[i], cipher);
        result[i]=lower[numSet[i]];
    }
    return result;
}

int main() {
    cout<<"How many letters?"<<endl;
    int size;
    cin>>size;
    char cipher[size];

    for (int i=0; i<size; i++) {
        cout<<lower[i]<<":"<< endl;
        cin>>cipher[i];
    }
    string word;
    char action='e';

    while (true) {
        cout<<"Encode or Decode. E/D"<<endl;
        cin>>action;
        if (action=='E'||action=='e') {
            cout<<"Word: "<< endl;
            cin>>word;
            cout<<encode(cipher, word.length(), word)<<endl;
        }else if (action=='D'||action=='d') {
            cout<<"Word: "<< endl;
            cin>>word;
            cout<<decode(cipher, word.length(), word)<<endl;
        }else {
            cout<<"Invalid input. Please try again."<<endl;
        }
    }
}








