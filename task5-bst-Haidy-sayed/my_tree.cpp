//============================================================================
// Name        : BST.cpp
// Author      : Haidy Sayed Hassan
// Version     :
// Copyright   : Your copyright notice
// Description : BST
//============================================================================
#include <iostream>
#include<bits/stdc++.h>


using namespace std;

int siz=0;
int i=0;//countr for node in insertion function
int TLength;

struct Node {
	int data;
	Node* left;
	Node* right;
};
Node* root = NULL;  // Creating an empty tree

// Function to create a new Node in heap
Node* CreateNode(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	siz++;
	return newNode;

}

// To insert data in BST, returns address of root node
Node* Insert(Node* root,int data) {
	if(siz==TLength){
		std::cout<<"Max size of tree reached you cannot insert anymore"<<endl;
		return root;
	}else{
	if(root == NULL) { // empty tree
		root = CreateNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree.
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree.
	else {
		root->right = Insert(root->right,data);
	}
	return root;}
}
//To search an element in BST, returns true if element is found
bool Search(Node* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}

void postOrderIter(Node* root){
	if (root == NULL) {
	    return;
	  }
	  stack<Node*> postTempTree;
	  postTempTree.push(root);

	  while (!postTempTree.empty()) {
	    Node* next = postTempTree.top();

	    bool finishedSubtrees = (next->right == root || next->left == root);
	    bool isLeaf = (next->left == NULL && next->right == NULL);
	    if (finishedSubtrees || isLeaf) {
	    	postTempTree.pop();
	      std::cout<<(next->data)<<" ";
	      root = next;
	    }
	    else {
	      if (next->right != NULL) {
	    	  postTempTree.push(next->right);
	      }
	      if (next->left != NULL) {
	    	  postTempTree.push(next->left);
	      }
	    }
	  }


}
void preOrderIter(Node* root){
	if (root == NULL)
	        return;

	    // Create an empty stack and push root to it
	    stack<Node*> preTreeTemp;
	    preTreeTemp.push(root);
	    while (preTreeTemp.empty() == false) {
	        // Pop the top item from stack and print it
	        Node* tempNode = preTreeTemp.top();
	        std::cout<<tempNode->data<<" ";
	        preTreeTemp.pop();

	        // Push right and left children of the popped node to stack
	        if (tempNode->right)
	        	preTreeTemp.push(tempNode->right);
	        if (tempNode->left)
	        	preTreeTemp.push(tempNode->left);
	    }

}
void inOrderIter(Node* root){
	    stack<Node *> tempTree;
	    Node *currentNode = root;

	    while (currentNode != NULL || tempTree.empty() == false)
	    {
	        /* Reach the left most Node of the
	           currentNode Node */
	        while (currentNode !=  NULL)
	        {
	        	tempTree.push(currentNode);
	            currentNode = currentNode->left;
	        }

	        /* Current must be NULL at this point */
	        currentNode = tempTree.top();
	        tempTree.pop();

	        cout << currentNode->data << " ";
	        currentNode = currentNode->right;

	    } /* end of while */

}

void inOrderRec(Node* root){
		  if (root != NULL) {
			  inOrderRec(root->left);
			  cout<<root->data<<" ";
			  inOrderRec(root->right);
	}
}

void preOrderRec(Node* root) {
   if (root != NULL) {
      cout<<root->data<<" ";
      preOrderRec(root->left);
      preOrderRec(root->right);
   }
}

void postOrderRec(Node* root) {
   if (root != NULL) {
	   postOrderRec(root->left);
	   postOrderRec(root->right);
      cout<<root->data<<" ";
   }
}

void breadthTrav()
{
	queue<Node *> breadthTempTree;
	breadthTempTree.push(root);
	   while (breadthTempTree.empty() == false) {
	      Node* tempNodeBreadth = breadthTempTree.front();
	      cout << tempNodeBreadth->data << " ";
	      breadthTempTree.pop();
	      if (tempNodeBreadth->left != NULL)
	    	  breadthTempTree.push(tempNodeBreadth->left);
	      if (tempNodeBreadth->right != NULL)
	    	  breadthTempTree.push(tempNodeBreadth->right);
	   }
}
int size(){
	return siz;
}

void prepInsert(){
		int TLength=size()+1;
		int temp;
	for(i;i<TLength;i++){
			std::cout<<"Please Insert your "<<(i+1)<<"th"<<" node's data"<<endl;
			std::cin>>temp;
			root = Insert(root,temp);
		}
}

void prepSearch(){

	// Ask user to enter a number.
		int number;
		cout<<"Enter number be searched"<<endl;
		cin>>number;
		//If number is found, print "FOUND"
		if(Search(root,number) == true) cout<<"Found"<<endl;
		else cout<<"Not Found"<<endl;
}
void inOrderPrep(){
	int choice;
	std::cout<<"Please insert 1 for Recursive in-order search, or 2 for Iterative in-order Search"<<endl;
	std::cin>>choice;
	if(choice ==1){
		inOrderRec(root);
	}
	else{
		inOrderIter(root);
	}
}
void preOrderPrep(){
	int choice;
		std::cout<<"Please insert 1 for Recursive pre-order search, or 2 for Iterative pre-order Search"<<endl;
		std::cin>>choice;
		if(choice ==1){
			preOrderRec(root);
		}
		else{
			preOrderIter(root);
		}

}
void postOrderPrep(){
	int choice;
		std::cout<<"Please insert 1 for Recursive post-order search, or 2 for Iterative post-order Search"<<endl;
		std::cin>>choice;
		if(choice ==1){
			postOrderRec(root);
		}
		else{
			postOrderIter(root);
		}

}
void opChecker(int opCode){
	switch (opCode){
	case 1: prepInsert();
		break;
	case 2:	prepSearch();
		break;
	case 3: inOrderPrep();
		break;
	case 4:	preOrderPrep();
		break;
	case 5:	postOrderPrep();
		break;
	case 6: breadthTrav();
		break;
	case 7: std::cout<<endl<<size();
		break;
	}

}

int main() {
	//Node* root = NULL;  // Creating an empty tree

	int op;
	//int temp;
	int numOperations=0;
	std::cout<<"Insert how many nodes are you willing to add to your BST"<<endl;
	std::cin>>TLength;
	std::cout<<"Insert the number of operations you are about to perform on the tree"<<endl;
	std::cin>>numOperations;
	for(int iter=0; iter <numOperations;iter++){
		std::cout<<endl<<"Insert the number corresponding to the operation you want:"<<endl<<"1- For Inserting an element"<<endl<<"2- For Searching for a certain element"<<endl<<"3- For in-order search"<<endl<<"4- For pre-order search"<<endl<<"5- For post-order search"<<endl<<"6- For breadth search"<<endl<<"7- For size"<<endl;
		std::cin>>op;
		opChecker(op);
	}
	std::cout<<endl<<"Thanks for using this BST code!";


}
