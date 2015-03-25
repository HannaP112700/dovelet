
I-Keeper 코딩 문제 정답제출
글 수 552

    설정
    관리
    회원 정보 보기
    로그아웃
    Skin Info
    Tag list
    List
    Webzine
    Gallery

[03/26] tw 박한나
박한나
http://www.ikeeper.or.kr/index.php?document_srl=194233
2015.03.26 01:49:40 (119.212.21.222)
0
0
재학1


#include <stdio.h>
#include <stdlib.h>
#define TRUE    1
#define FALSE    0

typedef int Data;
Data data,data2;

typedef struct _node
{
    Data data,data2;
    struct _node * next;
} Node;

typedef struct _listStack
{
    Node * head;
} ListStack;


typedef ListStack Stack;

void StackInit(Stack * pstack)
{
    pstack->head = NULL;
}

int SIsEmpty(Stack * pstack)
{
    if(pstack->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack * pstack, Data data, Data data2)
{
    Node * newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->data2 = data2;
    newNode->next = pstack->head;

    pstack->head = newNode;
}

Data SPop(Stack * pstack)
{
    Data rdata;
    Node * rnode;

    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }

    rdata = pstack->head->data;
    rnode = pstack->head;

    pstack->head = pstack->head->next;
    free(rnode);

    return rdata;
}
Data SPop2(Stack * pstack)
{
    Data rdata2;
    Node * rnode;

    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }

    rdata2 = pstack->head->data2;
    rnode = pstack->head;

    pstack->head = pstack->head->next;
    free(rnode);

    return rdata2;
}
Data SPeek(Stack * pstack)
{
    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }

    return pstack->head->data;
}
Data SPeek2(Stack * pstack)
{
    if(SIsEmpty(pstack)) {
        return 0;
    }

    return pstack->head->data2;
}


//stack
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    Stack stack;
    StackInit(&stack);

    data2=1;

    int N,i;

    scanf("%d",&N);

    scanf("%d",&data);
    printf("%d ",SPeek2(&stack));
    SPush(&stack, data, data2++);//스택에 탑의 높이와 순서번호를 함께 저장
//첫번째 탑의 경우 어차피 앞에서 수신 가능한 탑이 없으므로 따로 빼준다
    for(i=1;i<N;i++){
    
        scanf("%d",&data);//높이 입력
       
        if(SPeek(&stack)>data){//앞의 탑이 자신보다 높이가 높다면 넣는다
            printf("%d ",SPeek2(&stack));
            SPush(&stack, data, data2++);
       
            }
        else{//앞의 탑이 자신보다 작다면 큰 것을 만날때 까지 빼준다
            while(SPeek(&stack)<=data){
               
               
             
                SPop(&stack);
                if(SIsEmpty(&stack)){break;}//만약 전체가 비었다면 멈춘다.
           
             }
             printf("%d ",SPeek2(&stack));
            SPush(&stack, data, data2++);//빼준 후 삽입
        
            }
    }
   
   
    while(!SIsEmpty(&stack))
       SPop(&stack);
       

    return 0;
}



