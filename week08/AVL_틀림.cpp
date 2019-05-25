#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include<iostream>
using namespace std;
#define _max(x,y) ((x > y) ? x : y)

// class Node ����
class Node
{
public:
	int height;
	int key;
	string value;
	Node *parent, *left, *right;
	Node() {					// ������1
		key = height = 0;
		value = "";
		parent = left = right = NULL;
	};
	Node(int key, string value) {	// ������2
		this->key = key;
		this->value = value;
		parent = left = right = NULL;
	};
};

// class AVLTree (AVL Ʈ��) ����
class AVLTree
{
public:
	Node *root;
	int n;
	AVLTree() {		// ������
		this->root = NULL;
		n = 0;
	};
	Node* find(int key, Node* v);
	Node* insert(int key, string value);

	int height(Node* v);
	void setHeight(Node* v);
	bool isBalanced(Node *v);
	Node* tallGrandChild(Node* v);
	Node* restructure(Node* v);
	void rebalance(Node* v);
	bool isExternal(Node* v);

	Node* ll(Node* z, Node* y, Node* x);
	Node* rl(Node* z, Node* y, Node* x);
	Node* lr(Node* z, Node* y, Node* x);
	Node* rr(Node* z, Node* y, Node* x);

	int size();
	bool empty();

	void print(Node* root);
};



// AVL Ʈ���� size ��ȯ
int AVLTree::size() {
	return n;
}

// AVL Ʈ���� empty ���� ��ȯ
bool AVLTree::empty() {
	return (n == 0);
}

void AVLTree::print(Node * root)
{
		Node *queue[128] = { 0, }; // level 7
		Node *node;
		int front = 0;
		int rear = 0;
		int level = 0;
		int items = 0;
		int count_of_items = 0;
		int count;
		Node *dummy_node;
		int screen[20][200];
		int start_idx;
		int span;
		int i;
		int l;
		int tmp;

		dummy_node = new Node(-1,"null");

		queue[rear++] = root;
		count = 0x01 << level;
		tmp = 0;
		while (front != rear) {
			node = queue[front];
			front = (front + 1) % (sizeof(queue) / sizeof(queue[0]));

			if (node->left) {
				queue[rear] = node->left;
				count_of_items++;
				tmp++;
			}
			else queue[rear] = dummy_node;
			rear = (rear + 1) % (sizeof(queue) / sizeof(queue[0]));

			if (node->right) {
				queue[rear] = node->right;
				count_of_items++;
				tmp++;
			}
			else queue[rear] = dummy_node;
			rear = (rear + 1) % (sizeof(queue) / sizeof(queue[0]));

			items++;

			if (items == count) {
				if (tmp == 0) break;
				level++;
				items = 0;
				tmp = 0;
				count = 0x01 << level;
			}
		}

		for (l = 0; l < sizeof(screen) / sizeof(screen[0]); l++) {
			for (i = 0; i < sizeof(screen[0]) / sizeof(screen[0][0]); i++) {
				screen[l][i] = -2;
			}
		}

		start_idx = 0;
		span = 4;
		for (l = level; l >= 0; l--) {
			for (i = 0; i < (0x01 << l); i++) {
				screen[l][start_idx + (i * span)] = queue[(0x01 << l) + i - 1]->key;
			}

			// Index of the first item of the upper level
			tmp = ((start_idx + span * 3) + (start_idx + span * 2)) / 2;
			start_idx = (start_idx + start_idx + span) / 2;
			span = tmp - start_idx;
		}

		for (l = 0; l <= level; l++) {
			for (i = 0; i < sizeof(screen[0]) / sizeof(screen[0][0]); i++) {
				if (screen[l][i] == -2) printf("   ");
				else if (screen[l][i] == -1) printf("---");
				else if (screen[l][i] >= 0) printf("%d", screen[l][i]);
			}
			putchar('\n');
			putchar('\n');
		}

		delete dummy_node;
}

// ���v�� leaf ������� Ȯ��
bool AVLTree::isExternal(Node* v) {
	return (v->left == NULL && v->right == NULL);
}

Node* AVLTree::rr(Node * x, Node * y, Node * z)
{
	Node* tmp = y->left;
	y->left = z;
	if (z != root) {
		if (z->parent->left == z)
			z->parent->left = y;
		else
			z->parent->right = y;
		y->parent = z->parent;
	}
	else {
		y->parent = NULL;
		root = y;
	}
	z->parent = y;
	x->parent = y;
	z->right = tmp;
	if (tmp != NULL) {
		tmp->parent = z;
	}
	return y;
}

Node* AVLTree::ll(Node * x, Node * y, Node * z)
{
	Node* tmp = y->right;
	y->right = z;
	if (z != root) {
		if (z->parent->left == z)
			z->parent->left = y;
		else
			z->parent->right = y;
		y->parent = z->parent;
	}
	else {
		y->parent = NULL;
		root = y;
	}
	z->parent = y;
	x->parent = y;
	z->left = tmp;
	if (tmp != NULL) {
		tmp->parent = z;
	}
	return y;
}

Node* AVLTree::rl(Node * x, Node * y, Node * z)
{
	Node* tmp1, *tmp2;
	tmp2 = x->right;
	tmp1 = x->left;
	z->right = tmp1;
	if (tmp1 != NULL) {
		tmp1->parent = z;
	}
	y->left = tmp2;
	if (tmp2 != NULL) {
		tmp2->parent = y;
	}
	x->right = y;
	x->left = z;
	if (z != root) {
		if (z->parent->left == z)
			z->parent->left = x;
		else
			z->parent->right = x;
		x->parent = z->parent;
	}
	else {
		x->parent = NULL;
		root = x;
	}
	y->parent = x;
	z->parent = x;
	return x;
}

