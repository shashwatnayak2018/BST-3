#include<iostream>
using namespace std;


class Node{
public:
    int data;
    Node * left;
    Node * right;
    Node * parent;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
        parent = NULL;
    }  
};

class BST{
public:
    Node * root;
    BST(){
        root = NULL;
    }
    void insertHelper(int value){
        insert(root, value);
    }
    void insert(Node *curr, int value){
        // If root is NULL, then create a node and make it root. 
        if (root == NULL) root = new Node(value);
        // Else Decide to move left or right. 
        else if (value < curr->data)  {
            // if left is already NULL, create a new node and link it. 
            if (curr->left == NULL) {
                curr->left = new Node(value);
                curr->left->parent = curr;
            }
            // Move left and call insert there. 
            else insert(curr->left, value);
        }
        else {
            // if right is already NULL, create a new node and link it. 
            if (curr->right == NULL) {
                curr->right = new Node(value);
                curr->right->parent = curr;
            }
            // Move right and call insert there. 
            else insert(curr->right, value);
        }
    }
    void displayHelper(){
        display(root);
    }
    void display(Node * curr){
        // Case for empty tree and leaf nodes children.
        if( curr ==  NULL) return;
        // IN order print.
        // Print left. 
        display(curr->left);
        // Print myself.
        cout << curr->data << ", ";
        // Print right.
        display(curr->right);
    }
    Node * searchHelper(int value){
        return search(root, value);
    }
    Node * search(Node * curr, int value){
        // Are you the value? or Are you NULL?  if yes return curr
        if(curr == NULL || curr->data == value ) return curr;
        // else you search in right or left. 
        // Left
        else if(value < curr->data) return search(curr->left, value);
        // Right
        else  return search(curr->right, value);
    }
    void print2DUtil(Node *root, int space)  
    {  
        // Base case  
        if (root == NULL)  
            return;  
        // Increase distance between levels  
        space += 5;  
        // Process right child first  
        print2DUtil(root->right, space);  
    
        // Print current node after space  
        // count  
        cout<<endl;  
        for (int i = 5; i < space; i++)  
            cout<<" ";  
        cout<<root->data<<"\n";  
    
        // Process left child  
        print2DUtil(root->left, space);  
    }  
  
    // Wrapper over print2DUtil()  
    void print2D()  
    {  
        cout << "******************************" << endl;
        // Pass initial space count as 0  
        print2DUtil(root, 0);  
        cout << "******************************" << endl;
        
    }

	int count(Node * current)
	{
		int i = 0;
		if(current != NULL)
		{
			i++;
			i = i + count(current->left);
			i = i + count(current->right);
		}
		return i;
	}

	int height(Node * current)
	{
		int h;
		if(current == NULL)
		{
			return 0;
		}
		int left = height(current->left);
		int right = height(current->right);
		if(left > right)
		{
			h = 1+left;
		}
		else
		{
			 h = 1+right;
		}
		return h;
	}
	int rangesearchhelper(int k1, int k2)
	{
		cout<<"nodes and number of nodes between k1 and k2 is";
		rangesearch(root, k1, k2, 0);
	}
		
	int rangesearch(Node * current, int k1, int k2,int i)
	{
		if(current == NULL)
		{
			return i;
		}
		if(k1 < current->data)
		{
			i = rangesearch(current->left, k1, k2,i);
		}
		if(k1 <= current->data && k2 >= current->data)
		{
			i++;
			cout<<current->data<<"->";
		}
		if(k2 > current->data)
		{
			i = rangesearch(current->right, k1, k2,i);
		}
		return i;	
	}
	
};

int main(){
    
    BST bst1;
    bst1.insertHelper(4);
    bst1.insertHelper(2);
    bst1.insertHelper(3);
    bst1.insertHelper(1);
    bst1.insertHelper(6);
    bst1.insertHelper(5);
    bst1.insertHelper(7);
    bst1.insertHelper(8);
    bst1.displayHelper();
    if(bst1.searchHelper(3) != NULL){
        cout << endl << bst1.searchHelper(3)->data << endl;
    }
    bst1.print2D();
    cout<<bst1.height(bst1.root)<<endl;
    cout<<bst1.count(bst1.root)<<endl;
    //bst1.rangesearch(bst1.root,3,7);
	cout<<bst1.rangesearchhelper(4,7);
}
