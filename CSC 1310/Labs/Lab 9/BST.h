#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

class BST{
	private:
		struct Node {
			int data;
			Node* left;
			Node* right;
		};
		
		Node *root;
		
		void insert(Node* &root, Node* &newNode) {
			if (root == nullptr)
				root = newNode;
			else if (newNode->data < root->data)
				insert(root->left, newNode);
			else
				insert(root->right, newNode);
		}

		bool search(Node* root, int target) {
			// TODO Part 2: Implement recursive BST search.
			if(root == nullptr){
				return false;
			}
			if(target == root->data){	//USED https://www.geeksforgeeks.org/dsa/binary-search-tree-set-1-search-and-insertion/ FOR CONCEPT
				return true;
			}
			if(target > root->data){
				return search(root->right, target);
			}
		
			return search(root->left, target);
		}

		int height(Node* root) {
			//base case
			if(root == nullptr){
				return -1;	//no tree height
			}

			//recursion
			int leftH = height(root->left); //grabs height of left side of tree
			int rightH = height(root->right); //grabs heights of right side of tree

			return max(leftH, rightH) + 1; //uses max function to find the max number returned out of the two variables
			
		}

		void destroyTree(Node* nodePtr) {
			if (nodePtr == nullptr) 
				return;
			destroyTree(nodePtr->left);
			destroyTree(nodePtr->right);
			delete nodePtr;
		}

		void runSearchTests(Node* root) {
			int targets[] = {40, 10, 65, 90};
			for (int i=0; i<4; i++) {
				cout << "Search " << targets[i] << ": ";
				if(search(root, targets[i]))
					cout << "Found\n";
				else
					cout << "Not Found\n";
			}
		}
		
	public:
		BST(){
			root = NULL;
			cout << "\n\nTree was created in constructor.\n\n";
		}
		~BST(){
			destroyTree(root);
			cout << "\n\nTree was destroyed in destructor.\n\n";
		}
		void insert(int data){
			Node* newNode;
			newNode = new Node;
			newNode->data = data;
			newNode->left = NULL;
			newNode->right = NULL;
			
			insert(root, newNode);			
		}
		
		void destroyTree(){
			destroyTree(root);
			root = NULL;
		}
		
		void searchTests(){
			runSearchTests(root);
		}
		
		int getHeight(){
			return height(root);
		}
};

#endif