#include <iostream>
#include <string>
using namespace std;

class Array {
private:
	int* arr;
	int arrSize;
public:
	Array(int size) {
		this->arrSize = size;
		this->arr = new int[arrSize];
		for (int i = 0; i < size; i++) {
			arr[i] = 0;
		}
	}

	int at(int idx) {
		return arr[idx];
	}

	void add(int idx, int val) {
		for (int i = arrSize - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = val;
	}

	void remove(int idx) {
		for (int i = idx + 1; i < arrSize; i++) {
			arr[i - 1] = arr[i];
		}
		arr[arrSize - 1] = 0;
	}

	void set(int idx, int val) {
		arr[idx] = val;
		cout << arr[idx] << endl;
	}

	void print() {
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void find_max(){
		int max = -10000;
		for (int i = 0; i < arrSize; i++) {
			if (arr[i] > max) max = arr[i];
		}
		cout << max << endl;
	}
};

int main() {
	int N, T, i = 0, value = 0;
	string str;
	cin >> N >> T;
	Array ar(N);
	for (int j = 0; j < T; j++) {
		cin >> str;
		if (str[0] == 'a' && str[1] == 't') {
			cin >> i;
			cout << ar.at(i) << endl;
		}
		else if (str[0] == 'a' && str[1] == 'd') {
			cin >> i >> value;
			ar.add(i, value);
		}
		else if (str[0] == 'r') {
			cin >> i;
			ar.remove(i);
		}
		else if (str[0] == 's') {
			cin >> i >> value;
			ar.set(i, value);
		}
		else if (str[0] == 'p') {
			ar.print();
		}
		else if (str[0] == 'f') {
			ar.find_max();
		}
		else {
			continue;
		}
	}
	return 0;
}