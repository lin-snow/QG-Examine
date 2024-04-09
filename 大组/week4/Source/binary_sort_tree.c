#ifndef BINAERY_SORT_TREE_C
#define BINAERY_SORT_TREE_C

#include "../Header/binary_sort_tree.h"

// BST initialize
Status BST_init(BinarySortTreePtr BST)
{
    if (BST->root == NULL) {
        return failed;
    }
    BST->root = NULL;
    return succeed;
}

// BST insert
Status BST_insert(BinarySortTreePtr BST, ElemType value)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode == NULL) {
        return failed;
    }
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    if (BST->root == NULL) {
        BST->root = newNode;
        return succeed;
    }

    NodePtr p = BST->root;
    NodePtr q = NULL;


    // find the position to insert
    while (p != NULL) {
        q = p;
        if (value < p->value) {
            p = p->left;
        }else if (value > p->value) {
            p = p->right;
        }
    }

    if (q == NULL) {
        return failed;
    }

    // start to insert
    if (value < q->value) {
        q->left = newNode;
    }
    if (value > q->value) {
        q->right = newNode;
    }

    return succeed;
}

// Status BST_delete(BinarySortTreePtr BST, ElemType value) 
// {
//     // check the BST is empty
//     if (BST->root == NULL) {
//         printf("The BST is empty\n");
//         return failed;
//     }

//     // find the Node to delete
//     NodePtr p = BST->root;
//     NodePtr q = NULL;
//     while (p != NULL && p->value != value) {
//         q = p;
//         if (value < p->value) {
//             p = p->left;
//         }else if (value > p->value) {
//             p = p->right;
//         }
//     }

//     // check the Node is exist
//     if (p == NULL) {
//         return failed; 
//     }

//     // delete the Node
//     if (p->left == NULL && p->right == NULL) {
//         if (q->left == p) {
//             q->left = NULL;
//         }
//         if (q->right == p) {
//             q->right = NULL;
//         }
//     }

//     if (p->left != NULL && p->right == NULL) {
//         if (q->left == p) {
//             q->left = p->left;
//         }
//         if (q->right == p) {
//             q->right = p->left;
//         }
//     }

//     if (p->left == NULL && p->right != NULL) {
//         if (q->left == p) {
//             q->left = p->right;
//         }
//         if (q->right == p) {
//             q->right = p->right;
//         }
//     }

    

//     if (p->left != NULL && p->right != NULL) {
//         // find the min Node in right subtree
//         NodePtr min  = p->right;
//         while (min->left != NULL) {
//             min = min->left;
//         }
//         // replace the value
//         p->value = min->value;
        
//         // delete the min Node
//         BST_delete(BST, min->value);
//     }

//     free(p);
//     p = NULL;
//     return succeed;
// }

Status BST_delete(BinarySortTreePtr BST, ElemType value) {
    // check the BST is empty
    if (BST->root == NULL) {
        printf("The BST is empty\n");
        return failed;
    }

    // find the Node to delete
    NodePtr p = BST->root;
    NodePtr q = NULL;
    while (p != NULL && p->value != value) {
        q = p;
        if (value < p->value) {
            p = p->left;
        } else if (value > p->value) {
            p = p->right;
        }
    }

    // check the Node is exist
    if (p == NULL) {
        return failed;
    }

    // delete the Node
    if (p->left == NULL && p->right == NULL) {
        if (q == NULL) { // root node
            BST->root = NULL;
        } else if (q->left == p) {
            q->left = NULL;
        } else if (q->right == p) {
            q->right = NULL;
        }
    } else if (p->left != NULL && p->right == NULL) {
        if (q == NULL) { // root node
            BST->root = p->left;
        } else if (q->left == p) {
            q->left = p->left;
        } else if (q->right == p) {
            q->right = p->left;
        }
    } else if (p->left == NULL && p->right != NULL) {
        if (q == NULL) { // root node
            BST->root = p->right;
        } else if (q->left == p) {
            q->left = p->right;
        } else if (q->right == p) {
            q->right = p->right;
        }
    } else if (p->left != NULL && p->right != NULL) {
        // find the min Node in right subtree
        NodePtr min = p->right;
        while (min->left != NULL) {
            min = min->left;
        }
        // replace the value
        p->value = min->value;

        // delete the min Node
        if (p->right == min) {
            p->right = min->right;
        } else {
            BST_delete(p->right, min->value);
        }
    }

    free(p);
    p = NULL;
    return succeed;
}

