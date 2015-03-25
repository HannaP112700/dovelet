#include<stdio.h> 
#include<stdlib.h> 

#define TRUE 1 
#define FALSE 0 
#define STACK_LEN 100 

typedef int Data; 


typedef struct _node{ //node 정의  값과 count를 데이터로 가지고 있다
	Data count; 
	Data sum;
	struct _node * next; 
}Node; 

typedef struct _listStack{  //head 정의 
	Node * head; 
}ListStack; 

typedef ListStack Stack; 

void StackInit(Stack * pstack) { 
	pstack->head=NULL; 
} 

int SIsEmpty(Stack * pstack)  //empty 검사 
{ 
	if(pstack->head == NULL) 
		return TRUE; 

	else
		return FALSE; 
} 

void SPush(Stack * pstack, Data count, Data sum)  //push 함수 
{ 
	Node * newNode=(Node*)malloc(sizeof(Node)); 
	newNode->count=count; 
	newNode->sum=sum; 
	newNode->next=pstack->head; 
	pstack->head=newNode; 

} 
Data SPop(Stack * pstack)  //pop 함수 값을 리턴하는 것
{ 

	Data rsum,rcount; 
	Node * rnode; 

	if(SIsEmpty(pstack)){ 

		exit(-1); 

	} 
	rsum=pstack->head->sum; 
	rcount=pstack->head->count; 
	rnode=pstack->head; 




	pstack->head=pstack->head->next; 

	free(rnode); 

	return rsum; 

}

Data SPop2(Stack * pstack)  //pop 함수 카운트를 리턴해주는 것
{ 

	Data rsum,rcount; 
	Node * rnode; 

	if(SIsEmpty(pstack)){ 

		exit(-1); 

	} 
	rsum=pstack->head->sum; 
	rcount=pstack->head->count; 
	rnode=pstack->head; 




	pstack->head=pstack->head->next; 

	free(rnode); 

	return rcount; 

}

Data SPeek(Stack * pstack){//peek함수 값을 리턴
		if(SIsEmpty(pstack)){
			printf("Stack Memory Error!");
			exit(-1);
		}
		return pstack->head->sum;
	}

Data SPeek2(Stack * pstack){//peek함수 카운트를 리턴
	if(SIsEmpty(pstack)){
		printf("Stack Memory Error!");
		exit(-1);
	}
	return pstack->head->count;
}



int main() 

{ 
	int arr[80000];//80000번 까지인 배열 선언
	
	unsigned int i, j=0, sum, temp,sum2,count,count2,size;
double allsum=0;//값이 int를 넘치므로 double형 선언




	Stack stack;  //stack 생성 
	StackInit(&stack); 


	scanf("%d",&size); //size를 입력

	for(i=0;i<size;i++) {
		scanf("%d", &arr[i]);//차례로 값을 입력받는다
	}

	for(i=0;i<size;i++){//차례대로 스택에 넣어준다

		if(!SIsEmpty(&stack))//공백이 아니라면
		{
			if(SPeek(&stack)>arr[i]){//아래 값이 대입값보다 크다면
				sum=SPeek(&stack);
				count=SPop2(&stack);
				count=count+1;
				SPush(&stack, count, sum );//먼저 저장된 값을 꺼내 카운트를 증가시키고 다시 넣는다

				SPush(&stack, j,arr[i]);//새로운 대입값을 push
			}
			else{//아래값이 크지 않다면, 같거나 작은 경우
				
				count=SPop2(&stack);//먼저 가지고 있는 카운트를 count에 저장
				allsum=allsum+count;//전체 합에 더한다

				if(SIsEmpty(&stack))//만약 이걸 빼고나서 스택이 비었다면
				{
					SPush(&stack, j,arr[i]);//새로운 대입값을 넣는다
				}
				
				else{//아니라면

				count2=SPeek2(&stack);//지금 탑의 카운트를 저장해놓고
				sum=SPop(&stack);//값도 저장해 놓은채

				SPush(&stack, count+count2, sum);	//두 카운트를 더해서 다시 push
				i--;//밑에 아직 비교해보지 않은 값이 있으므로 i를 감소시킨뒤
				continue;//반복한다
				
			}
				
				
			}
		}
		else//스택이 비어있다면
		{
			SPush(&stack,j,arr[i]);//단순 삽입
		}
		



		
	}

	while(!SIsEmpty(&stack))//마지막으로 볼 때 스택이 비어있지 않다면
	{
		count=SPop2(&stack);//top을 pop하면서 count에 카운트 값 저장
		allsum=allsum+count;//전체에 카운트값 더한다
		if(!SIsEmpty(&stack)){//이 top 제거 후에도 공백이 아니라면
			sum=SPeek(&stack);
			count2=SPop2(&stack);
			SPush(&stack, count+count2, sum);//빼놓은 count를 더해 다시 삽입
		}
		

	}




	printf("%f",allsum);//마지막 전체 합 출력
	

	return 0; 
}
