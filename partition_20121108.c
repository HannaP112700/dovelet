#include<stdio.h>

int SUM(int n, int k)//분할수 점화식 함수
{
	int i,sum=0;//변수 초기화

	if(n==0){//입력받은수가 0일 경우 0출력
		sum=0;
		return sum;
	}
	else if(k==0){//입력받은 수가 존재하더라도 1~n까지 실행해야하므로 0일때 0출력
		sum=0;
		return sum;
	}
	else if(n==1){//시간안에 해결을 위해 간단하게 n이 입력 되었을 경우 1을 나타낸 다는 것을 표시
		if(k==1){
			sum=1;
			return sum;
		}
		else {//그 안에서 n이 1이 아닌경우는 모두 1보다 k의 값이 크므로 0을 반환
		sum=0;
		return sum;
	}
	}

	else if(n < k){//k가 n보다 클경우는 만족하지 못하므로 0출력
		sum=0;
		return sum;
	}
	else{
		sum = sum + SUM(n-1,k-1);//분할수 점화식을 이용하여 자신보다 1씩 작은 식과
		sum = sum + SUM(n-k,k);//n-k,k를 더한것을 총 합한다

		return sum;//sum반환}
}

int main()
{
	int n,k,i,temp=0;//변수 선언

	scanf("%d",&n);//n을 입력받는다

	for(k=1;k<=n;k++)
	{
		
		temp=temp+SUM(n,k);//k는 1부터 n까지의 갯수로 n을 만드는 것으로 모두 더한다
	}

	printf("%d",temp);//temp출력
}
