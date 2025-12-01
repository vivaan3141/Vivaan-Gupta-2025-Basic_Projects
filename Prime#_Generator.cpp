#include <iostream>
using namespace std;
int main() {
    int num=0;
    int c=0;
    int x=0;
    
    cout << "Number: ";
    cin >> num;
    if (num<=1){
        cout<<"None";
    }
     
    for (int j=2; j<=num; j++){
        c=0;
        for (int i = 2; i <= (j/2); i++) {
            if (j % i==0){
                c=1;
            }
        }
        if (c==0){
            cout<<j<<" is a prime number!"<<endl;
        }
        
     
    }
         cout<<endl;

    return 0;
}
