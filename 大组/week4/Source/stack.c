#if !defined(stack)
#define stack

#include <stdio.h>
#include <stdlib.h>
#include "../Header/binary_sort_tree.h" 
//链栈

//初始化栈
Status initLStack(LinkStack *s){
    s->top = NULL;
    s->count = 0;
    if (s->top == NULL && s->count == 0) {
        return succeed;
    }else {
        return failed;
    }
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if (s->count == 0) {
        // 是空栈
        return succeed;
    }else if (s->count > 0) {
        // 不是空栈
        return failed;
    }
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	// 判断栈是否为空
    if (isEmptyLStack(s) == succeed) {
        // 为空
        printf("This Stack is Empty!!!\n");
        return failed;
    }
    // 获取栈顶元素
    if (s->top != NULL) {
        *e = s->top->data;
        return succeed;
    }
}

//清空栈
Status clearLStack(LinkStack *s){
	// 检测栈是否为空
    if(isEmptyLStack(s) == succeed) {
        printf("It neednt to clear!\n");
        return succeed;
    }
    // 开始清空
    LinkStackPtr FreeToolPTR = s->top;
    while (FreeToolPTR != NULL) {
        s->top = s->top->next;
        free(FreeToolPTR);
        // 移动指针
        FreeToolPTR = s->top;
        // 节点数量减少
        s->count--;
    }
    return succeed;
}

//销毁栈
Status destroyLStack(LinkStack *s){
	// 先清空栈的内容
    clearLStack(s);
    // 销毁栈
    free(s);
    return succeed;
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	// 初始化栈的长度
    *length = 0;
    // 获取栈的长度
    *length = s->count;
    if (*length < 0) {
        return failed;
    }else {
        return succeed;
    }
}

//入栈
Status pushLStack(LinkStack *s,ElemType data){
    // 创建节点
    LinkStackPtr MyStackNode = (LinkStackPtr)malloc(sizeof(StackNode));
    // 检查是否分配成功
    if (MyStackNode == NULL) {
        pfailed("malloc failed!");
        exit(0); // 退出
    }
    // 
    MyStackNode->data = data;
	// 检查栈是否为空
    if (isEmptyLStack(s) == succeed) {
        MyStackNode->next = NULL;
    }else if (isEmptyLStack(s) == failed) {
        MyStackNode->next = s->top;
    }
    // 将栈顶指针移动到栈顶
    s->top = MyStackNode;
    // 栈内节点数加一
    s->count++;
}

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	// 检查栈是否为空
    if (isEmptyLStack(s) == succeed) {
        printf("The Stack is Empty!!!");
        return failed;
    }
    // 开始出栈
    // 创建一个用于free的指针
    LinkStackPtr FreePTR = s->top;
    LinkStackPtr SearchPTR = s->top;
    Status isExist;
    while (SearchPTR != NULL) {
        if(SearchPTR->data == *data) {
            isExist = succeed; // 链栈中存在要出栈的节点
            break;
        }else {
            isExist = failed;
            SearchPTR = SearchPTR->next;
        }
    }
    if (isExist == failed) {
        printf("The data you want to pop isnt exist!\n");
        return failed;
    }else if (isExist == succeed) {
        // 从栈顶开始依次出栈
        while(FreePTR != SearchPTR->next ) {
            // 检查是否已经是最后一个了
            if (FreePTR == NULL) {
                break;
            }
            // 移动栈顶的指针
            s->top = s->top->next;
            // 开始清除
            free(FreePTR);
            // 移动Free指针
            FreePTR = s->top;
            // 栈内节点数减一
            s->count--;
        }
        // 返回成功
        return succeed;
    }
}

//打印栈
Status print(LinkStack* s) {
    // 检查栈是否为空
    if(isEmptyLStack(s) == succeed) {
        printf("There is nothing in this stack!\n");
        return failed;
    }
    // 开始打印栈
    LinkStackPtr APTR = s->top;
    while (APTR != NULL) {
        printf("%d\n",APTR->data);
        APTR = APTR->next;
    }
    return succeed;
}


#endif // stack
