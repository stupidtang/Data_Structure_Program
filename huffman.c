#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXBIT 10
#define MAXVALUE 1000

typedef struct HNode                   //定义节点结构
{
    int weight;
	int parent,lchild,rchild;
}HNode;

typedef struct HCode                   //定义赫夫曼编码结构
{
    int bit[MAXBIT];
	int start;
}HCode;

char ch[1000];         //存放明文电文的字母
int w[256]={0};       //存放每个字母出现的次数,数组下标即为每个字符的ASCII的值
int i,j,k,m;
int length,length2;
int m1,m2,x1,x2;
int c,f;
HNode *Node[1000];
HCode *Code[1000];

void init()
{
	i=0;
	
	printf("请输入需要编码的明文电文：\n");

	while(1)
	{
	    ch[i]=getchar();
		if(ch[i]=='\n')
		{
		    ch[i]='\0';
			length=i;
			break;
		}
		w[ch[i]]++;
		i++;
	}
}

void create()
{
	j=-1;

	for(i=0;i<=255;i++)                //创建需编码字符的数组（即叶子结点）并初始化
	{	
		if(w[i]!=0)
		{
		    j++;
			Node[j]=(HNode *)malloc(sizeof(HNode));
			Node[j]->weight=w[i];
			Node[j]->parent=-1;
			Node[j]->lchild=-1;
			Node[j]->rchild=-1;
		}
		
	}

	length2=j+1;
	j++;

	for(;j<(2*length2-1);j++)                           //创建分支结点并初始化
	{
	    Node[j]=(HNode *)malloc(sizeof(HNode));
		Node[j]->weight=0;
		Node[j]->parent=-1;
		Node[j]->lchild=-1;
		Node[j]->rchild=-1;

	}

	for(i=length2;i<(2*length2-1);++i)        
	{
	    m1=m2=MAXVALUE;
		x1=x2=0;

		for(j=0;j<i;++j)                    //寻找叶子结点权值最小和次小的两棵子树
		{

			if(Node[j]->parent==-1&&Node[j]->weight<=m1)
			{
			    m2=m1;
				x2=x1;
				m1=Node[j]->weight;
				x1=j;
			}
			else if(Node[j]->parent==-1&&Node[j]->weight<=m2)
			{
				m2=Node[j]->weight;
				x2=j;
			}
			
		}

		Node[x1]->parent=i;                    //合并成一棵新的子树
		Node[x2]->parent=i;
		Node[i]->lchild=x1;
		Node[i]->rchild=x2;
		Node[i]->weight=m1+m2;
	}

	for(i=0;i<length2;i++)                  //字符m 编码
	{
		Code[i]=(HCode *)malloc(sizeof(HCode));
		for(c=i,f=Node[i]->parent,j=0;f!=-1;c=f,f=Node[f]->parent,j++)
		{
			if(Node[f]->lchild==c) (Code[i]->bit[j])=0;
			else (Code[i]->bit[j])=1;
		}
	}


}

void output()
{
	printf("出现的字符及其出现的次数:\n");
	
	for(i=0;i<=255;i++)                              
	{	
		if(w[i]!=0)
			printf("%c:%d\t",i,w[i]);
	}
	printf("\n");
	printf("编码规则：\n");

	for(i=0;i<=255;i++)                                
	{	
		if(w[i]!=0)
			printf("%c\t",i);
	}
	printf("\n");
	
	for(i=0;i<length2;i++)
	{		
		for(j=MAXBIT-1;j>=0;j--)
			if(Code[i]->bit[j]==0||Code[i]->bit[j]==1)
		    printf("%d",Code[i]->bit[j]);
		printf("\t");
	}
	printf("\n");
}

int main()
{
    init();
	create();
	output();
	
	return 0;
}
