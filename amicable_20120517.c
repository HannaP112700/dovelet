#include <stdio.h>

int main()
{
	int a, x,j,i;//int형변수 a,x,j,i를 선언
	int sum,num;//int형변수 sum,num을 선언

	printf("");
	scanf("%d",&a);//자연수a를 입력받는다


	if(a<=10000)//범위는 10000이하의 자연수이므로 if문설정
	{
		
		for(x=2; x<=a;x++)//입력된 a까지의 자연수들이 완전수인지 검사해봐야 하므로 for문 후위증감연산자 사용
		{
			sum=0;//sum의 초기값을 0으로 설정한다.
			for(i=1; i <= x/2; i++)//x의 제외한 모든 약수를 돌려야 하므로 x/2이하의 약수를 for문 후위증감연산자로 모두 더한다.
			{
				
				if(x%i == 0)
					sum += i;//x는 x의 약수(=i)로 나누어지므로 if문을 사용해 맞다면 sum으로 모두 더한다
			}
			num=0;//num의 값을 0으로 초기화한다
			for(j=1; j <= sum/2; j++)//j는 sum을 제외한 sum의 모든 약수를 더하는 것으로 for문 설정
			{
				
				if(sum%j == 0)
					num += j;//sum는 sum의 약수(=j)로 나누어지므로 if문을 사용해 맞다면 num으로 모두 더한다
			}
			if(num == x)//만약 sum을 제외 모든 약수를 더한 num과 x의 값이 같을 경우 if문 설정
			{
				if(x < sum)//x가 sum보다 작다는 if문을 설정 안할 경우 예를들어 220 284과 284 220이 모두 나타난다 
					printf("%d %d\n",x, sum);//x와 sum을 출력한다
			}
		}
		
	}
	else
		printf("잘못입력");
}
