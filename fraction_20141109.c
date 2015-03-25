#include <stdio.h>

void BubbleSort(int arr[], int arr2[], int n)//버블정렬
{
	int i, j;
	int temp,temp2;


	for(i=1; i<n-1; i++)
	{
		for(j=1; j<(n-i)-1; j++)
		{
			if(arr[j]*arr2[j+1] > arr[j+1]*arr2[j])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;

				temp2 = arr2[j];
				arr2[j] = arr2[j+1];
				arr2[j+1] = temp2;

			}
		}	
	}
}


int main(void)
{
	int arr[5000] = {0};//분자
	int arr2[5000] = {0};//분모
	int x,i,num,j,k,tmp,numtemp,numtemp2;
	int sum=1;


	scanf("%d",&num);
	arr[0]=0;
	arr2[0]=1;
	
	j=1;
	for(i=1;i<=num;i++){
		for(k=1;k<=num;k++){
			if(i < k){
				if(i>1 &&k%i!=0 ){
					x=k%i;
					
					for(numtemp=2;numtemp<100;numtemp++){//같은 값을 가지는 분수 제거

						if(k%numtemp==0 && i%numtemp==0)
							break;

						}
					
					if(x==1 || k%numtemp!=0 || i%numtemp!=0 )//조건에 일치하는 분수 배열에 넣음
					{		
						arr[j]=i;
						arr2[j]=k;		
			
						j++;
						}
				}
				else if (i==1){//i는 분자로 분자가 1인 조건 따로 배열에 넣음
			
				arr[j]=i;
			arr2[j]=k;
			
			j++;
				}
			
				else{}
				}

		}
	}
	
	for(i=0; arr2[i]>0; i++){//배열에 삽입된 값 계산
		tmp=i;
	}
	tmp=tmp+2;//여유공간
	BubbleSort(arr,arr2, tmp);//정렬
	tmp=tmp-2;
	arr[tmp+1]=1;//1은 늘 마지막 값이므로 정렬을 하지 않아도 된다
	arr2[tmp+1]=1;
	for(i=0; tmp+1>=i; i++){//출력
		printf("%d/%d\n", arr[i],arr2[i]);
		
	}

	return 0;
}
