#include <stdio.h>
#include <stdlib.h>

/*2023-01-04 정복*/
/*스택 구현해보기*/

#define MAX 100

typedef struct element {	//key값과 문자열로 이루어진 스택의 요소.
	int key;
}Element;

typedef struct stack {		//element로 이루어진 스택
	element data[MAX];
	int top;
};

stack S;

void init() {				//스택을 초기화
	S.top = -1;
}

int is_empty() {			//스택이 비었다면 1, 아니라면 0 반환.
	if (S.top == -1)
		return 1;
	else  return 0;
}

int is_full() {				//스택이 찼다면 1, 아니라면 0 반환.
	if (S.top == MAX - 1)
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
		printf("에러 : 스택이 가득 찼습니다.\n\n");
		return;
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

int main(void)
{
	init();
	int button = 0;
	int key;
	element temp;
	while (1) {
		printf("작업을 선택해주세요.\npush : 1, pop : 2, peak : 3, 종료 : 4 : ");
		scanf("%d", &button);
		if (button == 1) {
			printf("키값을 입력해주세요. : ");
			scanf("%d", &temp.key);
			push(temp);
		}
		if (button == 2) {
			temp = pop();
			if (temp.key != -999)
				printf("pop된 요소의 키 값 : %d\n\n", temp.key);
		}
		if (button == 3) {
			temp = peak();
			if (temp.key != -999)
				printf("peak된 요소의 키 값 : %d\n\n", temp.key);
		}
		if (button == 4) {
			break;
		}
	}
	printf("프로그램을 종료합니다.");
	return 0;
}
