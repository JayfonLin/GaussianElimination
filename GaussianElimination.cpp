#include <iostream>
#include <iomanip>
using namespace std;
const int row = 3, column = 4;
double* Gao(double a[][4]){
	double* ans = new double[row];
	for (int i = 0; i < column-1; i++){
		for (int j = i+1; j < row; j++){
			double t = -a[j][i]/a[i][i];
			double l[column];
			for (int k = 0; k < column; k++){
				l[k] = a[i][k]*t + a[j][k];
			}
			for (int k = 0; k < column; k++){
				a[j][k] = l[k];
			}
		}
	}
	for (int i = row-1; i >= 0; i--){
		//ans[i] = a[i][column-1]/a[i][column-2];
		double t = a[i][column-1];
		for (int j = column-2; j > i; j--){
			
			t -= (a[i][j]*ans[j]);
		}
		ans[i] = t/a[i][i];
	}
	return ans;
}
int main()
{
	double in[3][4] = {{2,1,-1,8},{-3,-1,2,-11},{-2,1,2,-3}};
	double* result = Gao(in);
	for (int i = 0; i < row; i++){
		cout << "x" << i+1 << " = " << fixed << setiosflags(ios::showpoint) << setprecision(6) << result[i] << endl;
	}
	return 0;
}