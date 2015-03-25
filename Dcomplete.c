#include <stdio.h>
int GetSum(int b, int c, int sum);// GetSum함수를 선언한다.
void main()
{
int a, b, c=1;//c에 초기값을 설정한뒤 선언한다.
int sum=0, sum2=0;//sum,sum2의 초기값을 설정해준뒤 선언한다.
scanf("%d",&a); 
if(1<=a && a<=10000) //10000이하의 자연수이여야 하므로 if문설정
{
b=2;
while(b <= a)//입력된 a까지의 자연수들이 완전수인지 검사해봐야 하므로 while문 후위증감연산자 사용
{
b++; 
sum2=GetSum(b,c,sum);//GetSum함수에서 받은 값을 sum2로 넘겨준다.
if(b==sum2)// b와 약수의 합인 sum2이 같다면 출력한다.
printf("%d\n",b);
}
}
}
int GetSum(int b, int c, int sum)
{
for(c=1; c <=b/2; c++)//b의 약수를 구할때,b의 약수에서 2를나눈값까지 포함해서 더하면 본인제외 모든 약수의 합이므로 조건식을c<=b/2로 설정,약수는b/2이하1부터후위증감연산자로 증가시킴.
{
if(b%c==0)//b는 b의 약수(=c)로 나누어지므로 if문을 사용해 맞다면
{
sum += c;//sum = sum + c로 약수를 모두더한다
}
}
return sum;//sum값을 리턴해서 main함수로 돌아간다
}


/*변수 명들이 전부 a, b, c <------ 이런식이면 나중에 코드 보기 힘들다..
 
의미 있는 변수명을 사용하는걸 추천한다..
 
그리고 코드 다시한번 잘 봐봐 불필요한 부분이 좀 보이는것 같네 코드 최적화 시켜보면 좋을것 같다.
*/
