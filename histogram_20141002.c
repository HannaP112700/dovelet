#include<stdio.h>
#include<string.h>

int main(){

	int i,j,length;
	char abc[26][100]={0};//출력할 배열
	char ch;//버퍼를 저장/

	for(i=0;i<4;i++){//4줄입력
	
	while((ch = getchar())!='\n')//한글자씩 입력받으면서 줄바꿈이 아닐경우
	{
		switch(ch){
			case 'A': strcat(abc[0],"*"); break;
			case 'B': strcat(abc[1],"*"); break;
			case 'C': strcat(abc[2],"*"); break;
			case 'D': strcat(abc[3],"*"); break;
			case 'E': strcat(abc[4],"*"); break;
			case 'F': strcat(abc[5],"*"); break;
			case 'G': strcat(abc[6],"*"); break;
			case 'H': strcat(abc[7],"*"); break;
			case 'I': strcat(abc[8],"*"); break;
			case 'J': strcat(abc[9],"*"); break;
			case 'K': strcat(abc[10],"*"); break;
			case 'L': strcat(abc[11],"*"); break;
			case 'M': strcat(abc[12],"*"); break;
			case 'N': strcat(abc[13],"*"); break;
			case 'O': strcat(abc[14],"*"); break;
			case 'P': strcat(abc[15],"*"); break;
			case 'Q': strcat(abc[16],"*"); break;
			case 'R': strcat(abc[17],"*"); break;
			case 'S': strcat(abc[18],"*"); break;
			case 'T': strcat(abc[19],"*"); break;
			case 'U': strcat(abc[20],"*"); break;
			case 'V': strcat(abc[21],"*"); break;
			case 'W': strcat(abc[22],"*"); break;
			case 'X': strcat(abc[23],"*"); break;
			case 'Y': strcat(abc[24],"*"); break;
			case 'Z': strcat(abc[25],"*"); break;//STRCAT으로 *을 추가
			default: break;

		}
	}
	}
	length=strlen(abc[0]);
	for(i=0;i<26;i++){
		
			if(length<strlen(abc[i]))
				length=strlen(abc[i]);
			else{}
			
	}//가장 긴 길이를 구한다


	for(i=length-1;i>=0;i--){//저장한 배열을 회전시켜 출력
		for(j=0;j<26;j++){

			if(abc[j][i]==0){
				printf("  ");
			}

			else{
			printf("%c ",abc[j][i]);
			}
		}
		printf("\n");
	}
	for(i=65;i<91;i++)
	{
		printf("%c ", i);
	}//아스키코드로 알파벳 출력


	return 0;
}