Node* AVLTree::lr(Node * x, Node * y, Node * z)
{
	Node* tmp1, *tmp2;
	tmp2 = x->right;
	tmp1 = x->left;
	z->left = tmp1;
	if (tmp1 != NULL) {
		tmp1->parent = z;
	}
	y->right = tmp2;
	if (tmp2 != NULL) {
		tmp2->parent = y;
	}
	x->right = z;
	x->left = y;
	if (z != root) {
		if (z->parent->left == z)
			z->parent->left = x;
		else
			z->parent->right = x;
		x->parent = z->parent;
	}
	else {
		x->parent = NULL;
		root = x;
	}
	y->parent = x;
	z->parent = x;
	return x;
}

// ��� v�� ���� ��ȯ
int AVLTree::height(Node* v) {
	if (v == NULL)
		return -1;
	else
		return (isExternal(v)) ? 0 : v->height;
}

// ��� v�� ���� ���
void AVLTree::setHeight(Node* v) {
	int hl = height(v->left);	// height of left child
	int hr = height(v->right);	// height of right child
	v->height = 1 + _max(hl, hr);
}

//  ��� v�� ���� ���� ���� Ȯ��
bool AVLTree::isBalanced(Node *v) {
	int bal = height(v->left) - height(v->right);
	return ((-1 <= bal) && (bal <= 1));
}

// ������ �ұ��� ��� z�� ����, height�� �� ū, z�� grandchld Ž��
Node* AVLTree::tallGrandChild(Node* z) {
	Node* zl = z->left;
	Node* zr = z->right;
	if (height(zl) >= height(zr)) {
		if (height(zl->left) >= height(zl->right))	// �ڽİ� ���� ������ ���ڸ� �켱������ ����
			return zl->left;
		else
			return zl->right;
	}
	else {
		if (height(zr->right) >= height(zr->left))	// �ڽİ� ���� ������ ���ڸ� �켱������ ����
			return zr->right;
		else
			return zr->left;
	}
}


/****************************************************************************************************************************************///�л��� ����. 

Node* AVLTree::restructure(Node* x) {
	// ���� �����ϼ���.
	Node* y = x->parent;
	Node* z = y->parent;
	bool yl, xl;
	yl = (z->left == y);
	xl = (y->left == x);

	if (yl&&xl)
		x = ll(x, y, z);
	else if (!yl&&xl)
		x = rl(x, y, z);
	else if (yl && !xl)
		x = lr(x, y, z);
	else if (!yl && !xl)
		x = rr(x, y, z);
	return x;
}

/*****************************************************************************************************************************************///�л��� ����





 // ��� v���� root �������� path �� ����� height�� �缳���ϰ� �������� Ȯ��
// �ұ��� ��尡 ������, restructuring
void AVLTree::rebalance(Node* v) {
	Node *z = v;
	while (z->parent != NULL) {
		z = z->parent;
		setHeight(z);
		if (!isBalanced(z)) {
			Node* x = tallGrandChild(z);
			z = restructure(x);		// -------------------> restructure() �� ���� �����ؾ��մϴ�.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			setHeight(z->left);
			setHeight(z->right);
			setHeight(z);
		}
	}
	root = z;
}



//key�� ���Ե� ��ġ ��ȯ
Node* AVLTree::find(int key, Node* v) {
	Node* leafNode;
	leafNode = NULL;

	while (v != NULL) {
		leafNode = v;
		if (key < v->key)
			v = v->left;
		else if (key > v->key)
			v = v->right;
		else
			return v;
	}

	// leaf���� ������ ���, leaf��带 ��ȯ�Ѵ�. 
	return leafNode;
}


//��� ����
Node* AVLTree::insert(int key, string value) {
	Node *curLeafNode = find(key, root);
	Node *newNode = new Node(key, value);
	Node *insertNode = new Node();

	if (key < curLeafNode->key)	// �����Ϸ��� key�� ���� leaf����� key���� ���� ���
	{
		curLeafNode->left = newNode;
	}
	else 	// �����Ϸ��� key��  ���� leaf����� key���� ū ���
	{
		curLeafNode->right = newNode;
	}
	newNode->parent = curLeafNode;
	n++;

	// restructure �� height ����
	setHeight(newNode);
	rebalance(newNode);


	// ���Ե� AVL tree�� ����� height ���
	insertNode = find(key, root);
	cout << insertNode->value << " " << insertNode->height << endl;
	return insertNode;
}


int main()
{
	ios::sync_with_stdio(false);
	int t, key;
	string instruct;
	AVLTree T;

	cin >> t;
	while (t--) {
		Node* tempNode;
		cin >> instruct;
		if (instruct == "find") {
			cin >> key;
			///�л��� ����.
			// �ش� �Է¿� ���� ������ ����ó��  ��µǵ��� �����ϼ���. 
			tempNode = T.find(key, T.root);

			if (tempNode->key == key)
				cout << tempNode->value << " " << tempNode->height << endl;
			else
				cout << "-1" << endl;
			///�л��� ����.

		}

		else if (instruct == "insert") {
			cin >> key >> instruct;
			if (T.empty()) {
				T.root = new Node(key, instruct);
				T.n++;
				cout << T.root->value << " " << T.root->height << endl;
			}
			else
				T.insert(key, instruct);
		}

		T.print(T.root);
	}
	return 0;
}