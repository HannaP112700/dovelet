#include<stdio.h>

int day(int k){


	int i,temp=1,j;
	int arr[100];
	for(i=0;i<100;i++){
		arr[i]=1;
	}
	for(i=k;i>1;i--){
	arr[i/2]=arr[i/2]+arr[i];
	}

	if(k==1 || k==2){
	return 1;
	}

	else{

	
	for(i=k-1;i>(k-1)-arr[2];i--)
	{
		temp=temp*i;
	}

	for(j=arr[2];j>0;j--)
	{
		temp=temp/j;
	}
		return day(arr[2])*day(arr[3])*temp;

	}


}



int main(){
	
	int n,i,j;
	long long int temp;
	int arr[100];
	int super;
	for(i=0;i<100;i++){
		arr[i]=1;
	}
	
	scanf("%d", &n);//수를 입력받는다.

	for(i=n;i>1;i--){//자식부터 올라오며 부모 노드의 자식수+자신 을 계산.
	arr[i/2]=arr[i/2]+arr[i];
	}


	

	temp=1;//Combination 부분 계산
	for(i=n-1;i>(n-1)-arr[2];i--)
	{
		temp=temp*i;
	}

	for(j=arr[2];j>0;j--)
	{
		temp=temp/j;
	}

	super=day(arr[2])*day(arr[3])*temp;//왼자식, 오른자식, Combination 부분을 곱함. 왼자식과 오른자식은 재귀를 통해 계산
	printf("%d",super);


	return 0;
}
