#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"assert.h"
#pragma warning(disable:6031)
#define MAX_SIZE 1000
//定义学生结构主体
struct student {
	int no=0;
	char name[10]=" ";
	double score[3] = {0.0};
	double avg=0.0;
	double sum=0.0;
	int tip = 0;
};
struct student stu[MAX_SIZE];

int flag = 0;
int count = 0;

void login();
void menu();
void input();
void display();
void ShowStuData(student stu);
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
		case 7:
			return 0;
		}
	}
	return 0;
}

void login() {
	char name[10] = { 0 }, pwd[10] = { 0 };
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
	//char answer;
	printf("\n\t单个学生信息的循环录入");
	int i;
	do {
		fflush(stdin);
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
				if (stu[count].name[i] >='0' && stu[count].name[i] <= '9') {
					printf("\n\t不好意思：名字不能含有数字，请重新输入\n");
					break;
				}
			}
		} while (i < strlen(stu[count].name));
		stu[count].sum = 0;
		for (int i = 0; i < 3; i++) {
			printf("\n\t成绩%d:", i + 1);
			scanf("%lf", &stu[count].score[i]);
			if (stu[count].score[i] < 0 || stu[count].score[i]>100) {
				printf("\n\t不好意思：成绩应为0到100之间的数字，请重新输入哦\n");
				i--;
				continue;
			}
			stu[count].sum += stu[count].score[i];
		}
		stu[count].avg = stu[count].sum / 3;
		stu[count].tip = 1;
		count++;
		printf("\n\t是否还进行录入？(y/n):");
		fflush(stdin);//getchar()不行？
		getchar();//fflush(stdin)不行？
	} while ((getchar())=='y');
}

void display() {
	int i;
	printf("\t学号\t姓名\t语文\t数学\t英语\t平均分\t总分\n");
	printf("\t__________________________________________________________\n");
	for (i = 0; i < count; i++) {
		printf("\t%d\t%s\t%.lf\t%.lf\t%.lf\t%.lf\t%.lf\n", stu[i].no, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].avg, stu[i].sum);
		printf("\t_______________________________________\n");
	}
}

void ShowStuData(student stu) {
	printf("\t学号\t姓名\t语文\t数学\t英语\t平均分\t总分\n");
	printf("\t%d\t%s\t%.lf\t%.lf\t%.lf\t%.lf\t%.lf\n", stu.no, stu.name, stu.score[0], stu.score[1], stu.score[2], stu.avg, stu.sum);
}
void sort()
{
	struct student temp;
	int i;
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
	newstu.sum = 0;
	for (int i = 0; i < 3; i++) {
		printf("\n\t成绩%d:", i + 1);
		scanf("%lf", &newstu.score[i]);
		if (newstu.score[i] < 0 || newstu.score[i]>100) {
			printf("\n\t不好意思：成绩应为0到100之间的数字，请重新输入哦\n");
			i--;
			continue;
		}
		newstu.sum += newstu.score[i];
	}
	newstu.avg = newstu.sum / 3;
	newstu.tip = 1;
	stu[count] = newstu;
	count++;
}


void remove() {
	int id, i,j,k;
	printf("删除学生的记录。\n");
	printf("请输入学号：");
	scanf("%d", &id);
	fflush(stdin);
	i = 0;
	do{
		if (stu[i].no == id) {
			printf("找到该生的记录，如下所示：\n");
			ShowStuData(stu[i]);
			printf("是否删除?(Y/N)\n");
			getchar();
			if ((getchar())=='Y') {
				for (j = i+1,k=i;j < count;j++,k++) {
					stu[k] = stu[j];
				}
				count--;
				break;
			}
			else;
		}
		i++;
	} while (i < count);
}



void search() {
	char name[10];
	int i, count = 0;
	printf("\n\t查找学生的记录。\n");
	printf("\n\t请输入学生的姓名：");
	scanf("%s", &name);
	for (i = 0;stu[i].tip != 0;i++) {
		count++;
	}
	for (i = 0;i < count;i++) {
		if (strcmp(name, stu[i].name) == 0) {
			printf("找到该生的记录，如下所示：\n");
			printf("该学生信息如下：\n");
			printf("\t\t───────────────────────────────────────────────────────────\n");
			printf("\t学号\t姓名\t语文\t数学\t英语\t平均\t总分\n");
			printf("\t%d\t%s\t%.lf\t%.lf\t%.lf\t%.lf\t%.lf\n", stu[i].no, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].avg, stu[i].sum);
			break;
		}
		else;
	}
	if (i == count) {
		printf("错误，未找到！\n");
	}
}


