#include <iostream>
using namespace std;

class Node { //�����Ͱ��� ���� ����� �ּҰ��� ���� �����͸� ��� �����ϴ� ��� Ŭ������ �����Ѵ�.
	friend class List; //friend�� ����� �ش� Ŭ������ ���� ���� ������ �����ϵ��� �Ѵ�.
public:
	Node(){ //��� Ŭ������ �����ڸ� �ʱ��� ���� �������� �����Ѵ�.
		data = 0;
		next = nullptr;
	}
	Node(int i){ //�����Ͱ��� �����ϴ� ��� Ŭ������ �����ڵ� �����Ѵ�.
		data = i;
		next = nullptr;
	}
private:
	int data; //�����Ͱ��� ��������� �����Ѵ�.
	Node* next; //���� ��带 ����Ű�� �����͵� ��������� �����Ѵ�.
};

class List { //��� ���� ������ �����Ͽ� �����ϴ� ����Ʈ Ŭ������ �����Ѵ�.
private:
	Node* head; //���Ͽ��Ḯ��Ʈ�� ���� ù ��° ��带 ����Ű�� head �����͸� �����Ѵ�.
public:
	List() { //����Ʈ Ŭ������ �����ڸ� �����Ѵ�.
		head = nullptr;
	}
	List(Node *insertNode) { //������ ���� �ٷ� ���� �� �ִ� ����Ʈ Ŭ������ ������ ���� �����Ѵ�.
		head = nullptr;
		insert(insertNode);
	}
	void insert(Node* insertNode); //���� ����� ������ ���� �Լ��� �����Ѵ�.
	void del(int delNum); //���� ����� ������ ������ �Լ��� �����Ѵ�.
	void printList(); //���� ���Ḯ��Ʈ ��ü�� ����� �Լ��� �����Ѵ�.
};

void List::insert(Node* insertNode) {
	if (head == nullptr) head = insertNode;
	else {
		Node* current = head;
		for (Node* ptr = head; ptr != nullptr; ptr = ptr->next) 
			current = ptr; //���� ��带 ����Ű�� current �����͸� nullptr�� ����Ű�� ������ �̵����ش�.
		current->next = insertNode; //�����ϰ��� �ϴ� ��带 ����Ű�� �����͸� current �������� ������ �ǵ���, �� ���� ���� ���Եǵ��� �Ѵ�.
	}
}

void List::del(int delNum) {
	if (head == nullptr) cout << "List is empty\n";
	else {
		Node* current = head;
		Node* beforeCurrent = nullptr;
		for (Node* ptr = head; ptr != nullptr; ptr = ptr->next) {
			beforeCurrent = current; //����ؼ� �ݺ��� ��ġ�鼭 ���� ���� ���� ����� ���� ����ų �� �ֵ��� �������� �Ѿ�� �� ���� ����� ������ ���� �޴´�.
			current = ptr; //���� ��带 ����Ű�� �����͸� ����ؼ� nullptr�� ���� �ʵ��� �� ĭ�� ���� ���� �̵��Ѵ�.
			if (current->data == delNum) { //���縦 ����Ű�� �������� �����Ͱ� �����ϰ��� �ϴ� ����� �����Ϳ� ������,
				if (beforeCurrent == head && current == head) //�������� ��츦 ����Ͽ�, ���� ���� ���� ��尡 ��� head�� ����Ű�� �ִٸ�, �� head�� �����ϰ��� �Ѵٸ�,
					head = current->next; //���簡 head�̹Ƿ� ������ ������ ����Ű�� �����͸� ��� �����ͷ� �����Ѵ�.
				else beforeCurrent->next = current->next; //head�� �����ϴ� ��찡 �ƴ϶��, ������ ������ ������ ������ �ǵ��� �����͸� �����Ѵ�.
				delete current; //�׸��� ���縦 �����Ѵ�.
				return;
			}
		}
		cout << delNum << " cannot find in List\n"; //�������� ��Ȳ���� ã���� �ϴ� ���� ���� ��쿡�� list ���� ���� �������� ������ ��Ÿ������ �Ѵ�.
	}
	return;
}

void List::printList() {
	if (head == nullptr) {
		cout << "List is empty\n";
	}
	else {
		for (Node* ptr = head; ptr != nullptr; ptr = ptr->next) { //ptr�� ����ؼ� �ٲ��ָ鼭 ptr�� ����Ű�� �������� ���� head���� ���������� ����Ѵ�.
			cout << ptr->data << " ";
		}
		cout << endl;
	}
}

void inputSet(List* linkedList) {
	int select;
	cout << "1. insert 2. delete 3. printList 4. Exit" << endl << ">>";
	cin >> select;
	switch (select) {
	case 1: {
		int data;
		cout << "Input Data(Integer) : ";
		cin >> data;
		Node* insertNode = new Node(data);
		linkedList->insert(insertNode);
		break; }
	case 2: {
		int data;
		cout << "Enter Delete Data(Integer) : ";
		cin >> data;
		linkedList->del(data);
		break; }
	case 3: {
		linkedList->printList();
		break; }
	case 4: {
		exit(0);
		break; }
	}
}

int main() {
	List* linkedList = new List();
	while (1) inputSet(linkedList);
}

