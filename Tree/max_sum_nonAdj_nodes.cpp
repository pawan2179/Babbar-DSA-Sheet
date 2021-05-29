#include<bits/stdc++.h>
using namespace std;

typedef struct Node {
	int data;
	Node *left;
	Node *right;
} Node;

Node *getNode(int);
int getMaxSum(Node *);
int getMaxSumUtil(Node *, unordered_map<Node*, int>&);
int sumOfGrandChildren(Node *root, unordered_map<Node *, int>&);


Node *getNode(int val) {
	Node *newnode = (Node *)malloc(sizeof(Node *));
	newnode->data = val;
	newnode->left = newnode->right = NULL;

	return newnode;
}


int getMaxSumUtil(Node *root, unordered_map<Node *, int> &mp) {
	if (root == NULL)    return 0;

	if (mp.find(root) != mp.end()) {
		return mp[root];
	}

	int incl = root->data + sumOfGrandChildren(root, mp);
	int excl = getMaxSumUtil(root->left, mp) + getMaxSumUtil(root->right, mp);

	mp[root] = max(incl, excl);
	return mp[root];
}

int sumOfGrandChildren(Node *root, unordered_map<Node *, int> &mp) {
	int sum = 0;

	if (root->left) {
		sum += getMaxSumUtil(root->left->left, mp) + getMaxSumUtil(root->left->right, mp);
	}

	if (root->right)
		sum += getMaxSumUtil(root->right->left, mp) + getMaxSumUtil(root->right->right, mp);

	return sum;
}


int getMaxSum(Node *root) {
	if (root == NULL)    return 0;
	unordered_map<Node *, int> mp;

	return getMaxSumUtil(root, mp);
}

int main() {

	Node* root = getNode(1);
	root->left = getNode(2);
	root->right = getNode(3);
	root->right->left = getNode(4);
	root->right->right = getNode(5);
	root->left->left = getNode(1);

	cout << getMaxSum(root) << endl;
	return 0;
}