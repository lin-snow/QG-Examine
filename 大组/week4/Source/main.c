#include <stdio.h>
#include <stdlib.h>
#include "../Header/binary_sort_tree.h"
#include "./binary_sort_tree.c"


int main() {
    system("cls");

    /* ------------test-------------- */
    // create a BST
    BinarySortTreePtr BST = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    // initialize the BST
    BST_init(BST);
    // add some nodes
    BST_insert(BST, 5);
    BST_insert(BST, 3);
    BST_insert(BST, 7);
    BST_insert(BST, 2);
    BST_insert(BST, 4);
    BST_insert(BST, 6);
    BST_insert(BST, 8);
    // delete one node
    BST_delete(BST, 3);
    // search a node
    if(BST_search(BST, 3) == succeed) {
        printf("3 is in the BST\n");
    }
    // preorder traversal
    BST_preorderR(BST, preorder);
    printf("\n");
    BST_preorderI(BST);
    printf("\n");
    BST_inorderR(BST, inorder);
    printf("\n");
    BST_inorderI(BST);
    printf("\n");
    BST_postorderR(BST, postorder);
    printf("\n");
    BST_postorderI(BST);
    printf("\n");
    BST_levelOrder(BST);
    printf("\n");



    system("pause");
    return 0;
}
