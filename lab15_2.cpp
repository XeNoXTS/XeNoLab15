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

void inputMatrix(double data[N][N]){
	for(int i = 0; i < N; i++){
		cout << "Row " << i+1 << ": ";
		for(int j = 0; j < N; j++){
			cin >> data[i][j];
		}
	}
}

void findLocalMax(const double dataA[N][N], bool dataB[N][N]){
	for(int i=0 ;i<N;i++){
		for(int j=0; j<N;j++){
			if(dataA[i][j] >= dataA[i-1][j] && dataA[i][j] >= dataA[i+1][j] && dataA[i][j] >= dataA[i][j-1] && dataA[i][j] >= dataA[i][j+1]) dataB[i][j] = true;
			else dataB[i][j] = false;
			if(i == 0 || j == 0 || i == N-1 || j == N-1) dataB[i][j] = false;
		}
	}
}

void showMatrix(const bool data[][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << data[i][j] << ' ';
		}
		cout << "\n";
	}
}