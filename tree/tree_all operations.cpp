#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
	
	node (int t_data)
	{
		data=t_data;
		left=NULL;
		right=NULL;
	}
	
};

class tree{
	
	public:
		struct node * root;
		bst(){
			root=NULL;
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
		
		
			  
			void inorder(struct node* root)
			{
			    if (root == NULL)
			        return;
			 
			    // Traverse left subtree
			    inorder(root->left);
			 
			    // Visit node
			    cout << root->data << " ";
			 
			    // Traverse right subtree
			    inorder(root->right);
			}
			bool search(int t_data){
				while(root!=NULL){
					if(root->data == t_data){
						return 1;
					}
					if(t_data < root->data)
					{
						root=root->left;
					}else{
						root=root->right;
					}
				}
			}
		
			struct node * inorderpredesessor(struct node *current){
				//INORDER PREDESSSESOR MEANS LEFT SUBTREE KA RIGHT MOST CHILD
				current=current->left;
				while(current->right!=NULL)
				{
					current=current->right;
				}
				return current;
				
			}
			
			struct node* deletion(struct node *root ,int t_data){
				// delete leaf node
				//delete non leaf node exchange the node with its inorder predesesor or inorder successor
				//delete root node
			struct node *current=root ;
			struct node * ipre;
			
			if(current==NULL)
			{
				return NULL;
			}
			if(current->left==NULL && current->right==NULL){
				free(current);
				return NULL;
			}
				
				//step1 search for the node
			
				if(t_data < current->data)
				{
					current->left=deletion(current->left,t_data);
				}
				else if(t_data > current->data)
				{
					current->right=deletion(current->right,t_data);
				}
				else{
				
					//step2 deletion process when the node is found
				
					ipre=inorderpredesessor(current);
					
					current->data=ipre->data;
					current->left=deletion(current->left,ipre->data);
				}
				
				
				
			
			return current;
			}



//struct node * inorderpredesessor(struct node *current){
//    // INORDER PREDECESSOR MEANS LEFT SUBTREE KA RIGHT MOST CHILD
//    while (current->right != NULL) {
//        current = current->right;
//    }
//    return current;
//}
//
//struct node* deletion(struct node *root ,int t_data){
//    // delete leaf node
//    // delete non-leaf node exchange the node with its inorder predecessor or inorder successor
//    // delete root node
//    struct node *current = root;
//    struct node *ipre;
//
//    if (current == NULL) {
//        return NULL;
//    }
//    if (current->left == NULL && current->right == NULL){
//        free(current); // Delete leaf node and free memory
//        return NULL;
//    }
//
//    // Step 1: search for the node
//    if (t_data < current->data) {
//        current->left = deletion(current->left, t_data);
//    }
//    else if (t_data > current->data) { // Remove semicolon
//        current->right = deletion(current->right, t_data);
//    }
//    else {
//        // Step 2: deletion process when the node is found
//        if (current->left == NULL) {
//            struct node* temp = current->right;
//            free(current);
//            return temp;
//        }
//        else if (current->right == NULL) {
//            struct node* temp = current->left;
//            free(current);
//            return temp;
//        }
//        // Node has two children
//        ipre = inorderpredesessor(current->left);
//        current->data = ipre->data;
//        current->left = deletion(current->left, ipre->data);
//    }
//    return current;
//}

			
			

};
 int main()
 {
 	tree bst;
 	int op,t_data;
do {
        cout << "\n_________________________________\n";
        cout << "\n1. Insert";
        cout << "\n2. Inorder Traversal";
       	cout << "\n3. search";
       	cout << "\n4. delete";
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
            bst.inorder(bst.root);
            break;
        case 3:
        	cout << "\nEnter data to search: ";
            cin >> t_data;
           int n;
			n=bst.search(t_data);
            if(n!=0){
            	cout<<" element found";
			}
			else
			{
				cout<<"element not found";
			}
            break;
		
		case 4:
        	cout << "\nEnter data to delete: ";
            cin >> t_data;
            
        	bst.deletion(bst.root,t_data);
        	cout<<"node deteted"
            ;break;
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
