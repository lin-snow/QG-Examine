#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// #include "..\\Headers\\menu.h"


struct Node {
    // 数据域
    int data; // 作为演示，数据存储为有序数字
    // 指针域
    struct Node * prev; // 该节点上一个节点的地址
    struct Node * next; // 该节点下一个节点的地址
};

struct LinkList {
    // 头节点
    struct Node * Head; // 链表中第一个节点的地址
    // 尾节点
    struct Node * Tail; // 链表中最后一个节点的地址
    // 链表信息
    int LinkList_Size; // 链表中的节点数量
};

// // 创建单向链表
// struct LinkList * UniLinkList;

// // 创建双向链表
// struct LinkList * BiLinkList;

// // 创建循环链表
// struct LinkList * LoopLinkList;

// 函数原型
void InitLinkList(struct LinkList * LinkList); // 链表初始化函数
void InitNode(struct Node * MyNode); // 节点初始化函数
_Bool isLinkListEmpty(struct LinkList * MyLinkList); // 判断链表是否为空函数
void AppendUniNode(struct LinkList* LinkList); // 单向链表节点创建函数
void InsertUniNode(struct LinkList* LinkList); // 单向链表节点插入函数
void AppendBiNode(struct LinkList* LinkList); // 双向链表节点创建函数
void InsertBiNode(struct LinkList* LinkList); // 双向链表节点插入函数
void FreeLinkList(struct LinkList * LinkListToFree); // 释放链表函数
void oeswap(struct LinkList * LinkList); // 单向链表奇偶调换
struct Node * FindMidPoint(struct LinkList * LinkList); // 找到链表的中点
_Bool isLoop(struct LinkList * LinkList); // 判断链表是否成环
void NonRecReverse(struct LinkList * LinkList); // 非递归反转链表
void RecReverse(struct LinkList * LinkList); // 递归反转链表

int main()
{
    system("cls"); // 清理屏幕
    printf("各项功能都写完了，已经测试完毕，详细查看各功能源码。\n");
// ----------------------------------没用的测试代码-----------------------
    // // 创建单向链表
    // UniLinkList = (struct LinkList *)malloc(sizeof(struct LinkList));
    // // 初始化单向链表
    // InitLinkList(UniLinkList); 
    // // 输入需要创建的单向节点数量
    // int Node_Num = 0;
    // printf("Please input the number of the Node that you want to create: ");
    // scanf("%d", &Node_Num);
    // for(int i = 1;i <= Node_Num;i++ ) {
    //     AppendUniNode(UniLinkList);
    // }
    // // 遍历链表，查看创建结果
    // struct Node * ToolPTR = UniLinkList->Head; // 用于遍历节点的指针
    // if(!isLinkListEmpty(UniLinkList)) {
    //     while(ToolPTR != NULL) {
    //         printf("I'm the %d Node.\n",ToolPTR->data);
    //         ToolPTR=ToolPTR->next;
    //     }
    // }

    // // FreeLinkList(UniLinkList); // 释放单向链表
    // // 创建双向链表
    // BiLinkList = (struct LinkList *)malloc(sizeof(struct LinkList));
    // // 初始化双向链表
    // InitLinkList(BiLinkList);
    // // 输出需要创建的双向节点数量
    // printf("Please input the number of the Node that you want to create: ");
    // scanf("%d", &Node_Num);
    // for(int i = 1;i <= Node_Num;i++ ) {
    //     AppendBiNode(BiLinkList);
    // }
    // // 遍历链表，查看创建结果
    // if(!isLinkListEmpty(BiLinkList)) {
    //     // 正向遍历
    //     printf("正向遍历双向链表\n");
    //     ToolPTR = BiLinkList->Head;
    //     while (ToolPTR != NULL)
    //     {
    //         printf("I'm the %d Node.\n",ToolPTR->data);
    //         ToolPTR = ToolPTR->next;
    //     }
    //     // 反向遍历
    //     printf("反向遍历双向链表\n");
    //     ToolPTR = BiLinkList->Tail;
    //     while (ToolPTR != NULL)
    //     {
    //         printf("I'm the %d Node.\n",ToolPTR->data);
    //         ToolPTR = ToolPTR->prev;
    //     }
    // }

    // // 创建循环链表
    // LoopLinkList = (struct LinkList *)malloc(sizeof(struct LinkList));
    // // 初始化循环链表
    // InitLinkList(LoopLinkList);
    // // 输入需要创建的单向节点数量
    // Node_Num = 0;
    // printf("Please input the number of the Node that you want to create: ");
    // scanf("%d", &Node_Num);
    // for(int i = 1;i <= Node_Num;i++ ) {
    //     AppendUniNode(LoopLinkList);
    // }
    // LoopLinkList->Tail->next = LoopLinkList->Head;

    // if (isLoop(LoopLinkList)) {
    //     printf("This is a LoopLinkList!\n");
    // }

    // FreeLinkList(BiLinkList); // 释放双向链表    
        
    // Actchoice(ShowMenu(1));
    // oeswap(UniLinkList);
    //     NonRecReverse(UniLinkList);
    // // 遍历链表，查看创建结果
    // ToolPTR = UniLinkList->Head;
    // if(!isLinkListEmpty(UniLinkList)) {
    //     while(ToolPTR != NULL) {
    //         printf("I'm the %d Node.\n",ToolPTR->data);
    //         ToolPTR=ToolPTR->next;
    //     }
    // }
    // printf("%d", FindMidPoint(UniLinkList)->data);
// ----------------------------------没用的测试代码-----------------------

    system("pause"); // 暂停程序
    return 0;
}

