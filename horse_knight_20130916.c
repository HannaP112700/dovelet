#include <stdio.h>
#include <stdlib.h>
 
#define TRUE    1
#define FALSE   0
 
typedef int Data;
 
typedef struct _node
{
    Data data,data2;
    struct _node * next;
} Node;
 
typedef struct _lQueue
{
    Node * front;
    Node * rear;
} LQueue;
 
typedef LQueue Queue;
 
void QueueInit(Queue * pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}
 
int QIsEmpty(Queue * pq)
{
    if(pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}
 
void Enqueue(Queue * pq, Data data, Data data2)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
    newNode->data2 = data2;
 
    if(QIsEmpty(pq))
    {
        pq->front = newNode;
        pq->rear = newNode;
    }
    else
    {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}
 
Data Dequeue(Queue * pq)
{
    Node * delNode;
    Data retData;
    Data retData2;
 
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
 
    delNode = pq->front;
    retData = delNode->data;
    retData2 = delNode->data2;
    pq->front = pq->front->next;
 
    free(delNode);
    return retData2;
}
 
Data QPeek(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
 
    return pq->front->data;
}
Data QPeek2(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
 
    return pq->front->data2;
}
 ////////////////////////////////////여기까지 큐 구현
int main(void)
{
    int n,k,i,j,f_i,f_j;
    int arr[1000][1000];
    int arr2[1000][1000];
    int star=1,star2=1;
    int count=0;
    // Queue의 생성 및 초기화 ///////
    Queue q;
    QueueInit(&q);
 
     
 
    scanf("%d %d", &n,&k);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d", &arr[i][j]);
            if(arr[i][j]==1)
                arr[i][j]=-2;
        }
    }
 
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            arr2[i][j]=arr[i][j];
        }
    }
 
    scanf("%d %d", &f_i,&f_j);
    f_i=f_i-1;
    f_j=f_j-1;
     
    arr[f_i][f_j]=-1;
    arr2[f_i][f_j]=-1;
 
    i=f_i; j=f_j;
 
 while(1){//나이트 조건, 갈 수 있는 8가지 조건을 반복문을 통해 반복, 단 쓰지않는 부분도 포함해 계산.
	if(i-2>= 0&& j-1>=0 && arr[i-2][j-1]==0){arr[i-2][j-1]=star; Enqueue(&q, i-2,j-1);}
	else if(i-2>=0 && j+1<n && arr[i-2][j+1]==0){arr[i-2][j+1]=star;Enqueue(&q, i-2,j+1);}
	else if(i+2 <n && j-1>=0 && arr[i+2][j-1]==0){arr[i+2][j-1]=star;Enqueue(&q, i+2,j-1);}
	else if(i+2<n && j+1<n && arr[i+2][j+1]==0){arr[i+2][j+1]=star;Enqueue(&q, i+2,j+1);}
	else if(j-2 >=0 && i-1>=0 && arr[i-1][j-2]==0){arr[i-1][j-2]=star;Enqueue(&q, i-1,j-2);}
	else if(i-1 >=0 && j+2<n && arr[i-1][j+2]==0){arr[i-1][j+2]=star;Enqueue(&q, i-1,j+2);}
	else if(j-2 >=0 && i+1<n && arr[i+1][j-2]==0){arr[i+1][j-2]=star;Enqueue(&q, i+1,j-2);}
	else if(i+1<n && j+2<n && arr[i+1][j+2]==0){arr[i+1][j+2]=star;Enqueue(&q, i+1,j+2);}
	else {	star++; break;}
	}
   	while(!QIsEmpty(&q)){
		i=QPeek(&q); j=QPeek2(&q);
		if(arr[i][j]==star) {star++;}

		
	if(i-2>= 0&& j-1>=0 && arr[i-2][j-1]==0){arr[i-2][j-1]=star; Enqueue(&q, i-2,j-1);}
	else if(i-2>=0 && j+1<n && arr[i-2][j+1]==0){arr[i-2][j+1]=star;Enqueue(&q, i-2,j+1);}
	else if(i+2 <n && j-1>=0 && arr[i+2][j-1]==0){arr[i+2][j-1]=star;Enqueue(&q, i+2,j-1);}
	else if(i+2<n && j+1<n && arr[i+2][j+1]==0){arr[i+2][j+1]=star;Enqueue(&q, i+2,j+1);}
	else if(j-2 >=0 && i-1>=0 && arr[i-1][j-2]==0){arr[i-1][j-2]=star;Enqueue(&q, i-1,j-2);}
	else if(i-1 >=0 && j+2<n && arr[i-1][j+2]==0){arr[i-1][j+2]=star;Enqueue(&q, i-1,j+2);}
	else if(j-2 >=0 && i+1<n && arr[i+1][j-2]==0){arr[i+1][j-2]=star;Enqueue(&q, i+1,j-2);}
	else if(i+1<n && j+2<n && arr[i+1][j+2]==0){arr[i+1][j+2]=star;Enqueue(&q, i+1,j+2);}
	else {	Dequeue(&q); }
	}
     
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
           // printf("%d ", arr[i][j]);   
        }
      // printf("\n");
    }
 
   i=f_i; j=f_j;

	while(1){//마 조건
	if(i-2>= 0&& j-1>=0 && arr2[i-2][j-1]==0 && arr2[i-1][j] != -2){arr2[i-2][j-1]=star2; Enqueue(&q, i-2,j-1);}
	else if(i-2>=0 && j+1<n &&arr2[i-2][j+1]==0 && arr2[i-1][j] != -2 ){arr2[i-2][j+1]=star2;Enqueue(&q, i-2,j+1);}
	else if(i+2 <n && j-1>=0 && arr2[i+2][j-1]==0 && arr2[i+1][j] != -2 ){arr2[i+2][j-1]=star2;Enqueue(&q, i+2,j-1);}
	else if(i+2<n && j+1<n && arr2[i+2][j+1]==0 && arr2[i+1][j] != -2 ){arr2[i+2][j+1]=star2;Enqueue(&q, i+2,j+1);}
	else if(j-2 >=0 && i-1>=0 && arr2[i-1][j-2]==0 &&   arr2[i][j-1] != -2){arr2[i-1][j-2]=star2;Enqueue(&q, i-1,j-2);}
	else if(i-1 >=0 && j+2<n && arr2[i-1][j+2]==0 &&   arr2[i][j+1] != -2){arr2[i-1][j+2]=star2;Enqueue(&q, i-1,j+2);}
	else if(j-2 >=0 && i+1<n && arr2[i+1][j-2]==0 &&  arr2[i][j-1] != -2){arr2[i+1][j-2]=star2;Enqueue(&q, i+1,j-2);}
	else if(i+1<n && j+2<n &&  arr2[i+1][j+2]==0 &&   arr2[i][j+1] != -2){arr2[i+1][j+2]=star2;Enqueue(&q, i+1,j+2);}
	else {	star2++; break;}
	}





	while(!QIsEmpty(&q)){
		i=QPeek(&q); j=QPeek2(&q);
		if(arr2[i][j]==star2) {star2++;}
	if(i-2>= 0&& j-1>=0 && arr2[i-2][j-1]==0 && arr2[i-1][j] != -2){arr2[i-2][j-1]=star2; Enqueue(&q, i-2,j-1);}
	else if(i-2>=0 && j+1<n &&arr2[i-2][j+1]==0 && arr2[i-1][j] != -2 ){arr2[i-2][j+1]=star2;Enqueue(&q, i-2,j+1);}
	else if(i+2 <n && j-1>=0 && arr2[i+2][j-1]==0 && arr2[i+1][j] != -2 ){arr2[i+2][j-1]=star2;Enqueue(&q, i+2,j-1);}
	else if(i+2<n && j+1<n && arr2[i+2][j+1]==0 && arr2[i+1][j] != -2 ){arr2[i+2][j+1]=star2;Enqueue(&q, i+2,j+1);}
	else if(j-2 >=0 && i-1>=0 && arr2[i-1][j-2]==0 &&   arr2[i][j-1] != -2){arr2[i-1][j-2]=star2;Enqueue(&q, i-1,j-2);}
	else if(i-1 >=0 && j+2<n && arr2[i-1][j+2]==0 &&   arr2[i][j+1] != -2){arr2[i-1][j+2]=star2;Enqueue(&q, i-1,j+2);}
	else if(j-2 >=0 && i+1<n && arr2[i+1][j-2]==0 &&  arr2[i][j-1] != -2){arr2[i+1][j-2]=star2;Enqueue(&q, i+1,j-2);}
	else if(i+1<n && j+2<n &&  arr2[i+1][j+2]==0 &&   arr2[i][j+1] != -2){arr2[i+1][j+2]=star2;Enqueue(&q, i+1,j+2);}
	else {	Dequeue(&q); }
	}

	//printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			//printf("%d ", arr2[i][j]);	
			if(arr2[i][j]==0)
			{//count++;
			}
		}
		//printf("\n");
	}

   for(i=0;i<n;i++)// 나이트의 수가 작거나, 아예 마가 출발을 못한 경우
    {
        for(j=0;j<n;j++){
            if(arr[i][j]<arr2[i][j])
                count++;
			else if(arr2[i][j]==0 && arr[i][j]>0){
count++;
			}
else{}
        }
    }
  
    printf("%d", count);
	
    return 0;
}


//더블릿은 절대 거짓말을 하지 않습니다.
