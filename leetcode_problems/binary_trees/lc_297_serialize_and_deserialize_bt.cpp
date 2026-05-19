/**
 * Leetcode-106: Construct Binary from inorder and postorder traversal
 */

#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

template <typename T> struct BinaryTree {
  T data;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree() : data(T{}), left(nullptr), right(nullptr) {}
  BinaryTree(T d) : data(d), left(nullptr), right(nullptr) {}
  BinaryTree(T d, BinaryTree *left, BinaryTree *right)
      : data(d), left(left), right(right) {}

  ~BinaryTree() {
    delete left;
    delete right;
  }
};

template <typename T> void insert(BinaryTree<T> *&ptr, T val) {
  BinaryTree<T> *node = new BinaryTree(val);
  ptr = node;
}

template <typename T>
void printBinaryTree(BinaryTree<T> *root, string prefix, bool is_left) {
  if (root == nullptr)
    return;

  string connector = is_left ? "|--" : "'--";
  cout << prefix << connector << root->data << endl;

  string new_prefix = prefix + (is_left ? "|  " : "   ");
  printBinaryTree(root->left, new_prefix, true);
  printBinaryTree(root->right, new_prefix, false);
}

template <typename T> void printVectorOfVectors(vector<vector<T>> &a) {
  for (auto &i : a) {
    for (auto &j : i)
      cout << j << " ";
    cout << endl;
  }
}

template <typename T> void printVector(vector<T> &a) {
  for (auto &i : a) {
    cout << i << endl;
  }
}

template <typename T> string serialize(BinaryTree<T> *root) {
  if (!root)
    return "";
  string s = "";
  queue<BinaryTree<T> *> q;
  q.push(root);

  while (!q.empty()) {
    BinaryTree<T> *node = q.front();
    q.pop();

    if (node == NULL)
      s.append("#,");
    else {
      s.append(to_string(node->data) + ",");
    }
    if (node != NULL) {
      q.push(node->left);
      q.push(node->right);
    }
  }

  cout << s;
  return s;
}

template <typename T> BinaryTree<T> *deserialize(string data) {
  if (data.size() == 0)
    return nullptr;
  stringstream s(data);
  string str;

  getline(s, str, ',');

  BinaryTree<T> *root = new BinaryTree(stoi(str));

  queue<BinaryTree<T> *> q;
  q.push(root);

  while (!q.empty()) {
    BinaryTree<T> *node = q.front();
    q.pop();

    getline(s, str, ',');

    if (str == "#") {
      node->left = nullptr;
    } else {
      BinaryTree<T> *leftNode = new BinaryTree(stoi(str));
      node->left = leftNode;
      q.push(leftNode);
    }

    getline(s, str, ',');
    if (str == "#")
      node->right = nullptr;
    else {
      BinaryTree<T> *rightNode = new BinaryTree(stoi(str));
      node->right = rightNode;
      q.push(rightNode);
    }
  }
  return root;
}

int main() {
  BinaryTree<int> *root = new BinaryTree(3);

  insert(root->left, 5);
  insert(root->right, 1);

  insert(root->left->left, 6);
  insert(root->left->right, 2);
  insert(root->right->right, 8);
  insert(root->right->left, 0);

  insert(root->left->right->left, 7);
  insert(root->left->right->right, 4);

  string prefix = "";
  cout << root->data << endl;
  printBinaryTree(root->left, prefix, true);
  printBinaryTree(root->right, prefix, false);

  string serialize_string = serialize(root);

  BinaryTree<int> *newRoot = deserialize<int>(serialize_string);
  cout << endl;
  string prefix1 = "";
  cout << root->data << endl;
  printBinaryTree(newRoot->left, prefix1, true);
  printBinaryTree(newRoot->right, prefix1, false);
}
