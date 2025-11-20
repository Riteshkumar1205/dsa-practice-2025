#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// SAFE buildTree (Preorder style)
Node* buildTree(const string &msg = "Enter data") {
    cout << msg << " (-1 for no node): ";
    int data;
    cin >> data;

    if (!cin) {
        cout << "Invalid input encountered.\n";
        exit(0);
    }

    if (data == -1) return NULL;

    Node* root = new Node(data);

    root->left = buildTree("Enter LEFT child of " + to_string(data));
    root->right = buildTree("Enter RIGHT child of " + to_string(data));

    return root;
}

// Print tree in your format: 1 / 2 3 / 4 5 6 7 /
void printTreeLikeFormat(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty.\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << "/ ";
    }
    cout << endl;
}

int main() {
    cout << "Build Tree using -1 to stop a branch:\n";
    Node* root = buildTree();

    cout << "\nTree in your level format:\n";
    printTreeLikeFormat(root);

    return 0;
}
