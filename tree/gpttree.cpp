#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
    
    node (int t_data) {
        data = t_data;
        left = NULL;
        right = NULL;
    }
};

class tree {
public:
    struct node * root;
    
    tree() {
        root = NULL;
    }
    
    void insert(int t_data) {
        struct node *newnode = new node(t_data);
        
        if (root == NULL) {
            root = newnode;
        }
        else {
            struct node *current = root;
            struct node *parent = NULL;
            
            while (current != NULL) {
                parent = current;
                
                if (t_data == current->data) {
                    cout << "Duplicate cannot be inserted." << endl;
                    return;
                }
                else if (t_data < current->data) {
                    current = current->left;
                }
                else {
                    current = current->right;
                }
            }
            
            if (t_data < parent->data) {
                parent->left = newnode;
            }
            else {
                parent->right = newnode;
            }
        }
    }
    
    void inorder(struct node* root) {
        if (root == NULL)
            return;
        
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    
    struct node* search(int t_data) {
        struct node *current = root;
        
        while (current != NULL) {
            if (current->data == t_data) {
                return current;
            }
            else if (t_data < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        
        return NULL; // Element not found
    }
};

int main() {
    tree bst;
    int op, t_data;
    do {
        cout << "\n_________________________________\n";
        cout << "\n1. Insert";
        cout << "\n2. Inorder Traversal";
        cout << "\n3. Search";
        cout << "\n99. Exit";
        cout << "\nEnter option: ";
        cin >> op;
        
        switch (op) {
            case 1:
                cout << "\nEnter data to insert: ";
                cin >> t_data;
                bst.insert(t_data);
                break;
                
            case 2:
                cout << "\nInorder Traversal: ";
                bst.inorder(bst.root);
                cout << endl;
                break;
                
            case 3:
                cout << "\nEnter data to search: ";
                cin >> t_data;
                if (bst.search(t_data) != NULL) {
                    cout << "Element found" << endl;
                } else {
                    cout << "Element not found" << endl;
                }
                break;
                
            case 99:
                cout << "\nExiting program.\n";
                break;
                
            default:
                cout << "\nInvalid option.\n";
                break;
        }
    } while (op != 99);
    
    return 0;
}

