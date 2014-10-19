#include<stdio.h>
#include <stdlib.h>
#include<string.h>

struct node                          /*定义节点结构体*/
{    
     char  stuName[10];              /*数据域中的学生姓名*/
     int    Age ;                    /*数据域中的学生年龄*/
     struct  node  *next;            /*指针域*/
 };

int i,j;                             /*循环中的计数器*/
int	Length=0,length_1,length_2;      /*链表的长度*/
int Age[100],age_1[100],age_2[100];  /*存放年龄数据的一维数组*/
int age;                             /*排序中用来暂存年龄的变量*/
char Name[100][10],name_1[100][10],name_2[100][10];/*存放姓名数据的二维数组*/
char name[100][10];                  /*排序中用来暂存姓名的二维数组*/
struct node *phead,*phead2,*p,*q,*p1,*p2,*L1,*L2,*L3;/*指向节点结构体的指针*/
           

void init( )               /*初始化函数，用于录入数据及排序*/
{
    printf("请输入第一个链表中学生的个数：\n");
	scanf("%d",&length_1);
	printf("请输入第一个链表中学生的姓名与年龄(空格分开)：\n");
	for(i=0;i<length_1;i++)
	{
		scanf("%s %d",&name_1[i], &age_1[i]);
		getchar();
	};
	
	for(i=0;i<length_1;i++)
	{
		for(j=i+1;j<length_1;j++)
		{
		    if(age_1[i]>age_1[j])
		    {
		        age=age_1[i];
			    age_1[i]=age_1[j];
			    age_1[j]=age;
		 	    strcpy(name[i],name_1[i]);
			    strcpy(name_1[i],name_1[j]);
			    strcpy(name_1[j],name[i]);
		    }
		}
	}
	
    printf("请输入第二个链表中学生的个数：\n");
	scanf("%d",&length_2);
	printf("请输入第二个链表中学生的姓名与年龄（空格分开）：\n");
	for(j=0;j<length_2;j++)
	{
		scanf("%s %d",&name_2[j],&age_2[j]);
		getchar();
	};
	
	for(i=0;i<length_2;i++)
	{
		for(j=i+1;j<length_2;j++)
		{
		    if(age_2[i]>age_2[j])
		    {
		        age=age_2[i];
			    age_2[i]=age_2[j];
			    age_2[j]=age;
			    strcpy(name[i],name_2[i]);
			    strcpy(name_2[i],name_2[j]);
			    strcpy(name_2[j],name[i]);
		    }
		}

	}
}

void create1( )                         /*创建第一个链表*/
{
	struct node *phead=(struct node *)malloc(sizeof(struct node));
	phead->next=NULL;

	for(i=length_1-1;i>=0;i--)
	{
	    struct node *p=(struct node *)malloc(sizeof(struct node));
        p->Age=age_1[i];
		strcpy(p->stuName,name_1[i]);
		p->next=phead;
		phead=p;
	}
	p1=phead;

	printf("第一个链表合并前信息：\n");
	for(i=0;i<length_1;i++)
	{
	    if (phead->Age>0)	
		printf("student\t%s\tage\t%d\n",phead->stuName,phead->Age);
	    phead=phead->next;
	}	    
}



void create2( )                    /*创建第二个链表*/
{
	struct node *phead2=(struct node *)malloc(sizeof(struct node));
	phead2->next=NULL;

	for(j=length_2-1;j>=0;j--)
	{
	    struct node *p2=(struct node *)malloc(sizeof(struct node));
     	p2->Age=age_2[j];
		strcpy(p2->stuName,name_2[j]);
		p2->next=phead2;
		phead2=p2;
	}

	p2=phead2;

	printf("第二个链表合并前信息：\n");
	for(j=0;j<length_2;j++)
	{
	    if (phead2->Age>0)
		printf("student\t%s\tage\t%d\n",phead2->stuName,phead2->Age);
	    phead2=phead2->next;
	}
}

 void combine( )                  /*合并链表*/
{
     int flag=0;   
	 L1=p1;
     L2=p2;
       
	 q=(struct node *)malloc(sizeof(struct node));
	 q->next=NULL;
	 while (L1&&L2)
	 {
		 p=(struct node *)malloc(sizeof(struct node));
	     if (L2->Age>L1->Age) flag=1;
		 if (L2->Age<L1->Age) flag=2;
		 if (L1->Age==L2->Age&&strcmp(L1->stuName,L2->stuName)==0) flag=3;
		 switch (flag)
		 {
			 case 1:
				p->Age=L1->Age;
				strcpy(p->stuName,L1->stuName);
				p->next=q;
				q=p;
				L1=L1->next;
				Length++;
				break;
			 case 2:
				p->Age=L2->Age;
				strcpy(p->stuName,L2->stuName);
				p->next=q;
				q=p;
				L2=L2->next;
				Length++;
				break;
			 case 3:
				p->Age=L1->Age;
				strcpy(p->stuName,L1->stuName);
				p->next=q;
				q=p;
				L1=L1->next;
				L2=L2->next;
				Length++;
				break;
		}
    }
	while (L1!=NULL)
	{
		p=(struct node *)malloc(sizeof(struct node));
		p->Age=L1->Age;
		strcpy(p->stuName,L1->stuName);
		p->next=q;
		q=p;
		L1=L1->next;
		Length++;
	}
	while (L2!=NULL)
	{
		p=(struct node *)malloc(sizeof(struct node));
		p->Age=L2->Age;
		strcpy(p->stuName,L2->stuName);
		p->next=q;
		q=p;
		L2=L2->next;
		Length++;
	}
	L3=q;

	printf("两个链表合并后信息：\n");
    for(i=0;i<Length;i++)
	{
		if (L3->Age>0)	
		printf("student\t%s\tage\t%d\n",L3->stuName,L3->Age);
	    L3=L3->next;
	}
	
}


int main( )                   /*主函数*/
{
    init( );   
	
    create1( );   

	create2( );

	combine( );

	getchar( );

}

