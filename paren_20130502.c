#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;

typedef struct _node{ //node 정의
	Data data;
	struct _node * next;
}Node;

typedef struct _listStack{  //head 정의
	Node * head;
}ListStack;

typedef ListStack Stack;

void StackInit(Stack * pstack)
{
	pstack->head=NULL;
}

int SIsEmpty(Stack * pstack)  //empty 검사
{
	if(pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)  //push 함수
{
	Node * newNode=(Node*)malloc(sizeof(Node));

	newNode->data=data;
	newNode->next=pstack->head;

	pstack->head=newNode;
}



Data SPop(Stack * pstack)  //pop 함수
{
	Data rdata;
	Node * rnode;

	if(SIsEmpty(pstack)){
		exit(-1);
	}

	rdata=pstack->head->data;
	rnode=pstack->head;

	pstack->head=pstack->head->next;
	free(rnode);

	return rdata;
}


int main()
{
	char arr[31]; //문자열 저장 배열
	int arr2[100];  //stack 값 꺼내서 저장할 배열
	int i=0;
	int sum=0,sum2=0;
	int errorcode=0;  // 괄호의 코드 값과 일치할 경우 오류 발생 잡는 errorcode

	Stack stack;  //stack 생성
	StackInit(&stack);

	gets(arr);  //문자열 입력

	if(arr[0]=='('||arr[0]=='[')  //첫번째 괄호는 오른쪽으로 열린 (,[를 받는다
		SPush(&stack,arr[0]);

	for(i=1;arr[i]!='\0';i++)  // 입력받은 문자열을 반복
	{
		switch(arr[i])  //문자열의 경우에 따라 계산
		{

		case '(':
			if(arr[i-1]!=']' || arr[i-1]!=')')  //stack 저장된 전 배열이 연관이 없을 시 입력
				SPush(&stack,arr[i]);
			break;

		case ')':
			if(arr[i-1]=='('){//전  배열와 짝이 맞을 경우
				SPop(&stack);  // pop 하고
				if(SIsEmpty(&stack) == FALSE)  //비어있지않다면
				{
					sum=SPop(&stack);  //꺼낸 뒤 한번더 꺼내 sum저장
					if(sum != '(' && sum != ')' && sum != '[' && sum != ']'){  //숫자라면
						SPush(&stack,2+sum);  //sum과 ()의 값은 2를 더해 push

						if(sum+2 == '(' || sum+2 == ')' || sum+2 == '[' || sum+2 == ']'){
							errorcode=sum+2; //sum에 2를 더한 값이 괄호의 코드와 같다면 에러코드에 저장해둔다
						}
					}

					else{
						SPush(&stack,sum);  //아니라면 sum을 다시 삽입
						SPush(&stack,2);}  //()결과 2 삽입
				}
				else{
					SPush(&stack,2);
				}  // 비어있다면 2삽입

				arr[i]=0;// 연산후 배열 값 0으로 만든다
			}
			else if(arr[i-1]==0){ //자신의 배열보다 한 칸 전이 0이라면 연산처리 한 것이므로
				sum=SPop(&stack);//pop한 값을 sum 저장
				SPop(&stack);//pop한 이전의 괄호 짝을 꺼낸다
				SPush(&stack,sum*2);//괄호()는 2이며 그 안에 있던 값을 곱함


				sum2=SPop(&stack);  //stack안에 숫자값이 있을 경우를 대비해 pop
				if(SIsEmpty(&stack) == FALSE)
				{
					sum=SPop(&stack);//한번더 pop
					if(sum != '(' && sum != ')' && sum != '[' && sum != ']')//이 값이 숫자라면
					{	SPush(&stack,sum2+sum);//더해서 push
					if(sum2+sum == '(' || sum2+sum == ')' || sum2+sum == '[' || sum2+sum == ']')//더한 값이 괄호의 코드와 같을 경우
						errorcode=sum2+sum;//에러 코드 저장
					}
					else{//숫자가 아니라면
						SPush(&stack,sum);//다시 차례로 push한다
						SPush(&stack,sum2);}
				}
				else//비어있다면
					SPush(&stack,sum2);//다시 저장한다
				arr[i]=0;//배열값 0으로 변경
			}
			break;

		case '[':
			sum=0;
			if(arr[i-1]!=']' || arr[i-1]!=')')
				SPush(&stack,arr[i]);
			break;

		case ']':

			if(arr[i-1]=='['){
				SPop(&stack);
				if(SIsEmpty(&stack) == FALSE)
				{
					sum=SPop(&stack);
					if(sum != '(' && sum != ')' && sum != '[' && sum != ']')
					{	SPush(&stack,3+sum);
					}
					else{
						SPush(&stack,sum);
						SPush(&stack,3);}
				}
				else{
					SPush(&stack,3);}
				if(sum+3 == '(' || sum+3 == ')' || sum+3 == '[' || sum+3 == ']'){
					errorcode=sum2+sum;

				}
				arr[i]=0;
			}
			else if(arr[i-1]==0){

				sum=SPop(&stack);
				SPop(&stack);
				SPush(&stack,sum*3);


				sum2=SPop(&stack);
				if(SIsEmpty(&stack) == FALSE)
				{
					sum=SPop(&stack);
					if(sum != '(' && sum != ')' && sum != '[' && sum != ']')
					{	SPush(&stack,sum2+sum);

					if(sum2+sum == '(' || sum2+sum == ')' || sum2+sum == '[' || sum2+sum == ']')
						errorcode=sum2+sum;
					}
					else{
						SPush(&stack,sum);
						SPush(&stack,sum2);
					}
				}
				else
					SPush(&stack,sum2);
				arr[i]=0;
			}
			break;
		}

	}

	i=0;
	while(!SIsEmpty(&stack)){//스택이 빌때까지
		arr2[i]=SPop(&stack);//pop한 값을 배열에 저장하고

		if(arr2[i] == '(' || arr2[i] == ')' || arr2[i] == '[' || arr2[i] == ']'){//괄호가 남아있는지 검사
			if(errorcode==0)//남아있을 경우 그게 괄호인지 더한 값인지 검사
				arr2[i]=0;//괄호라면 0저장
		}
	}
	for(sum=i;i>=0;i--){

		if(arr2[i]==0)
		{
			printf("0");//오류 있을 시 0출력
			break;//탈출
		}
		SPush(&stack, arr2[i]);//오류가 없을 때 계속 다시 push
	}


	if(arr2[i]!=0)  //오류가 없을 시
	{
		while(!SIsEmpty(&stack)){//스택이 빌때까지
			printf("%d\n", SPop(&stack));
		}
	}
	return 0;

}
