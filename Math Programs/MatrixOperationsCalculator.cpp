#include <iostream>
using namespace std;
int main() {
    int rows1;
    int col1;
    int rows2;
    int col2;

    int op;


    cout<<"1. Addition"<<endl;
    cout<<"2. Subtraction"<<endl;
    cout<<"--------------------------------------"<<endl;

    cin>>op;

    cout << "Matrix 1 Rows: ";
    cin >> rows1;
    cout << "Matrix 1 Col: ";
    cin >> col1;




    cout<<"--------------------------------------"<<endl;


    cout << "Matrix 2 Rows: ";
    cin >> rows2;
    cout << "Matrix 2 Col: ";
    cin >> col2;
    cout<<"--------------------------------------"<<endl;

    if (op==1 || op==2) {
        if (rows1 != rows2 || col1 != col2) {
            cout<<"Invalid input. Matrix rows and columns must be equal"<<endl<<"for this operation"<<endl;
            return 1;
        }
    }

    cout<<"--------------------------------------"<<endl;



    double matrix2[col2][rows2];
    double matrix1[col1][rows1];
    double matrix3[col1][rows1];

    for (int i = 0; i < col1; i++) {
        for (int j = 0; j < rows1; j++) {
            cout << "Enter value for matrix 1[" << i << "][" << j << "]: ";
            cin >> matrix1[i][j];
        }
    }
    cout<<"--------------------------------------"<<endl;

    for (int i = 0; i < col2; i++) {
        for (int j = 0; j < rows2; j++) {
            cout << "Enter value for matrix 2 [" << i << "][" << j << "]: ";
            cin >> matrix2[i][j];
        }
    }
    cout<<"--------------------------------------"<<endl;

    for (int i=0; i<=rows1; i++ ){
        for (int j=0; j<=col1; j++){
            if (op==1){
                matrix3[i][j] = matrix1[i][j]+matrix2[i][j];
            } else if (op==2){
                matrix3[i][j] = matrix1[i][j]-matrix2[i][j];
            }
        }
    }
    cout<<"--------------------------------------"<<endl;

    for (int i=0; i<rows1; i++ ){
        for (int j=0; j<col1; j++){
            cout<<matrix3[i][j]<<",";
        }
        cout<<endl;
    }



    return 0;
}