Status BST_search(BinarySortTreePtr BST, ElemType value)
{
    // check the BST is empty
    if (BST->root == NULL) {
        printf("The BST is empty\n");
        return failed;
    }

    NodePtr p = BST->root;

    while (p != NULL && p->value != value) {
        if (value < p->value) {
            p = p->left;
        }else if (value > p->value) {
            p = p->right;
        }
    }

    if (p == NULL) {
        return failed;
    }

    return succeed;
}



// BST preorder traversal with recursion
// preorder
void preorder(NodePtr root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->value);

    preorder(root->left);
    preorder(root->right);
}

Status BST_preorderR(BinarySortTreePtr BST, void (*visit)(NodePtr root)) {
    // check the BST is empty
    if (BST->root == NULL) {
        printf("The BST is empty!\n");
        return failed;
    }

    // start to traversal
    visit(BST->root);

    return succeed;
}

// BST Inorder traversal with recursion
// inorder
void inorder(NodePtr root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}
Status BST_inorderR(BinarySortTreePtr BST, void (*visit)(NodePtr root)) {
    // check the BST is empty
    if (BST->root == NULL) {
        printf("The BST is empty!\n");
        return failed;
    }

    // start to traversal
    visit(BST->root);

    return succeed;
}

// BST postorder traversal with recursion
// postorder
void postorder(NodePtr root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->value);
}
Status BST_postorderR(BinarySortTreePtr BST, void (*visit)(NodePtr root)) {
    // check the BST is empty
    if (BST->root == NULL) {
        printf("The BST is empty!\n");
        return failed;
    }

    // start to traversal
    visit(BST->root);

    return succeed;
}

// Traverse the BST without recursion
// BST preorder traversal without recursion
Status BST_preorderI(BinarySortTreePtr BST)
{
    // check the BST is empty
    if (BST->root == NULL) {
        printf("The BST is empty!\n");
        return failed;
    }

    // start to traversal
    // create a stack 
    NodePtr stack[500];

    // push the root into stack
    int top = 0;
    stack[top] = BST->root;

    // traversal
    while (top >= 0) {
        NodePtr p = stack[top--];
        printf("%d ", p->value);

        if (p->right != NULL) {
            stack[++top] = p->right;
        }

        if (p->left != NULL) {
            stack[++top] = p->left;
        }
    }

    return succeed;
}

// BST inorder traversal without recursion
Status BST_inorderI(BinarySortTreePtr BST) {
    // check the BST is empty
    if (BST->root == NULL) {
        printf("The BST is empty!\n");
        return failed;
    }

    // start to traversal
    // create a stack
    NodePtr stack[500];
    int top = 0;

    // push the root into stack
    NodePtr p = BST->root;
    while (top > 0 || p != NULL) {
        while (p != NULL) {
            stack[++top] = p;
            p = p->left;
        }

        if (top > 0) {
            p = stack[top--];
            printf("%d ", p->value);
            p = p->right;
        }
    }
}

// BST postorder traversal without recursion
Status BST_postorderI(BinarySortTreePtr BST) {
    // check the BST is empty
    if (BST->root == NULL) {
        printf("The BST is empty!\n");
        return failed;
    }

    // start to traversal
    // create two stack
    NodePtr stack1[500];
    NodePtr stack2[500];
    int top1 = 0;
    int top2 = 0;

    // push the root into stack1
    stack1[++top1] = BST->root;

    // traversal
    while (top1 > 0) {
        NodePtr p = stack1[top1--];
        stack2[++top2] = p;

        if (p->left != NULL) {
            stack1[++top1] = p->left;
        }

        if (p->right != NULL) {
            stack1[++top1] = p->right;
        }
    }

    // print the result
    while (top2 > 0) {
        NodePtr p = stack2[top2--];
        printf("%d ", p->value);
    }

    return succeed;
}

// BST level order traversal
Status BST_levelOrder(BinarySortTreePtr BST) {
    // check the BST is empty
    if (BST->root == NULL) {
        printf("The BST is empty!\n");
        return failed;
    }

    // start to traversal
    // create a queue
    NodePtr queue[500];
    int front = 0;
    int rear = 0;

    // push the root into queue
    queue[rear++] = BST->root;

    // traversal
    while (front < rear) {
        NodePtr p = queue[front++];
        printf("%d ", p->value);

        if (p->left != NULL) {
            queue[rear++] = p->left;
        }

        if (p->right != NULL) {
            queue[rear++] = p->right;
        }
    }

    return succeed;
}
#endif