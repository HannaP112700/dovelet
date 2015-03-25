#include <stdio.h>
#include <stdlib.h>

//배열의요소는element타입으로선언

typedef struct StackNode {
	int data;
	struct StackNode *link;
}StackNode;//노드의타입 구조체선언

StackNode* top;///연결된스택의관련데이터

int isEmpty()//공백검사
{
	return (top == NULL);//top==null이라면반환
}

void push(int item)//데이터삽입함수 
{
	StackNode *temp=(StackNode*)malloc(sizeof(StackNode));//스택구조체동적할당
	temp->data=item;//item data에 temp값
	temp->link=top;//top의링크에temp
	top=temp;//temp를 top에넣는다
}

int pop()//삭제함수
{
	int item;//데이터선언
	StackNode *temp=top;//temp가 top를 가르키게함

	if(top == NULL){//top이 null이면 {
		
		return 0;
	}
	else {
		item = temp->data;//temp이저장된data는 item으로 
		top=temp->link;//temp가가르키던link는 top으로
		free(temp);
		return item;
	}
}


int main()//catalan num을 다시 pop해 순차적인 배열이 되는 지 확인
{
	int j,i,n,a,temp=0,k;//int형변수선언
	int arr[100];//배열 arr,arr2,num선언
	int arr2[100];
	int num[100];

	scanf("%d",&n);//숫자의 개수를 입력받는다

	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);//그 다음줄에 입력받은 숫자를 각각 배열 arr에 순서대로 넣는다
		num[i]=i+1;//num에는 위와 달리 1부터 n까지 순서대로 숫자를 집어넣고 나중에 비교할 수 있도록 만들어둔다
	}

	for(i=0;i<n;i++)
	{
		push(arr[i]);
		if(arr[i]<arr[i+1])//배열에입력된 숫자의 대소를 비교해 만약 뒷 숫자가 크다면 순차적인 배열의 흐름이 깨진거라생각해
		{
			break;//탈출한뒤
		}

	}
	j=i+1;
	
	while(isEmpty()==false)//스택이 빌때까지 pop을 해준다
	{
		arr2[temp]=pop();//pop을 하면서 배열arr2에 나온 순서대로 숫자를 입력한다
		temp++;
	}


	for(k=0;k<n;k++){//예를들어 7을 넣을 경우 1,2,3,4,5,6,7처럼 순차적인 최대경우를 고려해 n번까지 for문을 돌린다 


		for(i=j;i<n;i++)//앞부분과 같은 과정을 흐름이 끊긴이후 다시반복한다
		{
			push(arr[i]);
			if(arr[i]<arr[i+1])//만약 또 뒷 숫자가 크다면
			{
				break;//탈출
			}

		}
		while(isEmpty()==false)
		{
			arr2[temp]=pop();
			temp++;
		}

		j=i+1;//흐름이 다시시작하는 부분부터 이어가기위해 j에 i+1넣어준다
	}


	for(i=0;i<n;i++)
	{
		if(i == n-1)
		{
			printf("YES\n");//for문이 돌다 마지막인 n-1이 되면 모두 같았기 때문에 yes를 출력한다
		}
		else if(arr2[i]==num[i])//arr2에 들어간 숫자가 순차적인지, 순차적인 배열 num과 지교해준다
		{ 
			continue;//같다면 밑으로 가지 않고 continue 해준다
		}
		else
		{
			printf("NO\n");//하나라도 같지 않다면 no출력
			break;//탈출
		}
	}



}
