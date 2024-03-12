/* 
������������� ������� ��� ����, ��� ��� �������������� ������������ �++:
	� friend - �������� ����� ��� ����������� ������������� �������
	� ������������� ������� - �������, ������� �� �������� ������� ������, ������ ����� ������ �
		��� �������� ������ �� private
	� insigned - ������� ��� ���������� ����������, ����������, ��� ��� �������� ������ �������������
		����a. Unsigned ��� ������������ int ���������� int �� ���������
	� this - �������� �����, ������� ������������ ��������� �� ������� ������ ������� ������. �����
		this �� ����� ���������� ������ ������ � ����� ��� ������. ����� � ������������ ������������
		��������� � ���������� ������ ��� ��� � ������������ ��������� this. ��� ����� ���� 
		����������, ���� ��������� ������� ��� ����������, ������� ������������ ������ �������, 
		���������� ����� ��� � ���������� ������.
*/

#include<iostream>
#include <iomanip> //��� �������� � �������

using namespace std;

class Matrix { //T��������� 1. ����������� ������ Matrix
private:

	unsigned m; //������
	unsigned n; //������
	int** data;

public:

	Matrix(unsigned p_m, unsigned p_n) { //T��������� 2. �����������
		m = p_m;
		n = p_n;
		data = new int* [p_m];
		for (int i = 0; i < p_m; i++) data[i] = new int[n];
	};

	void fill() { //���������� 5. ���������� ������� ���������� �������
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				data[i][j] = rand() % 10;
			}
		}
	}

	friend ostream& operator<<(ostream& out, const Matrix& obj); //���������� 6. ���������� ��������� <<
	friend bool operator==(Matrix& obj1, Matrix& obj2); //���������� 8. ����������� ��������� ==


	bool operator!= (Matrix& obj) { //���������� 8. ���������� ��������� !=
		return !(*this == obj);
	}

	int*& operator[](int k) { //���������� 4. ���������� ��������� []
		return data[k];
	}

	Matrix operator+(const Matrix& obj) { //���������� 7. ���������� ��������� +
		Matrix tmp(m, n);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				tmp[i][j] = data[i][j] + obj.data[i][j];
		return tmp;
	}

	Matrix& operator+=(const Matrix& obj) { //���������� 7. ���������� ��������� +=
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				data[i][j] += obj.data[i][j];
		return *this;
	}

	Matrix operator-(const Matrix& obj) { //���������� 7. ���������� ��������� - 
		Matrix tmp(m, n);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				tmp[i][j] = data[i][j] - obj.data[i][j];
		return tmp;
	}

	Matrix& operator -=(const Matrix& obj) { //���������� 7. ���������� ��������� -=
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				data[i][j] -= obj.data[i][j];
		return *this;
	}

	Matrix operator*(const Matrix& obj) { //���������� 7. ���������� ��������� *
		Matrix tmp(m, n);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				tmp[i][j] = data[i][j] * obj.data[i][j];
		return tmp;
	}

	~Matrix() { //���������� 3. ����������
		for (int i = 0; i < m; i++) {
			delete[] data[i];
		}
		delete[] data;
	}

};

ostream& operator<<(ostream& out, const Matrix& obj) { //���������� 6. ���������� ��������� <<
	Matrix tmp(0, 0);
	for (int i = 0; i < obj.m; i++) {
		for (int j = 0; j < obj.n; j++)
			out << setw(4) << obj.data[i][j] << '|';
		out << endl;
	}
	return out;
}

bool operator == (Matrix& obj1, Matrix& obj2) { //���������� 8. ���������� ��������� ==
	if (obj1.n != obj2.n || obj1.m != obj2.m) return false;
	for (int i = 0; i < obj1.n; i++) {
		for (int j = 0; j < obj1.m; j++) {
			if (obj1[i][j] != obj2[i][j]) {
				return false;
			}
		}
	}
	return true;

}

