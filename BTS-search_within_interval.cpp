#include <iostream>
#include <string.h>
using namespace std;
struct node {
    int info;
    node* st, * dr;
};
node* insert(node* root, int value) {
    if (root == NULL) {
        node* temp = new node;
        temp->info = value;
        temp->st = temp->dr = NULL;
        return temp;
    }
    if (root->info > value) root->st = insert(root->st, value);
    else if (root->info < value) root->dr = insert(root->dr, value);
    return root;
}
void inorder(node* root) {
    if (root != NULL) {
        inorder(root->st);
        cout << root->info << " ";
        inorder(root->dr);
    }
}
void showValuesBetween(node* root,int v1, int v2) {
    if (root) {
        if (root->info > v1 && root->info < v2) cout << root->info << " ";
        if (root->info >= v1) showValuesBetween(root->st, v1, v2);
        if (root->info <= v2) showValuesBetween(root->dr, v1, v2);
    }

}
int main()
{
    node* root = NULL;
    root = insert(root, 12);
    insert(root, 32);
    insert(root, 54);
    insert(root, 43);
    insert(root, 65);
    insert(root, 93);
    insert(root, 2);
    showValuesBetween(root, 30, 60);
}
