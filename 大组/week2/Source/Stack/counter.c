#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 200

// 栈结构
typedef struct Stack {
    char items[MAX_SIZE];
    int top;
} Stack;

// 初始化栈
void initStack(Stack *stack) {
    stack->top = -1;
}

// 入栈操作
void push(Stack *stack, char value) {
    stack->items[++stack->top] = value;
}

// 出栈操作
char pop(Stack *stack) {
    return stack->items[stack->top--];
}

// 获取栈顶元素
char peek(Stack *stack) {
    return stack->items[stack->top];
}

// 运算符优先级判断函数
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// 中缀表达式转后缀表达式函数
void infixToPostfix(char *infix, char *postfix) {
    // 创建栈
    Stack stack;
    // 初始化栈
    initStack(&stack);
    int i = 0;
    int j = 0;

    // 开始转换
    while(infix[i] != '\0') {
        if (isdigit(infix[i])) {
            // 是数字，入栈
            postfix[j++] = infix[i];
        }else if (infix[i] == '(') {
            // 是左括号，入栈
            push(&stack, '(');
        }else if (infix[i] == ')') {
            // 是右括号，将运算符出栈，直到当前运算符大于栈顶运算符为止
            while(peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            // 将左括号出栈
            pop(&stack);
        }else {
            // 运算符
            while (stack.top != -1 && precedence(infix[i]) <= precedence(peek(&stack))) {
                // 小于栈顶的运算符就写到后缀表达式中
                postfix[j++] = pop(&stack);
            }
            // 如果当前的运算符优先级大于栈顶运算符，则入栈
            push(&stack, infix[i]);
        }
        // 迭代到下一个
        i++;
    }

    while (stack.top != -1) {
        // 结束时把栈剩余数据出栈到为空为止
        postfix[j++] = pop(&stack);
    }
    // 手动在末尾添加\0
    postfix[j] = '\0';
}

// 计算出后缀表达式子的值
int evaluatePostfix(char *postfix) {
    Stack stack;
    initStack(&stack);
    int i = 0;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0');
        } else {
            int operand2 = pop(&stack); // 取出栈顶值作为运算符右边的运算数
            int operand1 = pop(&stack); // 再次取出栈顶的值作为运算符左边的运算数
            // 执行运算
            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
        // 迭代到下一个字符
        i++;
    }

    // 栈顶为最终计算的结果，将其返回
    return peek(&stack);
}
int main()
{
    system("cls"); // 清屏

    char infix[MAX_SIZE] = "6+(4-2)*3+9/3" ; // 中缀表达式
    char postfix[MAX_SIZE]; // 

    // 开始转换
    infixToPostfix(infix, postfix);
    printf("Infix expression: %s\n", infix);
    printf("Postfix expression: %s\n", postfix);
    
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    system("pause"); // 查看结果
    return 0;
}