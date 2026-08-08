#pragma once
#ifndef NODE_H
#define NODE_H

class BinaryTree;

class Node
{
	friend class BinaryTree;

private:
	int weight;
	int parent;
	int lchild;
	int rchild;
public:
	Node()
		:weight(0), parent(0), lchild(0), rchild(0)
	{

	}

	void setWeight(const int num)
	{
		weight = num;
	}

	int getWeight() const
	{
		return weight;
	}
};
#endif // !NODE_H

