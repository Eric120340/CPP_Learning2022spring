#include <iostream>
#include "assign2.hpp"
#define ALL_CORRECT 0x0
//节点高度为 该节点到叶子节点的个数
//节点深度为 到root节点节点的个数
/*Check whether the pointer is NULL or not*/

void judge_Zig_Zag(BST *root, tree_node *node);
void Zig(BST *bst, tree_node *node);
void Zag(BST *bst, tree_node *node);
void tree_count_update(tree_node *node_old);
void all_tree_count_update(tree_node *node_new);
int judge_node_existing(BST *bst, tree_node *node);

assign2_exception::exception add_node(tree_node *father, tree_node *child, int child_direction)
{
    uint32_t exception = ALL_CORRECT;
    /*Judge whether this is a NULL pointer*/
    if (father == nullptr || child == nullptr) // This is a NULL pointer
    {
        exception |= NULL_POINTER_EXCEPTION;
    }
    /*Check whether the left_child is NULL or not, if there is already have value, then return exception*/
    if (father != nullptr && child_direction == CHILD_DIRECTION_LEFT)
    {
        if (father->l_child != nullptr)
            exception |= DUPLICATED_LEFT_CHILD_EXCEPTION;
    }
    /*Check whether the right_child is NULL or not, if there is already have value, then return exception*/
    else if (father != nullptr && child_direction == CHILD_DIRECTION_RIGHT)
    {
        if (father->r_child != nullptr)
            exception |= DUPLICATED_RIGHT_CHILD_EXCEPTION;
    }
    /*Check whether the child already have a father*/
    if (child != nullptr && child->father != nullptr)
    {
        exception |= DUPLICATED_FATHER_EXCEPTION;
    }
    /*check the child_direction is valid or not*/
    if ((child_direction != CHILD_DIRECTION_LEFT) && (child_direction != CHILD_DIRECTION_RIGHT))
    {
        exception |= INVALID_CHILD_DIRECTION_EXCEPTION;
    } 

    if (exception & NULL_POINTER_EXCEPTION || exception & DUPLICATED_FATHER_EXCEPTION ||
        exception & DUPLICATED_LEFT_CHILD_EXCEPTION || exception & DUPLICATED_RIGHT_CHILD_EXCEPTION || 
        exception & INVALID_CHILD_DIRECTION_EXCEPTION)
    {
        return exception;
    }

    /*Child_direction*/
    if (child_direction == CHILD_DIRECTION_LEFT)
    {
        /* Put child to father's left */
        father->l_child = child;
    }
    else if (child_direction == CHILD_DIRECTION_RIGHT)
    {
        /* Put child to father's right*/
        father->r_child = child;
    }
    child->father = father;

    return exception;
}

/*判断这个结点是父亲结点的右节点还是左节点
  比较node的father的左孩和右孩的地址和node的地址；
  若是左节点，就小于父亲节点的数据；若是右节点，就大于父亲节点的数据
*/
assign2_exception::exception judge_child_direction(tree_node *node, int *child_direction)
{
    uint32_t exception = ALL_CORRECT;

    /*Judge whether this is a NULL pointer*/
    if (node == nullptr || child_direction == nullptr) // This is a NULL pointer
    {
        exception |= NULL_POINTER_EXCEPTION;
    }
    /*Judge whether the access node is a root or not*/
    if (node != nullptr && node->father == nullptr)
    {
        exception |= ROOTS_FATHER_EXCEPTION;
    }
    if (exception & NULL_POINTER_EXCEPTION || exception & ROOTS_FATHER_EXCEPTION)
    {
        return exception;
    }

    /*Compare the addresses of father's left_child and right_child with the node*/
    // node->father == node->father->l_child ? *child_direction = CHILD_DIRECTION_LEFT : *child_direction = CHILD_DIRECTION_RIGHT;
    if (node == node->father->l_child)
    {
        *child_direction = CHILD_DIRECTION_LEFT;
    }
    else if (node == node->father->r_child)
    {
        *child_direction = CHILD_DIRECTION_RIGHT;
    }
    return exception;
}

