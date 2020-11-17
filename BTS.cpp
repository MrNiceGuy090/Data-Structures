#include <iostream>
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
void preorder(node* root) {
    if (root != NULL) {
        cout << root->info << " ";
        preorder(root->st);
        preorder(root->dr);
    }
}
node* search(node* root, int value) {
    if (root == NULL)return NULL;
    else if (root->info == value)
        return root;
    else if (root->info > value)
        return search(root->st, value);
    else if (root->info < value)
        return search(root->dr, value);
}
bool isInTree(node* root, int value) {
    if (search(root, value) != NULL)return true;
    else return false;
}
node* minValueInTree(node *root) {
    node* temp = root;
    while (temp && temp->st != NULL)
        temp = temp->st;
    return temp;
}
node* deleteNode(node* root, int value) {
    if (root == NULL) return root;
    if (root->info > value)root->st = deleteNode(root->st, value);
    else if (root->info < value)root->dr = deleteNode(root->dr, value);
    else {
        if (root->st == NULL) {
            node* temp = root->dr;
            delete(root);
            return temp;
        }
        else if (root->dr == NULL) {
            node* temp = root->st;
            delete(root);
            return temp;
        }
        node* temp = minValueInTree(root->dr);
        root->info = temp->info;
        root->dr = deleteNode(root->dr, temp->info);
    }
    return root;
}
int main()
{
    node* root = NULL;
    root = insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 4);
    insert(root, 10);
    cout << "gaseste 180, 20? " << isInTree(root, 180) << " " << isInTree(root, 20) << endl << "inorder: ";
    inorder(root);
    cout << endl << "preoder: ";
    preorder(root);
    cout << endl << "delete 10: ";
    root = deleteNode(root, 10);
    inorder(root);
}
