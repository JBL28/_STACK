#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*2023-01-04 ����*/
/*���� �����غ���*/

#define MAX 100

typedef struct element {	//key���� ���ڿ��� �̷���� ������ ���.
	int key;
	char* data;
}Element;

typedef struct stack {		//element�� �̷���� ����
	element data[MAX];
	int top;
};

stack S;

void init() {				//������ �ʱ�ȭ�ϸ� ���ڿ��� �����Ҵ�.
	S.top = -1;
	for (int i = 0; i <= MAX - 1; i++)
		S.data[i].data = (char*)malloc(sizeof(char) * 40);
}

int is_empty() {			//������ ����ٸ� 1, �ƴ϶�� 0 ��ȯ.
	if (S.top == -1)
		return 1;
	else  return 0;
}

int is_full() {				//������ á�ٸ� 1, �ƴ϶�� 0 ��ȯ.
	if (S.top == MAX - 1)
		return 1;
	else return 0;
}

element pop() {				//pop����. ���� �ʰ� push�� ��Ҹ� ���ÿ��� ����� ��ȯ.
	if (is_empty() == 1) {
		printf("���� : ������ ����ֽ��ϴ�.\n\n");
		element temp;
		temp.data = (char*)malloc(sizeof(char) * 40);
		temp.key = -999;
		return temp;
	}
	return S.data[S.top--];
}

void push(element item) {	//push����. ���ÿ� �� ��� �߰�.
	if (is_full() == 1) {
		printf("���� : ������ ���� á���ϴ�.\n\n");
		return;
	}
	S.data[++S.top] = item;
}

element peak() {			//���ÿ� ���� �ʰ� �߰��� ��Ҹ� ��ȯ.
	if (is_empty() == 1) {
		printf("���� : ������ ����ֽ��ϴ�.\n\n");
		element temp;
		temp.data = (char*)malloc(sizeof(char) * 40);
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
	char str[40];
	element temp;
	while (1) {
		printf("�۾��� �������ּ���.\npush : 1, pop : 2, peak : 3, ���� : 4 : ");
		scanf("%d", &button);
		if (button == 1) {
			printf("Ű���� �Է����ּ���. : ");
			scanf("%d", &key);
			printf("�̸��� �Է����ּ���. : ");
			scanf("%s", &str);
			push({ key, str });
		}
		if (button == 2) {
			temp = pop();
			if (temp.key != -999)
				printf("pop�� ����� Ű �� : %d, �̸� : %s\n\n", temp.key, temp.data);
		}
		if (button == 3) {
			temp = peak();
			if (temp.key != -999)
				printf("peak�� ����� Ű �� : %d, �̸� : %s\n\n", temp.key, temp.data);
		}
		if (button == 4) {
			break;
		}
	}
	printf("���α׷��� �����մϴ�.");
	for (int i = 0; i <= MAX - 1; i++) {	//�����Ҵ� �� ��ҵ��� ���ڿ��� �����Ҵ� ����.
		free(S.data[i].data);
	}
	return 0;
}