// 初始化链表
void InitLinkList(struct LinkList * MyLinkList) {
    MyLinkList->Head = NULL; 
    MyLinkList->Tail = NULL;
    MyLinkList->LinkList_Size = 0;
}
// 初始化节点
void InitNode(struct Node * MyNode) {
    MyNode->prev = NULL; // 初始化prev指针
    MyNode->next = NULL; // 初始化next指针
    MyNode->data = 0; // 初始化节点数据为0
}

// 判断链表是否为空函数
_Bool isLinkListEmpty(struct LinkList * MyLinkList) {
    if((MyLinkList->Head == NULL ) && (MyLinkList->Tail == NULL) && (MyLinkList->LinkList_Size == 0)) {
        return 1; // 链表为空
    } else {
        return 0; // 链表不为空
    }
}


// 单向链表节点创建函数(添加到链表末尾)
void AppendUniNode(struct LinkList* LinkList) {
    struct Node * NewNode = (struct Node *)malloc(sizeof(struct Node)); // 内存中开辟一块节点空间
    if(NewNode == NULL) {
        perror("Creating New Node  failed!!!"); // 输出错误信息。
        exit(0); // 退出
    }
    InitNode(NewNode); // 初始化节点

    // 链表为空
    if(isLinkListEmpty(LinkList)) {
        LinkList->Head = NewNode; // 链表头指针指向新节点
        LinkList->Tail = NewNode; // 链表尾指针指向新节点
        LinkList->LinkList_Size++; // 链表节点数加一
        LinkList->Tail->data = 1; // 第一个节点的数据
        return;
    }    

    // 链表不为空
    LinkList->Tail->next = NewNode; // 链表最后一个节点指向新节点
    LinkList->Tail = NewNode; // 链表尾指针指向新节点
    LinkList->LinkList_Size++; // 链表节点数加一
    LinkList->Tail->data=LinkList->LinkList_Size; // 为新加入的节点数据设置序号
}

// 单向链表插入节点函数
void InsertUniNode(struct LinkList* LinkList) {
    // 根据具体情况而定
}

// 双向链表节点创建函数（添加到链表末尾）
void AppendBiNode(struct LinkList* LinkList) {
    struct Node * NewNode = (struct Node *)malloc(sizeof(struct Node)); // 内存中开辟一块节点空间
    if(NewNode == NULL) {
        perror("Creating New Node  failed!!!"); // 输出错误信息。
        exit(0); // 退出
    }
    InitNode(NewNode); // 初始化节点

    // 链表为空
    if(isLinkListEmpty(LinkList)) {
        LinkList->Head = NewNode; // 链表头指针指向新节点
        LinkList->Tail = NewNode; // 链表尾指针指向新节点
        LinkList->LinkList_Size++; // 链表节点数加一
        LinkList->Tail->data = 1; // 第一个节点的数据
        return;
    }
    // 链表不为空 
    NewNode->prev = LinkList->Tail; // 新节点的prev指向原链表最后一个节点
    LinkList->Tail->next = NewNode; // 原链表最后一个节点的next指向新节点
    LinkList->Tail = NewNode; // 链表尾指针指向新节点
    LinkList->LinkList_Size++; // 链表数加一
    LinkList->Tail->data=LinkList->LinkList_Size; // 为新加入的节点数据设置序号
}

// 双向链表节点插入节点节点函数
void InsertBiNode(struct LinkList* LinkList) {
    // 根据具体情况而定
}


