#include<stdio.h>

int main()
{
	int size, Target, i,count,num;//변수 선언
	int ScoreList[100000]={0};// 누적된 수를 저장할 배열 선언
	int Left, Right, Mid;//이진 탐색 left,mid,right 선언

	scanf("%d %d", &size,&Target);//size와 target을 입력받고

	for(i=0;i<size;i++)
	{
		scanf("%d", &ScoreList[i]);//for문으로 size만큼 입력받은 수를 배열방에 저장한다
		if(i != 0) //단, 0번 방 이상부터는
			ScoreList[i] += ScoreList[i-1];//누적배열로 전 배열 방의 수와 이번에 입력받은 숫자를 더해 이 방에 저장한다
	}

	if(ScoreList[size-1]<Target) // while문으로 탐색 전에 누적배열의 총합이 target값보다 못하다면 
	{							// 이진탐색을 돌려도 만족하는 값을 찾을 수 없으므로 0을 출력해준다
		printf("0");
	}
	else	//if문을 만족하지 않을시, 이진탐색 실행
	{
		Left=0;//left를 0으로
		Right=size;//size를 right값에 넣은 상태에서

		while(Left<Right)//left가 right보다 작을 동안 while문 실행
		{
			Mid=(Left+Right)/2;//mid는 left 와 right의 합을 2로 나눔으로 mid값을 맞쳐주기위해 size의 값을 그대로 right에 넣은 것이다
			if(ScoreList[Mid-1]>Target)//이진탐색 첫번째 구간은 배열에서 배열을 빼지 않고 mid값보다 1작은 방의 값 그대로를 나타내는
				num=ScoreList[Mid-1];	//것이므로 mid-1번 방의 값ㄷ이 target보다 크다면 num에 그 값을 저장한다
			else	//if문을 만족하지 않을 시
			{
				count=0;//count는 0으로 초기화

				for(i=Mid;i<size;i++)	//mid-1번방 확인 후 이므로 mid부터 size이하까지 for문을 돌린다
				{
					num=ScoreList[i]-ScoreList[count];//num에는 누적된 값을 빼면서 사이값을 구하므로 그것을 num에 저장
					count++;//count는 빼주는 방이 증가하므로 for문안에서 증가시킨다.
					if(num > Target)//저장된 num의 값이 target보다 크다면
						break;//for문을 빠져나간다
				}
				count=0;//for문이 끝나고 while문이 반복되기때문에 count를 다시 0으로 초기화
			}
			if(Target>=num){	Left=Mid+1;		}	//num에 저장되는 값을 바탕으로 target과 num 크기를 비교한다. target이 num보다 같거나 크다면 left를 mid+1해주고 
			else{	Right=Mid;	}//	if문 불만족시 right에 mid값을 저장
		}
		printf("%d",Left);}//while문 끝낸뒤 left의 값을 출력해준다

	return 0;
}

