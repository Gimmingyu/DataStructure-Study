#ifndef _SIMULATION_
# define _SIMULATION_

#include <stdio.h>
#include <stdlib.h>

typedef	enum e_flag
{
	TRUE = 1,
	FALSE = 0,
	ERR = -1,
} t_flag;

typedef enum SimStatusType { arrival, start, end } SimStatus;

typedef struct SimCustomerType
{
	SimStatus	status;
	int			arrivalTime;
	int			serviceTime;
	int			startTime;
	int			endTime;
} SimCustomer;

typedef struct QueueNodeType
{
	SimCustomer				*customerData;
	struct QueueNodeType	*pRLink;
} QueueNode;

typedef struct LinkedQueueType
{
	int 		currentElementCount;
	QueueNode	*pFrontNode;
	QueueNode	*pRearNode;
} LinkedQueue;

// 고객을 도착큐에 전부 담아놓고
void		insertCustomer(int arrivalTime, int processTime, LinkedQueue *pQueue);
// 도착 시간되면 대기큐로 이동
void		processArrival(int cureentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue);

// 대기큐에서 front노드 service시작 
QueueNode	*processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue);
// 서비스가 종료된 고객 free
QueueNode	*processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, \
int *pServiceUserCount, int *pTotalWaitTime);

// 현재 시간에 service중인 customer?
void		printSimCustomer(int currentTime, SimCustomer customer);
// 대기중인 큐 display
void		printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);
// 남은 고객, 서비스 받은 고객, 고객들이 총 기다린 시간 display
void		printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime);


LinkedQueue	*createLinkedQueue();
int	insertLQ(LinkedQueue* pQueue, QueueNode element);
QueueNode	*deleteLQ(LinkedQueue* pQueue);
QueueNode	*peekFrontLQ(LinkedQueue* pQueue);
QueueNode	*peekRearLQ(LinkedQueue* pQueue);
void	deleteLinkedQueue(LinkedQueue* pQueue);
int isLinkedQueueEmpty(LinkedQueue* pQueue);

#endif

