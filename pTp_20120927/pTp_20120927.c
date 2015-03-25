#include <stdio.h>

int function(int n)//function함수로 받는다
{
	if(n==1){//n==1이라면
		printf("%d",n);//출력하고
		return 1;}//삐져나간다
	else
	{

		function(n-1);//다시 function으로 n-1값을보내는것을 반복한다
		printf("%d",n);//n을 가운데로 출력한다
		function(n-1);//위와 마찬가지로 n을 기점으로 양 쪽에 같은 값을 출력하기위한 기능
	}	
}

int main()
{
	int a; int n;//int형변수선언
	scanf("%d",&n);//n을 입력받음


	function(n);//function함수로 n을 보낸다

	return 0;//반환
}
