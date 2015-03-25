#include<stdio.h>
#include<stdlib.h>

typedef int BTData;

typedef struct _bTreeNode{	//트리노드 정의
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
}BTNode;

BTNode * MakeBTNode(void)	//동적할당으로 노드 생성
{
	BTNode * nd = (BTNode*)malloc(sizeof(BTNode));
	nd->left=NULL;
	nd->right=NULL;

	return nd;
}

void SetData(BTNode * bt, BTData data){//노드에 데이터 할당
	bt->data=data;
}

void MakeLeftSubTree(BTNode * main, BTNode * sub)//왼쪽 노드 연결
{
	if(main->left != NULL)
		free(main->left);
	main->left=sub;
}

void MakeRightSubTree(BTNode * main, BTNode * sub)//오른쪽 노드 연결
{
	if(main->right != NULL)
		free(main->right);
	main->right=sub;
}

typedef void VisitFuncPtr(BTData data); 


void PostorderTraverse(BTNode *bt, VisitFuncPtr action)//후위 순회 
{
	if(bt==NULL)
		return;

	PostorderTraverse(bt->left,action);

	PostorderTraverse(bt->right,action);

	action(bt->data);
}
void ShowIntData(int data)//출력
{
	if(data!=-1)
		printf("%d ", data);
}
////////////////////////////////////////메인등장/////////////////////////////////////


int main()
{
	int grandi,grandj,count=0,fulo=0;
	int i,j;
	int temp=-2;

	BTNode *arr[100][100];	//노드 포인터 배열 정의
	for(i=0;i<19;i++){
		for(j=0;j<19;j++){
			arr[i][j]=MakeBTNode();//노드를 생성해서 초기값을 -2로 준다
			SetData(arr[i][j],temp );
		}
	}

	scanf("%d",&temp);//첫번째 뿌리 노드
	SetData(arr[0][0], temp);//뿌리노드 데이터 삽입
	count++;//-1이 아닐때 
	grandi=0;
	grandj=0;

	for(i=1;i<19;i++){
		for(j=0;j<19;j++){

			if(arr[i][j]==arr[0][0] && arr[i][j]->left->data>-2)
			{
				i=1;	j=1;	//뿌리의 왼쪽 삽입이 모두 끝났을 경우 다시 0,0을 가르킬 경우 뿌리의 오른쪽을 가르키게한다
			}
			if(arr[i][j]->data>-2){
				if(arr[i][j]->data!=-1&& arr[i][j]->right == NULL)
					break;//data가 공백 상태가 아닐경우에서 데이터가 -1인 끝이 아니고 오른쪽이 비어있을 경우는 현재보다 레벨을 높혀 right로 가게 함 
				else 
					continue;//공백이 아닐경우 걸리지 않을 경우 계속
			}

			scanf("%d",&temp);// 뿌리 이외의 값 반복으로 입력

			if(temp==-1)//-1을 입력받을때
			{
				fulo++;//fulo 증가
			}
			else//자연수일때 
			{
				count++;//count 증가
			}

			SetData(arr[i][j],temp);//데이터를 노드에 저장

		
				if(grandi>=i)//부모 노드의 레벨 값이 나보다 크거나 같다면
				{
					grandi=i-1;//나보다 1 작게 
					grandj=0;//순서는 초기화

					while(arr[grandi][grandj]->data>-2)//부모의 데이터가 null이 아니라면
					{
						grandj++;//방을 증가시키고
					}
					grandj=grandj-1;//하나 더 증가되는 것을 -1해주고
				}
	if(j%2==0){//그 레벨의 몇번째 방인가를 확인하되 짝수일 경우 왼쪽노드 이므로
				MakeLeftSubTree(arr[grandi][grandj], arr[i][j]);//부모 노드와 나를 왼쪽노드로 연결
			}

			else{
				MakeRightSubTree(arr[grandi][grandj], arr[i][j]);//부모노드의 오른쪽에 나를 연결
			}
			if(arr[i][j]->data==-1)//마지막 자식노드일 경우
			{
				if(j%2 != 0)//오른쪽일 경우
				{

					if(fulo==count+1){break;}//-1의 개수와 숫자갯수+1이 같을 경우
						i=i-3;//3레벨을 올린다. 처음으로 돌아가면서 +1이 되므로
if(count>=10)i=i-1;//중간 이상 진행 되었을 경우 한 레벨을 더 올리고
						
						break;//for문 탈출
				}

			}

			else{
				grandi=i;//내가 -1이 아니고 저장해갈때 조상을 나로 지정
				grandj=j;
				break;//탈출
			}




		}
		if(fulo==count+1)//위에서 탈출 했을 때 -1갯수와 숫자 비교
				break;
	}

	PostorderTraverse(arr[0][0],ShowIntData);	//후위 방식 출력

	return 0;

}

/*
preorder 전위 : 전위 탐색은 root->left->right 순으로, root을 먼저 출력한 뒤 left로 계속 출력진행하며 더이상 불가능 시 right 출력하고 고 역순으로 출력되지 않은 부분에서 root->l->r 순으로 작게 쪼개 계속 출력하며 root의 왼쪽이 다 출력된 후 root의 오른쪽을 작은 트리로 보고 같은 방법으로 진행한다. 자손노드보다 루트를 가장 먼저 방문

inorder 중위 : 중위 탐색은 left->root->right 순으로, 왼쪽 서브트리 방문 후 루트 방문 후 오른쪽 방문한다.  

postorder 후위 : 후위 탐색은 left->right->root 순으로, 왼쪽 서브트리 방문 후 오른쪽 방문 후 루트를 방문한다. 트리를 작게 쪼개 본다. 일단 left를 연속 출력 후 더이상 없을 시 right쪽으로 이동하되 다시 left가 나타나면 left부터 다시 right 순으로 진행하며 마지막 남은 root를 출력.
*/
