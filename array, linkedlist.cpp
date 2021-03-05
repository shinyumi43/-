#include <iostream>
using namespace std;

class Node { //데이터값과 다음 노드의 주소값을 지닌 포인터를 모두 포함하는 노드 클래스를 생성한다.
	friend class List; //friend로 선언된 해당 클래스에 대해 서로 공유가 가능하도록 한다.
public:
	Node(){ //노드 클래스의 생성자를 초기의 값을 기준으로 설정한다.
		data = 0;
		next = nullptr;
	}
	Node(int i){ //데이터값을 포함하는 노드 클래스의 생성자도 설정한다.
		data = i;
		next = nullptr;
	}
private:
	int data; //데이터값을 멤버변수로 선언한다.
	Node* next; //다음 노드를 가리키는 포인터도 멤버변수로 선언한다.
};

class List { //노드 간의 연결을 통합하여 관리하는 리스트 클래스를 생성한다.
private:
	Node* head; //단일연결리스트의 가장 첫 번째 노드를 가리키는 head 포인터를 생성한다.
public:
	List() { //리스트 클래스의 생성자를 설정한다.
		head = nullptr;
	}
	List(Node *insertNode) { //삽입할 값을 바로 받을 수 있는 리스트 클래스의 생성자 또한 생성한다.
		head = nullptr;
		insert(insertNode);
	}
	void insert(Node* insertNode); //삽입 기능을 수행할 삽입 함수를 생성한다.
	void del(int delNum); //삭제 기능을 수행할 삭제할 함수를 생성한다.
	void printList(); //단일 연결리스트 전체를 출력할 함수를 생성한다.
};

void List::insert(Node* insertNode) {
	if (head == nullptr) head = insertNode;
	else {
		Node* current = head;
		for (Node* ptr = head; ptr != nullptr; ptr = ptr->next) 
			current = ptr; //현재 노드를 가리키는 current 포인터를 nullptr을 가리키기 전까지 이동해준다.
		current->next = insertNode; //삽입하고자 하는 노드를 가리키는 포인터를 current 포인터의 다음이 되도록, 즉 가장 끝에 삽입되도록 한다.
	}
}

void List::del(int delNum) {
	if (head == nullptr) cout << "List is empty\n";
	else {
		Node* current = head;
		Node* beforeCurrent = nullptr;
		for (Node* ptr = head; ptr != nullptr; ptr = ptr->next) {
			beforeCurrent = current; //계속해서 반복을 거치면서 이전 노드는 현재 노드의 전을 가리킬 수 있도록 다음으로 넘어가기 전 현재 노드의 포인터 값을 받는다.
			current = ptr; //현재 노드를 가리키는 포인터를 계속해서 nullptr이 되지 않도록 한 칸씩 다음 노드로 이동한다.
			if (current->data == delNum) { //현재를 가리키는 포인터의 데이터가 삭제하고자 하는 노드의 데이터와 같으면,
				if (beforeCurrent == head && current == head) //예외적인 경우를 고려하여, 이전 노드와 현재 노드가 모두 head를 가리키고 있다면, 즉 head를 삭제하고자 한다면,
					head = current->next; //현재가 head이므로 현재의 다음을 가리키는 포인터를 헤드 포인터로 지정한다.
				else beforeCurrent->next = current->next; //head를 삭제하는 경우가 아니라면, 이전의 다음이 현재의 다음이 되도록 포인터를 변경한다.
				delete current; //그리고 현재를 삭제한다.
				return;
			}
		}
		cout << delNum << " cannot find in List\n"; //예외적인 상황으로 찾고자 하는 수가 없을 경우에는 list 내의 수가 존재하지 않음을 나타내도록 한다.
	}
	return;
}

void List::printList() {
	if (head == nullptr) {
		cout << "List is empty\n";
	}
	else {
		for (Node* ptr = head; ptr != nullptr; ptr = ptr->next) { //ptr을 계속해서 바꿔주면서 ptr이 가리키는 데이터의 값을 head부터 순차적으로 출력한다.
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

