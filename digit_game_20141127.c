#include<stdio.h>

int main(){

	int count,i,j,k,l,temp=0,super;
	int arr[1000][6];
	int sum[1000]={0};

	scanf("%d", &count);

	for(i=0;i<count;i++)
	{
		temp=0;
		for(j=0;j<5;j++)
			scanf("%d",&arr[i][j]);


		for(j=0;j<3;j++){//5P3 실행
			for(k=j+1;k<4;k++){
				for(l=k+1;l<5;l++){

					temp=(arr[i][j]+arr[i][k]+arr[i][l])%10;
					//printf("tmp값 입니당 %d 연산에 사용된값 순서 %d %d %d\n",temp,j,k,l);
					if(temp>=sum[i])
						sum[i]=temp; 
					
					
					//printf("현재 쵝오값 %d\n",sum[i]);



					
				}
			}
		}

	}

	super=0;
	for(i=1;i<count;i++){
		
		
		
		if(sum[super]<=sum[i])
		{super=i;}

		
		


	}
	
	for(i=0;i<count;i++){
		//printf("%d\n",sum[i]);
}
		printf("%d",super+1);






	return 0;
}
이 게시물을...
