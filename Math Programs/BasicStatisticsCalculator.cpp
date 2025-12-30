#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    cout<<"How many data pts?"<<endl;
    int size;
    cin>>size;
    double mean,median,devsum,sdev,range=0;

    double data[size];
    double deviations[size];

    for (int i=0; i<size; i++) { // Takes in values, and adds values for mean
        cout<<"Data value "<<i<<":"<<endl;
        cin>>data[i];
        mean+=data[i];
    }
  
    mean=mean/size;

    sort(data, data+size); // Sorts data for median

    if (size % 2 == 1) { // Middle or 2 middle for median
         median= data[size / 2];

    } else {
        median= 0.5 * (data[size / 2 - 1] + data[size / 2]);
    }

    for (int i=0; i<size; i++) { // Standard dev. calc for loop
        deviations[i]=data[i]-mean;
        deviations[i]=deviations[i]*deviations[i];
        devsum+=deviations[i];
    }

    sdev=sqrt(devsum/size); // Final sqrt

    range=data[size-1]-data[0]; //Range

    cout<<"Mean: "<<mean<<endl;
    cout<<"Median: "<<median<<endl;
    cout<<"Sdev: "<<sdev<<" or √("<<devsum/size<<")"<<endl;
    cout<<"Range: "<<range<<endl;

}




