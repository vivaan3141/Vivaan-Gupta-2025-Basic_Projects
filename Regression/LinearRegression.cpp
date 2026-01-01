#include <iostream>
using namespace std;

double slope(double x[], double y[], int n) {
    double product[n], squares[n]; double productSum, squareSum, xSum, ySum=0;
    for(int i=0;i<n;i++) {
        product[i]=x[i]*y[i]; squares[i]=x[i]*x[i];
        squareSum+=squares[i]; productSum+=product[i];
        xSum+=x[i]; ySum+=y[i];
    }
    return ((n*productSum)-(xSum*ySum))/((n*squareSum)-(xSum*xSum));
}
double yInt(double x[], double y[], int n) {
    double m, xSum, ySum=0;
    for(int i=0;i<n;i++) {
        xSum+=x[i]; ySum+=y[i];
    }
    m=slope(x,y,n);
    return (ySum-(m*xSum))/n;
}


int main() {
    int n;
    double xPred;
    cout<<"How many data points?"<<endl;
    cin>>n;
    double x[n],y[n];

    for(int i=0;i<n;i++) {
        cout<<"X value "<<i+1<<endl;
        cin>>x[i];

        cout<<"Y value "<<i+1<<endl;
        cin>>y[i];
    }
    cout<<"Slope = "<<slope(x,y,n)<<endl;
    cout<<"Y int = "<<yInt(x,y,n)<<endl;

    cout<<"X value for prediction:"<<endl;
    cin>>xPred;
    cout<<(xPred*slope(x,y,n))+yInt(x,y,n)<<endl;

}
