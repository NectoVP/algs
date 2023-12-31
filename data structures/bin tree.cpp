#include <iostream>
#include <string>

class node {
public:
	int data;
	node* left;
	node* right;
	node(int data = 0, node* left = nullptr, node* right = nullptr) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

node* insert(node* x, int z) {
	if (x == nullptr)
		return new node(z);
	else if (z < x->data)
		x->left = insert(x->left, z);
	else if (z > x->data)
		x->right = insert(x->right, z);
	return x;
}

void find(node* x, int data, node*& finded) {
	if (x == nullptr || data == x->data) {
		finded = x;
		return;
	}
	if (data < x->data)
		find(x->left, data, finded);
	else
		find(x->right, data, finded);
}

node* min(node* x)
{
	if (x->left == nullptr)
		return x;
	return min(x->left);
}

node* max(node* x)
{
	if (x->right == nullptr)
		return x;
	return max(x->right);
}

node* next(int x, node* root)
{
	node* cur = root;
	node* suc = nullptr;
	while (cur != nullptr) {
		if (cur->data > x) {
			suc = cur;
			cur = cur->left;
		}
		else {
			cur = cur->right;
		}
	}
	return suc;
}

node* prev(int x, node* root)
{
	node* cur = root;
	node* suc = nullptr;
	while (cur != nullptr) {
		if (cur->data < x) {
			suc = cur;
			cur = cur->right;
		}
		else {
			cur = cur->left;
		}
	}
	return suc;
}

node* del(node* root, int z) {
	if (root == nullptr)
		return root;
	if (z < root->data)
		root->left = del(root->left, z);
	else if (z > root->data)
		root->right = del(root->right, z);
	else if (root->left != nullptr and root->right != nullptr) {
		root->data = min(root->right)->data;
		root->right = del(root->right, root->data);
	}
	else {
		if (root->left != nullptr)
			root = root->left;
		else if (root->right != nullptr)
			root = root->right;
		else {
			root = nullptr;
		}
	}
	return root;
}

int main() {
	std::string s;
	int n;
	node* root = nullptr;
	while (std::cin >> s >> n) {
		if (s[0] == 'i') {
			if (root == nullptr) {
				root =  new node(n);
				continue;
			}
			node* temp;
			find(root, n, temp);
			if(temp == nullptr)
				root = insert(root, n);
		}
		else if (s[0] == 'd') {
			node* temp;
			find(root, n, temp);
			if (temp != nullptr)
				root = del(root, n);
		}
		else if (s[0] == 'e') {
			node* temp;
			find(root, n, temp);
			if (temp == nullptr)
				std::cout << "false" << '\n';
			else
				std::cout << "true" << '\n';
		}
		else if (s[0] == 'n') {
			node* temp = next(n, root);
			if (temp != nullptr)
				std::cout << temp->data << '\n';
			else
				std::cout << "none" << '\n';
		}
		else if (s[0] == 'p') {
			node* temp = prev(n, root);
			if (temp != nullptr)
				std::cout << temp->data << '\n';
			else
				std::cout << "none" << '\n';
		}
	}
	return 0;
}
