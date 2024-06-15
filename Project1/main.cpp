#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>


template <typename T>
class interval {
private:
	T first;
	T end;

public:
	interval(const T& a,const T& b) {
		first = a;
		end = b;
	}

	bool operator ()(const T& value) const {
		return ((value >= first) && (value <= end));
	}
};



class date {
	private:
		int day;
		int month;
		int year;
	public:
		date(int a, int b, int c) {
			day = a;
			month = b;
			year = c;
		}
		friend ostream& operator<<(ostream& os, const date& dt);

		bool operator <= (const date& f1) const{
			if (year <= f1.year) {
				if (month <= f1.month) {
					if (day <= f1.day) {
						return 1;
					}
				}
			}
			return 0;
		}

		bool operator >= (const date& f1) const {
			if (year >= f1.year) {
				if (month >= f1.month) {
					if (day >= f1.day) {
						return 1;
					}
				}
			}
			return 0;
		}

		bool operator = (const date& f1) const {
			return ((year == f1.year) && (month == f1.month) && (day == f1.day));
		}

		
		

};

ostream& operator<<(ostream& os, const date& f1) {
	cout << f1.day << "," << f1.month << "," << f1.year;
	return os;
}

class EsMayor {
	public:
		EsMayor(int v) : valor(v) {}
		bool operator () (int otroValor) const {
		return otroValor > valor;
		
	}
	
	private:
		int valor;
};

template <typename T>
class Greater_Than {
public:
	bool operator () (const T & left, const T &right) {
		return left >= right;
	}
};

int main() {
	interval <int> I(2, 8);
	cout << I(5) << endl;

	date f1(2, 4, 2006);
	date f2(2, 7, 2006);
	date f3(2, 7, 2010);
	date f4(2, 4, 2006);

	cout << (f1 <= f2) << endl;
	cout << (f1 >= f2) << endl;
	cout << (f1 = f4) << endl;

	
	vector <date > int_nums = { f1,f2,f3,f4 };
		
	sort(int_nums.begin(), int_nums.end(),Greater_Than <date >());


	for (auto num : int_nums) {
	cout << num << "; ";
	
	}

	return 0;
}





