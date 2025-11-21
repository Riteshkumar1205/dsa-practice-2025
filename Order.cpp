/*
#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node* buildTree(Node* root){
  
    cout << "Enter the data: ";
    int data;
    cin >> data;

    if(data == -1) return NULL; 
    root = new Node(data);

    

    cout << "Enter the data for inserting inleft:-"  << data << endl;
    root->left = buildTree(root->left);
    cout << "ENter the data for inserting in right:- " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
int main(){
    Node* root = NULL;
    root = buildTree(root);
    return 0;
}
    */


#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(Node* root){
    int data;
    cout << "Enter the data: ";
    cin >> data;

    if(data == -1) return NULL;

    root = new Node(data);

    cout << "Enter data for the left child of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for the right child of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// -------- ASCII TREE PRINTING --------
void printTreeAscii(Node* root, int space = 0, int indent = 6) {
    if (root == NULL)
        return;

    space += indent;

    printTreeAscii(root->right, space);

    cout << endl;
    for (int i = indent; i < space; i++)
        cout << " ";
    cout << root->data;

    if (root->left || root->right) {
        cout << endl;
        for (int i = indent; i < space - 2; i++)
            cout << " ";

        if (root->right)
            cout << "/";
        else
            cout << " ";

        if (root->left)
            cout << " \\";
    }

    cout << endl;

    printTreeAscii(root->left, space);
}

int main(){
    Node* root = buildTree(NULL);

    cout << "\n\nTree Structure:\n";
    printTreeAscii(root);

    return 0;
}
