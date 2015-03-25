#include <stdio.h>
#include <stdlib.h>//동적할당을 사용하기위해 선언
main()
{
      int i,j, a, b; //int형 변수 선언
long long **arr;//long long형 이중포인터선언

      scanf("%d", &a);//행을 입력받음
      arr = (long long**)malloc(sizeof(long long)*a);//동적할당

      scanf("%d", &b);//열을 입력받음
      for(i=0; i<a; i++)
            arr[i] = (long long*)malloc(sizeof(long long)*b);//동적할당
 

 for(i=0;i<a;i++)//열이 0인 배열의 값에 1을 넣는다
  arr[i][0]=1;

 for(j=0;j<b;j++)//행이 0인 배열의 값에 1을 넣는다
  arr[0][j]=1;

 for(i=1;i<a;i++)
 {
  for(j=1;j<b;j++)
  {
   arr[i][j]=arr[i][j-1]+arr[i-1][j];//배열에 행 -1, 열 -1 배열에서 더한 값을 대입
  }
 }

 for(a=0;a<i;a++)
 {
  for(b=0;b<j;b++)
  {
   printf("%lld ",arr[a][b]);//배열 출력
   
  }printf("\n");
 }
 for(i=0; i<a; i++)
            free(arr[i]); //동적할당 메모리 해제
     free(arr); 
 

 return 0;
}
