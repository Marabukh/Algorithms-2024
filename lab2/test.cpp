#include "gtest/gtest.h"
#include "../Test/Method.h"

TEST(test, Insert) {
    Node* tree = create(4);
    Node* node1 = create(3);
    tree = insert(tree, node1);
    Node* node2 = create(5);
    tree = insert(tree, node2);
    char res1[200] = "";
    PrintTree(tree, res1);
    EXPECT_STREQ(res1, "5 (4 (3 () ()) ()) ()");
}

TEST(test, Find) {
    Node* tree = create(4);
    Node* node1 = create(3);
    tree = insert(tree, node1);
    Node* node2 = create(5);
    tree = insert(tree, node2);
    Node* find4 = find(tree, 4);
    char res24[200] = "";
    Node* find2 = find(tree, 2);
    char res22[200] = "";
    PrintTree(find4, res24);
    PrintTree(find2, res22);
    EXPECT_STREQ(res24, "4 () (5 () ())");
    EXPECT_STREQ(res22, "");
}

TEST(test, Split) {
    Node* tree = create(4);
    Node* node1 = create(3);
    tree = insert(tree, node1);
    Node* node2 = create(5);
    tree = insert(tree, node2);
    Node** splitTree = split(node1);
    char res31[200] = "";
    char res32[200] = "";
    PrintTree(splitTree[0], res31);
    PrintTree(splitTree[1], res32);
    EXPECT_STREQ(res31, "3 () ()");
    EXPECT_STREQ(res32, "4 () (5 () ())");
}

TEST(test, Join) {
    Node* tree = create(4);
    Node* node1 = create(3);
    tree = insert(tree, node1);
    Node* node2 = create(5);
    tree = insert(tree, node2);
    Node* tree2 = create(7);
    Node* node21 = create(9);
    tree2 = insert(tree2, node21);
    char res4[200] = "";
    PrintTree(join(tree, tree2), res4);
    EXPECT_STREQ(res4, "5 (4 (3 () ()) ()) (9 (7 () ()) ())");
}