#include <bits/stdc++.h>
using namespace std;
class node {
public:
  node(int i) {
    this->data = i;
    this->left = nullptr;
    this->right = nullptr;
  }
  int data;
  node *left;
  node *right;
};

int sumLeafNodesAndItself(node *root) {
  if (root->left == nullptr && root->right == nullptr)
    return root->data;
  else if (root->left == nullptr) {
    int value = ((root->data) + sumLeafNodesAndItself(root->right));
    root->data = value;
    return value;
  } else if (root->right == nullptr) {
    int value = ((root->data) + sumLeafNodesAndItself(root->left));
    root->data = value;
    return value;
  }
  int value = ((root->data) + sumLeafNodesAndItself(root->left) +
               sumLeafNodesAndItself(root->right));
  root->data = value;
  return value;
}

// level order traversal of binary tree
void printLevelWise(node *root) {
  if (root == nullptr)
    return;
  queue<node *> q;
  q.push(root);
  q.push(nullptr);

  while (!q.empty()) {
    node *_node = q.front();
    q.pop();
    if (_node != nullptr) {
      cout << _node->data << ' ';

      if (_node->left != nullptr)
        q.push(_node->left);
      if (_node->right != nullptr)
        q.push(_node->right);
    } else if (!q.empty()) {
      q.push(nullptr);
    }
  }
  puts("");
}

int main() {
  int _root;
  puts("ENter root value: ");
  cin >> _root;
  node *root = new node(_root);

  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);

  printLevelWise(root);

  int _v = sumLeafNodesAndItself(root);

  printLevelWise(root);

  return 0;
}