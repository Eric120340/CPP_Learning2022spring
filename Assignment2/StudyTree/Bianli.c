#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
    char data;              //数据域字符表示
    struct treeNode* LChild;
    struct treeNode* RChild;
}TREE,*LPTREE;
//lp一般指指针别名
/*Create a new node*/
LPTREE createNode(char data)
{
    LPTREE newNode = (LPTREE)malloc(sizeof(TREE));
    newNode->data = data;
    newNode->LChild = NULL;
    newNode->RChild = NULL;
    return newNode;
}
//Random tree
void insertNode(LPTREE father, LPTREE left_child, LPTREE right_child)
{
    father->LChild = left_child;
    father->RChild = right_child;
}

void printCurNodeData(LPTREE curData)
{
    printf("%c\t",curData->data);
}
//递归遍历
void preOrder(LPTREE root)
{
    if(root != NULL)
    {
        printCurNodeData(root); //root
        preOrder(root->LChild); //Left
        preOrder(root->RChild); //Right
    }
}

void midOrder(LPTREE root)
{
    if(root != NULL)
    {
        midOrder(root->LChild); //Left
        printCurNodeData(root); //Root
        midOrder(root->RChild); //Right
    }
}

void lastOrder(LPTREE root)
{
    if(root != NULL)
    {
        lastOrder(root->LChild); //Left
        lastOrder(root->RChild); //Right
        printCurNodeData(root);  //Root
        
    }
}

void preOrderBystack(LPTREE root)
{
    if (root == NULL)
    {
        return;
    }
    LPTREE stack[10];   //存储每次打印节点的位置
    int stackTop = -1;     //栈顶标记
    LPTREE pMove = root;//从根节点开始打印
    while (stackTop != -1 || pMove) //没有到栈顶，当前节点不等于空的时候
    {
        //根 左 右
        while(pMove)    //走过的节点入栈
        {
            //路径入栈
            printf("%c\t",pMove->data);
            stack[++stackTop] = pMove;
            pMove = pMove->LChild;
        }
        //无路可走
        if (stackTop != -1)
        {
            pMove = stack[stackTop];
            stackTop--;
            pMove = pMove->RChild;
        }   
    }
} 
//中序
void midOrderBystack(LPTREE root)
{
    if (root == NULL)
    {
        return;
    }
    LPTREE stack[10];
    int stackTop = -1;
    //定义移动的指针
    LPTREE pMove = root;
    while (stackTop != -1 || pMove)
    {
        /* 走到最左边，把走过的结点入栈 */
        while (pMove)
        {
            stack[++stackTop] = pMove;
            pMove = pMove->LChild;
        }
        //出栈
        if (stackTop != -1)
        {
            pMove = stack[stackTop--];
            printf("%c\t",pMove->data);
            pMove = pMove->RChild;
        }
    }
}

//后序 左 根 右
void lastOrderBystack(LPTREE root)
{
    if (root == NULL)
    {
        return;
    }
    LPTREE stack[10];
    int stackTop = -1;
    //定义移动的指针
    LPTREE pMove = root;
    //定义最后遍历到的结点.访问标记
    LPTREE pLastVisit = NULL;
    //左 右 根
    while (pMove)
    {
        stack[++stackTop] = pMove;
        pMove = pMove->LChild;
    }
    while (stackTop != -1)
    {
        pMove = stack[stackTop--];
        if (pMove->RChild == NULL || pMove->RChild == pLastVisit)//左边是不是空的，右边是不是已经被访问了
        {
            //如果被访问就可以打印 左右访问过才能访问根
            printf("%c\t",pMove->data);
            pLastVisit = pMove; //保存位置 标记
        }
        else
        {
            //右边没有被访问
            stack[++stackTop] = pMove;
            pMove = pMove->RChild;
            while (pMove)
            {
                stack[++stackTop] = pMove;
                pMove = pMove->LChild;
            }
        }
    }
}
int main()
{
    LPTREE A = createNode('A');
    LPTREE B = createNode('B');
    LPTREE C = createNode('C');
    LPTREE D = createNode('D');
    LPTREE E = createNode('E');
    LPTREE F = createNode('F');
    LPTREE G = createNode('G');
    insertNode(A,B,C);
    insertNode(B,D,NULL);
    insertNode(D,NULL,G);
    insertNode(C,E,F);
    preOrder(A);
    printf("\n");
    midOrder(A);
    printf("\n");
    lastOrder(A);
    printf("\n非递归的\n");
    preOrderBystack(A);
    printf("\n中序\n");
    midOrderBystack(A);
    printf("\n后序\n");
    lastOrderBystack(A);
    //system("pause");
    return 0;
}