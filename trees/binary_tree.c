#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct TreeNode{
    char value;
    struct TreeNode* left_child;
    struct TreeNode* right_child;
    bool rightThread;
    bool leftThread;
} TreeNode;

typedef struct stackNode{
    struct TreeNode* node;
    struct stackNode* link;
} stackNode;

typedef struct queueNode{
    TreeNode* node;
    struct queueNode* rlink;
    struct queueNode* llink;
} queueNode;

queueNode* create_queue()
{
    queueNode* head = (queueNode*) malloc(sizeof(queueNode));
    if (!head) return NULL;
    head->node = NULL;
    head->llink = head;
    head->rlink = head;
    return head;
}

void addq(queueNode** head, TreeNode* tree_node)
{
    queueNode* node = (queueNode*) malloc(sizeof(queueNode));
    if (!node) return;
    node->node = tree_node;
    queueNode* rear = (*head)->llink;
    rear->rlink = node;
    node->llink = rear;
    node->rlink = (*head);
    (*head)->llink = node;
}

TreeNode* deleteq(queueNode** head)
{
    queueNode* node = (*head)->rlink;
    if (node == (*head)) return NULL;
    (*head)->rlink = node->rlink;
    node->rlink->llink = (*head);
    TreeNode* return_node = node->node;
    free(node);
    return return_node;
}

stackNode* create_stack()
{
    stackNode* stack = (stackNode*) malloc(sizeof(stackNode));
    if (!stack) return NULL;
    stack->node = NULL;
    stack->link = NULL;
    return stack;
}

void push(stackNode** stack, TreeNode* node)
{
    stackNode* stack_node = (stackNode*) malloc(sizeof(stackNode));
    if (!stack_node) return;
    stack_node->node = node;
    stack_node->link = (*stack);
    (*stack) = stack_node;
}

TreeNode* pop(stackNode** top)
{
    if (!(*top)) return NULL;
    TreeNode* return_val = (*top)->node;
    stackNode* temp = (*top);
    (*top) = (*top)->link;
    free(temp);
    return return_val;
}

TreeNode* create_root(char value)
{
    TreeNode* root = (TreeNode*) malloc(sizeof(TreeNode));
    if (!root) return NULL;
    root->value = value;
    root->left_child = NULL;
    root->right_child = NULL;
    root->leftThread = false;
    root->rightThread = false;
    return root;
}

void add_child(TreeNode** current, char value, int dir)
{
    // 0 for left, 1 for right
    TreeNode* child = (TreeNode*) malloc(sizeof(TreeNode));
    if (!child) return;
    child->value = value;
    child->left_child = NULL;
    child->right_child = NULL;
    child->leftThread = false;
    child->rightThread = false;
    if (dir)
        (*current)->right_child = child;
    else
        (*current)->left_child = child;
}

void iter_inorder(TreeNode* root)
{
    stackNode* stack = create_stack();
    while(1){
        if (root){
            push(&stack, root);
            root = root->left_child;
        }else {
            root = pop(&stack);
            if (!root) break;
            printf("%c", root->value);
            root = root->right_child;
        }
    }
}

void iter_preorder(TreeNode* root)
{
    stackNode* stack = create_stack();
    while(1){
        if (root){
            printf("%c", root->value);
            push(&stack, root);
            root = root->left_child;
        }else {
            root = pop(&stack);
            if (!root) break;
            root = root->right_child;
        }
    }
}

void iter_levelorder(TreeNode* root)
{
    queueNode* head = create_queue();
    addq(&head, root);
    while(1){
        root = deleteq(&head);
        if (root){
            printf("%c", root->value);
            if (root->left_child)
                addq(&head, root->left_child);
            if (root->right_child)
                addq(&head, root->right_child);
        }else{
            free(head);
            break;
        }
    }
}

void main()
{
    TreeNode* root = create_root('+');
    TreeNode* current = root;
    add_child(&current, 'E', 1);
    add_child(&current, '*', 0);
    current = current->left_child;
    add_child(&current, 'D', 1);
    add_child(&current, '*', 0);
    current = current->left_child;
    add_child(&current, 'C', 1);
    add_child(&current, '/', 0);
    current = current->left_child;
    add_child(&current, 'B', 1);
    add_child(&current, 'A', 0);

    iter_inorder(root);
    printf("\n");
    iter_levelorder(root);
    printf("\n");
    iter_preorder(root);
    printf("\n");

    // Another Tree Order: Inorder
    TreeNode* root1 = create_root('8');
    stackNode* stack = create_stack();
    TreeNode* current1 = root1;
    add_child(&current1, '4', 0);
    push(&stack, current1->left_child);
    add_child(&current1, 'C', 1);
    push(&stack, current1->right_child);
    current1 = pop(&stack);
    add_child(&current1, 'A', 0);
    push(&stack, current1->left_child);
    add_child(&current1, 'E', 1);
    push(&stack, current1->right_child);
    current1 = pop(&stack);
    add_child(&current1, 'F', 1);
    add_child(&current1, 'D', 0);
    current1 = pop(&stack);
    add_child(&current1, '9', 0);
    add_child(&current1, 'B', 1);
    current1 = pop(&stack);
    add_child(&current1, '2', 0);
    push(&stack, current1->left_child);
    add_child(&current1, '6', 1);
    push(&stack, current1->right_child);
    current1 = pop(&stack);
    add_child(&current1, '5', 0);
    add_child(&current1, '7', 1);
    current1 = pop(&stack);
    add_child(&current1, '1', 0);
    add_child(&current1, '3', 1);
    
    iter_inorder(root1);
    printf("\n");
    iter_levelorder(root1);
}