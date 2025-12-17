#include <iostream>
#include <string>

using namespace std;
int main() {

    string x;
    int y;
    string z[25];
    string alpha[] = {"a", "b","c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    cout<<"Shift value?"<<endl;
    cin>>y;


    for (int i=0; i<25; i++) {
        if (i+y>25) {
            z[i]=alpha[(i+y-25)];
        }else{
            z[i]=alpha[i+y];
        }
    }

    cout<<"Type something, only lowercase"<<endl;
    cin>>x;
    string a[x.size()-1];
    string b[x.size()-1];



    for (int i=0; i<x.size(); i++) {
        a[i]=x.at(i);
    }

    for (int i=0; i<x.size(); i++) {
        for (int j=0; j<25; j++) {
            if (a[i]==alpha[j]) {
                if (j+y>25) {
                    b[i]=alpha[(j+y-25)];
                }else {
                    b[i]=alpha[j+y];
                }
                break;
            }
        }
    }

    cout<<"alpha= "<<alpha<<endl;
    for (int i=0; i<x.size(); i++) {
        cout<<b[i];
    }
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}
