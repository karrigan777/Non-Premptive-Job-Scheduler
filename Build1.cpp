#include<stdio.h>
#include<conio.h>
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void sort(int arr[], int n){
int i, j,temp;
for (i = 0; i < n-1; i++)      
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] < arr[j+1])
           swap(&arr[j], &arr[j+1]);
}
 
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
for(int i=removeIndex;i<n-1;i++){
	arr[i]=arr[i+1];
}
}
 
int main(){
	int noOfProcesses, turnTime;
	printf("Enter the number of processes ");
	scanf("%d",&noOfProcesses);
	int arrivalTime[noOfProcesses], burstTime[noOfProcesses], processID[noOfProcesses], queue[noOfProcesses];
	int i=0,k=0;
	while(i<noOfProcesses){
		printf("Enter the Arrival Time of processes %d ",i+1);
		scanf("%d",&arrivalTime[i]);
		burstTime[i]=2*arrivalTime[i];
		processID[i]=i+1;
		i++;
	}
	i=0;
	printf("\n\nProcessID | | Arrival Time | | Burst Time \n\n");
	while(i<noOfProcesses){
		printf("%d | | %d | | %d \n\n",processID[i],arrivalTime[i],burstTime[i]);
		i++;
	}
	i=0;
	while(i<noOfProcesses){
		queue[i]=burstTime[i];
		i++;
	}
	//	displayArray(queue, noOfProcesses);
	//	sort(queue, noOfProcesses);
	//	displayArray(queue, noOfProcesses);
	i=0;
	int j=44;
	int total = noOfProcesses;
	int comp=0, arrTime=0;
	while(i<total){
		j=0;
		while(j<noOfProcesses){
			if(queue[i] == burstTime[j]){
				printf("\nExecuted Process with BurstTime %d and ProcessID %d",burstTime[j],processID[j]);
				decrementArray(burstTime,noOfProcesses,burstTime[j]);
				decrementArray(arrivalTime,noOfProcesses,arrivalTime[j]);
				decrementArray(processID,noOfProcesses,processID[j]); 
				noOfProcesses--;
				int a=0;
				printf("\n\n\n\n\nProcesses Left:");
				printf("\n\nProcessID | | Arrival Time | | Burst Time \n\n");
				while(a<noOfProcesses){
					printf("\n\n%d | | %d | | %d ",processID[a],arrivalTime[a],burstTime[a]);
					a++;
				}
			}
			j++;
		}
		i++;
	}
	printf("\nPress Any key to Exit");
	char a = getch();
}
