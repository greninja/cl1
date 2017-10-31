#include<iostream>
#include<math.h>

using namespace std;

#define MAX 20

int main()
{
	int k,n,min=999;
	int xcnt=0,cnt=0;
	float x[MAX],y[MAX],cenx[MAX],ceny[MAX],kc[MAX],kc1[MAX];
	double d[MAX],euc_distance[MAX][MAX];
	cout<<"\nEnter the number of clusters you want to create : ";
	cin>>k;
	cout<<"\nEnter the number of objects: ";
	cin>>n;
	cout<<"\nEnter the co-ordinates of the objects now : ";
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter x co-ordinate: ";
		cin>>x[i];
		cenx[i]=x[i];
		cout<<"Enter y co-ordinate: ";
		cin>>y[i];
		ceny[i]=y[i];
		kc[i]=kc1[i]=0; //initializing as 0 "RANDOM PARTITION METHOD"
	}
	do
	{
		//"Calculating the euclidean distances"
		for(int m=0;m<k;m++) //m is for cluster number
		{
			for(int j=0;j<n;j++) //j is for object number
			{
				d[j]=(((cenx[m]-x[j])*(cenx[m]-x[j]))+((ceny[m]-y[j])*(ceny[m]-y[j])));
				euc_distance[m][j] = sqrt(d[j]);
			}
		}
		//Now,comparing if kc1 is equal to kc.
		int l=0;
		for(int j=0;j<n;j++)
		{
			if(kc1[j]==kc[j]) //checking each element
			{
				l++;
				//It checks if all the elements are equal.
			}
		}
		if(l==n)
		{
			cnt++;
			/*if(cnt==2) //if yes then go outside this whole do-while loop
			{
				goto L1;
			}*/
		}
		else //or just put the values of kc to kc1.
		{
			for(int j=0;j<n;j++)
			{
				kc1[j]=kc[j];   //checking for covergence
			}
		}
		//"Checking which data object is nearer to which cluster and creating cluster."
		for(int j=0;j<n;j++) // data objects
		{
			for(int m=0;m<k;m++) //cluster number
			{
				if(euc_distance[m][j]<min)
				{
					min=euc_distance[m][j];
					kc[j]=m;
				}
			}
			min=999;
			cenx[j]=ceny[j]=0; //For further calculation as it would be overwritten
		}
		//Calculating the new centroid co-ordinates
		for(int m=0;m<k;m++) // cluster number
		{
			xcnt=0;
			for(int j=0;j<n;j++) //data objects
			{
				if(kc[j]==m)
				{
					cenx[m]=x[j]+cenx[m];
					ceny[m]=y[j]+ceny[m];
					xcnt++;
				}
			}
			cout<<"\nThe new centroids are: ";
			cenx[m]=cenx[m]/xcnt;
			ceny[m]=ceny[m]/xcnt;
			cout<<cenx[m]<<","<<ceny[m]<<"\n";
		}
	}while(cnt<2);
	for(int i=0;i<k;i++) //for cluster number
	{
		cout<<"\nCluster "<<i+1<<" centre is : ("<<cenx[i]<<","<<ceny[i]<<")";
		cout<<"\nObjects are: ";
		for(int j=0;j<n;j++)
		{
			if(kc[j]==i) //if the cluster number is equal to i then print the elements i.e. present
			{
				cout<<"\n("<<x[j]<<","<<y[j]<<")";
			}
		}
	}
	cout<<"\n----------------------------------------------------------\n";
	return 0;
}

