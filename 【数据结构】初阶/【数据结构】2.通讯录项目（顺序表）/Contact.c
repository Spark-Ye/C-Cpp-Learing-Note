#include "SeqList.h"

// 通讯录的初始化和销毁
//SL* ps
void ContactInit(Contact* pcon)// 实际初始化的还是顺序表
{
	SLInit(pcon);
}
void ContactDestroy(Contact* pcon)
{
	SLDestroy(pcon);
}

int FindByName(Contact* pcon, char name[])
{
	for (int i = 0; i < pcon->size; i++)
	{
		if (strcmp(pcon->arr[i].name, name) == 0)
		{
			// 找到了
			return i;
		}
	}
	return -1;
}

// 增加、删除、修改、查找、查看通讯录
void ContactAdd(Contact* pcon)
{
	// 创建联系人结构体变量
	Info info;

	printf("请输入联系人姓名：\n");
	scanf("%s", info.name);
	printf("请输入联系人年龄：\n");
	scanf("%d", &info.age);
	printf("请输入联系人性别：\n");
	scanf("%s", info.gender);
	printf("请输入联系人电话：\n");
	scanf("%s", info.tel);
	printf("请输入联系人住址：\n");
	scanf("%s", info.addr);

	// 保存数据到通讯录（顺序表）
	SLPushBack(pcon, info);

}
void ContactDel(Contact* pcon)
{
	// 删除之前一定要先查找
	// 找到了，可以删除
	// 找不到，不能执行删除
	printf("请输入要删除的联系人姓名：\n");
	char name[NAME_MAX];
	scanf("%s", name);

	int findIndex = FindByName(pcon, name);
	if (findIndex < 0)
	{
		printf("要删除的联系人不存在！\n");
		return;
	}
	// 执行删除操作
	SLErase(pcon, findIndex);
	printf("联系人删除成功！\n");
}
void ContactModify(Contact* pcon)
{
	// 修改之前要先查找
	// 找到了，执行修改操作
	// 没有找到，不能执行修改操作

	char name[NAME_MAX];
	printf("请输入要修改的联系人姓名：\n");
	scanf("%s", name);

	int findIndex = FindByName(pcon, name);
	if (findIndex < 0)
	{
		printf("要修改的联系人不存在！\n");
		return;
	}
	// 找到了，执行修改操作
	//int arr[10]     int arr[findIndex] = 100
	printf("请输入姓名：\n");
	scanf("%s", pcon->arr[findIndex].name);
	printf("请输入年龄：\n");
	scanf("%d", &pcon->arr[findIndex].age);
	printf("请输入性别；\n");
	scanf("%s", pcon->arr[findIndex].gender);
	printf("请输入电话；\n");
	scanf("%s", pcon->arr[findIndex].tel);
	printf("请输入地址；\n");
	scanf("%s", pcon->arr[findIndex].addr);

	printf("联系人修改成功！\n");
}
void ContactFind(Contact* pcon)
{
	char name[NAME_MAX];
	printf("请输入要查找的用户姓名：\n");
	scanf("%s", name);

	int findIndex = FindByName(pcon, name);
	if (findIndex < 0)
	{
		printf("该联系人不存在！\n");
		return;
	}
	// 找到了，打印下查找的联系人信息
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "住址");
	printf("%s %s %d %s %s\n",
		pcon->arr[findIndex].name,
		pcon->arr[findIndex].gender,
		pcon->arr[findIndex].age,
		pcon->arr[findIndex].tel,
		pcon->arr[findIndex].addr);
}
// 查看通讯录
void ContactShow(Contact* pcon)
{
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "住址");
	for (int i = 0; i < pcon->size; i++)
	{
		printf("%s %s %d %s %s\n",
			pcon->arr[i].name,
			pcon->arr[i].gender,
			pcon->arr[i].age,
			pcon->arr[i].tel,
			pcon->arr[i].addr
		);
	}
}


