#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/////////////////////////////////problem 3

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
// create new Node
Node* newNode(int value)
{
    Node* n = new Node;
    n->data = value;
    n->left = n->right = NULL;
    return n;
}

void insertInorder(Node* root, vector<int> &v)
{
    if (!root)
        return;
    insertInorder(root->left, v);
    v.push_back(root->data);
    insertInorder(root->right, v);
}

bool checkBSTs(Node* T1, Node* T2)
{
    if (!T1 && !T2)
        return true;
    if ((T1 && !T2) || (!T1 && T2))
        return false;

    //// put values using vectors
    vector<int> v1, v2;
    insertInorder(T1, v1);
    insertInorder(T1, v2);
    return (v1 == v2);
}

int main()
{
    Node* T1 = newNode(15);
    T1->left = newNode(10);
    T1->left->left = newNode(5);
    T1->left->right = newNode(12);
    T1->right = newNode(20);
    T1->right->right = newNode(25);

    Node* T2 = newNode(15);
    T2->left = newNode(12);
    T2->left->left = newNode(5);
    T2->left->left->right = newNode(10);
    T2->right = newNode(20);
    T2->right->right = newNode(25);

    if (checkBSTs(T1, T2))
        cout << "TRUE, THEY ARE THE SAME";
    else
        cout << "FALSE, THEY ARE NOT THE SAME";
    return 0;
}
