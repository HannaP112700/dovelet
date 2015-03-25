#include <stdio.h>
int main()
{
	int i,n,j;//변수선언

	scanf("%d",&n);//n에 숫자입력받음 

	for(j=1;j<=n;j++)//1줄 , 각 줄의 *과 공백을 구별하여 각 개수를 센 뒤 n만큼 곱해 표현하고 이를 반복
	{
		for(i=4*n;i>0;i--){printf("*");}
		for(i=5*n;i>0;i--){printf(" ");}
		for(i=3*n;i>0;i--){printf("*");}
		for(i=3*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=5*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=1*n;i>0;i--){printf(" ");}
		for(i=5*n;i>0;i--){printf("*");}
		for(i=1*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=5*n;i>0;i--){printf(" ");}
		for(i=5*n;i>0;i--){printf("*");}
		for(i=1*n;i>0;i--){printf(" ");}
		for(i=5*n;i>0;i--){printf("*");}

		printf("\n");
	}

	for(j=1;j<=n;j++)//2줄
	{
		for(i=1*n;i>0;i--){printf("*");}
		for(i=3*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=3*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=3*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=2*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=5*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=1*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=5*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=5*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=7*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}

		printf("\n");
	}

	for(j=1;j<=n;j++)//3줄
	{
		for(i=1*n;i>0;i--){printf("*");}
		for(i=4*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=1*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=5*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=2*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=3*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=2*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=5*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=5*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=7*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}

		printf("\n");
	}

	for(j=1;j<=n;j++)//4줄
	{
		for(i=1*n;i>0;i--){printf("*");}
		for(i=4*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=1*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=5*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=2*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=3*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=2*n;i>0;i--){printf(" ");}
		for(i=5*n;i>0;i--){printf("*");}
		for(i=1*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=5*n;i>0;i--){printf(" ");}
		for(i=5*n;i>0;i--){printf("*");}
		for(i=3*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}

		printf("\n");
	}

	for(j=1;j<=n;j++)//5줄
	{
		for(i=1*n;i>0;i--){printf("*");}
		for(i=4*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=1*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=5*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=2*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=3*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=2*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=5*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=5*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=7*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}

		printf("\n");
	}

	for(j=1;j<=n;j++)//6줄
	{
		for(i=1*n;i>0;i--){printf("*");}
		for(i=3*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=3*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=3*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=4*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=1*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=3*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=5*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=5*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=7*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}

		printf("\n");
	}

	for(j=1;j<=n;j++)//7줄
	{
		for(i=4*n;i>0;i--){printf("*");}
		for(i=5*n;i>0;i--){printf(" ");}
		for(i=3*n;i>0;i--){printf("*");}
		for(i=6*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		for(i=4*n;i>0;i--){printf(" ");}
		for(i=5*n;i>0;i--){printf("*");}
		for(i=1*n;i>0;i--){printf(" ");}
		for(i=5*n;i>0;i--){printf("*");}
		for(i=1*n;i>0;i--){printf(" ");}
		for(i=5*n;i>0;i--){printf("*");}
		for(i=3*n;i>0;i--){printf(" ");}
		for(i=1*n;i>0;i--){printf("*");}
		
		printf("\n");
	}
	return 0;
}
