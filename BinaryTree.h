/*
	File name : simple Binary tree
	author : Hyuntaek Lim

	-----ADT-----
	각 트리는 왼쪽자식과 오른쪽 자식을 0~1개를 가지고 있다.
	NULL포인터인 원소도 공집합 노드로 간주한다.
	해당 구현은 간단한 이진트리 구현이 목적이므로, 중간에서 원소를 삽입하거나,
	중간에서 원소를 삭제하는 등의 행위는 일체 신경쓰지 않았다.
	모든 삭제와 삽입은 단말노드(자식이 없는 노드)에서만 진행한다. 
*/

#ifndef __BINARYTREE_H___
#define __BINARYTREE_H___

#define TRUE	1
#define FALSE	0

typedef struct _node {
	struct _node *leftChild;
	struct _node *rightChild;
	int data;
}TreeNode;

/*새로운 트리 개체를 만든다.*/
TreeNode* NewNode(void);
/*상위 트리의 왼쪽 자식트리를 만든다.*/
void MakeLeftSubTree(TreeNode *tp);
/*상위 트리의 오른쪽 자식트리를 만든다.*/
void MakeRightSubTree(TreeNode *tp);
/*상위 트리의 왼쪽 자식트리를 삭제한다.*/
void DeleteLeftSubTree(TreeNode *tp);
/*상위 트리의 오른쪽 자식트리를 삭제한다.*/
void DeleteRightSubTree(TreeNode *tp);
/*해당 트리에 데이터를 넣는다.*/
void TreePushData(TreeNode *tp, int data);
/*해당 트리의 데이터를 삭제하고 그 값을 반환한다.*/
int TreePopData(TreeNode *tp);

#endif // !__BINARYTREE_H___
