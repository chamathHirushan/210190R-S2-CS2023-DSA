#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root != NULL){
        traverseInOrder(root->left);
        cout << root->key << " ";
        traverseInOrder(root->right);
    }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {

  if (node == NULL) {
    //create the node with key at found position
    struct node* newNode = new struct node;
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;

  } 
  else if (key <= node->key) {
        node->left = insertNode(node->left, key); //find the position at left path
  } 
  else {
        node->right = insertNode(node->right, key); //find the position at right path
  }
  return node;
}

//Finding the node with minimum key
struct node* minNode(node* root)
{
	while(root->left != NULL){
        root = root->left;
    }
	return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key){
  
	if(root == NULL){
        return root; //No such node
    }
    else if(key < root->key){
        root->left = deleteNode(root->left,key); //find the node at left path
    }
    else if (key > root->key){
        root->right = deleteNode(root->right,key); //find the node at right path
	}
    else {
		// No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//One child at right
        else if(root->right == NULL) {
			struct node *temp = root;
			root = root->left;
			delete temp;
		}
        //One chld at left
		else if(root->left == NULL) {
			struct node *temp = root;
			root = root->right;
			delete temp;
		}
		//Two children
		else { 
			struct node *temp = minNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right,temp->key);
		}
	}
	return root;

}

// Driver code
int main() {
    struct node *root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch(operation) {
        case 1: // insert
            cin >> operand;
            root = insertNode(root, operand);
            cin >> operation;
            break;
        case 2: // delete
            cin >> operand;
            root = deleteNode(root, operand);
            cin >> operation;
            break;
        default:
            cout << "Invalid Operator!\n";
            return 0;
        }
    }
  
    traverseInOrder(root);
}