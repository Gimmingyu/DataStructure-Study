#ifndef _LINKEDLIST_
#define _LINKEDLIST_


#include <stdlib.h>
#include <stdio.h>

typedef struct ListNodeType
{
	int coef; // 계수
	int	degree; // 차수 
	struct ListNodeType *pLLink;
	struct ListNodeType *pRLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode headerNode;		// 헤더 노드(Header Node)
} LinkedList;

LinkedList* createPolynomialList();
void		deletePolynomialList(LinkedList *pList);
void		clearPolynomialList(LinkedList *pList);

LinkedList	*plus(LinkedList *aList, LinkedList *bList);
LinkedList	*minus(LinkedList *aList, LinkedList *bList);
void		alloc_calc_node(LinkedList *new_list, LinkedList *base_list, int flag);


int 		addPLElement(LinkedList* pList, ListNode element);
int			removePLElement(LinkedList *pList, int position);

ListNode	*getPLElement(LinkedList* pList, int position);
int			getPolynomialListLength(LinkedList *pList);
void		displayPLLinkedList(LinkedList *pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE	1
#define FALSE	0
#define ZERO(x) (x == 0 ? TRUE : FALSE)
#define UPPER_ZERO(x) (x > 0 ? TRUE : FALSE)
#define NULLCHECK(x) (!x ? NULL : x)
#define IS_BIG(x, y) (x < y ? TRUE : FALSE)
#define IS_LOWER(x, y) (x > y ? TRUE : FALSE)
#define IS_SAME(x, y) (x == y ? TRUE : FALSE)

#endif
