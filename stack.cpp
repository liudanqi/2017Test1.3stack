#include <iostream>
#include <string>
#include <vector>
using namespace std;
enum Error_code{overflow,underflow,success};
const int maxstack = 100;
class stack {
public:
	stack();
	Error_code instack(int&item);
	Error_code outstack();
	int getMin();
private:
	int count;
	int entry[maxstack];
};
stack::stack() {
	count = 0;
}
Error_code stack::instack(int&item) {
	if (count >=maxstack)
		return overflow;
	else {
		entry[count] = item;
		count++;
		return success;
	}
}
Error_code stack::outstack() {
	if (count <= 0) {
		cout << "-1" <<endl;
		return underflow;
	}
	else {
		cout << entry[count-1] << endl;
		count--;
		return success;
	}
}
int stack::getMin() {
	if (count == 0) {
		cout << "empty" << endl;
	}
	else {
		int min = entry[0];
		for (int i = 0;i < count;i++) {
			if (entry[i] < min)
				min = entry[i];
		}
		return min;
	}
}
int main() {
	stack my;
	int m;
	cin >> m;	
	vector<string>s(100);
	int st[100];
	for (int i = 0;i < m;i++) {
		cin >> s[i];
		if (s[i] == "instack")
			cin >> st[i];
	}
	for (int i = 0;i < m;++i) {
		if (s[i] == "instack") {
			my.instack(st[i]);
		}
		else if (s[i] == "outstack")
			my.outstack();
		else {
			cout << my.getMin() << endl;
		}
	}
	return 0;
}