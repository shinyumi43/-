#include <iostream>
using namespace std;

class StringNode {
	friend class StringLinkedList;
private:
	string elem;
	StringNode* next;
	StringNode(string e, StringNode* n) : elem(e), next(n) {}
};

class StringLinkedList {
public:
	StringLinkedList(string);
	~StringLinkedList();
	void addFront(const string& a);
	void removeFront();
	void addTail(const string& b);
	void print();
private:
	StringNode* head;
	StringNode* tail;
};

StringLinkedList::StringLinkedList(string s) {
	head = tail = new StringNode(s, nullptr);
}

void StringLinkedList::addFront(const string& a) {
	StringNode* temp = new StringNode(a, nullptr);
	if (head == nullptr) head = temp;
	else {
		temp->next = head->next;
		head->next = temp;
	}
}

void StringLinkedList::removeFront() {
	if (head != nullptr) {
		StringNode* removal = head;
		head = head->next;
		delete removal;
	}
}

void StringLinkedList::addTail(const string& b) {
	StringNode* temp = new StringNode(b, nullptr);
	if (head == nullptr) head = temp;
	else {
		tail->next = temp;
		tail = temp;
	}
}

void StringLinkedList::print() {
	StringNode* temp = head;
	while (temp != nullptr) {
		cout << temp->elem << "\n";
		temp = temp->next;
	}
}

StringLinkedList::~StringLinkedList() {
	while (head != nullptr) removeFront();
}

int main() {
	StringLinkedList* list = new StringLinkedList("Judy");
	list->addTail("Jessy");
	list->addFront("Nick");
	list->removeFront();
	list->print();
	return 0;
}