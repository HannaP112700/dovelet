#include <stdio.h>
 
int main()
{
  int array[1000]={0};//배열의 크기는 1000으로 지정
  int i,j, n,s;//int형변수선언
  int temp;//int형변수선언
 
  scanf("%d %d",&n,&s);//데이터의개수와 스텝수를 입력받는다
  for(i=0;i<n;i++)//데이터의 개수만큼의 각 배열에 scanf로 데이터값을 받는다
   scanf("%d",&array[i]);
 
 
  for(i=0;i<s;i++)//스텝수만큼만 선택정렬이 일어난다
  {
   for(j=0;j<n;j++)//배열의 값은 하나하나 비교 해야하므로 0부터 n미만까지 돌린다
   {
    if(i<j && array[i]>array[j])//하지만 i<j라는 조건이 없으면 앞에 정렬된 것이 다시 정렬당할수 있으므로 이조건과 array[i]가 array[j]보다 클경우 두 배열값의 자리를 바꾸는 것이므로 둘 다 만족하는 경우에 if문을 이용한다
    {
     temp=array[i];
     array[i]=array[j];
     array[j]=temp;//temp를 이용해 임시값을 주고 두 배열의 자리를 바꿔야한다.
    }
   }
  }
 

  for(i=0;i<n;i++)///for문으로 데이터의개수만큼의 배열을 출력한다.
  {
   printf("%d ",array[i]);
  }
  printf("\n");
 

  return 0;
}
