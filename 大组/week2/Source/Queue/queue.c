#if !defined(queue_h)
#define queue_h


#include <stdio.h>
#include <stdlib.h>


// 定义 Node 结构体
typedef struct Node {
    void *data;
    struct Node *next;
} Node;

// 定义 LQueue 结构体
typedef struct {
    Node *front;
    Node *rear;
    int length;
} LQueue;

// 定义 Status 类型
typedef enum {
    FALSE = 0,
    TRUE = 1
} Status;

// 函数原型
void InitLQueue(LQueue *Q);
void DestoryLQueue(LQueue *Q);
Status IsEmptyLQueue(const LQueue *Q);
Status GetHeadLQueue(LQueue *Q, void *e);
int LengthLQueue(LQueue *Q);
Status EnLQueue(LQueue *Q, void *data);
Status DeLQueue(LQueue *Q);
void ClearLQueue(LQueue *Q);
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q));
void LPrint(void *q);


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Q->front = NULL;
    Q->rear = NULL;
    Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	/* 清除队列中所有的节点和销毁队列 */
    // 开始清除队列中的节点
    ClearLQueue(Q);
    // 销毁队列
    free(Q);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if (Q->length == 0 && Q->front == NULL && Q->rear == NULL) {
        // 为空
        return TRUE;
    }else {
        // 不为空
        return FALSE;
    }
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	// 判断队列是否为空
    if (IsEmptyLQueue(Q)) {
        // 为空，无法获取
        printf("The LQueue is Empty!\n");
        return FALSE;
    }else {
        e = Q->front;
        return TRUE;
    }
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	return (int)Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
	// 开辟新的节点
    Node * MyNode = (Node *)malloc(sizeof(Node));
    // 检查是否创建成功
    if (MyNode == NULL) {
        perror("create failed!!!\n");
        return FALSE;
    }

    MyNode->data = data;
    // 检查队列是否为空
    if (IsEmptyLQueue(Q)) {
        Q->front = MyNode;
        Q->rear = MyNode;
        Q->length++;
    }else { // 不为空
        Q->rear->next = MyNode;
        Q->rear = MyNode;
        Q->length++;
    }
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	// 检查队列是否为空
    if (IsEmptyLQueue(Q)) {
        printf("This Queue is Empty!\n");
        return FALSE;
    }
    // 将末尾的节点出队
    Node *SearchPTR = Q->front;
    while(SearchPTR->next != Q->rear) {
        SearchPTR = SearchPTR->next;
    }
    free(Q->rear);
    Q->rear = SearchPTR;
    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	// 检查队列是否为空
    if (IsEmptyLQueue(Q)) {
        return;
    }

    // 开始清除队列中的节点
    Node *FreeToolPTR = Q->front;
    Node *TempToolPTR = NULL;
    while (FreeToolPTR != NULL) {
        TempToolPTR = FreeToolPTR->next;
        free(FreeToolPTR);
        FreeToolPTR = TempToolPTR;
    }
    // 修改队列信息
    Q->front = NULL;
    Q->rear = NULL;
    Q->length = 0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
    if (IsEmptyLQueue(Q)) {
        printf("The Queue is Empty!\n");
        return FALSE;
    }
    Node *currentNode = Q->front;
    while (currentNode != NULL) {
        foo(currentNode->data);
        currentNode = currentNode->next;
    }
    return TRUE;	
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void LPrint(void *q){
    // 将 void* 转换为 int*，然后解引用得到整数值
    int value = *(int *)q;
    // 打印整数值
    printf("%d\n", value);
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED


