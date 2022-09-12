#include <iostream>
#include <string>
#include "assign2.hpp"
using namespace std;

void update_tree_count(tree_node *node)
{
    if (node->father != nullptr)
    {
        int temp1, temp2;
        if (node->l_child != nullptr)
            temp1 = (node->l_child)->tree_count;
        if (node->r_child != nullptr)
            temp2 = (node->r_child)->tree_count;
        node->tree_count = node->node_count + temp1 + temp2;
        update_tree_count(node->father);
    }
    else
        return;
}

int exist_node(BST *bst, tree_node *node)
{
    tree_node *current_node = node;
    while (current_node->father != nullptr)
    {
        current_node = current_node->father;
    }
    if (current_node == bst->root)
        return 1;
    else
        return 0;
}

void zig(BST *bst, tree_node *node)
{
    tree_node *father = node->father;
    tree_node *grandfather = father->father;
    father->l_child = node->r_child;
    if (node->r_child != nullptr)
        node->r_child->father = father;
    node->r_child = father;
    node->father = grandfather;
    father->father = node;
    if (grandfather != nullptr)
    {
        if (grandfather->l_child == father)
            grandfather->l_child = node;
        else if (grandfather->r_child == father)
            grandfather->r_child = node;
    }
    else
        bst->root = node;
}

void zag(BST *bst, tree_node *node)
{
    tree_node *father = node->father;
    tree_node *grandfather = father->father;
    father->r_child = node->l_child;
    if (node->l_child != nullptr)
        node->l_child->father = father;
    node->l_child = father;
    node->father = grandfather;
    father->father = node;
    if (grandfather != nullptr)
    {
        if (grandfather->l_child == father)
            grandfather->l_child = node;
        else if (grandfather->r_child == father)
            grandfather->r_child = node;
    }
    else
        bst->root = node;
}

void zig_zig(BST *bst, tree_node *node)
{
    zig(bst, node->father);
    zig(bst, node);
}

void zag_zag(BST *bst, tree_node *node)
{
    zag(bst, node->father);
    zag(bst, node);
}

void zig_zag(BST *bst, tree_node *node)
{
    zig(bst, node);
    zag(bst, node);
}

void zag_zig(BST *bst, tree_node *node)
{
    zag(bst, node);
    zig(bst, node);
}

void update_all_tree_count(tree_node *node)
{
    if (node == nullptr)
        return;
    else
    {
        update_all_tree_count(node->l_child);
        update_all_tree_count(node->r_child);
        int temp1 = 0, temp2 = 0;
        if (node->l_child != nullptr)
            temp1 = (node->l_child)->tree_count;
        if (node->r_child != nullptr)
            temp2 = (node->r_child)->tree_count;
        node->tree_count = node->node_count + temp1 + temp2;
    }
}

assign2_exception::exception add_node(tree_node *father, tree_node *child, int child_direction)
{
    assign2_exception::exception e = 0;
    if ((father == nullptr) || (child == nullptr)) // check if both tree_node are non-null pointer
        e |= NULL_POINTER_EXCEPTION;
    if (child != nullptr && child->father != nullptr) // check the being added child node has no father node
        e |= DUPLICATED_FATHER_EXCEPTION;
    if ((child_direction != CHILD_DIRECTION_LEFT) && (child_direction != CHILD_DIRECTION_RIGHT)) // check the child_direction is valid or not
        e |= INVALID_CHILD_DIRECTION_EXCEPTION;
    if (father != nullptr && child_direction == CHILD_DIRECTION_LEFT)
    {
        if (father->l_child != nullptr)
            e |= DUPLICATED_LEFT_CHILD_EXCEPTION;
    }
    else if (father != nullptr && child_direction == CHILD_DIRECTION_RIGHT)
    {
        if (father->r_child != nullptr)
            e |= DUPLICATED_RIGHT_CHILD_EXCEPTION;
    }
    if (!e)
    {
        if (child_direction == CHILD_DIRECTION_LEFT) // check which derection
            father->l_child = child;
        else if (child_direction == CHILD_DIRECTION_RIGHT)
            father->r_child = child;
        child->father = father;
    }
    return e;
}

