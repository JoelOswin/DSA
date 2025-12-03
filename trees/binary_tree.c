#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode{
    char value;
    struct TreeNode* left_child;
    struct TreeNode* right_child;
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

queueNode* create_head()
{
    queueNode* head = (queueNode*) malloc(sizeof(queueNode));
    if (!head) return NULL;
    head->node = NULL;
    head->llink = head;
    head->rlink = head;
    return head;
}

void addq(queueNode** head, queueNode** current, TreeNode* tree_node)
{
    queueNode* node = (queueNode*) malloc(sizeof(queueNode));
    if (!node) return;
    node->node = tree_node;
    node->llink = (*current);
    (*current)->rlink = node;
    node->rlink = (*head);
    (*head)->llink = node;
}

TreeNode* deleteq(queueNode** head)
{
    queueNode* front = (*head)->rlink;
    queueNode* rear = (*head)->llink;
    if (!front){
        TreeNode* node = front->node;
        front->node = NULL;
        front->llink = rear;
        rear->rlink = front;
        queueNode* temp = (*head);
        (*head) = front;
        free(temp);
        return node;
    }
    return NULL;
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
    TreeNode* return_val = (*top)->node;
    (*top) = (*top)->link;
    return return_val;
}

TreeNode* create_root(char value)
{
    TreeNode* root = (TreeNode*) malloc(sizeof(TreeNode));
    if (!root) return NULL;
    root->value = value;
    root->left_child = NULL;
    root->right_child = NULL;
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
    if (dir)
        (*current)->right_child = child;
    else
        (*current)->left_child = child;
}

void iter_inorder(TreeNode* root)
{
    stackNode* stack = create_stack();
    while(root){
        push(&stack, root);
        root = root->left_child;
    }
    while(1){
        TreeNode* node = pop(&stack);
        if (!node) break;
        printf("%c", node->value);
        if (node->right_child)
            printf("%c", node->right_child->value);
        free(node);
    }
}

void iter_levelorder(TreeNode* root)
{
    
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
}