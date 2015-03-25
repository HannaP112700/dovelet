#include <stdio.h>
int main()
{
	int i,j,k,n,stop_num,d,gs,ks,l,kang;//변수선언
	int f_num;//입력받은숫자
	int arr1[100];//int형 배열선언
	int arr2[100];
	int temp[100];



	scanf("%d",&n);//입력받을 숫자의 개수
	scanf("%d", &f_num);//숫자를입력받음



	d=1;gs=1;//d와 gs를1로초기화,
	while(1)//무한루프
	{
		if(d <= f_num && f_num <d*10)//d보다 크거나 d*10미만일때 탈출
		{
			//printf("%d\n",gs);
			break;
		}
		else
		{
			d=d*10;//d는 10을 곱하면서 자릿수의 증가를 표현
			gs++;//몇자리숫자냐는 일의자리숫자 몇개로 구성되어있느냐를 나타내는 것으로 gs로 표현
		}
	}//개수체크




	ks=gs;//ks에 gs값대입
	d=1;//d를 다시 1로 초기화한다
	for(k=0;k<ks;k++)
	{
		printf("%d\n",d);
		temp[k]=d;
		d=d*10;

	}//temp배열 값에 1부터 만약 만의자리수라면 10000까지 1,10,100,1000,10000까지 차례대로 대입
	
	
	l=0;//l을 0으로 초기화
	for(i=ks-1;i>=0;i--)//배열을 거꾸로 가장 큰 개수를 가진 배열부터 아래로 나타낸다
	{
		arr1[i]=f_num;//각 자리의 수를 알기위해서는 일단 각자리에 첫입력값을 대입한다
		
		for(j=ks-1;j>l;j--)
		{
			arr1[i]=arr1[i]%temp[j];//그후 각자리수에 해당하는 temp의 자릿수값으로 %d해가며 줄여가며
		}
		
		if(j==l)
		{
			arr1[i]=arr1[i]/temp[l];l++;//마지막한번은 나누기를 함으로 그 몫을 해당 자리 수의 값으로 지정할 수 있다.
		}

	}
	kang=gs;//kang에 gs값 대입



	f_num=f_num*gs;//첫입력숫자에 그자리수를 곱한다.


	d=1;gs=1;//초기화, arr2도 arr1과 같은 방법으로 구한다. arr2는 arr1을 뒤집은 그 숫자를 f_num으로 대입한 상태에서 그에따른 자릿값저장.
	while(1)
	{
		if(d <= f_num && f_num <d*10)
		{
			
			break;
		}
		else
		{
			d=d*10;
			gs++;
		}
	}//개수체크



	ks=gs;
	d=1;
	for(k=0;k<ks;k++)
	{
		printf("%d\n",d);
		temp[k]=d;
		d=d*10;

	}
	l=0;
	for(i=ks-1;i>=0;i--){
		arr2[i]=f_num;
		for(j=ks-1;j>l;j--){
			arr2[i]=arr2[i]%temp[j];
		}
		if(j==l)
		{
			arr2[i]=arr2[i]/temp[l];l++;
		}	
	}






	if(kang == gs)
	{
		for(i=0;i<kang;i++)
		{
			for(j=0;j<gs;j++)
			{
				if(arr1[i]==arr2[j])
				{
					stop_num=j;
					printf("%d\n",stop_num);
					break;
				}
			}
		}
	}//멈추는 숫자구하기. arr2의 몇번째 방에서 다시시작되는지를 찾는다





	stop_num=stop_num+1;//1을 더한값이 stop_num의 값이되고
	i=0;j=0;//초기화
	k=stop_num;//k에 stop_num의 값을 대입한다.




	while(1)//무한루프
	{

		if(arr1[i++]==arr2[stop_num++])
		{
			if(stop_num >=gs)
			{
				if(arr1[i++]==arr2[j++])
				{
					if(j == k)
					{
						printf("YES");break;//i는 0부터 증가하되 arr2의 경우는 stop_num부터 증가하며 stop_num이 개수 이상이 될때는 처음의 0값으로돌아가
						//stop_num보다 작은 값까지 돌며 두 값이 같은지 확인을 하며 같다면 yes를 출력하고 탈출한다.
					}
					else
					{
						printf("NO");
					}
				}
				printf("NO");
			}
			printf("NO")
		}
		else
			break;
	}






	return 0;
}



//숫자재배열까지는 돌아가며 
//마지막에 
//YES,NO판단과 
///입력 받은 만큼 돌아가는 것에 대한 것이 미흡합니다.
