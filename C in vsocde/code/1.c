#include <bits/stdc++.h>
#include <graphics.h>

typedef struct Node // ������������
{
	int a;
	struct Node *next;
} node;

int insert_node(node *head, int a, int i) // ��������aΪ�����ֵ��iΪ�����λ��
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
	if (i == 1) // �жϲ�����Ƿ��һ��
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

int delete_node_oder(node **head, int i) // ɾ��ָ��λ�õĽڵ�
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

int delete_node_number(node **head, int a) // ͨ��ɾ��ָ�����ݵĽڵ�
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

int change_value(node *head, int i, int new_value) // �ı��ض��ڵ��ֵ
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
	printf("�������ʼ������\n");
	scanf("%d", &n);
	while (n <= 0)
	{
		printf("��Ч����,����������\n");
		scanf("%d", &n);
	}

	printf("������ڵ�����\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (i == 0) // ����ͷ�ڵ�
		{
			head = (node *)malloc(sizeof(node));
			head->a = a;
			head->next = NULL;
			p1 = p2 = head;
		}
		else // ����һ��ڵ�
		{
			p1 = (node *)malloc(sizeof(node));
			p1->a = a;
			p1->next = NULL;
			p2->next = p1;
			p2 = p1;
		}
	}
	printf("�����ʼΪ��\n");
	for (p1 = head; p1->next != NULL; p1 = p1->next)
	{
		printf("%d ", p1->a);
	}
	printf("%d ", p1->a);
	system("cls");

	printf("��������:\n");
	for (p1 = head; p1->next != NULL; p1 = p1->next)
	{
		printf("%d ", p1->a);
	}
	printf("%d\n", p1->a);
	printf("������Ҫ\n1.����\n2.ɾ����ͨ��λ�ã�\n3.ɾ����ͨ�����ݣ�\n4.����"
		   "\n5.��ֵ\n6.�˳�\n");
	int opt = 0;
	scanf("%d", &opt);
	int i = 0;


	while (1)
	{

		switch (opt)
		{
		case 1:
			printf("����������\n"); // �������½ڵ�
			scanf("%d", &a);
			p2 = (node *)malloc(sizeof(node));
			p2->a = a;
			p2->next = NULL;
			p1->next = p2;
			break;

		case 2:
			printf("������ɾ����λ��\n");
			scanf("%d", &i);
			delete_node_oder(&head, i);
			break;

		case 3:
			printf("������Ҫɾ���ڵ������\n");
			scanf("%d", &a);
			delete_node_number(& head, a);
			break;

		case 4:
			printf("���������Ľڵ�����ݺ�λ��\n");
			scanf("%d%d", &a, &i);
			insert_node(head, a, i);
			break;

		case 5:
			printf("������Ҫ�ı�λ�ú�ֵ\n");
			scanf("%d %d", &i, &a);
			change_value(head, i, a);
			break;

		case 6:
			printf("ȷ���˳�? 1(yes) 2(no) \n");
			scanf("%d", &a);
			if (a == 1)
				return 0;
			else
				break;
		default:
			printf("�������,����������\n");
			system("pause");
			break;
		}
		system("cls"); // ����
		printf("��������:\n");
		for (p1 = head; p1->next != NULL; p1 = p1->next)
		{
			printf("%d ", p1->a);
		}
		printf("%d \n", p1->a);
		printf("������Ҫ\n1.����\n2.ɾ����ͨ��λ�ã�\n3.ɾ����ͨ�����ݣ�\n4.����"
			   "\n5.��ֵ\n6.�˳�\n");
		scanf("%d", &opt);
	}
	system("pause");
	return 0;
}