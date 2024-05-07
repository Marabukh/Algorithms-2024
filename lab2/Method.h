#pragma once

typedef struct Node {
    int value;
    struct Node* child[2];
    struct Node* parent;
} Node;

void PrintOutTree(Node* tree) {
    if (!tree) return;
    printf("%d (", tree->value);
    if (tree->child[0]) {
        PrintOutTree(tree->child[0]);
    }
    printf(") (");
    if (tree->child[1]) {
        PrintOutTree(tree->child[1]);
    }
    printf(")");
}

void PrintOutFromNode(Node* node) {
    if (node) {
        if (!node->parent) {
            PrintOutTree(node);
        }
        else {
            PrintOutFromNode(node->parent);
        }
    }
}

void PrintTree(Node* node, char* Str) {
    char S[20];
    if (node == NULL) return;
    sprintf(S, "%d (", node->value);
    strcat(Str, S);
    PrintTree(node->child[0], Str);
    sprintf(S, ") (");
    strcat(Str, S);
    PrintTree(node->child[1], Str);
    sprintf(S, ")");
    strcat(Str, S);
}

void PrintFromNode(Node* node, char* Str) {
    if (node) {
        if (!node->parent) {
            PrintTree(node, Str);
        }
        else {
            PrintFromNode(node->parent, Str);
        }
    }
}

bool side(Node* node) {
    return (node->parent->child[1] == node);
}

void attach(Node* node, bool side, Node* new_node) {
    if (new_node) {
        new_node->parent = node;
    }
    node->child[side] = new_node;
}

void rotate(Node* node) {
    Node* p = node->parent;
    bool i = side(node);
    if (p->parent) {
        attach(p->parent, side(p), node);
    }
    else {
        node->parent = NULL;
    }
    attach(p, i, node->child[!i]);
    attach(node, !i, p);
}

void splay(Node* node) {
    while (node->parent) {
        if (node->parent && node->parent->parent) {
            if (side(node) == side(node->parent)) {
                rotate(node->parent);
            }
            else {
                rotate(node);
            }
        }
        rotate(node);
    }
}

Node** split(Node* node) {
    Node** res = (Node**)malloc(2 * sizeof(Node*));
    splay(node);
    Node* right = node->child[1];
    if (right) {
        right->parent = NULL;
    }
    node->child[1] = NULL;
    res[0] = node;
    res[1] = right;
    return res;
}

Node* create(int value) {
    Node* res = (Node*)malloc(sizeof(Node));
    res->parent = NULL;
    res->child[0] = NULL;
    res->child[1] = NULL;
    res->value = value;
    return res;
}

Node* insert(Node* tree, Node* node) {
    if (!tree) {
        tree = node;
        return tree;
    }
    Node* y = tree;
    while (true) {
        Node** nw = &y->child[node->value > y->value];
        if (!*nw) {
            *nw = node;
            (*nw)->parent = y;
            tree = *nw;
            splay(*nw);
            return tree;
        }
        y = *nw;
    }
    return tree;
}

Node* find(Node* tree, int key) {
    Node* x = tree;
    while (x && key != x->value) {
        Node* next = x->child[key > x->value];
        if (!next) {
            splay(x);
        }
        x = next;
    }
    return x;
}

Node* extremum(Node* x, bool max) {
    if (!x) {
        return NULL;
    }
    while (x->child[max]) {
        x = x->child[max];
    }
    return x;
}

Node* join(Node* a, Node* b) {
    if (!a) {
        if (b) {
            b->parent = NULL;
        }
        return b;
    }
    Node* mx = extremum(a, true);
    splay(mx);
    attach(mx, true, b);
    mx->parent = NULL;
    return mx;
}