#include<stdio.h>
int main()
{
 int n,i,j,count;//변수선언
 long long int num[100];//배열은 int형으로 하니 넘쳐서 long long int형으로 선언
 long long int sel1[100];
 long long int sel2[100];

 scanf("%d", &n);//n개입력받음
 for(i=1;i<=n;i++)//for문으로
 {
  scanf("%d", &num[i]);//num을 입력받아 배열에 저장
  j=num[i];//입력받은 값을 j에 저장
  sel1[j]=1;//sel1값에 j를 대입해 1로 저장
 }
 while(1)//무한루프
 {
 start://goto문을 받는다
 for(i=1;i<=n;i++)
  {
   sel2[i]=sel1[i];//비교가 필요하므로 sel1에 입력받은 값을 sel2에저장한뒤
   sel1[i]=0;//sel1을 0으로해준다
  }
  for(i=1;i<=n;i++)
  {
   if(sel2[i]==1)//sel1에서받은 sel2의 값이 1인 배열이있다면
   {
    j=num[i];//위와 마찬가지로 num값을 넘겨받아
    sel1[j]=1;//sel1에 넣어 준뒤 1을 대입
   }
  }
  for(i=1;i<=n;i++)
  {
   if(sel1[i]!=sel2[i])//만약 sel1과 sel2가 다르다면 아직 해결된 것이 아니므로
   {
    goto start;//start의 위치로 돌아간다
   }
  }

  break;//다른게 없다면 내려와 break로 while을 나간다
 }

 count=0;//count 초기화
 for(i=1;i<=n;i++)
 {
  if(sel1[i]==1 && sel2[i]==1) //sel1,sel2가 1인경우 
  {
   count++;//count증가
  }
 }
 printf("%d\n", count);//출력
 for(i=1;i<=n;i++)
 {
  if(sel1[i]==1 && sel2[i]==1) //sel1,sel2가 1인경우 
  {
   printf("%d\n", i);//i값이 1부터 시작하므로 순서가 같으므로 i를 출력하면 몇번째의 값인지 알수 있다
  }
 }
 return 0;
}

/*이거 goto문 썼네...
goto문 쓰지마라 C언어는 절차지향언어이라서 절차대로 흘러가야 하는데 저걸 써버리면 왔다갔다거리면서 소스가 꼬여버린다
안 좋은 버릇 중 하나니까 절대 쓰면 안 된다*/
