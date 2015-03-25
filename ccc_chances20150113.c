#include<stdio.h>

int main(){

	int t, g, sa, sb;
	int i, j,k,l,first=1;
	int Aa[100], Ab[100], Asa[100], Asb[100];
	int count[4][4] = { 0 };
	int score[4] = { 0 };
	int sum = 0;
	int temp = 0;
	int counter = 0;
	
	int total[1000][4] = { 0 };
	int cal = 0;
	
	scanf("%d", &t);
	scanf("%d", &g);

	for (i = 0; i < g; i++){

		scanf("%d %d %d %d",
			&Aa[i], &Ab[i], &Asa[i], &Asb[i]);
		if (Asa[i]>Asb[i]){ 
			score[Aa[i] - 1] = score[Aa[i] - 1]+3; }
		else if (Asa[i] == Asb[i]){
			score[Aa[i] - 1] = score[Aa[i] - 1]+1;
			score[Ab[i] - 1] = score[Ab[i] - 1]+1;
		}
		else if (Asa[i]<Asb[i]){ 
			score[Ab[i] - 1] = score[Ab[i] - 1]+3;
		}
		else{}

		count[Aa[i] - 1][Ab[i] - 1] = 1;

		
	} //이미 치뤄진 경기 스코어
	
	sum = 6 - g;
	temp = 1;
	for (i = 0; i < sum; i++)
		temp = temp * 3;

	l = temp / 3;
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			if (i < j && count[i][j]==0){
				cal = 0;
				while (cal<=temp){
					if ((cal/l)%3==0){
						total[cal][i] = total[cal][i]+3;
						cal++;
					}
					else if ((cal / l) % 3 == 1)
					{
						total[cal][i] = total[cal][i]+1;
						total[cal][j] = total[cal][j]+1;
						cal++;
					}
					else{
						total[cal][j] = total[cal][j] + 3;
						cal++;
					}
				}

				l = l / 3;
					
			
			}
		}
	}
	
	//치뤄지지 않은 경기의 경우의 수를 모두 구함

	for (i = 0; i < temp; i++)
	{
		sum = 0;
		
			total[i][0] = score[0] + total[i][0];
			total[i][1] = score[1] + total[i][1];
			total[i][2] = score[2] + total[i][2];
			total[i][3] = score[3] + total[i][3];
		
			
			
			if (total[i][0] > total[i][1] && total[i][0] > total[i][2] && total[i][0] > total[i][3]){
				if (t == 1) counter++;
			}
			else if (total[i][1] > total[i][0] && total[i][1] > total[i][2] && total[i][1] > total[i][3]){
				if (t == 2) counter++;
			}
			else if (total[i][2] > total[i][0] && total[i][2] > total[i][1] && total[i][2] > total[i][3]){
				if (t == 3) counter++;
			}
			else if (total[i][3] > total[i][0] && total[i][3] > total[i][1] && total[i][3] > total[i][2]){
				if (t == 4) counter++;
			}
			else{  }

		
	}
	
		// 현재 스코어에 가상 경우의 수를 더한 뒤, 우리팀의 결과가 1등인 결과와 일치한다면 카운트를 증가시킨다.

		
	
	

	printf("%d\n", counter);

	
//우리팀이 1등이 될 경우의 수를 출력

	return 0;


}
