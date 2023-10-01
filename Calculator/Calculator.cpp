#include<iostream>
using namespace std;
#include<string>
#include<vector>

class Num {
private:
	int A1;//arr的长度
	int N; //若第一个数小，则为0，否则为1

	void setA1() {
		A1 = arr.size();
	}

	void daoZhi1() {
		for (int i = 0; i < A1; i++) {
			_arr.push_back(arr[A1 - 1 - i]);
		}
	}

	void daoZhi2() {
		while (_arr.size() > 1 && _arr[_arr.size() - 1] == 0) {
			_arr.pop_back();
		}
		for (int i = 0; i < _arr.size(); i++) {
			arr.push_back(_arr[_arr.size() - 1 - i]);
		}
	}
public:
	vector<int> arr;	//我们规定：arr表示正序数组，_arr表示倒序数组
	vector<int> _arr;


	int compare(Num& n1, Num& n2) {
		n1.setA1();
		n2.setA1();
		if (n1.A1 < n2.A1) {
			N = 0;
			return 0;
		}
		else if (n1.A1 > n2.A1) {
			N = 1;
			return 1;
		}
		else {
			for (int i = 0; i < n1.A1; i++) {
				if (n1.arr[i] > n2.arr[i]) {
					N = 1;
					return 1;
				}
				else if (n1.arr[i] < n2.arr[i]) {
					N = 0;
					return 0;
				}
			}
			N = 1;
			return 1;
		}
	}

	void addPrint() {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i];
		}
	}

	void minusPrint() {
		if (N) {
			for (int i = 0; i < _arr.size(); i++) {
				cout << arr[i];
			}
		}
		else {
			cout << "-";
			for (int i = 0; i < _arr.size(); i++) {
				cout << arr[i];
			}
		}

	}

	Num operator+(Num m) {
		int n = 0;
		Num temp1;
		setA1();
		daoZhi1();
		m.setA1();
		m.daoZhi1();
		int A2 = min(A1, m.A1);
		for (int i = 0; i < A2; i++) {
			int temp = _arr[i] + m._arr[i] + n;
			if (temp > 9) {
				temp1._arr.push_back(temp % 10);
				n = 1;
			}
			else {
				temp1._arr.push_back(temp);
				n = 0;
			}
		}
		for (int i = A2; i < A1; i++) {
			int temp;
			if (A1 > m.A1)
				temp = _arr[i] + n;
			else
				temp = m._arr[i] + n;

			if (temp > 9) {
				temp1._arr.push_back(temp % 10);
				n = 1;
			}
			else {
				temp1._arr.push_back(temp);
				n = 0;
			}
		}
		temp1._arr.push_back(n);
		temp1.daoZhi2();
		return temp1;
	}

	Num operator-(Num m) {
		int n = 0;
		Num temp1;
		setA1();
		daoZhi1();
		m.setA1();
		m.daoZhi1();
		int A2 = min(A1, m.A1);
		for (int i = 0; i < A2; i++) {
			int temp = _arr[i] - m._arr[i] - n;
			if (temp < 0) {
				temp1._arr.push_back(-1 * (temp % 10));
				n = 1;
			}
			else {
				temp1._arr.push_back(temp);
				n = 0;
			}
		}
		for (int i = A2; i < A1; i++) {
			int temp;
			if (A1 > m.A1)
				temp = _arr[i] - n;
			else
				temp = m._arr[i] - n;

			if (temp < 0) {
				temp1._arr.push_back(-1 * (temp % 10));
				n = 1;
			}
			else {
				temp1._arr.push_back(temp);
				n = 0;
			}
		}
		temp1._arr.push_back(n);
		temp1.daoZhi2();
		return temp1;
	}
};


int main() {
	Num n1;
	Num n2;
	string s1, s2;
	char operator_;
	cin >> s1 >> operator_ >> s2;
	for (int i = 0; i < s1.size(); i++) {
		n1.arr.push_back(s1[i] - '0');
	}
	for (int i = 0; i < s2.size(); i++) {
		n2.arr.push_back(s2[i] - '0');
	}
	if (operator_ == '+') {
		Num n3 = n1 + n2;
		n3.addPrint();
	}
	else if (operator_ == '-') {
		Num n3;
		if (n3.compare(n1, n2))
			n3 = n1 - n2;
		else {
			n3 = n2 - n1;
		}
		n3.minusPrint();
	}
	return 0;
}