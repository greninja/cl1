#include <iostream>
using namespace std;
#define MAXSIZE 10

int totalItems;
float weight_c,weight[MAXSIZE],profit[MAXSIZE];

struct tuple
{
	int flag,id;
	float UB,LB;
};

void Accept_input()
{
	cout<<"Enter no of items: ";
	cin>>totalItems;
	cout<<"Enter the weights for items:\n ";
	for(int i=1;i<=totalItems;i++)
		cin>>weight[i];
	cout<<"Enter the profit for items:\n";
	for(int i=1;i<=totalItems;i++)
		cin>>profit[i];
	cout<<"Enter the weight constraint: ";
	cin>>weight_c;
}
void Sort_input()
{
	int i,j,temp;
	float Ratio[totalItems];
	for(i=1;i<=totalItems;i++)
		Ratio[i]=profit[i]/weight[i];
	for(i=1;i<=totalItems;i++)
	{
		for(j=i+1;j<=totalItems;j++)
		{
			if(weight[j]<weight[j-1])
			{
				temp=profit[j];
				profit[j]=profit[j-1];
				profit[j-1]=temp;
				temp=Ratio[j];
				Ratio[j]=Ratio[j-1];
				Ratio[j-1]=temp;
				temp=weight[j];
				weight[j]=weight[j-1];
				weight[j-1]=temp;
			}
		}
	}
	for(i=1;i<=totalItems;i++)

	{
		for(j=i+1;j<=totalItems;j++)
		{
			if(Ratio[j]>Ratio[j-1])
			{
				temp=profit[j];
				profit[j]=profit[j-1];
				profit[j-1]=temp;
				temp=Ratio[j];
				Ratio[j]=Ratio[j-1];
				Ratio[j-1]=temp;
				temp=weight[j];
				weight[j]=weight[j-1];
				weight[j-1]=temp;
			}
		}
	}
	cout<<"Input is : \n";
	cout<<"Tuple\tProfit\tWeight\tRatio\n";
	for(i=1;i<=totalItems;i++)
		cout<<i<<"\t"<<profit[i]<<"\t"<<weight[i]<<"\t"<<Ratio[i]<<"\n";
}
float calculate_UB(float current_wt,float current_pr,int current_item)
{
	float cw=current_wt;
	float cp=current_pr;
	for(int i=current_item+1;i<=totalItems;i++)
	{
		if(cw+weight[i] <= weight_c)
		{
			cp=cp-profit[i];
			cw=cw+weight[i];
		}
	}
	return cp;
}
float calculate_LB(float current_wt,float current_pr,int current_item)
{
	float cw=current_wt;
	float cp=current_pr;
	for(int i=current_item+1;i<=totalItems;i++)
	{
		cw=cw+weight[i];
		if(cw<weight_c)
			cp=cp-profit[i];
		else
			return (cp-(1-(cw-weight_c)/weight[i])*profit[i]);
	}
	return cp;
}
void Knapsack_BB()
{
	int i,next,solution[MAXSIZE]={0};
	float wt=0,pr=0;
	struct tuple left_child,right_child,current;
	current.LB=calculate_LB(0,0,0);
	current.UB=calculate_UB(0,0,0);
	current.flag=-1;
	current.id=0;
	i=1;
	do
	{
		next=current.id+1;
		right_child.LB=calculate_LB(wt,pr,next);
		right_child.UB=calculate_UB(wt,pr,next);
		right_child.flag=0;
		right_child.id=next;
		left_child.flag=1;
		left_child.id=next;
		if(wt+weight[next] <= weight_c)
		{
			left_child.LB=calculate_LB(wt+weight[next],pr-profit[next],next);
			left_child.UB=calculate_UB(wt+weight[next],pr-profit[next],next);
		}
		else
		{
			current.UB=pr;
			left_child.LB=pr;
		}
		if(left_child.LB<=right_child.LB && left_child.UB <= right_child.UB)
		{
			current=left_child;
		}
		else
			current=right_child;
		solution[i]=current.flag;
		i++;
		if(current.flag==1)
		{
			wt=wt+weight[(current.id)];
			pr=pr-profit[(current.id)];
		}
	}while(current.id!=totalItems);
	cout<<"The solution is: ";
	for(i=1;i<=totalItems;i++)
			cout<<solution[i]<<"\t";
	cout<<"\nMax profit is: "<<-(current.LB);
}
int main()
{
	Accept_input();
	Sort_input();
	Knapsack_BB();
	return 0;
}

/*
########OUTPUT############
[omkar@localhost ~]$ cd Downloads/
[omkar@localhost Downloads]$ cd cl1
[omkar@localhost cl1]$ cd omkar/
[omkar@localhost omkar]$ cd B3
[omkar@localhost B3]$ g++ knapsack.cpp 
[omkar@localhost B3]$ ./a.out
Enter no of items: 5
Enter the weights for items:
 8 4 3 9 1
Enter the profit for items:
1 3 4 9 2
Enter the weight constraint: 5
Input is : 
Tuple	Profit	Weight	Ratio
1	4	3	1
2	2	1	2
3	9	9	1
4	1	8	0
5	3	4	0
The solution is: 1	1	0	0	1	
Max profit is: 6[omkar@localhost B3]$ 

*/
