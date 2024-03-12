/* 
Теоретическая справка для меня, как для непродвинутого пользователя С++:
	• friend - ключевое слово для определения ДРУЖЕСТВЕННЫХ ФУНКЦИЙ
	• дружественные функции - функцие, которые не являются членами класса, однако имеют доступ к
		его закрытым членам из private
	• insigned - префикс при объявлении переменной, означающий, что она содержит только положительные
		числa. Unsigned без последующего int обозначает int по умолчанию
	• this - ключевое слово, которое представляет указатель на текущий объект данного класса. Через
		this мы можем обращаться внутри класса к любым его членам. Чтобы в конструкторе разграничить
		параметры и переменные класса как раз и используется указатель this. Оно может быть 
		необходимо, если параметры функции или переменные, которые определяются внутри функции, 
		называются также как и переменные класса.
*/

#include<iostream>
#include <iomanip> //для отступов в таблице

using namespace std;

class Matrix { //Tребование 1. Определение класса Matrix
private:

	unsigned m; //строки
	unsigned n; //столбы
	int** data;

public:

	Matrix(unsigned p_m, unsigned p_n) { //Tребование 2. Конструктор
		m = p_m;
		n = p_n;
		data = new int* [p_m];
		for (int i = 0; i < p_m; i++) data[i] = new int[n];
	};

	void fill() { //Требование 5. Заполнение массива случайными числами
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				data[i][j] = rand() % 10;
			}
		}
	}

	friend ostream& operator<<(ostream& out, const Matrix& obj); //Требование 6. Перегрузка оператора <<
	friend bool operator==(Matrix& obj1, Matrix& obj2); //Требование 8. Пегрегрузка оператора ==


	bool operator!= (Matrix& obj) { //Требование 8. Перегрузка оператора !=
		return !(*this == obj);
	}

	int*& operator[](int k) { //Требование 4. Перегрузка оператора []
		return data[k];
	}

	Matrix operator+(const Matrix& obj) { //Требование 7. Перегрузка оператора +
		Matrix tmp(m, n);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				tmp[i][j] = data[i][j] + obj.data[i][j];
		return tmp;
	}

	Matrix& operator+=(const Matrix& obj) { //Требование 7. Перегрузка оператора +=
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				data[i][j] += obj.data[i][j];
		return *this;
	}

	Matrix operator-(const Matrix& obj) { //Требование 7. Перегрузка оператора - 
		Matrix tmp(m, n);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				tmp[i][j] = data[i][j] - obj.data[i][j];
		return tmp;
	}

	Matrix& operator -=(const Matrix& obj) { //Требование 7. Перегрузка оператора -=
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				data[i][j] -= obj.data[i][j];
		return *this;
	}

	Matrix operator*(const Matrix& obj) { //Требование 7. Перегрузка оператора *
		Matrix tmp(m, n);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				tmp[i][j] = data[i][j] * obj.data[i][j];
		return tmp;
	}

	~Matrix() { //Требование 3. Деструктор
		for (int i = 0; i < m; i++) {
			delete[] data[i];
		}
		delete[] data;
	}

};

ostream& operator<<(ostream& out, const Matrix& obj) { //Требование 6. Перегрузка оператора <<
	Matrix tmp(0, 0);
	for (int i = 0; i < obj.m; i++) {
		for (int j = 0; j < obj.n; j++)
			out << setw(4) << obj.data[i][j] << '|';
		out << endl;
	}
	return out;
}

bool operator == (Matrix& obj1, Matrix& obj2) { //Требование 8. Перегрузка оператора ==
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

