#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0
#define STACK_LEN	1000

typedef int Data;

typedef struct _arrayStack//스택구조체선언
{
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack * pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack)
{
	if(pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack)
{
	int rIdx;

	if(SIsEmpty(pstack))
	{
		//printf("Stack Memory Error!");
		exit(-1);
	}

	rIdx = pstack->topIndex;
	pstack->topIndex -= 1;

	return pstack->stackArr[rIdx];
}

Data SPeek(Stack * pstack)
{
	if(SIsEmpty(pstack))
	{
		//printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];
}


int main(void)
{
	int n, i=0,j,s=0,mem=0;
	int arr[1000][1000];
	int check[1000][1000];
	int super;


	Stack stack;
	StackInit(&stack);
	
	



	scanf("%d",&n);

	for(i=0;i<1000;i++){//출력을 표시하기에 반대로 입력
	for(j=n-1;j>=0;j--){
 	scanf("%d",&arr[i][j]);

	
	if(arr[i][j]==0){
		super=i;mem=1;
			break;

	}	

	}
if(mem==1)
break;


	}


		
	for(i=0;i<super;i++){//스택에 넣을 때의 조건
// 자신보다 큰 것에는 삽입 불가 조건
		s=0;
	for(j=0;j<n;j++){
		
		if(j==0)
	SPush(&stack, arr[i][j]);

		else if(arr[i][j-1]<arr[i][j])
			SPush(&stack, arr[i][j]);

		
		else{
			while(SPeek(&stack)>arr[i][j]){
				check[i][s]=SPop(&stack);
				s++;
				if(SIsEmpty(&stack))
					break;
	
		}
			SPush(&stack, arr[i][j]);
			
	}
	}
	while(!SIsEmpty(&stack)){
				check[i][s]=SPop(&stack);
				s++;
	}
	
	}



	int snap=n;//숫자를 순서대로 출력하고 그것과 같은 순이라면 yes, 아니라면 no
	for(i=0;i<super;i++){
		snap=n;
		for(s=0;s<n;s++){
	
	if(check[i][s]==snap){
		
		if(s==n-1)
			printf("Yes\n");
	}
	else{
		printf("No\n");
		break;
	}
	snap--;
		}
	}
	
	
	return 0;
}
