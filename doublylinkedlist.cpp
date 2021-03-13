#include <iostream>
#include <string>
using namespace std;

class Node {
	int elem;
	Node* prev;
	Node* next;

	Node();

	friend class DList;
};

Node::Node() {
	prev = next = nullptr;
	elem = 0;
}

class DList {
public:
	DList();
	int List_size();
	bool Empty();
	void Print();
	void Append(int elem);
	int Delete(int idx);
	void Print_reverse();
	void Max();
private:
	Node* header;
	Node* trailer;
};

DList::DList() {
	header = new Node();
	trailer = new Node();

	header->next = trailer;
	trailer->prev = header;
}

bool DList::Empty() {
	return (header->next == trailer && trailer->prev == header);
}

int DList::List_size() {
	int listSize = 0;
	if (Empty()) return listSize;
	else {
		Node* curNode = header->next;
		while (curNode->next != trailer) {
			listSize++;
			curNode = curNode->next;
		}
		listSize++;
		return listSize;
	}
}

void DList::Print() {
	if (Empty()) cout << "empty" << endl;
	else {
		Node* curNode = header->next;
		while (curNode->next != trailer) {
			cout << curNode->elem << ' ';
			curNode = curNode->next;
		}
		cout << curNode->elem << endl;
	}
}

void DList::Append(int elem) {
	Node* newNode = new Node();
	newNode->elem = elem;
	if (Empty()) {
		header->next = newNode;
		newNode->prev = header;
		trailer->prev = newNode;
		newNode->next = trailer;
	}
	else {
		newNode->prev = trailer->prev;
		trailer->prev->next = newNode;
		newNode->next = trailer;
		trailer->prev = newNode;
	}

	Print();
}

int DList::Delete(int idx) {
	int removeNum = 0, cnt = 0;
	Node* curNode;
	if (Empty() || List_size() <= idx) {
		return - 1;
	}
	else if (idx == 0) {
		if (List_size() == 1) {
			removeNum = header->next->elem;
			header->next = trailer;
			trailer->prev = header;
		}
	}
	else {
		curNode = header->next;
		while (cnt != idx) {
			curNode = curNode->next;
			cnt++;
		}
		removeNum = curNode->elem;
		curNode->prev->next = curNode->next;
		curNode->next->prev = curNode->prev;
	}

	return removeNum;
}

void DList::Print_reverse() {
	if (Empty()) cout << "empty" << endl;
	else {
		Node* curNode = trailer->prev;
		while (curNode->prev != header) {
			cout << curNode->elem << ' ';
			curNode = curNode->prev;
		}
		cout << curNode->elem << endl;
	}
}

void DList::Max() {
	int max = -1;
	if (Empty()) cout << "empty" << endl;
	else {
		Node* curNode = header->next;
		while (curNode->next != trailer) {
			if (max < curNode->elem) max = curNode->elem;
			curNode = curNode->next;
		}
		if (max < curNode->elem) max = curNode->elem;
		cout << max << endl;
	}
}

int main() {
	DList* dlist = new DList();
	string str;
	int M, i, X;
	cin >> M;
	for (int j = 0; j < M; j++) {
		cin >> str;
		if (str[0] == 'P') {
			if (str.size() < 10) dlist->Print();
			else dlist->Print_reverse();
		} 
		else if (str[0] == 'A') {
			cin >> X;
			dlist->Append(X);
		}
		else if (str[0] == 'D') {
			cin >> i;
			cout << dlist->Delete(i) << endl;
		}
		else if (str[0] == 'M') { dlist->Max(); }
	}
	return 0;
}