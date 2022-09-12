#include <stdio.h>
#define BUF_LEN_MAX 3       //定义一个宏buf的大小
#define DATA_LEN_MAX 3      //该宏定义来存放data字段buf的大小
typedef unsigned char uint8_t;  //unsigned char 重新命名为uint8_t
typedef struct          //结构体，并且用typedef重新命名为RF_FRAME
{
    /* data */
    uint8_t head;
    uint8_t len;
    uint8_t add;
    uint8_t data[DATA_LEN_MAX];
    uint8_t chk;
}RF_FRAME;      //重新命名

RF_FRAME txbuf[BUF_LEN_MAX] = {         //定义一个RF_FRAME类型的txbuf[]并进行初始化。
    {0xAA,6,0x00,0x11,0x11,0x11,0xE3},
    {0xAA,6,0x01,0x22,0x22,0x22,0x17},
    {0xAA,6,0x02,0x33,0x33,0x33,0x48}
};
void output(RF_FRAME *p_ptr);       //声明output函数

int main(void)
{
    RF_FRAME  *ptr_tmp;     //定义RF_FRAME类型的指针变量ptr_tmp
    ptr_tmp = txbuf;        //给指针变量ptr_tmp赋值，让它指向数组txbuf。ptr_tmp是指向结构体的指针变量
    output(ptr_tmp);        //调用output函数，output是一个带参的函数：指针类型
    return 0;
}

void output(RF_FRAME *p_ptr)        //output函数体，形参p_ptr同时指向实参ptr_tmp.两者同时指向数组txbuf[]
{
    uint8_t i,j;                    //定义辅助变量
    for(i=0;i<BUF_LEN_MAX;i++)      //这个for是以输出数组txbuf[]的3个数组元素
    {
        printf(" %x",p_ptr[i].head);    //p_ptr[i].head就相当于txbuf[i].head
        printf(" %x",p_ptr[i].len);
        printf(" %x",p_ptr[i].add);

        for(i=0;i<DATA_LEN_MAX;i++)     //这个for循环是用来输出data字段的3个元素
        {
            printf(" %x",p_ptr[i].data[j]);
        }
        printf("%x\n",p_ptr[i].chk);
    }
}
