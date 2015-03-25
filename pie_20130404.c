#include<stdio.h>

int main()
{
	int f1_1, f1_2,f2_1, f2_2;//int형변수
	int up,down,i,up1,down1;//분자, 분모값
	int temp=1;//최대공약수 저장

	scanf("%d %d",&f1_1, &f1_2);//두명의 조각을 입력
	scanf("%d %d",&f2_1, &f2_2);

	down=f1_2*f2_2;//분모는 두 분모의 곱
	up=(f1_1*f2_2)+(f2_1*f1_2);//분자는 통분하면서 분자와 다른분모의 곱 또 다른분자와 분모의 곱을 더한다

	down1=down; up1=up;//값을 나눠가며 줄여가므로 초기 분모 분자값을 저장해둔다


	i=2;//1은 무의미하므로 2부터 while문 반복
	while(i!=down)//분자보다 큰 분모의 값과 같아지면 탈출
	{

		if(down%i==0 && up%i==0)// 분모 분자 모두 나눈 나머지가 0이 되야 최대공약수 만족
		{
			down=down/i;//값을 나눠 다시 저장한다 만약 그렇지 않을 경우 무한루프
			up=up/i;
			temp=temp*i;//최대공약수를 저장한다	

			continue;//한번 2로 나눴지만 또 나눌수도 있어 i증가전 다시 반복

		}
		i++;//i증가

		if(i>up)
			break;//계속 나눠진 up보다 i가 커지면 탈출

	}




	up=up1/temp;//처음 저장된 분자를 최대공약수로 나눈다
	down=down1/temp;//분모도 나눈다

	up=down-up;//구하는 값은 먹은 값이 아니라 남은 값이므로 분모-분자를 한다.

	if(up==0)//그러나 만약 분자가 0이면 분수형태가아닌 0으로 출력
	{
		printf("%d",up);
	}
	else
	{
		printf("%d",up);
		printf("/");
		printf("%d\n",down);
	}
}
