#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//定义学生结构主体
struct student {
	int no;
	char name[10];
	double score[3];
	double avg;
	double sum;
};
struct student syu[3];

int flag = 0;

int count = 0;

void login();
void menu();
void input();
void display();
void sort();
void insert();
void remove();
void search();
void remove();
void search();

int main() {
	printf("\t\t\t┌ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ┐\n");
	printf("\t\t\t┆       学 生 管 理 系 统 平 台    ┆\n");
	printf("\t\t\t└ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ┘\n");
	printf("─────────────────────────────────\n");
	printf("【用户登录】\n\n");
	login();
	if (flag == 3) {

		printf("\n\t\t提示：你输入密码出错次数太多，请稍后再试一试！\n");
		printf("\n程序结束！\n");
		return 1;
	}
	int num;
	while (1) {
		menu();
		scanf("%d", &num);
		switch (num) {
		case 1:
			input();
			printf("\n");
			system("pause");
			break;
		case 2:
			printf("\n\n所有学生信息:\n");
			display();
			printf("\n");
			system("pause");
			break;
		case 3:
			sort();
			printf("\n\n<按照平均成绩>降序排列后的所有学生信息:\n");
			display();
			printf("\n");
			system("pause");
			break;
		case 4:
			insert();
			printf("\n\n插入新学员信息后的所有学生信息:\n");
			display();
			printf("\n");
			system("pause");
			break;
		case 5:
			remove();
			printf("\n\n以下是删后的结果:\n");
			display();
			printf("\n");
			system("pause");
			break;
		case 6:
			search();
			printf("\n");
			system("pause");
			break;
		}
	}
	return 1;
}

void login() {
	char name[10], pwd[10];
	do {
		printf("\t\t用户名：");
		scanf("%s", name);
		printf("\n\t\t密 码：");
		scanf("%s", pwd);
		if (strcmp(name, "admin") == 0 && strcmp(pwd, "admin") == 0) {
			break;
		}
		flag++;
		if (flag < 3) {
			printf("\n\t\to(╥﹏╥)o用户名或密码错误，请重新输入！\n\n");
		}
	} while (flag < 3);
}
void menu() {
	system("cls");
	printf("\t\t\t┌-----------------------------┐\n");
	printf("\t\t\t┆      学生管理系统平台      ┆\n");
	printf("\t\t\t└-----------------------------┘\n");

	printf("____________________________________________________________\n");
	printf("◎功能菜单：\n");
	printf("\t\t__________________________________\n");
	printf("\t\t\t欢迎使用学生管理系统\n");
	printf("\t\t__________________________________\n");
	printf("\t\t\t1:录入单个学生信息\n");
	printf("\t\t__________________________________\n");
	printf("\t\t\t2:显示所有学生信息\n");
	printf("\t\t__________________________________\n");
	printf("\t\t\t3:排序显示所有学生信息\n");
	printf("\t\t__________________________________\n");
	printf("\t\t\t4:插入单个学生信息\n");
	printf("\t\t__________________________________\n");
	printf("\t\t\t5:删除单个学生信息\n");
	printf("\t\t__________________________________\n");
	printf("\t\t\t6:查找单个学生信息\n");
	printf("\t\t__________________________________\n");
	printf("\t\t\t7:退出系统\n");
	printf("\t\t__________________________________\n");
	printf("请选择:");
}
void input() {
	char answer;
	printf("\n\t单个学生信息的循环录入");
	do {
		int i;
		do {
			printf("\n\t学号:");
			scanf("%d", &stu[count].no);
			for (i = 0; i < count; i++) {
				if (stu[i].no == stu[count].no) {
					printf("\n\t不好意思：学号重复，请重新输入\n");
					break;
				}
			}
		} while (i < count);
		do {
			printf("\n\t名字：");
			scanf("%s", &stu[count].name);
			for (i = 0; i < strlen(stu[count].name); i++) {
				if (stu[count].name[i] >= '0' && stu[count].name[i] <= '9') {
					printf("\n\t不好意思：名字不能含有数字，请重新输入\n");
					break;
				}
			}
		} while (i < strlen(stu[count].name));
		stu[count].sum = 0;
		for (int i = 0; i < 3; i++) {
			printf("\n\t成绩%d:", i + 1);
			scanf("%1f", &stu[count].score[i]);
			if (stu[count].score[i] < 0 || stu[count].score[i]>100) {
				printf("\n\t不好意思：成绩应为0到100之间的数字，请重新输入哦\n");
				i--;
				continue;
			}
			stu[count].sum += stu[count].score[i];
		}
		stu[count].avg = stu[count].sum / 3;
		count++;
		printf("\n\t是否还进行录入？(y/n):");
		fflush(stdin);
		scanf("%c", &answer);
	} while (answer == 'y' || answer == 'y');
}

