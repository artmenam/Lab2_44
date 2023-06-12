#pragma once

#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class Trunk
{
public:
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
    void showTrunks(Trunk *p)
    {
        if (p == nullptr) {
            return;
        }

        showTrunks(p->prev);
        cout << p->str;
    }
};


template<class T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }

};

template<class T>
class BinaryTree {
private:
    Node<T> *root;

    Node<T> *insert(Node<T> *root, T data) {
        if (root == nullptr) {
            root = new Node<T>(data);
        } else if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }

    //КЛП
    void klp(Node<T>* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            klp(root->left);
            klp(root->right);
        }
    }

    //КПЛ
    void kpl(Node<T>* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            kpl(root->right);
            kpl(root->left);
        }
    }

    //ЛПК
    void lpk(Node<T>* root) {
        if (root != nullptr) {
            lpk(root->left);
            lpk(root->right);
            cout << root->data << " ";
        }
    }

    void lkp(Node<T>* root) {
        if (root != nullptr) {
            lkp(root->left);
            cout << root->data << " ";
            lkp(root->right);
        }
    }

    void plk(Node<T>* root) {
        if (root != nullptr) {
            plk(root->right);
            plk(root->left);
            cout << root->data << " ";
        }
    }

    void pkl(Node<T>* root) {
        if (root != nullptr) {
            pkl(root->right);
            cout << root->data << " ";
            pkl(root->left);
        }
    }

    Node<T>* map(Node<T>* root, T (*func)(T)) {
        if (root != nullptr) {
            Node<T>* newNode = new Node<T>(func(root->data));
            newNode->left = map(root->left, func);
            newNode->right = map(root->right, func);
            return newNode;
        }
        return nullptr;
    }

    Node<T>* where(Node<T>* root, bool (*condition)(T)) {
        if (root == nullptr) {
            return nullptr;
        }

        Node<T>* newNode = nullptr;
        if (condition(root->data)) {
            newNode = new Node<T>(root->data);
            newNode->left = where(root->left, condition);
            newNode->right = where(root->right, condition);
        } else {
            newNode = where(root->left, condition);
            Node<T>* rightNode = where(root->right, condition);

            if (newNode == nullptr) {
                newNode = rightNode;
            } else {
                Node<T>* curr = newNode;
                while (curr->right != nullptr) {
                    curr = curr->right;
                }
                curr->right = rightNode;
            }
        }

        return newNode;
    }

    // слияние
    Node<T>* merge(Node<T>* root1, Node<T>* root2) {
        if (root1 == nullptr) {
            return root2;
        }
        if (root2 == nullptr) {
            return root1;
        }

        Node<T>* merged = new Node<T>(root1->data + root2->data);
        merged->left = merge(root1->left, root2->left);
        merged->right = merge(root1->right, root2->right);

        return merged;
    }

    Node<T>* extractSubtree(Node<T>* root, T value) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->data == value) {
            Node<T>* subtree = new Node<T>(root->data);
            subtree->left = root->left;
            subtree->right = root->right;
            return subtree;
        }

        if (value < root->data) {
            return extractSubtree(root->left, value);
        } else {
            return extractSubtree(root->right, value);
        }
    }

    bool isSubtree(Node<T>* root, Node<T>* subtreeRoot) const{
        if (root == nullptr) {
            return false;
        }

        if (root->data == subtreeRoot->data) {
            return true;
        }

        return isSubtree(root->left, subtreeRoot) || isSubtree(root->right, subtreeRoot);
    }

    bool containsElement(Node<T>* root, const T& value) const {
        if (root == nullptr) {
            return false;
        }

        if (root->data == value) {
            return true;
        }

        return containsElement(root->left, value) || containsElement(root->right, value);
    }

    void klpToString (Node<T>* root, ostringstream& oss) const {
        if (root == nullptr) {
            return;
        }
        oss << root->data << " ";
        klpToString(root->left, oss);
        klpToString(root->right,oss);
    }

    void kplToString (Node<T>* root, ostringstream& oss) const {
        if (root == nullptr) {
            return;
        }
        oss << root->data << " ";
        kplToString(root->right,oss);
        kplToString(root->left, oss);
    }

    void lpkToString (Node<T>* root, ostringstream& oss) const {
        if (root == nullptr) {
            return;
        }
        lpkToString(root->left, oss);
        lpkToString(root->right,oss);
        oss << root->data << " ";
    }

    void lkpToString (Node<T>* root, ostringstream& oss) const {
        if (root == nullptr) {
            return;
        }
        lkpToString(root->left, oss);
        oss << root->data << " ";
        lkpToString(root->right,oss);
    }

    void plkToString (Node<T>* root, ostringstream& oss) const {
        if (root == nullptr) {
            return;
        }
        plkToString(root->right,oss);
        plkToString(root->left, oss);
        oss << root->data << " ";
    }

    void pklToString (Node<T>* root, ostringstream& oss) const {
        if (root == nullptr) {
            return;
        }
        pklToString(root->right,oss);
        oss << root->data << " ";
        pklToString(root->left, oss);

    }

    Node<T>* klpFromString(istringstream& iss) {
        T value;
        iss >> value;
        if (!iss) {
            return nullptr;
        }
        Node<T>* node = new Node<T>(value);
        node->left = klpFromString(iss);
        node->right = klpFromString(iss);
        return node;
    }

    Node<T>* kplFromString(istringstream& iss) {
        T value;
        iss >> value;
        if (!iss) {
            return nullptr;
        }
        Node<T>* node = new Node<T>(value);
        node->right = kplFromString(iss);
        node->left = kplFromString(iss);
        return node;
    }

    Node<T>* findNodeByPathRecursive(Node<T>* current, istringstream& iss) const {
        if (current == nullptr || !iss) {
            return nullptr;
        }

        string token;
        getline(iss, token, '/');

        if (token.empty()) {
            return current;
        }

        if (token == "L") {
            return findNodeByPathRecursive(current->left, iss);
        } else if (token == "R") {
            return findNodeByPathRecursive(current->right, iss);
        } else {
            return nullptr;
        }
    }

    void printTree(Node<T>* root, Trunk *prev, bool isLeft) const {
        if (root == nullptr) {
            return;
        }

        string prev_str = "    ";
        Trunk *trunk = new Trunk(prev, prev_str);

        printTree(root->right, trunk, true);

        if (!prev) {
            trunk->str = "———";
        }
        else if (isLeft)
        {
            trunk->str = ".———";
            prev_str = "   |";
        }
        else {
            trunk->str = "`———";
            prev->str = prev_str;
        }

        trunk->showTrunks(trunk);
        cout << " " << root->data << endl;

        if (prev) {
            prev->str = prev_str;
        }
        trunk->str = "   |";

        printTree(root->left, trunk, false);
    }

