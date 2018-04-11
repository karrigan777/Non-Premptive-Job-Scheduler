#include<stdio.h>
#include<conio.h>

void displayArray(int arr[], int n){
	printf("\n\n");
	int i=0;
	while(i<n){
		printf("\n%d",arr[i]);
		i++;
	}
}

struct Pro{
	int arrivalTime;
	int burstTime;
	int processID;
};

int main(){
	int noOfProcesses, temp;
	printf("Enter the number of processes ");
	scanf("%d",&noOfProcesses);
	struct Pro process[noOfProcesses];
	for(int i=0; i<noOfProcesses;i++)
	{
		printf("Enter Arrival Time for process %d\n",i+1);
		scanf("%d",&process[i].arrivalTime);
		process[i].processID=i+1;
		process[i].burstTime = 2 * process[i].arrivalTime;
	}
	
	for(int i=0;i<noOfProcesses;i++)
	{
		for(int j=0;j<noOfProcesses;j++)
		{
			if(process[i].arrivalTime<process[j].arrivalTime)
			{
				temp=process[j].processID;
				process[j].processID=process[i].processID;
				process[i].processID=temp;

				temp=process[j].arrivalTime;
				process[j].arrivalTime=process[i].arrivalTime;
				process[i].arrivalTime=temp;
				
				temp=process[j].burstTime;
				process[j].burstTime=process[i].burstTime;
				process[i].burstTime=temp;
			}
		}
	}
	int time=0, max=0;
	for(int i=0; i<noOfProcesses;i++)
	{
		time = time+process[i].burstTime;
		max = i+1;
		for(int j=i+1; j<noOfProcesses;j++)
		{
			if(process[j].arrivalTime<=time && process[j].arrivalTime>process[max].arrivalTime)
			{
				max = j;
			}
		}
		if(max!=i+1)
		{
				temp=process[max].processID;
				process[max].processID=process[i+1].processID;
				process[i+1].processID=temp;

				temp=process[max].arrivalTime;
				process[max].arrivalTime=process[i+1].arrivalTime;
				process[i+1].arrivalTime=temp;
				
				temp=process[max].burstTime;
				process[max].burstTime=process[i+1].burstTime;
				process[i+1].burstTime=temp;
		}
	}
	
	int btime=0, wt[noOfProcesses],tt[noOfProcesses], ta=0, sum=0, k=0;
	float wavg=0,tavg=0,tsum=0,wsum=0;
	
	wt[0]=0;

	for(int i=1;i<noOfProcesses;i++)
	{
		sum=sum+process[i-1].burstTime;
		wt[i]=sum-process[i].arrivalTime;
		wsum=wsum+wt[i];
	}
 
	wavg=(wsum/noOfProcesses);

	for(int i=0;i<noOfProcesses;i++)
	{
		ta=ta+process[i].burstTime;
		tt[i]=ta-process[i].arrivalTime;
		tsum=tsum+tt[i];
	}
	tavg=(tsum/noOfProcesses);

	printf("************************");
	printf("\n RESULT:-");
	printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
	for(int i=0;i<noOfProcesses;i++)
	{
	printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",process[i].processID,process[i].burstTime,process[i].arrivalTime,wt[i],tt[i]);
	}
	 
	printf("\n\nAVERAGE WAITING TIME : %f",wavg);
	printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
	
	printf("\n\n\nIf the SJF is Used ---\n\n\n");
	
	ta=0, sum=0, k=0;
	wavg=0,tavg=0,tsum=0,wsum=0;
	
	for(int i=0;i<noOfProcesses;i++)
	{
		for(int j=0;j<noOfProcesses;j++)
		{
			if(process[i].arrivalTime<process[j].arrivalTime)
			{
				temp=process[j].processID;
				process[j].processID=process[i].processID;
				process[i].processID=temp;

				temp=process[j].arrivalTime;
				process[j].arrivalTime=process[i].arrivalTime;
				process[i].arrivalTime=temp;
				
				temp=process[j].burstTime;
				process[j].burstTime=process[i].burstTime;
				process[i].burstTime=temp;
			}
		}
	}
	
	wt[0]=0;

	for(int i=1;i<noOfProcesses;i++)
	{
		sum=sum+process[i-1].burstTime;
		wt[i]=sum-process[i].arrivalTime;
		wsum=wsum+wt[i];
	}
 
	wavg=(wsum/noOfProcesses);

	for(int i=0;i<noOfProcesses;i++)
	{
		ta=ta+process[i].burstTime;
		tt[i]=ta-process[i].arrivalTime;
		tsum=tsum+tt[i];
	}
	tavg=(tsum/noOfProcesses);

	printf("************************");
	printf("\n RESULT:-");
	printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
	for(int i=0;i<noOfProcesses;i++)
	{
	printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",process[i].processID,process[i].burstTime,process[i].arrivalTime,wt[i],tt[i]);
	}
	 
	printf("\n\nAVERAGE WAITING TIME : %f",wavg);
	printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
	
}
