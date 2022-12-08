#include <bits/stdc++.h>
#include <graphics.h>

typedef struct Node // 建立链表类型
{
	int a;
	struct Node *next;
} node;

int insert_node(node *head, int a, int i) // 插入链表，a为插入的值，i为插入的位置
{
	node *p1, *p2;
	p1 = p2 = head;
	int j = 1;
	while (p1->next && j < i - 1)
	{
		p1 = p1->next;
		j++;
	}
	if (!p1->next || j > i)
	{
		printf("insert error");
		system("pause");
		return 0;
	}
	if (i == 1) // 判断插入点是否第一个
	{
		p1 = (node *)malloc(sizeof(node));
		p1->a = a;
		p1->next = p2;
		head = p1;
		printf("insert ok");
		system("pause");
		return 1;
	}
	else
	{
		p2 = (node *)malloc(sizeof(node));
		p2->a = a;
		p2->next = p1->next;
		p1->next = p2;
		printf("insert ok");
		system("pause");
		return 1;
	}
}

int delete_node_oder(node **head, int i) // 删除指定位置的节点
{
	if (i <= 0)
	{
		printf("invalid");
		return 0;
	}
	node *p1, *p2;
	p1 = p2 = *head;
	if (head == NULL)
	{
		printf("empty");
		return 0;
	}
	int j = 1;
	if (i == 1)
	{
		*head = p1->next;
		free(p1);
		printf("delete ok");
		return 1;
	}
	else
	{
		while (!p1->next && j < i - 1)
		{
			p1 = p1->next;
			j++;
			if (p1->next == NULL)
			{
				printf("delete error");
				system("pause");
				return 0;
			}
		}
		if (!p1->next || j > i - 1)
		{
			printf("delete error");
			system("pause");
			return 0;
		}
		p2 = p1;
		p1 = p1->next;
		if (p1->next != NULL)
		{
			p2->next = p1->next;
			free(p1);
		}
		else
		{
			free(p1);
			p2->next = NULL;
		}
	}
	printf("delete ok");
	system("pause");
	return 1;
}

int delete_node_number(node **head, int a) // 通过删除指定数据的节点
{
	node *p1, *p2;
	p1 = p2 = *head;
	if (head == NULL)
	{
		printf("empty");
		return 0;
	}
	if ((*head)->a == a)
	{
		*head = (*head)->next;
		free(p1);
	}
	while (p1->next != NULL && p1->a != a)
	{
		p1 = p1->next;
		if (p1->next == NULL && p1->a == a)
		{
			break;
		}
		if (p1->next == NULL && p1->a != a)
		{
			printf("delete error");
			system("pause");
			return 0;
		}
	}
	if (p1->next == NULL && p1->a != a)
	{
		printf("delete error");
		system("pause");
		return 0;
	}
	else
	{
		while (p2->next != p1)
			p2 = p2->next;
		p2->next = p1->next;
		free(p1);
	}
	printf("delete ok");
	system("pause");
	return 1;
}

int change_value(node *head, int i, int new_value) // 改变特定节点的值
{
	node *p1, *p2;
	p1 = p2 = head;
	int j = 1;
	while (p1->next && j < i)
	{
		p1 = p1->next;
		j++;
	}
	if (!p1->next || j > i)
	{
		printf("change error");
		system("pause");
		return 0;
	}
	p1->a = new_value;
	printf("change ok");
	system("pause");
	return 1;
}

int main()
{
	node *head, *p1, *p2;
	int n = 0;
	int a;
	printf("请输入初始链表长度\n");
	scanf("%d", &n);
	while (n <= 0)
	{
		printf("无效数据,请重新输入\n");
		scanf("%d", &n);
	}

	printf("请输入节点数据\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (i == 0) // 创建头节点
		{
			head = (node *)malloc(sizeof(node));
			head->a = a;
			head->next = NULL;
			p1 = p2 = head;
		}
		else // 创建一般节点
		{
			p1 = (node *)malloc(sizeof(node));
			p1->a = a;
			p1->next = NULL;
			p2->next = p1;
			p2 = p1;
		}
	}
	printf("链表初始为：\n");
	for (p1 = head; p1->next != NULL; p1 = p1->next)
	{
		printf("%d ", p1->a);
	}
	printf("%d ", p1->a);
	system("cls");

	printf("现有数据:\n");
	for (p1 = head; p1->next != NULL; p1 = p1->next)
	{
		printf("%d ", p1->a);
	}
	printf("%d\n", p1->a);
	printf("接下来要\n1.创建\n2.删除（通过位置）\n3.删除（通过数据）\n4.插入"
		   "\n5.改值\n6.退出\n");
	int opt = 0;
	scanf("%d", &opt);
	int i = 0;


	while (1)
	{

		switch (opt)
		{
		case 1:
			printf("请输入数据\n"); // 创建的新节点
			scanf("%d", &a);
			p2 = (node *)malloc(sizeof(node));
			p2->a = a;
			p2->next = NULL;
			p1->next = p2;
			break;

		case 2:
			printf("请输入删除的位置\n");
			scanf("%d", &i);
			delete_node_oder(&head, i);
			break;

		case 3:
			printf("请输入要删除节点的数据\n");
			scanf("%d", &a);
			delete_node_number(& head, a);
			break;

		case 4:
			printf("请输入插入的节点的数据和位置\n");
			scanf("%d%d", &a, &i);
			insert_node(head, a, i);
			break;

		case 5:
			printf("请输入要改变位置和值\n");
			scanf("%d %d", &i, &a);
			change_value(head, i, a);
			break;

		case 6:
			printf("确认退出? 1(yes) 2(no) \n");
			scanf("%d", &a);
			if (a == 1)
				return 0;
			else
				break;
		default:
			printf("输入错误,请重新输入\n");
			system("pause");
			break;
		}
		system("cls"); // 清屏
		printf("现有数据:\n");
		for (p1 = head; p1->next != NULL; p1 = p1->next)
		{
			printf("%d ", p1->a);
		}
		printf("%d \n", p1->a);
		printf("接下来要\n1.创建\n2.删除（通过位置）\n3.删除（通过数据）\n4.插入"
			   "\n5.改值\n6.退出\n");
		scanf("%d", &opt);
	}
	system("pause");
	return 0;
}