assign2_exception::exception insert_into_BST(BST *bst, uint64_t data, tree_node **inserted_node)
{
    uint32_t exception = ALL_CORRECT;
    int direction;

    /*Judge whether this is a NULL pointer, both bst and answer space(insert_node)*/
    if (bst == nullptr || inserted_node == nullptr) 
    {
        exception |= NULL_POINTER_EXCEPTION;
    }
    if (bst->comp == nullptr)
    {
        exception |= NULL_COMP_FUNCTION_EXCEPTION;
    }
    if (exception & NULL_POINTER_EXCEPTION || exception & NULL_COMP_FUNCTION_EXCEPTION)
    {
        return exception;
    }

    if (bst->root == nullptr)
    {
        /* code */
        bst->root->data = data;
        bst->root->node_count = 1;
        *inserted_node = bst->root;
        return exception;
    }

    tree_node *Move = bst->root;
    /*inserting specific {data} into {bst}, store the inserted tree node to the address of {inserted_node}*/
    while (true)
    {
        if (bst->comp(Move->data, data) < 0)
        {
            /*insert data is smaller, go to the left */
            if (Move->l_child != nullptr)
            {
                direction = CHILD_DIRECTION_LEFT;
                tree_node *left;
                left->data = data;
                left->node_count = 1;
                left->l_child = nullptr;
                left->r_child = nullptr;
                exception = add_node(Move, *inserted_node, direction);
            }
            Move = Move->l_child;
            return exception;
        }
        else if (bst->comp(Move->data, data) > 0)
        {
            /*insert data is larger, go to the right */
            if (Move->r_child != nullptr)
            {
                tree_node *right;
                right->data = data;
                right->node_count = 1;
                right->l_child = nullptr;
                right->r_child = nullptr;
                direction = CHILD_DIRECTION_RIGHT;
                exception = add_node(Move, *inserted_node, direction);
            }
            else
            {
                Move = Move->r_child;
            }
            return exception;
        }
        /*Two data have same value*/
        else if (bst->comp(Move->data, data) == 0)
        {
            Move->node_count++; // data appeared more than once，
            *inserted_node = Move;
            return exception;
        }
    }
    all_tree_count_update(bst->root);
    return exception;
}

assign2_exception::exception find_in_BST(BST *bst, uint64_t data, tree_node **target_node)
{
    uint32_t exception = ALL_CORRECT;

    /*Judge whether this is a NULL pointer*/
    if (bst == nullptr || target_node == nullptr) // This is a NULL pointer
    {
        exception |= NULL_POINTER_EXCEPTION;
    }
    if (bst->comp == nullptr)
    {
        exception |= NULL_COMP_FUNCTION_EXCEPTION;
    }
    if (exception & NULL_POINTER_EXCEPTION || exception & NULL_COMP_FUNCTION_EXCEPTION)
    {
        return exception;
    }

    if (bst->root != nullptr)
    {
        tree_node *current_node = bst->root;
        while (true)
        {
            if (bst->comp(current_node->data, data) > 0)
            {
                /*goto left*/
                if (current_node->r_child == nullptr)
                {
                    *target_node = 0x0;
                    break;
                }
                else
                {
                    current_node = current_node->r_child;
                }
            }
            else if (bst->comp(current_node->data, data) < 0)
            {
                /* goto right*/
                if (current_node->l_child == nullptr)
                {
                    *target_node = 0x0;
                    break;
                }
                else
                {
                    current_node = current_node->l_child;
                }
            }
            else if (bst->comp(current_node->data, data) == 0)
            {
                /* store node to the targetnode and return*/
                *target_node = current_node;
                return exception;
            }
        }
    }
    return exception;
}

assign2_exception::exception splay(BST *bst, tree_node *node)
{
    uint32_t exception = ALL_CORRECT;

    /*Judge whether this is a NULL pointer*/
    if (bst == nullptr || node == nullptr) // This is a NULL pointer
    {
        exception |= NULL_POINTER_EXCEPTION;
    }
    if (bst != nullptr && bst->comp == nullptr)
    {
        exception |= NULL_COMP_FUNCTION_EXCEPTION;
    }
    /*根据data找node是否在bst里？？？*/
    tree_node **record_node;
    find_in_BST(bst, node->data, record_node);
    if (!record_node)
    {
        exception |= SPLAY_NODE_NOT_IN_TREE_EXCEPTION;
    }

    if (exception & NULL_POINTER_EXCEPTION || exception & NULL_COMP_FUNCTION_EXCEPTION || exception & SPLAY_NODE_NOT_IN_TREE_EXCEPTION)
    {
        return exception;
    }
    /*Four kind of adjustment:
        1.Zig-Zig(LL)   当前节点的左子树太高，且左子树的左子树比较高
        2.Zig-Zag(LR)   当前节点的左子树太高，且左子树的右子树比较高
        3.Zag-Zig(RL)   当前节点的右子树太高，且右子树的左子树比较高
        4.Zag-Zag(RR)   当前节点的右子树太高，且右子树的右子树比较高
        */
    judge_Zig_Zag(bst, node);
    return exception;
}

