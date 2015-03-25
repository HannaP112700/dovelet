#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _node	//노드 생성
{
	Data data;
	struct _node * next;
}Node;

typedef struct _1Queue	//큐 front,rear 선언
{
	Node * front;
	Node * rear;
}LQueue;

typedef LQueue Queue;

void QueueInit(Queue *pq)	//큐 초기화
{
	pq->front=NULL;
	pq->rear=NULL;
}

int QIsEmpty(Queue *pq)	//큐가 비었다면
{
	if(pq->front==NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue *pq, Data data)	//큐에 노드 생성
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->next=NULL;
	newNode->data=data;



	if(QIsEmpty(pq))
	{
		pq->front=newNode;
		pq->rear=newNode;
	}
	else
	{
		pq->rear->next=newNode;
		pq->rear=newNode;
	}
}

Data Dequeue(Queue * pq)	//큐 노드 삭제
{
	Node * delNode;
	Data retData;

	if(QIsEmpty(pq))
	{
		printf("OH, MY GOD");
		exit(-1);
	}

	delNode=pq->front;
	retData=delNode->data;
	pq->front=pq->front->next;

	free(delNode);

	return retData;
}

Data QPeek(Queue * pq)	// peek함수
{
	if(QIsEmpty(pq))
	{
		printf("OH, MY GOD");
		exit(-1);
	}
	return pq->front->data;
}

int main()

{


	int arr[100][100];
	int i,j,size,ini,inj,move,supernum=2,temp=0,temp2=0;


	Queue q,q2;	//행 열 값 저장할 큐 선언
	QueueInit(&q);//큐 초기화
	QueueInit(&q2);



	scanf("%d", &size);//배열의 크기를 입력

	for(i=0;i<size;i++){
		for(j=0;j<size;j++){

			scanf("%d ",&arr[i][j]);//배열 구조 대입
		}
	}

	scanf("%d %d", &inj, &ini);//가로
	scanf("%d", &move);//세로


	ini=ini-1;//행열은 0부터이므로 -1
	inj=inj-1;
	arr[ini][inj]=9;//행열의 값이 0이면 비어있다고 생각해서 전진하려함

	
		if(arr[ini-1][inj] == 0)	//배열 시계 방향으로 검사, 0이라면 1의 값대입
		{

			if(ini-1<0 || ini-1>=size || inj<0 || inj>=size)
			{}
			else{	

				arr[ini-1][inj]=1;
				Enqueue(&q,ini-1);Enqueue(&q2, inj);
				temp++;
			}
		}


		if(arr[ini][inj+1] == 0)
		{


			if(ini<0 || ini>=size || inj+1<0 || inj+1>=size)
			{}
			else{

				arr[ini][inj+1]=1;
				Enqueue(&q,ini);Enqueue(&q2,inj+1);
				temp++;
			}
		}


		if(arr[ini+1][inj] == 0)
		{


			if(ini+1<0 || ini+1>=size || inj<0 || inj>=size)
			{}
			else{
				arr[ini+1][inj]=1;
				Enqueue(&q,ini+1);Enqueue(&q2,inj);
				temp++;
			}
		}


		if(arr[ini][inj-1] == 0)
		{


			if(ini<0 || ini>=size || inj-1<0 || inj-1>=size)
			{}
			else
			{
				arr[ini][inj-1]=1;
				Enqueue(&q,ini);Enqueue(&q2,inj-1);
				temp++;
			}
		}
	





	while(supernum-1!=move){//2부터는 while을 통해 검사

		if(arr[QPeek(&q)][QPeek(&q2)]==supernum-1){//2를 supernum이라고 주고 peek으로 본 큐에 저장된 값을 넣은 배열이 super-1이면 아직 1이 있으므로 돌린다
			ini=Dequeue(&q);//삭제와 동시에 가로세로에 대입한다
			inj=Dequeue(&q2);
			
				if(arr[ini-1][inj] == 0)	//0이 배열에 저장 되어 있다면 지금 루틴의 숫자를 대입한다
				{

					if(ini-1<0 || ini-1>=size || inj<0 || inj>=size)
					{}
					else{	
						arr[ini-1][inj]=supernum;
						Enqueue(&q,ini-1);Enqueue(&q2, inj);
						temp2++;
					}
				}


				if(arr[ini][inj+1] == 0)
				{


					if(ini<0 || ini>=size || inj+1<0 || inj+1>=size)
					{}
					else{
						arr[ini][inj+1]=supernum;
						Enqueue(&q,ini);Enqueue(&q2,inj+1);temp2++;
					}
				}


				if(arr[ini+1][inj] == 0)
				{


					if(ini+1<0 || ini+1>=size || inj<0 || inj>=size)
					{}
					else{
						arr[ini+1][inj]=supernum;
						Enqueue(&q,ini+1);Enqueue(&q2,inj);temp2++;
					}
				}


				if(arr[ini][inj-1] == 0)
				{


					if(ini<0 || ini>=size || inj-1<0 || inj-1>=size)
					{}
					else
					{
						arr[ini][inj-1]=supernum;
						Enqueue(&q,ini);Enqueue(&q2,inj-1);temp2++;
					}
				}
			

		}
	

		if(arr[QPeek(&q)][QPeek(&q2)]==supernum)//supernum과 다음 배열의 값이 같다면 
		{
			if(supernum!=move)temp2=0;//이게 마지막이 아닌 경우 temp를 초기화하고 아닐경우 초기화하지 않는다


			supernum++;//supernum을 증가해 반복문을 실행
			
			
			
		}
		
	

	}


	if(move==1)
	printf("%d",temp);//무브가 1이면 반복문 없이 앞의 1을 위한 식으로만 계산가능

	else
	{
		printf("%d",temp2);//temp2 출력
	}




	return 0;
}
