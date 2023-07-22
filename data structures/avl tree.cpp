#include <iostream>
#include <string>

class node {
public:
	int data;
	node* left;
	node* right;
	int height;
	node(int& data, node* left = nullptr, node* right = nullptr) {
		this->height = 0;
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

void pre_order(node* x) {
	if (x != nullptr) {
		std::cout << x->data << " ";
		pre_order(x->left);
		pre_order(x->right);
	}
}

void fix_height(node* a) {
	int height1 = 0, height2 = 0;
	if (a == nullptr)
		return;
	if (a->left != nullptr && a->right != nullptr) {
		a->height = std::max(a->left->height, a->right->height) + 1;
	}
	else if (a->left != nullptr && a->right == nullptr)
		a->height = a->left->height + 1;
	else if (a->right != nullptr && a->left == nullptr)
		a->height = a->right->height + 1;
	else
	a->height = 0;
}

node* left_s(node* a) {
	node* b = a->right;
	a->right = b->left;
	b->left = a;
	fix_height(a);
	fix_height(b);
	return b;
}

node* right_s(node* a) {
	node* b = a->left;
	a->left = b->right;
	b->right = a;
	fix_height(a);
	fix_height(b);
	return b;
}

int calc_balance(node* a) {
	int height1 = 0, height2 = 0;
	if (a == nullptr)
		return 0;
	if (a->left != nullptr && a->right != nullptr) {
			height1 = a->left->height;
			height2 = a->right->height;
			return height2 - height1;
	}
	if (a->left != nullptr && a->right == nullptr)
		return -(a->left->height + 1);
	if (a->right != nullptr && a->left == nullptr)
		return a->right->height + 1;
	return 0;

}

node* balance(node* a) {
	fix_height(a);
	if (calc_balance(a) == 2) {
		if (calc_balance(a->right) < 0)
			a->right = right_s(a->right);
		return left_s(a);
	}
	if (calc_balance(a) == -2) {
		if (calc_balance(a->left) > 0)
			a->left = left_s(a->left);
		return right_s(a);
	}
	return a;
}

node* insert(node* x, int z) {
	if (!x) return new node(z);
	if (x->data > z)
		x->left = insert(x->left, z);
	else x->right = insert(x->right, z);
	return balance(x);
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

node* find_max(node *z) {
	if (z->right == nullptr)
		return z;
	return find_max(z->right);
}

node* delete_max(node *z) {
	if (z->right == nullptr)
		return z->left;
	z->right = delete_max(z->right);
	return balance(z);
}

node* del(node* x, int k) {
	if (x == nullptr)
		return 0;
	if (k < x->data) {
		x->left = del(x->left, k);
	}
	else if (k > x->data) {
		x->right = del(x->right, k);
	}
	else {
		node* y = x->left;
		node* z = x->right;
		x = nullptr;
		if (y == nullptr)
			return z;
		node* max = find_max(y);
		max->left = delete_max(y);
		max->right = z;
		return balance(max);
	}
	return balance(x);
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, num;
	std::cin >> n;
	char c;
	node* root = nullptr;
	for (int i = 0; i < n; ++i) {
		std::cin >> c >> num;
		if (c == 'A') {
			node* temp;
			find(root, num, temp);
			if (temp == nullptr)
				root = insert(root, num);
			std::cout << calc_balance(root)<< "\n";
		}
		if (c == 'C') {
			node* temp;
			find(root, num, temp);
			if (temp != nullptr)
				std::cout << "Y\n";
			else
				std::cout << "N\n";
		}
		if (c == 'D') {
			node* temp;
			find(root, num, temp);
			if (temp != nullptr)
				root = del(root, num);
			if (root == nullptr)
				std::cout << 0 << "\n";
			else
				std::cout << calc_balance(root) << "\n";
		}
	}
	return 0;
}
