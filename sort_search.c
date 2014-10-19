//实现快速排序和折半查找算法

#include<stdio.h>

#define MAX 1000             //最大数组长度

int R[MAX];                 //存放数据的数组
int i,j;                     //计数器变量   
int k;                     //数据元素个数
int m,n;                   //记录数据在数组中的位置

void init()               //初始化，在命令指示下输入数据
{
	 printf("请输入数据的个数：\n");
	 scanf("%d",&k);
	 printf("请依次输入每个数据：\n");
	 for(i=1;i<=k;i++)
		 scanf("%d",&R[i]);
	 printf("数据输入成功！结果如下：\n");
	 for(i=1;i<=k;i++)
		 printf("%d  ",R[i]);
	 printf("\n");
}

int Quick_Partition(int R[],int i,int j)   //快速排序的一次划分，左端位置为i，右端位置为j，划分元为R[i]
{
	R[0]=R[i];
	while(i<j)
	{
	    while(i<j&&R[j]>=R[0])
			j--;
		if(i<j)
		{	
			R[i]=R[j];
			i++;
		}

		while(i<j&&R[i]<=R[0])
			i++;
		if(i<j)
		{
		    R[j]=R[i];
			j--;
		}
	}
	R[i]=R[0];
	return i;
}

void Quick_Sort(int R[],int m,int n)    //对顺序表R[m...n]做快速排序
{	
	if(m<n)
	{
	    i=Quick_Partition(R,m,n);
		Quick_Sort(R,m,i-1);
		Quick_Sort(R,i+1,n);
	}
}

void output1()
{
	printf("快速排序成功！结果如下：\n");
	
	for(i=1;i<=k;i++)
		printf("%d  ",R[i]);

	printf("\n");
}

int BinarySearch(int R[],int k)
{
    int low=1;
	int high=k;
	int mid,key;
	
	printf("请输入你要查找的数据：\n");
	scanf("%d",&key);
	while(low<=high)
	{
	    mid=(low+high)/2;
		if(key==R[mid]) return mid;
		else if(key>R[mid]) low=mid+1;
		else high=mid-1;
	}
	return 0;
}

void output2()
{
	if (k==0)
		printf("不存在该数据！\n");
	else 
		printf("数据查找成功！为数据列表中第%d个数据！\n",k);
}

int main()
{
	init();
	Quick_Sort(R,1,k);
	output1();
	k=BinarySearch(R,k);
	output2();
    return 0;
}
