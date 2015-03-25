#include<stdio.h>

int main()
{
	int arr[50001];//입력받은값을 저장할 배열 생성
	int arr1[50000];//쓰러뜨리는 나무값 저장 배열
	int n,temp,num;
	int i,j,s=0;

	scanf("%d",&n);//나무의 갯수
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}//나무의 키 



	for(i=0;i<n-1;i++)//나무의 수만큼 반복(마지막 나무 제외)
	{
		if(arr[i] != 0)//쓰러뜨리면 나무의 키를 0으로 바꿈으로 0으로 바꾼 값이 다시 들어가지 않도록한다
		{

			if(arr[i]>= arr[i+1])//앞 나무가 뒷 나무 보다 크거나 같으면
			{
				if(i==0)//만약 첫번째 나무라면 
				{
					num=i;//while문 대입될 i 를 num 으로 대입
					temp=i;//나무쓰러뜨릴때 쓸 i temp 로 대입
					arr1[s++]=i+1;//쓰러뜨린 나무의 값 저장

					while(arr[num]-arr[num+1] >0)
					{
						num++;//앞나무가 계속 클 경우 num증가
					}

					for(j=temp;j<=num;j++)
					{
						arr[j]=0;//첫 나무부터 num으로 연속 쓰러뜨린 나무까지 배열 0대입
					}

				}

				else//첫번째 나무가 아니라면
				{
					num=i;
					temp=i;
					arr1[s++]=i+1;


					while(arr[num]-arr[num-1] >0)//이 나무보다 앞 나무가 작을경우
					{
						num--;//감소시킨다	
					}

					for(j=temp-1;j>=num;j--)
					{
						arr[j]=0;//num부터 이 나무 앞 나무까지 0 대입
					}

					num=i;
					while(arr[num]-arr[num+1] >0)
					{
						num++;//이 나무보다 뒷 나무들이 작으면 증가
					}

					for(j=temp;j<=num;j++)
					{
						arr[j]=0;//이 나무부터 작은 나무들을 모두 0대입
					}

				}
			}
		}
	}




	if(i== n-1)//마지막 나무
	{
		if(arr[n-1] != 0)//앞에서 대입된 0이 나오지 않도록
		{
			temp=i;
			arr1[s++]=i+1;

			num=i;
			while(arr[num]-arr[num-1] >0)//앞나무가 이 나무보다 작으면 반복
			{
				num--;//감소
			}


			for(j=temp;j>=num;j--)
			{
				arr[j]=0;//0대입
			}
		}
	}

	for(i=0;i<s;i++)
	{
		printf("%d\n",arr1[i]);//쓰러뜨린 나무 출력
	}





	return 0;
}
