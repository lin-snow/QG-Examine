#include <stdio.h>
#include <stdlib.h>

#include "../../Header/Stack/stack.h"
#include "./stack.c"

int main()
{
    system("cls");

    printf("本程序已经过以下各项功能测试,没有出现错误，详细可阅读测试源码！\n");
    /* ---------------测试开始----------------- */

    /* 开始实现链栈， */ 
    // 创建链栈
    LinkStack *MyLinkStack = (LinkStack *)malloc(sizeof(LinkStack));
    // 初始化栈
    initLStack(MyLinkStack);
    
    // 入栈测试
    ElemType data1 = 1;
    ElemType data2 = 2;
    ElemType data3 = 3;
    pushLStack(MyLinkStack, data1); // 推入第一个
    pushLStack(MyLinkStack, data2); // 推入第二个
    pushLStack(MyLinkStack, data3); // 推入第三个
    // 检查是否有推入
    print(MyLinkStack);
    system("pause"); // 查看结果
    
    // 检查栈的长度
    int length;
    LStackLength(MyLinkStack, &length);
    printf("length should be 3 , now is %d\n");
    system("pause"); // 查看结果
    
    // 得到栈顶元素
    ElemType e;
    getTopLStack(MyLinkStack, &e);
    printf("%d\n", e);
    system("pause"); // 查看结果
    
    // 出栈测试
    ElemType datatopop = data2;
    popLStack(MyLinkStack, &datatopop);
    print(MyLinkStack); 
    system("pause"); // 查看结果

    // 开始清空栈测试
    printf("before clear!\n"); 
    print(MyLinkStack);
    system("pause");
    clearLStack(MyLinkStack);
    printf("Aftere clear!\n");
    print(MyLinkStack);  
    system("pause"); // 查看结果
    
    // 开始销毁栈测试
    // 先给清空的栈添加点节点
    pushLStack(MyLinkStack, data1); // 推入第一个
    pushLStack(MyLinkStack, data2); // 推入第二个
    pushLStack(MyLinkStack, data3); // 推入第三个
    printf("before destroy!\n");
    print(MyLinkStack);
    destroyLStack(MyLinkStack);
    printf("Aftere destroy!\n");
    print(MyLinkStack);
    system("pause");

    /* ---------------测试完毕----------------- */
    /* 一切正常 */
    return 0;
}



