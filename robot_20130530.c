#include <stdio.h> 
#include <stdlib.h>
typedef char shellfish [100][100];//배열 정의


 int Ce(shellfish arr,shellfish arr2,int i,int s,int x, int y,int temp)//재귀함수
 {
	 
	 int loop=0;
	if(i<1 || i>x || s<1 || s>y){//loop없을 경우 출력
				printf("%d step(s) to exit",temp);
	return 0;}

	if(arr2[i][s]=='B')//확인을 거친 것을 통해 loop,와 temp 출력
	{
		for(i=1;i<=x;i++)
			for(s=0;s<=y;s++)
				if(arr2[i][s]=='B') loop++;
	
	printf("%d step(s) before a loop of %d step(s)",temp,loop);
	return 0;
	}

	if(arr2[i][s]=='A')//이미 한번 방문 한 경우는 temp 다시 감소
	{
		 switch(arr[i][s]){
			case 'W':
				arr2[i][s]='B';s=s-1;temp--;
				break;
			case 'S':
				arr2[i][s]='B';i=i+1;temp--;
				break;
			case 'E':
				arr2[i][s]='B';s=s+1;temp--;
				break;
			case 'N':
				arr2[i][s]='B';i=i-1;temp--;
				break;
			}
	}
	else{


	 switch(arr[i][s]){//이동경로 확인
			case 'W':
				arr2[i][s]='A';s=s-1;temp++;
				break;
			case 'S':
				arr2[i][s]='A';i=i+1;temp++;
				break;
			case 'E':
				arr2[i][s]='A';s=s+1;temp++;
				break;
			case 'N':
				arr2[i][s]='A';i=i-1;temp++;
				break;
			}
	}

	 return Ce(arr,arr2,i,s,x,y,temp);
 }


int main(void) {
 int x,y, i,j, s,temp=0,q;
  shellfish arr,arr2;

 scanf("%d %d %d", &x, &y, &s);

 for(i=1;i<=x;i++)
  scanf("%s", &arr[i][1]);

	Ce(arr,arr2,1,s,x,y,temp);
	 



return 0;



	}
