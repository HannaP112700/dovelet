#include<stdio.h>
int main()
{
	int i,j,k=0,count,temp,newtarget;
	int sum[4]={0};
	int num[4]={0};
	int target[4]={0};

	for(i=0;i<4;i++){scanf("%d",&target[i]);}//4자리 수 target배열값을 입력받는다

	sum[0]=target[0]*1000+target[1]*100+target[2]*10+target[3];//sum 배열에 입력받은 숫자를 시계방향으로 움직여가며 입력한다
	sum[1]=target[1]*1000+target[2]*100+target[3]*10+target[0];
	sum[2]=target[2]*1000+target[3]*100+target[0]*10+target[1];
	sum[3]=target[3]*1000+target[0]*100+target[1]*10+target[2];

	for(j=0;j<4;j++)//for문으로 sum배열의 최소의 값을 sum[0]에 저장하도록 한다.
	{
		if(sum[0]<sum[j]){continue;}
		else{
			temp=sum[0];
			sum[0]=sum[j];
			sum[j]=temp;
		}
	}

	newtarget=sum[0];//newtarget값에 sum[0]인 최솟값을 대입

	for(i=1111;i<=newtarget;i++)//1111부터 newtarget이 몇번째 시계수인지 알기위해 for문돌린다
	{
		num[0]=i/1000;//각자리의 값을 num배열에 저장
		num[1]=i%1000/100;
		num[2]=i%1000%100/10;
		num[3]=i%1000%100%10;

		if(num[0]==0 && num[1]==0 && num[2]==0 && num[3]==0){continue;}//조건에서 1~9까지라고 했으므로 0은 들어갈 수 없다
		else
		{
			sum[0]=num[0]*1000+num[1]*100+num[2]*10+num[3];//위와 마찬가지로 나눠진 값을 시계방향으로 돌려가며 sum배열에 저장
			sum[1]=num[1]*1000+num[2]*100+num[3]*10+num[0];
			sum[2]=num[2]*1000+num[3]*100+num[0]*10+num[1];
			sum[3]=num[3]*1000+num[0]*100+num[1]*10+num[2];

			for(j=0;j<4;j++)//최소값을 sum[0]에 저장하기위한 for문
			{
				if(sum[0]<sum[j])
				{}
				else
				{
					temp=sum[0];
					sum[0]=sum[j];
					sum[j]=temp;
				}
			}

			if(sum[0]==i)//만약 sum[0]의 값인 최솟값과 i의 값이 일치한다면 시계수로 볼 수 있기때문에 k증가
			{
				k++;//증가시킨다
			}
		}

	}
	printf("%d",k);//몇번째 시계수인지 출력

	return 0;
}

