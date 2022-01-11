#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double x[][N]){
    for(int i = 0;i < N;i++){
        cout << "Row " << i + 1 << ": ";
        for(int j = 0;j < N;j++){
            cin >> x[i][j];
        }
    }
}

void findLocalMax(const double y[][N], bool z[][N]){
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(i == N - 1 || i == 0 || j == 0 || j == N - 1)z[i][j] = 0;
            if(y[i + 1][j + 1] >= y[i + 1][j] && y[i + 1][j + 1] >= y[i][j + 1] && y[i + 1][j + 1] >= y[i + 2][j + 1] && y[i + 1][j + 1] >= y[i + 1][j + 2]){
                z[i + 1][j + 1] = 1;
            }else{
                z[i + 1][j + 1] = 0;
            }
        }
    }
}

void showMatrix(const bool w[][N]){
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cout << w[i][j] << " ";
        }
        cout << endl;
    }
}