assign2_exception::exception judge_child_direction(tree_node *node, int *child_direction)
{
    assign2_exception::exception e = 0;
    if (node == nullptr || child_direction == nullptr)
        e |= NULL_POINTER_EXCEPTION;
    if (node != nullptr && node->father == nullptr)
        e |= ROOTS_FATHER_EXCEPTION;

    if (!e)
    {
        if (node == node->father->l_child)
            *child_direction = CHILD_DIRECTION_LEFT;
        else if (node == node->father->r_child)
            *child_direction = CHILD_DIRECTION_RIGHT;
    }
    return e;
}

assign2_exception::exception insert_into_BST(BST *bst, uint64_t data, tree_node **inserted_node)
{
    assign2_exception::exception e = 0;
    if (bst == nullptr || inserted_node == nullptr)
        e |= NULL_POINTER_EXCEPTION;
    if ((bst->comp) == nullptr)
        e |= NULL_COMP_FUNCTION_EXCEPTION;
    if (!e)
    {
        if (bst->root == nullptr)
        {
            tree_node *root_node = new tree_node();
            root_node->data = data;
            root_node->node_count = 1;
            bst->root = root_node;
            *inserted_node = root_node;
        }
        else if (bst->root != nullptr)
        {
            tree_node *current_node = bst->root;
            while (true)
            {
                int comp = bst->comp(data, current_node->data);
                if (comp == 0)
                {
                    current_node->node_count++;
                    *inserted_node = current_node;
                    break;
                }
                else if (comp > 0)
                {
                    if (!current_node->r_child)
                    {
                        tree_node *new_node = new tree_node();
                        new_node->data = data;
                        new_node->node_count = 1;
                        new_node->l_child = nullptr;
                        new_node->r_child = nullptr;
                        e |= add_node(current_node, new_node, CHILD_DIRECTION_RIGHT);
                        // cout << data << endl;
                        *inserted_node = new_node;
                        break;
                    }
                    else
                        current_node = current_node->r_child;
                }
                else
                {
                    if (!current_node->l_child)
                    {
                        tree_node *new_node = new tree_node();
                        new_node->data = data;
                        new_node->node_count = 1;
                        new_node->l_child = nullptr;
                        new_node->r_child = nullptr;
                        e |= add_node(current_node, new_node, CHILD_DIRECTION_LEFT);
                        // cout << data << endl;
                        *inserted_node = new_node;
                        break;
                    }
                    else
                        current_node = current_node->l_child;
                }
            }
            update_all_tree_count(bst->root);
        }
    }
    return e;
}

assign2_exception::exception find_in_BST(BST *bst, uint64_t data, tree_node **target_node)
{
    assign2_exception::exception e = 0;
    if (bst == nullptr || target_node == nullptr)
        e |= NULL_POINTER_EXCEPTION;
    if ((bst->comp) == nullptr)
        e |= NULL_COMP_FUNCTION_EXCEPTION;

    if (!e)
    {
        if (bst->root == nullptr)
        {
            *target_node = 0x0;
        }
        else
        {
            tree_node *current_node = bst->root;
            while (true)
            {
                int comp = bst->comp(data, current_node->data);
                if (comp == 0)
                {
                    *target_node = current_node;
                    break;
                }
                else if (comp > 0)
                {
                    if (current_node->r_child == nullptr)
                    {
                        *target_node = 0x0;
                        break;
                    }
                    else
                        current_node = current_node->r_child;
                }
                else
                {
                    if (current_node->l_child == nullptr)
                    {
                        *target_node = 0x0;
                        break;
                    }
                    else
                        current_node = current_node->l_child;
                }
            }
        }
    }
    return e;
}

assign2_exception::exception splay(BST *bst, tree_node *node)
{
    uint32_t e = 0;
    if (bst == nullptr || node == nullptr)
        e |= NULL_POINTER_EXCEPTION;
    if (bst != nullptr && bst->comp == nullptr)
        e |= NULL_COMP_FUNCTION_EXCEPTION;
    if (!exist_node(bst, node))
    {
        e |= SPLAY_NODE_NOT_IN_TREE_EXCEPTION;
    }

    if (!e)
    {
        while(node->father!=nullptr){
            if(node->father->l_child==node){
                zig(bst,node);
            }
            else{
                zag(bst,node);
            }
        }

        update_all_tree_count(bst->root);
    }
    return e;
}