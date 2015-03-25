#include <stdio.h>

int main()
{
	int a,b,c,ai,aj,ak,al,am,an;//변수선언
	for(a=10;a<=100000;a++)//10~99까지
	{

		if(10<=a &&a<100){

			ai=a/10; aj=a%10; b=aj*10+ai;//각자리수를 ai,aj에 대입한뒤 자리를 바꾼 b를 만들고
			c=a+b;//c는 원숫자와 뒤집은숫자의 합

			if(c<100){//c가 100미만이라면
				ai=c/10; aj=c%10;//마찬가지로 c의 각자리 숫자를 한 문자에 대입한 뒤 
				if(ai==aj)//만약 앞숫자와 뒷숫자가 같다면
					printf("%d\n",a);}//출력
			else{//100이상일경우
				ai=c/100; aj=(c%100)/10; ak=c%10;
				if(ai==ak)
					printf("%d\n",a);}
			}



		 else if(100<=a && a<1000){//100~999
			ai=a/100; aj=(a%100)/10; ak=a%10; b=ak*100+aj*10+ai;//ai~ak까지 생성
			c=a+b;

			if(c<1000){
				ai=c/100; aj=(c%100)/10; ak=c%10;
				if(ai==ak)
					printf("%d\n",a);}
			else{
				ai=c/1000; aj=(c%1000)/100; ak=(c%1000)%100/10; al=c%10;
				if(ai==al && aj==ak)
					printf("%d\n",a);
				else{}}
		}




		else if(1000<=a &&a<10000){
			ai=a/1000; aj=(a%1000)/100; ak=(a%1000)%100/10; al=a%10; b=al*1000+ak*100+aj*10+ai;//ai~al까지 생성
			c=a+b;

			if(c<10000){
				ai=c/1000; aj=(c%1000)/100; ak=(c%1000)%100/10; al=c%10;
				if(ai==al && aj==ak)
					printf("%d\n",a);}
			else{
				ai=c/10000; aj=(c%10000)/1000; ak=(c%10000)%1000/100; al=(c%10000)%1000%100/10; am=c%10;
				if(ai==am && aj==al)
					printf("%d\n",a);}
		}



		else if(10000<=a &&a<100000){//1000~9999까지
			ai=a/10000; aj=(a%10000)/1000; ak=(a%10000)%1000/100; al=(a%10000)%1000%100/10; am=a%10; b=am*10000+al*1000+ak*100+aj*10+ai;//ai~am까지 생성
			c=a+b;

			if(c<100000){
				ai=c/10000; aj=(c%10000)/1000; ak=(c%10000)%1000/100; al=(c%10000)%1000%100/10; am=c%10;
				if(ai==am && aj==al)
					printf("%d\n",a);}
			else{
				ai=c/100000; aj=(c%100000)/10000; ak=(c%100000)%10000/1000; al=(c%100000)%10000%1000/100; am=(c%100000)%10000%1000%100/10; an=c%10;
				if(ai==an && aj==am && ak==al)
					printf("%d\n",a);}
		}



		else//100000이하까지 출력완료 했고 100000만 남은 상태에서 100000은 적합하므로 출력
		{
			printf("%d\n",a);
		}



	}


	return 0;
}
