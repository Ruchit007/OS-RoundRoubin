#include<stdio.h>
#include<stdbool.h>
#include"dos.h"
#include<windows.h>
void w_t(int p1[],int n,int bt[],int wt[],int q1)
{
	int s=0;
	int seq[s];
	int i;
	int rt[n]; // remaining time
	for(i=0;i<n;i++)
	{
		rt[i]=bt[i];
	}
	int t=3;
	printf("\n%5d to %5d    :\tCPU IS IDEAL\n",0,3);

	while(1)
	{
		bool d1= true;
		for(i=0;i<n;i++)
		{
			if(rt[i]>0)
			{
				d1=false;
				if(rt[i]>q1)
				{
					int t1=t;
					t+=q1;
					rt[i]=rt[i]-q1;
					s=s+1;
					seq[i]=p1[i];
					printf("%5d to %5d   :\t%d\n",t1,t,seq[i]);
				}
				else
				{
					int t2=t;
					t= t + rt[i];
					wt[i]=t-bt[i];
					rt[i]=0;
					s=s+1;
					seq[i]=p1[i];
					printf("%5d to %5d   :\t%d\n",t2,t,seq[i]);
				}
			}
		}
		if(d1==true)
		break;
	}
}

void t_t(int p1[],int n,int bt[],int wt[],int tat[])
{
	int i;
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}

}


void a_t(int p1[],int n,int bt[],int q2,int p2[])
{
	int wt[n],tat[n],total_wt=0,total_tat=0; // wt-->>waiting time || tat-->>Turnaround time 
	w_t(p1,n,bt,wt,q2);
	t_t(p1,n,bt,wt,tat);
	int i;
	printf("\n\nPROCESSES    BURST TIME    WAITING TIME    TURN AROUND TIME\n");

	for(i=0;i<n;i++)
	{
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		printf("%d \t           %d\t          %d\t          %d\n",p1[i],bt[i],wt[i],tat[i]);
	}
	printf("\nAverage waiting time= %f",(float)total_wt / (float)n);
	printf("\nAverage TurnAround time= %f",(float)total_tat / (float)n);



}


int main()
{
	int i,j;
	printf("How many Processes are entering the OS:\n");
	int n1;
	scanf("%d",&n1);
	int p[n1];
	int p2[n1];
	int bt1[n1];
	for(i=0;i<n1;i++)
	{
		p[i]=(i+1);
		p2[i]=(i+1);
	}
	printf("\nPLEASE NOTE THAT BURST TIME CANNOT EXCEED 10");
	for(i=0;i<n1;i++)
	{
		printf("\nEnter The Burst Time for P%d :",i+1);
		scanf("%d",&bt1[i]);

	}

	for(i=0;i<n1;i++)
	{
		int ps=i;
		for(j=i+1;j<n1;j++)
		{
			if(bt1[j]<bt1[ps])
			{
				ps=j;
			}
		}


		int x;
		x=bt1[i];
		bt1[i]=bt1[ps];
		bt1[ps]=x;
		x=p[i];
		p[i]=p[ps];
		p[ps]=x;
	}

	printf("\nENTER THE VALUE OF THE TIME QUANTUM : ");
	int q;
	scanf("%d",&q);
	fflush(stdout);
	sleep(3);
	a_t(p,n1,bt1,q,p2);
	return 0;
}

