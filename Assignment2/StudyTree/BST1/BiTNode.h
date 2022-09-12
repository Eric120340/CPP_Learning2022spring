
#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define TRUE 1
#define FALSE 0

//typedef int ElemType;
typedef int Status;
typedef int KeyType;

#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define GT(a,b) ((a)>(b))

struct ElemType {
	KeyType key;  //关键字
	int others;    // 其他数据
};

typedef struct BiTNode {
	ElemType data;    //结点的值
	BiTNode* lchild, * rchild;   //左右孩子指针
} BiTNode, *BiTree;




void InitBiTree(BiTree& T);
void DestroyBiTree(BiTree& T);
void PreOderTraverse(BiTree T, void(*Visit)(ElemType));
void InOrderTraverse(BiTree T, void(*Visit)(ElemType));
BiTree SearchBST(BiTree T, KeyType key);
Status SearchBST(BiTree& T, KeyType key, BiTree f, BiTree& p);
Status InsertBST(BiTree& T, ElemType e);

void Visit(ElemType c);
void InputFromFile(FILE* f, ElemType& c);




