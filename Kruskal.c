//实现最小生成树Kruskal 的算法，理解图的数据结构存储表示。

#include<stdio.h>
#include<stdlib.h>
#define maxnode 64
#define maxedgs 2016
#define maxvalue 10000

typedef struct acr            //弧的定义
{
    int pre;                  //弧的一结点
	int bak;                  //弧的另一结点
	int weight;               //弧的权值
}edg;

edg edgs[maxedgs],edgs2[maxedgs];
int arcvisited[maxnode]={0};     //弧标记数组，以防止出现回路
int m,n;
int i,j,k,l;

void init()
{
    printf("克鲁斯卡尔算法生成最小树\n\n");
	
	printf("请输入图中顶点的个数（规定编号从1开始）：");
	scanf("%d",&m);
	printf("\n");
	printf("请输入图中边的个数：");
	scanf("%d",&n);
	printf("\n");
	printf("请依次输入每条边的顶点和权值（如：1 2 4 表示（v1，v2）边的权值为4）：\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&edgs[i].pre,&edgs[i].bak,&edgs[i].weight);
	}
}

int find(int f)                              //并查集运用
{
    while(arcvisited[f]>0)
		f=arcvisited[f];
	return f;
}

void kruscal()
{
    int x,y,v;
	int buf,edf;
	l=0;

	for(i=1;i<=n;i++)
	{
	    v=maxvalue;
		k=0;
		
		for(j=1;j<=n;j++)                     //寻找权值最小的边
		{
			if(edgs[j].weight<v)
			{
				v=edgs[j].weight;
				x=edgs[j].pre;
				y=edgs[j].bak;
				k=j;
			}
		}

		buf=find(x);
		edf=find(y);
		edgs[k].weight=maxvalue;            //将此边权值置为最大，表示已访问
		if(buf!=edf)                        //没有出现环
		{
		    l++;
			arcvisited[buf]=edf;
			edgs2[l].pre=x;
			edgs2[l].bak=y;
			edgs2[l].weight=v;
		}
		if(l==m-1) 
			break;
	}

		if(l<m-1)
	{
	    printf("不存在！\n");
		return;
	}
	else
	{
		printf("最小生成树的边及其权值为：\n");
	    for(i=1;i<=l;i++)
		    printf("(%d,%d):%d\n",edgs2[i].pre,edgs2[i].bak,edgs2[i].weight);
	}
}

int main()
{
    init();
	kruscal();

	return 0;
}
