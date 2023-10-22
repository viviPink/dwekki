#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    const int n = 4; 

    double a[n][n]; 
    double l[n][n] = {0}; 
    double u[n][n] = {0}; 
    double c[n]; 
    double y[n] = {0}; 
    double x[n] = {0}; 

   
    cout << "Enter the matrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    
    cout << "Enter the vector c:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    l[0][0] = sqrt(a[0][0]);
    for (int i = 1; i < n; i++) {
        l[i][0] = a[i][0] / l[0][0];
    }

    for (int k = 1; k < n; k++) {
        double sqsum = 0;
        for (int m = 0; m < k; m++) {
            sqsum += l[k][m] * l[k][m];
        }
        l[k][k] = sqrt(a[k][k] - sqsum);

        if (k < (n-1)) {
            for (int i = k + 1; i < n; i++) {
                double pairsum = 0;
                for (int m = 0; m < k; m++) {
                    pairsum += l[i][m] * l[k][m];
                }
                l[i][k] = (a[i][k] - pairsum) / l[k][k];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            u[i][j] = l[j][i];
        }
    }

 
    y[0] = c[0] / l[0][0];
    for (int i = 1; i < n; i++) {
        double sum = 0;
        for (int m = 0; m < i; m++) {
            sum += l[i][m] * y[m];
        }
        y[i] = (c[i] - sum) / l[i][i];
    }


    x[n-1] = y[n-1] / u[n-1][n-1];
    for (int i = n-2; i >= 0; i--) {
        double sum = 0;
        for (int m = i + 1; m < n; m++) {
            sum += u[i][m] * x[m];
        }
        x[i] = (y[i] - sum) / u[i][i];
    }


    cout << "Matrix L:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout <<fixed<<setw(5)<<setprecision(2)<<l[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Matrix U:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout <<fixed<<setw(5)<<setprecision(2)<<u[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Vector y:" << endl;
    for (int i = 0; i < n; i++) {
        cout <<fixed<<setw(2)<<setprecision(2)<< y[i] << " ";
    }
    cout << endl;

    cout << "Vector x:" << endl;
    for (int i = 0; i < n; i++) {
        cout <<fixed<<setw(2)<<setprecision(2)<< x[i] << " ";
    }
    cout << endl;

    return 0;
}