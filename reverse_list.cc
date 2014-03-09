#include <iostream>

struct Node
{
	Node * next;
	int data;
	
	Node(): next(0) {}
	Node(int data, Node* next): data(data), next(next) {}
};

Node * reverse(Node * root)
{
	Node * new_root = 0;
	while (root) {
		Node * next = root->next;
		root->next = new_root;
		new_root = root;
		root = next;
	}
	return new_root;
}

void printList(Node * root, std::ostream & os)
{
	os << "[";
	char const * delim = "";
	while (root) {
		std::cout << delim << root->data;
		delim = ",";
		root = root->next;
	}
	os << "]";
}

int main()
{
	int val;
	Node * root = 0;
	Node * tail = 0;
	while (std::cin >> val) {
		Node * nd = new Node(val, 0);
		if (root == 0) {
			root = nd;
			tail = nd;
		} else {
			tail->next = nd;
			tail = nd;
		}
	}

	std::cout << "Input:    ";
	printList(root, std::cout);
	std::cout << std::endl;
	root = reverse(root);
	std::cout << "Reversed: ";
	printList(root, std::cout);
	std::cout << std::endl;

	return 0;
}