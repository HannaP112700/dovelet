#include<stdio.h>

int main()
{
	int arr[3][3]={0};//이차원배열을선언
	int i,j;//변수선언

	for(i=0;i<3;i++){//이중for문으로배열값입력
		for(j=0;j<3;j++){
			
			if(i == 2){//i==2일때 하나의값만을 입력받도록
				if(j < 1 )
					scanf("%d", &arr[i][j]);
			}
			else if(i == 1){//i==1일때 두개의 값을
				if(j < 2 )
					scanf("%d", &arr[i][j]);
			}
			else//3개의 값을 입력
			{	scanf("%d", &arr[i][j]);	}
		}
	}

	printf("%d ", arr[2][0]);//먼저 최하위값 출력

	while( arr[2][0] > 0)//arr[2][0]이 0이상 동안 while문 돌림
	{
		if( arr[1][0] > arr[1][1])//최하위 윗값끼리 비교
		{
			arr[2][0]=arr[1][0];
			arr[1][0]=0;//자리를 내려준뒤에는 그자리에 0을대입

			if(arr[0][0]>arr[0][1]){	
				arr[1][0]=arr[0][0];
				arr[0][0]=0;	
			}
			else{	
				arr[1][0]=arr[0][1];
				arr[0][1]=0;
			}

			
		}
		else//위의 if 불만족시
		{
			arr[2][0]=arr[1][1];
			arr[1][1]=0;

			if(arr[0][1]>arr[0][2]){
				arr[1][1]=arr[0][1];
				arr[0][1]=0;	
			}
			else{	
				arr[1][1]=arr[0][2]; 
				arr[0][2]=0;
			}
		}

		if( arr[2][0] != 0)//if와 else를 while문으로 반복하다 빈값에 저장된 0이 최하위에 도달할때
				printf("%d ", arr[2][0]);//출력한다
	}
	return 0;
}