void display() {
	int i;
	printf("\t学号\t姓名\t语文\t数学\t英语\t总分\t平均分\t排名\n");
	printf("\t__________________________________________________________\n");
	for (i = 0; i < count; i++) {
		printf("\t%d\t%s\t%.lf\t%.lf\t%.lf\t%.lf\t%.lf\n", stu[i].no, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].avg, stu[i].sum);
		printf("\t_______________________________________\n");
	}
}

void sort()
{
	struct student temp;
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (stu[j].avg < stu[j + 1].avg)
			{
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}
}

void insert()
{
	struct student newstu;
	int i;
	printf("\n\t新学生的信息录入：\n");

	do
	{
		printf("\n\t学号：");
		scanf("%d", &newstu.no);
		for (i = 0; i < count; i++)
		{
			if (stu[i].no == newstu.no)
			{
				printf("\n\t不好意思：学号重复，请重新输入\n");
				break;
			}
		}
	} while (i < count);
	do
	{
		printf("\n\t姓名：");
		scanf("%s", &newstu.name);
		for (i = 0; i < strlen(newstu.name); i++)
		{
			if (newstu.name[i] >= '0' && newstu.name[i] <= '9')
			{
				printf("\n\t不好意思：姓名不能含有数字，请重新输入\n");
				break;
			}
		}
	} while (i < strlen(newstu.name));
}


void remove() {
	int id, i;
	char ch;
	printf("删除学生的记录。\n");
	printf("请输入学号：");
	scanf("%d", &id);

	struct Node* current = *headRef;
	struct Node* prev = NULL;

	// 待删除的记录是头节点
	if (current != NULL && current->stu.id == id) {
		getchar();
		printf("找到该生的记录，如下所示：\n");
		HH;  //显示记录的标题
		ShowStuData(&current->stu);
		printf("是否删除?(Y/N)\n");
		scanf("%c", &ch);
		if (ch == 'Y' || ch == 'y') {
			*headRef = current->next;
			free(current);
			printf("删除成功！\n");

			// 添加，修改，删除后都应该重新排序

			return;
		}
	}

	while (current != NULL && current->stu.id != id) {
		prev = current;
		current = current->next;
	}

	if (current == NULL) {
		printf("没有找到该生的记录。\n");
		return;
	}

	getchar();
	printf("找到该生的记录，如下所示：\n");
	HH;  //显示记录的标题

	printf("是否删除?(Y/N)\n");
	scanf("%c", &ch);
	if (ch == 'Y' || ch == 'y') {
		prev->next = current->next;
		free(current);
		printf("删除成功！\n");
	}
	return;

}



void search() {
	int no;
	printf("\n\t查找学生的记录。\n");
	printf("\n\t请输入学生的姓名：");
	scanf("%s", &no);

	if (bsearch == 0) {
		no = 1;
		printf("找到该生的记录，如下所示：\n");
		printf("该学生信息如下：\n");
		printf("\t\t───────────────────────────────────────────────────────────\n");
		printf("\t\t学号：\t");
		printf("姓名：\t");
		printf("语文： ");
		printf("数学： ");
		printf("英语： ");
		printf("总分： ");
		printf("平均分： \n");
		printf("\t\t───────────────────────────────────────────────────────────\n");
		printf("\t\t%d\t%s\t%.lf\t%.lf\t%.lf\t%.lf\t%.lf\n", stu[i].no, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum, stu[i].avg);
		system("pause");
		break;
		bsearch = 1;
	}

}

	}

	if (bsearch == 0) {
		printf("没有找到该生的记录。\n");
	}
	else {
		printf("** 有 %d 条名叫： %s 的学生记录。\n", cnt, no);
		break;
	}

	printf("程序结束！\n");
	return 0;
}


