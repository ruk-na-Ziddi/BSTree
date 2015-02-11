#include "BSTree.h"
#include "expr_assert.h"
#include <stdlib.h>

void test_createBSTree_creates_a_tree_and_sets_its_root_to_NULL(){
	BSTree tree=createBSTree();
	assertEqual((int)tree.root, 0);
}

void test_createNode_creates_node_and_sets_its_data_to_15_leftNode_rightNode_to_NUll(){
	int data=15;
	Node_ptr node=createNode(data);
	assertEqual(node->data,15);
	assertEqual((int)(*node).leftNode, 0);
	assertEqual((int)(*node).rightNode, 0);
	free(node);
}

void test_createNode_creates_node_and_sets_its_data_to_150_leftNode_rightNode_to_NUll(){
	int data=150;
	Node_ptr node=createNode(data);
	assertEqual((*node).data,150);
	assertEqual((int)(*node).leftNode, 0);
	assertEqual((int)(*node).rightNode, 0);
	free(node);
}

void test_createNode_creates_node_and_sets_its_data_to_1500_leftNode_rightNode_to_NUll(){
	int data=1500;
	Node_ptr node=createNode(data);
	assertEqual((*node).data,1500);
	assertEqual((int)(*node).leftNode, 0);
	assertEqual((int)(*node).rightNode, 0);
	free(node);
}