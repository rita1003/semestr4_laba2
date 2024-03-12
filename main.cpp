#include "header.h"
#include <iostream>
#include <iomanip> //для отступов в таблице

using namespace std;

int main() {
	int m, n;

	cout << "Enter number of rows and columns of matrices: " << endl;
	cin >> m;
	cin >> n;

	Matrix m1(m, n);
	Matrix m2(m, n);
	Matrix m3(m, n); //Для демонстрации операции +=
	Matrix m4(m, n); //Для демонастрации операции -=

	m1.fill();
	m2.fill();
	m3.fill();
	m4.fill();

	cout << "The matrice 1: " << endl << m1 << endl;
	cout << "The matrice 2: " << endl << m2 << endl;
	cout << "The matrice 3: " << endl << m3 << endl;
	cout << "The matrice 4: " << endl << m4 << endl;

	cout << "Sum of matrices 1 and 2: " << endl << m1+m2 << endl;
	cout << "Subtraction of matrices 1 and 2: " << endl << m1-m2 << endl;
	cout << "Multiplication of matrices 1 and 2: " << endl << m1 * m2 << endl;

	m3 += m1;
	cout << "Operation += for matrice 3 and 1: " << endl << m3 << endl;

	m4 -= m1;
	cout << "Operation -= for matrice 4 and 1: " << endl << m4 << endl;

	bool res_operation1;
	res_operation1 = m1 == m2;
	cout << "Operation == for matrice 1 and 2: " << endl << res_operation1 << endl;

	bool res_operation2;
	res_operation2 = m1 != m2;
	cout << "Operation != for matrice 1 and 2: " << endl << res_operation2 << endl;

	return 0;
}