void tree_count_update(tree_node *node_old)
{
    if (node_old->father != nullptr)
    {
        uint32_t i, j;
        if (node_old->l_child != nullptr)
        {
            i = node_old->l_child->tree_count;
        }
        if (node_old->r_child != nullptr)
        {
            j = node_old->r_child->tree_count;
        }
        node_old->tree_count = node_old->node_count + i + j;
        tree_count_update(node_old->father);
    }
}

void all_tree_count_update(tree_node *node_new)
{
    if (node_new != nullptr)
    {
        all_tree_count_update(node_new->l_child);
        all_tree_count_update(node_new->r_child);
        int i = 0, j = 0;
        if (node_new->l_child != nullptr)
        {
            i = (node_new->l_child)->tree_count;
        }
        if (node_new->r_child != nullptr)
        {
            j = (node_new->r_child)->tree_count;
        }
        node_new->tree_count = node_new->node_count + i + j;
    }
}

int judge_node_existing(BST *bst, tree_node *node)
{
    tree_node *judge_node = node;
    int value;
    while (judge_node->father != nullptr)
    {
        judge_node = judge_node->father;
    }
    judge_node == bst->root ? value = 1 : value = 0;
    return value;
}

void judge_Zig_Zag(BST *root, tree_node *node)
{
    tree_node *parent = node->father;
    tree_node *grandparent = parent->father;
    int factor_i, factor_j;
    parent = node->father;
    grandparent = parent->father;

    factor_i = (grandparent->l_child == parent) ? -1 : 1;
    factor_j = (grandparent->r_child == parent) ? -1 : 1;
    if ((factor_i == -1 && factor_j == -1))
    {
        /* Zag-Zag */
        Zag(root, node);
        Zag(root, node);
    }
    else if ((factor_i == -1 && factor_j == 1))
    {
        /* Zig-Zag */
        Zig(root, node);
        Zag(root, node);
    }
    else if ((factor_i == 1 && factor_j == -1))
    {
        /* Zag-Zig */
        Zag(root, node);
        Zig(root, node);
    }
    else
    {
        /* Zig-Zig */
        Zig(root, node);
        Zig(root, node);
    }
    all_tree_count_update(root->root);
}

void Zig(BST *bst, tree_node *node)
{
    tree_node *dad = node->father;        //其父节点
    tree_node *grandfather = dad->father; //其祖父结点
    dad->r_child = node->l_child;         //设置其父节点的有孩子
    if (node->l_child != nullptr)         //如果有左孩则更新node结点左孩子
    {
        node->l_child->father = dad;
    }
    node->l_child = dad;
    grandfather->father = node;
    node->father = grandfather;

    if (grandfather != nullptr)
    {
        if (grandfather->l_child == dad)
        {
            grandfather->l_child = node;
        }
        else if (grandfather->r_child == dad)
        {
            grandfather->r_child = node;
        }
    }
    else
    {
        bst->root = node;
    }
}

void Zag(BST *bst, tree_node *node)
{
    tree_node *dad = node->father;        //其父节点
    tree_node *grandfather = dad->father; //其祖父结点
    dad->l_child = node->r_child;         //设置其父节点的有孩子
    if (node->r_child != nullptr)         //如果有左孩则更新node结点左孩子
    {
        node->r_child->father = dad;
    }
    node->r_child = dad;
    grandfather->father = node;
    node->father = grandfather;

    if (grandfather != nullptr)
    {
        /* code */
        if (grandfather->l_child == dad)
        {
            grandfather->l_child = node;
        }
        else if (grandfather->r_child == dad)
        {
            grandfather->r_child = node;
        }
    }
    else
    {
        bst->root = node;
    }
}
