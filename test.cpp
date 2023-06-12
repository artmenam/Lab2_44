#include <cassert>

#include "BinarTree.h"

void testBinaryTree() {
    BinaryTree<int> tree1;
    BinaryTree<int> tree2;
    BinaryTree<int> tree3;

    tree1.insert(5);
    tree1.insert(3);
    tree1.insert(7);
    tree1.insert(2);
    tree1.insert(4);

    tree2.insert(8);
    tree2.insert(6);
    tree2.insert(9);

    tree3.insert(5);
    tree3.insert(3);
    tree3.insert(7);

    // Проверяем методы KLP и KPL
    assert(tree1.toString(1) == "5 3 2 4 7 ");
    assert(tree1.toString(2) == "5 7 3 4 2 ");

    // Проверяем методы LPK и LKP
    assert(tree2.toString(3) == "6 9 8 ");
    assert(tree2.toString(4) == "6 8 9 ");

    // Проверяем методы PLK и PKL
    assert(tree1.toString(5) == "7 4 2 3 5 ");
    assert(tree1.toString(6) == "7 5 4 3 2 ");

    // Проверяем метод merge
    BinaryTree<int> mergedTree = tree1.merge(tree1, tree2);
    assert(mergedTree.toString(1) == "13 9 2 4 16 ");

    // Проверяем методы contains и containsSubtree
    assert(tree1.contains(3) == true);
    assert(tree1.contains(6) == false);
    assert(tree1.containsSubtree(tree2) == false);
    assert(tree1.containsSubtree(tree3) == true);

    // Проверяем методы map и where
    BinaryTree<int> mappedTree = tree1.map([](int x) { return x * 2; });
    assert(mappedTree.toString(1) == "10 6 4 8 14 ");
    BinaryTree<int> filteredTree = tree1.where([](int x) { return x % 2 == 0; });
    assert(filteredTree.toString(1) == "2 4 ");

    // Проверяем метод extractSubtree
    BinaryTree<int> extractedTree = tree1.extractSubtree(3);
    assert(extractedTree.toString(1) == "3 2 4 ");

    // Проверяем метод findNodeByPath
    Node<int>* node = tree1.findNodeByPath("L/L");
    assert(node != nullptr);
    assert(node->data == 2);

    // Проверяем метод findNodeByRelativePath
    Node<int>* rootNode = tree1.findNodeByPath("L");
    assert(rootNode->data == 3);
}