// 释放链表
void FreeLinkList(struct LinkList * LinkListToFree) {
    if(isLinkListEmpty(LinkListToFree)) {
        printf("There is no Node in the LinkList!\n");
        return;
    } else {
        struct Node * FreePTR = LinkListToFree->Head;
        while(FreePTR != NULL) {
            struct Node * TempPTR = FreePTR->next;
            free(FreePTR);
            FreePTR = TempPTR;
        }
    }
    free(LinkListToFree);
}

// 链表操作函数
// 单链表奇偶调换
void oeswap(struct LinkList * LinkList){
    // 判断是否没有节点或只有一个节点
    if (isLinkListEmpty(LinkList) || LinkList->LinkList_Size == 1) {
        printf("No need to Swap!\n");
        system("pause");
        return;
    }
    struct Node * Odd_PTR = LinkList->Head;  // 奇数指针
    struct Node * Even_PTR = LinkList->Head->next;  // 偶数指针
    struct Node * TempPTR = NULL;

    while (1) { 
        if (LinkList->Head == Odd_PTR) {
            LinkList->Head = Even_PTR;
            Odd_PTR->next = Even_PTR->next;
            Even_PTR->next = Odd_PTR;
            TempPTR = Odd_PTR;

            // 将奇偶指针指向下一组
            if (Odd_PTR->next != NULL) {
                Odd_PTR = Odd_PTR->next;
                if (Odd_PTR->next != NULL) {
                    Even_PTR = Odd_PTR->next;
                } else {
                    LinkList->Tail = Odd_PTR;
                    break;
                }
            } else {
                LinkList->Tail = TempPTR;
                break;
            }
        } else {
            TempPTR->next = Even_PTR;
            Odd_PTR->next = Even_PTR->next;
            Even_PTR->next = Odd_PTR;
            TempPTR = Odd_PTR;

            // 将奇偶指针指向下一组
            if (Odd_PTR->next != NULL) {
                Odd_PTR = Odd_PTR->next;
                if (Odd_PTR->next != NULL) {
                    Even_PTR = Odd_PTR->next;
                } else {
                    LinkList->Tail = Odd_PTR;
                    break;
                }
            } else {
                LinkList->Tail = TempPTR;
                break;
            }
        }
    }
}

//  找到单链表的中点
struct Node * FindMidPoint(struct LinkList * LinkList) {
    // 判断链表是否为空
    if(isLinkListEmpty(LinkList)) {
        printf("There is no Node in the LinkList!\n");
        return NULL;
    }
    // 判断链表节点数是否为偶数
    if(LinkList->LinkList_Size % 2 == 0) {
        printf("该链表没有中点!\n");
        return NULL;
    }
    
    // 找到单链表的中点
    int Mid = (LinkList->LinkList_Size / 2);
    struct Node * MidNodePTR = LinkList->Head;
    for(int i = 0;i < Mid;i++) {
        MidNodePTR = MidNodePTR->next;
    }
    return MidNodePTR;
}

// 判断链表是否成环
_Bool isLoop(struct LinkList * LinkList) {
    // 判断是否没有节点或只有一个节点
    if (isLinkListEmpty(LinkList) || LinkList->LinkList_Size == 1) {
        printf("No Loop!\n");
        system("pause");
        return 0;
    }

    struct Node * Move1PTR = LinkList->Head; // 慢指针
    struct Node * Move2PTR = LinkList->Head->next; // 快指针
    while(Move1PTR != NULL && Move2PTR != NULL && Move2PTR->next != NULL) {
        if (Move1PTR == Move2PTR) {
            return 1;
        }else {
            Move1PTR = Move1PTR->next;
            Move2PTR = Move2PTR->next->next;
        }
    }
    return 0;
}

// 反转链表（非递归）、
void NonRecReverse(struct LinkList * LinkList) {
        // 判断是否没有节点或只有一个节点
    if (isLinkListEmpty(LinkList) || LinkList->LinkList_Size == 1) {
        printf("No Need To Reverse!\n");
        system("pause");
        return;
    }
    struct Node * AddrArray[LinkList->LinkList_Size];
    struct Node * ToolPTR = LinkList->Head;
    int i = 0;
    while(ToolPTR != NULL) {
        AddrArray[i] = ToolPTR;
        i++;
        ToolPTR = ToolPTR->next;
    }
    // 开始反转
    LinkList->Head =AddrArray[i-1];
    for (int j = i-1;j > 0;j--)
    {
        AddrArray[j]->next = AddrArray[j-1];
    }
    LinkList->Tail = AddrArray[0];
    LinkList->Tail->next = NULL;     
}

// 反转链表（递归） 
void RecReverse(struct LinkList * LinkList) {
}