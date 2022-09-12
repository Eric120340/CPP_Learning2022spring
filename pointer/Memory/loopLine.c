

#define QueueSize_UartLen 8
typedef struct 
{
    int front;  //指向队伍头
    int rear;   //指向队伍尾
    int counter;    //counter用来记录队列元素的个数，方便判断队空、队满。int类型的数组用来存储队列元素
    int uart_data[QueueSize_UartLen];
}CIRQUEUE_UART;

//队列初始化
void InitQueue(CIRQUEUE_UART *queue)    //对指定队列进行初始化
{
    queue->front = 0;
    queue->rear = 0;
    queue->counter = 0;
}
//2.入队
//首先判断是否满，满就不能进行入队操作
int InQueue(CIRQUEUE_UART *queue, int data)
{
    if(QueueFull(queue))        //判断堆满函数QueueFull（），判断队列是否还有剩余空间。
    {
        //输出队满提示
        return 0;               //如果满了就返回0，提示队满
    }
    else                        //没有满就执行else，先让data入队，存放在queue->counter加1
    {
        queue->uart_data[queue->rear] = data;
        queue->counter++;       //记录有数据入队了
        queue->rear = (queue->rear+1) % QueueSize_UartLen;  //指向下一个带插入的数据位置
        //replace
/*         if(queue->rear + 1 ==QueueSize_UartLen)
        {
            queue->rear = 0;
        }
        else
        {
            queue->rear ++;
        } */

        return 1;
    }
    //3.出队
    //还是先要判断队列是否为空，否则也会有溢出的问题
    int OutQueue(CIRQUEUE_UART *queue, int *p_data)
    {
        if(QueueEmpty(queue))
        {
            return 0;
        }
        else{
            *p_data = queue -> data(front);
            queue->counter--;
            queue -> front =(queue->front + 1) % QueueSize_UartLen;
        }
    }
}
