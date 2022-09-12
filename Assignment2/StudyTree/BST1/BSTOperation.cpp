

#include "BiTNode.h"
#include <stdlib.h>


void InitBiTree(BiTree& T)
{
	T = NULL;
}

void DestroyBiTree(BiTree& T)
{
	if (T)
	{
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		free(T);
		T = NULL;
	}
}

//先序递归遍历T，对每个结点调用函数Visit一次且仅一次
void PreOderTraverse(BiTree T, void(*Visit)(ElemType))
{
	if (T)
	{
		Visit(T->data);
		PreOderTraverse(T->lchild, Visit);
		PreOderTraverse(T->rchild, Visit);
	}
}

//中序递归遍历T，对每个结点调用函数Visit一次且仅一次
void InOrderTraverse(BiTree T, void(*Visit)(ElemType))
{
	if(T)
	{
		InOrderTraverse(T->lchild, Visit);
		Visit(T->data);
		InOrderTraverse(T->rchild, Visit);
	}
	
}

/*在根指针T所指二叉排序树中递归地查找某关键字等于key的数据元素
* 若查找成功，则返回指向该数据元素结点的指针，否则返回空指针
*/
BiTree SearchBST(BiTree T, KeyType key)
{
	if (!T || key == T->data.key)  //树空或待查找的关键字等于T所指结点的关键字
		return T;
	else if (LT(key, T->data.key))   //待查找的关键字小于T所指结点的关键字
		return SearchBST(T->lchild, key);
	else
		return SearchBST(T->rchild, key);
}

/* 在根指针T所指二叉排序树中递归地查找其关键字等于key的数据元素
* 若查找成功，则指针p指向该数据元素结点，并返回TRUE
* 否则指针p指向查找路径上访问的最后一个结点，并返回FALSE
* 指针f指向T的双亲，其初始值为NULL
*/
Status SearchBST(BiTree& T, KeyType key, BiTree f, BiTree& p)
{
	if (!T)  //查找不成功
	{
		p = f;   //p指向查找路径上访问的最后一个结点
		return FALSE;
	}
	else if (EQ(key, T->data.key)) //查找成功
	{
		p = T;  //指向该数据元素结点
		return TRUE;
	}
	else if (LT(key, T->data.key))  //key 小于T所指结点的关键字
		return SearchBST(T->lchild, key, T, p);
	else   //key 小于T所指结点的关键字
		return SearchBST(T->rchild, key, T, p);
}

/* 若二叉排序树T中没有关键字e.key的元素，插入e并返回TRUE
* 否则返回FALSE
*/
Status InsertBST(BiTree& T, ElemType e)
{
	BiTree p, s=NULL;
	if (!SearchBST(T, e.key, NULL, p))  //查找不成功，p指向查找路径上访问的最后一个叶子结点
	{
		s = (BiTree)malloc(sizeof(BiTree));   //生成新结点
		if (s == NULL)
		{
			printf("Can not create node.");
			exit(0);
		}
		s->data = e;   //给新结点的数据赋值
		s->lchild = s->rchild = NULL;   //给新结点的左右孩子域赋初值空


		if (!T)    //如果树为空
			T = s;
		else if (LT(e.key, p->data.key))  //树不为空，*s的关键字小于*p的关键字
			p->lchild = s;   //待插结点*s为p所指结点的左孩子
		else
			p->rchild = s;  ////待插结点*s为p所指结点的右孩子

		return TRUE;
	}
	return FALSE;
}

void Visit(ElemType c)
{
	printf("(%d, %d)", c.key, c.others);
}

void InputFromFile(FILE* f, ElemType& c)
{
	fscanf(f, "%d%d", &c.key, &c.others);
}

