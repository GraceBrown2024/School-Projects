#include <iostream>
#include "BST.h"
using namespace std;

const int SIZE = 8;

int main() 
{
	int firstOrder[SIZE] = {50, 30, 70, 20, 40, 60, 80, 10};
	int sortedOrder[SIZE] = {10, 20, 30, 40, 50, 60, 70, 80};
	BST tree;

	cout << "PART 1 - Original insertion order\n";
	for (int i=0; i<SIZE; i++)
	{
		tree.insert(firstOrder[i]);
	}
	cout << "\n\nPART 2 - Search tests\n";
	tree.searchTests();
	cout << "\n\nPART 3 - Original tree height: " << tree.getHeight() << "\n\n";
	tree.destroyTree();
	
	cout << "PART 4 - Sorted insertion order\n";
	for (int i=0; i<SIZE; i++)
	{
		tree.insert(sortedOrder[i]);
	}
	cout << "Sorted tree height: " << tree.getHeight() << '\n';

	return 0;
}