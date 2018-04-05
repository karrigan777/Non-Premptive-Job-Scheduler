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

void decrementArray(int arr[], int n, int removeElement){
	int removeIndex=0;
	for(int i=0;i<n;i++){
		if(arr[i]==removeElement){
			removeIndex=i;
		}
	}
}



int main(){
	int noOfProcesses;
	printf("Enter the number of processes ");
	scanf("%d",&noOfProcesses);
	int arrivalTime[noOfProcesses], burstTime[noOfProcesses], processID[noOfProcesses], queue[noOfProcesses];
	int i=0;
	while(i<noOfProcesses){
		printf("Enter the Arrival Time of processes %d ",i+1);
		scanf("%d",&arrivalTime[i]);
		burstTime[i]=2*arrivalTime[i];
		processID[i]=i+1;
		i++;
	}

	int temp;

	for(int i=0;i<noOfProcesses;i++)
	{
		for(int j=0;j<noOfProcesses;j++)
		{
			if(arrivalTime[i]<arrivalTime[j])
			{
				temp=processID[j];
				processID[j]=processID[i];
				processID[i]=temp;

				temp=arrivalTime[j];
				arrivalTime[j]=arrivalTime[i];
				arrivalTime[i]=temp;
				
				temp=burstTime[j];
				burstTime[j]=burstTime[i];
				burstTime[i]=temp;
			}
		}
	}
	i=0;
	while(i<noOfProcesses){
		printf("%d | | %d | | %d \n\n",processID[i],arrivalTime[i],burstTime[i]);
		i++;
	}
/*	int queue[noOfProcesses], p[noOfProcesses], at[noOfProcesses], bt[noOfProcesses];
	int a=0;
	for (int Time =0, i = 0; noOfProcesses>0;)
	{
		for (int j = 0; j < noOfProcesses; ++j)
		{
			if (arrivalTime[j] == Time)
			{
				Time = Time + burstTime[j];
				for (int i = 0; i < Time; ++i)
				{
					if ()
					{
					}
				}
			}
			else{
				Time++;
			}
			printf("Time is %d",Time);
		}
		
	}
*/


	int btime=0, max=0, wt[noOfProcesses],tt[noOfProcesses], ta=0, sum=0, k=0;
	float wavg=0,tavg=0,tsum=0,wsum=0;
	int n = noOfProcesses;
	for(int j=0;j<n;j++)
	{
		btime=btime+burstTime[j];
		for(i=j;i<n;i++)
		{
			if(arrivalTime[i]<=btime && burstTime[i]>max)
			{
				max = i;
			}
		}
		temp=processID[j];
		processID[j]=processID[i];
		processID[i]=temp;
	
		temp=arrivalTime[j];
		arrivalTime[j]=arrivalTime[i];
		arrivalTime[i]=temp;
		
		temp=burstTime[j];
 		burstTime[j]=burstTime[i];
		burstTime[i]=temp;
	}

	i=0;
	while(i<noOfProcesses){
		printf("%d | | %d | | %d \n\n",processID[i],arrivalTime[i],burstTime[i]);
		i++;
	}

	wt[0]=0;

	for(i=1;i<noOfProcesses;i++)
	{
		sum=sum+burstTime[i-1];
		wt[i]=sum-arrivalTime[i];
		wsum=wsum+wt[i];
	}
 
	wavg=(wsum/noOfProcesses);

	for(i=0;i<noOfProcesses;i++)
	{
		ta=ta+burstTime[i];
		tt[i]=ta-arrivalTime[i];
		tsum=tsum+tt[i];
	}
	tavg=(tsum/noOfProcesses);

	printf("************************");
	printf("\n RESULT:-");
	printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
	for(i=0;i<noOfProcesses;i++)
	{
	printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",processID[i],burstTime[i],arrivalTime[i],wt[i],tt[i]);
	}
	 
	printf("\n\nAVERAGE WAITING TIME : %f",wavg);
	printf("\nAVERAGE TURN AROUND TIME : %f",tavg);

}
