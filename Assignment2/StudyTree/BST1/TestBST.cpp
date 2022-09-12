#include "BiTNode.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
	BiTree dt, p;
	int n;
	KeyType j;
	ElemType r;
	Status k;
	FILE* f;

	f = fopen("data.txt", "r");
	if (!f)
	{
		printf("Can not open the file.");
		exit(0);
	}
	fscanf(f, "%d", &n);
	InitBiTree(dt);

	for (int i = 0; i < n; i++)
	{
		InputFromFile(f, r);
		k = InsertBST(dt, r);
		if (!k)
			 printf("%d is already existed in Binary Search Tree dt, so (%d,%d) can not be inserted in dt.\n", 
      r.key, r.key, r.others);
	}
	fclose(f);

	printf("\nIn order traverse binary tree dt:\n");
	InOrderTraverse(dt, Visit);

	printf("\n\nPlease input the key you want to search:");
	scanf("%d", &j);
	p = SearchBST(dt, j);
	if (p)
		printf("The node %d is in the binary tree dt.\n", j);
	else
		printf("\nThe node %d is not in binary tree dt.\n", j);

	DestroyBiTree(dt);

	return 0;

}