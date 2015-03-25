#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){


	int num,i;
	int arr[100]={NULL};
	int j=0,temp;

	scanf("%d", &num);

	for(i=2;i<num;i++){

		if(num%i == 0){
			printf("%d is not prime",num);
			j=1;
			break;
		}// 나머지가 나눠지면 소수가 아니다!
	}
	


	 
	if(j==0){


		i=0;
		j=num;
		while(1)
		{
			arr[i]=j%10; 
			
			j=j/10;
			i++;
			if(j<10)
			{
				arr[i]=j;	
				
				break;

			}
			
		}//배열에 뒤집은 값 저장
		temp=0;
		
	
		if(num > 9){
		for(j=0;j<=i;j++)
		{
			temp=temp+arr[j]*(pow(10,i-j));//수 뒤집기, 제곱근으로 자릿수 맞추기
		}
		
		}
		else
		{
			temp=num;//1의 자리수는 뒤집는 과정 생략
		}
		

		if(temp > 9){
		for(i=2;i<temp;i++){

		if(temp%i == 0 ){
			printf("%d is a prime",num);
			j=1;
			break;
		}
		//나눠지면 단순한 소수이다!
		}
		

		}

		if(j!=1)
			printf("%d is an emirp",num);
		//나눠지지 않으면 역수 또한 소수이다!
	}
	

	return 0;

}
