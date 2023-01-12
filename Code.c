#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*스택 구현해보기*/

typedef struct element {	//key값과 문자열로 이루어진 스택의 요소.
    int key;
}Element;

typedef struct stack {		//element로 이루어진 스택
    element *data;
    int size;
    int top;
};

stack S;

void init() {				//스택을 초기화
    S.top = -1;
    S.size = 5;
    S.data = (element*)malloc(sizeof(element) * S.size);
}

int is_empty() {			//스택이 비었다면 1, 아니라면 0 반환.
    if (S.top == -1)
        return 1;
    else  return 0;
}

int is_full() {				//스택이 찼다면 1, 아니라면 0 반환.
    if (S.top == S.size - 1)
        return 1;
    else return 0;
}

element pop() {				//pop연산. 가장 늦게 push된 요소를 스택에서 지우며 반환.
    if (is_empty() == 1) {
        printf("에러 : 스택이 비어있습니다.\n\n");
        element temp;
        temp.key = -999;
        return temp;
    }
    return S.data[S.top--];
}

void push(element item) {	//push연산. 스택에 새 요소 추가.
    if (is_full() == 1) {
        S.size = S.size * 2;
        S.data = (element*)realloc(S.data, sizeof(element) * S.size);
    }
    S.data[++S.top] = item;
}

element peak() {			//스택에 가장 늦게 추가된 요소를 반환.
    if (is_empty() == 1) {
        printf("에러 : 스택이 비어있습니다.\n\n");
        element temp;
        temp.key = -999;
        return temp;
    }
    return S.data[S.top];
}

int search(int item) {      //스택 요소 키를 매개변수로 받아 해당 요소의 인덱스 반환
    for (int i = 0; i <= S.top ; i++) {
        if (S.data[i].key == item)
            return i;
    }
    return -1;
}

int main(void)
{
    init();
    int button = 0;
    int key;
    element temp;
    while (1) {
        printf("\n작업을 선택해주세요.\npush : 1, pop : 2, peak : 3, 검색 : 4 종료 : 5 : ");
        scanf("%d", &button);
        if (button == 1) {
            printf("키값을 입력해주세요. : ");
            scanf("%d", &temp.key);
            push(temp);
        }
        else if (button == 2) {
            temp = pop();
            if (temp.key != -999)
                printf("\npop된 요소의 키 값 : %d\n\n", temp.key);
        }
        else if (button == 3) {
            temp = peak();
            if (temp.key != -999)
                printf("\npeak된 요소의 키 값 : %d\n\n", temp.key);
        }
        else if (button == 4) {
            printf("검색할 데이터의 키 값을 입력해주세요. :");
            scanf("%d", &key);
            if (search(key) != -1)
                printf("\n해당 키 값을 갖는 요소는 %d번 째 인덱스에 위치합니다.\n\n", search(key));
            else
                printf("\n스택 내에 존재하지 않는 키 값입니다.\n\n");
        }
        if (button == 5) {
            break;
        }
    }
    printf("\n프로그램을 종료합니다.");
    free(S.data);
    return 0;
}
