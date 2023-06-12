#include <iostream>
#include <string>
#include "BinarTree.h"
#include "test.h"

void showMenu () {
    cout << "BinaryTree Menu:" << endl;
    cout << "1. Insert element" << endl;
    cout << "2. Perform KLP traversal" << endl;
    cout << "3. Perform KPL traversal" << endl;
    cout << "4. Perform LPK traversal" << endl;
    cout << "5. Perform LKP traversal" << endl;
    cout << "6. Perform PLK traversal" << endl;
    cout << "7. Perform PKL traversal" << endl;
    cout << "8. Map tree elements(multiply by 2)" << endl;
    cout << "9. Filter tree elements(x % 2 == 0)" << endl;
    cout << "10. Merge two trees" << endl;
    cout << "11. Extract subtree" << endl;
    cout << "12. Check if tree contains subtree" << endl;
    cout << "13. Check if tree contains element" << endl;
    cout << "14. Convert tree to string" << endl;
    cout << "15. Convert string to tree" << endl;
    cout << "16. Find node by path" << endl;
    cout << "17. Show tree" << endl;
    cout << "18. Clear tree" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

// Функция-пример для map()
template<class T>
T multiplyByTwo(T value) {
    return value * 2;
}

// Функция-пример для where()
template<class T>
bool isEven(T value) {
    return value % 2 == 0;
}

int main() {
    int choice;
    BinaryTree<int> tree;

    cout << "Menu:" << endl;
    cout << "1. AutoTest" << endl;
    cout << "2. BinaryTree" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            testBinaryTree();
            cout << "Success!!" << endl;
            break;
        case 2:
            do {
                int choice2;
                showMenu();
                cin >> choice;
                switch (choice) {

                    case 1: {
                        int data;
                        cout << "Enter element to insert: ";
                        cin >> data;
                        tree.insert(data);
                        tree.show();
                        break;
                    }
                    case 2:
                        tree.KLP();
                        break;
                    case 3:
                        tree.KPL();
                        break;
                    case 4:
                        tree.LPK();
                        break;
                    case 5:
                        tree.LKP();
                        break;
                    case 6:
                        tree.PLK();
                        break;
                    case 7:
                        tree.PKL();
                        break;
                    case 8:
                        tree = tree.map(multiplyByTwo<int>);
                        break;
                    case 9:
                        tree = tree.where(isEven<int>);
                        break;
                    case 10: {
                        BinaryTree<int> tree2;
                        // Заполнение второго дерева
                        BinaryTree<int> mergedTree = tree.merge(tree, tree2);
                        break;
                    }
                    case 11: {
                        int value;
                        cout << "Enter value to extract subtree: ";
                        cin >> value;
                        BinaryTree<int> subtree = tree.extractSubtree(value);
                        break;
                    }
                    case 12: {
                        // Создание и заполнение поддерева для проверки
                        BinaryTree<int> subtree;
                        bool contains = tree.containsSubtree(subtree);
                        cout << "Contains subtree: " << (contains ? "Yes" : "No") << endl;
                    }

                    case 13: {
                        int value;
                        cout << "Enter value to check: ";
                        cin >> value;
                        bool contains = tree.contains(value);
                        cout << "Contains element: " << (contains ? "Yes" : "No") << endl;
                        break;
                    }
                    case 14: {
                        cout << "1. KLP" << endl;
                        cout << "2. KPL" << endl;
                        cout << "3. LPK" << endl;
                        cout << "4. LKP" << endl;
                        cout << "5. PLK" << endl;
                        cout << "6. PKL" << endl;
                        cout << "Enter your choice: ";
                        cin >> choice2;
                        string treeString = tree.toString(choice2);
                        cout << "Tree as string: " << treeString << endl;
                        break;
                    }
                    case 15: {
                        cout << "1. KLP" << endl;
                        cout << "2. KPL" << endl;
                        cout << "Enter your choice: ";
                        cin >> choice2;
                        string treeString;
                        cout << "Enter tree as string: ";
                        cin.ignore();
                        getline(cin, treeString);
                        BinaryTree<int> newTree;
                        newTree.fromString(treeString, choice2);
                        newTree.show();
                        break;
                    }
                    case 16: {
                        string path;
                        cout << "Enter path to node: ";
                        cin.ignore();
                        getline(cin, path);
                        Node<int>* node = tree.findNodeByPath(path);
                        if (node) {
                            cout << "Node value: " << node->data << endl;
                        } else {
                            cout << "Node not found." << endl;
                        }
                        break;
                    }
                    case 17:
                        tree.show();
                        break;
                    case 18:
                        tree.clear();
                        break;
                    case 0:
                        cout << "Exiting..." << endl;
                        tree.clear();
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            } while (choice != 0);
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
    }
    return 0;
}