//    void showRecursive(Node<T>* node, const string& prefix, bool isLeft) const {
//        if (node == nullptr) {
//            return;
//        }
//
//        cout << prefix;
//
//        cout << (isLeft ? "├── " : "└── ");
//
//        cout << node->data << endl;
//
//        showRecursive(node->left, prefix + (isLeft ? "│   " : "    "), true);
//        showRecursive(node->right, prefix + (isLeft ? "│   " : "    "), false);
//    }
//
    void clearRecursive(Node<T>* node) {
        if (node == nullptr) {
            return;
        }

        clearRecursive(node->left);
        clearRecursive(node->right);

        delete node;
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(T data) {
        root = insert(root, data);
    }

    void KLP() {
        cout << "KLP traversal: ";
        klp(root);
        cout << endl;
    }

    void KPL() {
        cout << "KPL traversal: ";
        kpl(root);
        cout << endl;
    }

    void LPK() {
        cout << "LPK traversal: ";
        lpk(root);
        cout << endl;
    }

    void LKP() {
        cout << "LKP traversal: ";
        lkp(root);
        cout << endl;
    }

    void PLK() {
        cout << "PLK traversal: ";
        plk(root);
        cout << endl;
    }

    void PKL() {
        cout << "PKL traversal: ";
        pkl(root);
        cout << endl;
    }

    BinaryTree<T> map(T (*func)(T)) {
        BinaryTree<T> newTree;
        newTree.root = map(root, func);
        return newTree;
    }

    BinaryTree<T> where(bool (*condition)(T)) {
        BinaryTree<T> newTree;
        newTree.root = where(root, condition);
        return newTree;
    }

    BinaryTree<T> merge(BinaryTree<T>& tree1, BinaryTree<T>& tree2) {
        BinaryTree<T> mergedTree;
        mergedTree.root = merge(tree1.root, tree2.root);
        return mergedTree;
    }

    BinaryTree<T> extractSubtree(T value) {
        BinaryTree<T> subtree;
        subtree.root = extractSubtree(root, value);
        return subtree;
    }

    bool containsSubtree(const BinaryTree<T>& subtree) const {
        return isSubtree(root, subtree.root);
    }

    bool contains(const T& value) const {
        return containsElement(root, value);
    }

    string toString(int order) const {
        ostringstream oss;
        switch (order) {
            case 1:
                klpToString(root, oss);
                break;
            case 2:
                kplToString(root, oss);
                break;
            case 3:
                lpkToString(root, oss);
                break;
            case 4:
                lkpToString(root, oss);
                break;
            case 5:
                plkToString(root, oss);
                break;
            case 6:
                pklToString(root, oss);
                break;
            default:
                cout << "Error choice." << endl;
                break;
        }
        return oss.str();
    }

    void fromString(const string& str, int order) {
        istringstream iss(str);
        switch (order) {
            case 1:
                root = kplFromString(iss);
                break;
            case 2:
                root = kplFromString(iss);
                break;
            default:
                cout << "Error choice." << endl;
                break;
        }
    }

    Node<T>* findNodeByPath(const string& path) const {
        istringstream iss(path);
        return findNodeByPathRecursive(root, iss);
    }

    void show() const {
        printTree(root, nullptr, false);
    }

    void clear() {
        clearRecursive(root);
        root = nullptr;
    }
};