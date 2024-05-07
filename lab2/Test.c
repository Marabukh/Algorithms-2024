#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Method.h"


int main() {
    Node* tree = create(4);
    Node* node1 = create(3);
    tree = insert(tree, node1);
    Node* node2 = create(5);
    tree = insert(tree, node2);
    PrintOutTree(tree);
    printf("\n");
    /*
    Node* find4 = find(tree, 4);
    Node* find2 = find(tree, 2);
    PrintOutTree(find4);
    printf("\n");
    PrintOutTree(find2);
    */
    /*
    Node** splitTree = split(node1);
    PrintOutTree(splitTree[0]);
    printf("\n");
    PrintOutTree(splitTree[1]);
    */
    /*
    Node* tree2 = create(7);
    Node* node21 = create(9);
    tree2 = insert(tree2, node21);
    PrintOutTree(join(tree, tree2));
    */

    return 0;
}

