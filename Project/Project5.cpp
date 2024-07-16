#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key) : val(key), left(NULL), right(NULL) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int key) {
        if (!node) return new TreeNode(key);
        if (key < node->val) {
            node->left = insert(node->left, key);
        } else if (key > node->val) {
            node->right = insert(node->right, key);
        }
        return node;
    }

    TreeNode* search(TreeNode* node, int key) {
        if (!node || node->val == key) return node;
        if (key < node->val) return search(node->left, key);
        return search(node->right, key);
    }

    TreeNode* deleteNode(TreeNode* node, int key) {
        if (!node) return node;

        if (key < node->val) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->val) {
            node->right = deleteNode(node->right, key);
        } else {
            if (!node->left) return node->right;
            else if (!node->right) return node->left;

            TreeNode* minNode = findMin(node->right);
            node->val = minNode->val;
            node->right = deleteNode(node->right, minNode->val);
        }
        return node;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    void inOrderTraversal(TreeNode* node) {
        if (node) {
            inOrderTraversal(node->left);
            cout << node->val << " ";
            inOrderTraversal(node->right);
        }
    }

public:
    BinarySearchTree() : root(NULL) {}

    void insert(int key) {
        root = insert(root, key);
    }

    TreeNode* search(int key) {
        return search(root, key);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    void display() {
        cout << "Elements in the BST (in-order): ";
        inOrderTraversal(root);
        cout << endl;
    }
};
int main() {
    BinarySearchTree bst;
    int choice, key;
    do {
        cout << "Menu: "<<endl;
        cout << "1. Insert "<<endl;
        cout << "2. Search "<<endl;
        cout << "3. Delete "<<endl;
        cout << "4. Display Elements "<<endl;
        cout << "5. Exit "<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                bst.insert(key);
                cout << "Inserted " << key << endl;
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                cout << (bst.search(key) ? "Found" : "Not found") << endl;
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                bst.deleteNode(key);
                cout << "Deleted node with key " << key << endl;
                break;
            case 4:
                bst.display();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}

