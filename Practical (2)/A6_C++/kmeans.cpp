#include<iostream>
#include<math.h>
using namespace std;

#define MAX 20

int main()
{
	int k,n,min=999;
	int cnt=0;
	float x[MAX], y[MAX], cenx[MAX], ceny[MAX], previous_run[MAX], current_run[MAX];
	double d[MAX], euclidean_distance[MAX][MAX];
	cout<<"\nEnter the number of clusters you want to create : ";
	cin >> k;
	cout<<"\nEnter the number of objects: ";
	cin>>n;
	cout<<"\nEnter the co-ordinates of the objects now : ";
	for(int i=0; i<n; i++)
	{
		cout<<"\nEnter x coordinate";
		cin >> x[i];
		cenx[i] = x[i];
		cout<<"\nEnter y coordinate";
		cin >> y[i];
		ceny[i] = y[i];
		previous_run[i] = -999;
		current_run[i] = 999;
	}
	while(true)
	{
		for(int m=0; m < k;m++)
		{
			for(int j=0;j<n;j++) //j is for object number
			{
				d[j]=(((cenx[m]-x[j])*(cenx[m]-x[j]))+((ceny[m]-y[j])*(ceny[m]-y[j])));
				euclidean_distance[m][j] = sqrt(d[j]);
			}
		}

		for(int j=0;j<n;j++)
		{
			for(int m=0;m<k;m++)
			{
				if(euclidean_distance[m][j] < min)
				{
					min = euclidean_distance[m][j];
					current_run[j] = m;
				}
			}
			min = 999;
		}
	
		for(int m=0; m < k; m++)
		{
			float numerator_x = 0;
			float numerator_y = 0;
			int cluster_count = 0;
			for(int j=0; j < n; j++)
			{
				if (current_run[j] == m)
				{
					numerator_x += x[j];
					numerator_y += y[j];
					cluster_count++;
				}
			}
			cenx[m] = numerator_x / cluster_count;
			ceny[m] = numerator_y / cluster_count;
		}

		int l = 0;
		for(int j=0; j<n; j++)
		{
			if(current_run[j] == previous_run[j])
			{
				l++;
			}
		}
		
		if(l==n)
		{
			break;
		}
		else
		{
			for(int i=0; i<n; i++)
			{
				previous_run[i] = current_run[i];
			}
		}
	}

	for(int i=0; i<k; i++)
	{
		cout<<"\nCluster " <<i<<" centre is : ("<<cenx[i]<<","<<ceny[i]<<")";
		cout << "Objects are:";
		for(int j=0; j < n; j++)
		{
			if (current_run[j] == i)
			{
				cout<<"\n("<<x[j]<<","<<y[j]<<")";
			}
		}
	}
	return 0;
}
