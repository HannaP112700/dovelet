#include <stdio.h>
#include <stdlib.h>//동적할당을 사용하기위해 선언
int main()
{
	int **data;//이중포인터를 선언
	int row, col, N, i, j, distance;//int형변수 row,col,N,i,j,distance를 선언
	long long int sum1;//sum1은 이차원배열 [N][N]이 1500*1500만큼의 큰 메모리를 필요로하므로 long long int형을 선언
	scanf("%d", &N);
	data = (int **)malloc( sizeof(int *) *N);//열에대한 동적인 메모리를 할당 
	for(i=0; i<N; ++i)
	{
		data[i] = (int *)malloc( sizeof(int) *N);//행에대한 동적인 메모리를 할당
	}

	sum1=0;//sum1의 값을 0으로 초기화한다
	for(i=0;i<N;i++)//열 i를 for문으로 배열0~(N-1)까지 돌린다
	{
		for(j=0;j<N;j++)//위와 마찬가지로 행 j도 for문으로 돌린다
		{
			scanf("%d", &data[i][j]);//먼저 각 배열에 scanf로 값을 받아 저장한다.
			if(i>=N/2)//열을 반으로 나눠 N/2보다 크다면 거리를 계산하는 것이므로 N-1을 row의 값으로 지정한다.
				row=N-i;
			else//만약 N-1보다 작다면 i는 0부터 시작하므로 거리는 1부터이기때문에 1을 더한다.
				row=i+1;
			if(j>=N/2)//행을 반으로 나눠 N/2보다 크다면 거리를 계산하는 것이므로 N-1을 col의 값으로 지정
				col=N-j;
			else//만약 N-1보다 작다면 i는 0부터 시작하므로 거리는 1부터이기때문에 1을 더한다.
				col=j+1;
			distance = row<=col ? row : col;//거리는 col이 row보다 크거나 같다면 row, col이 row보다 작다면 col로 최소의 거리를 설정할 수 있게 한다.
			sum1 += distance*(data[i][j]);//sum1은 배열안의 모든 distance*배열값을 더한다
		}
	}


	printf("%lld",sum1);//longlongint형으로 선언했기때문에 %lld로 sum1의 값을 출력한다.

	for(i=0;i<N;i++){//2차원배열에 할당된 메모리를 해제한다.
		free(data[i]);
	}
	free(data);
}
