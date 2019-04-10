#include<stdio.h> 
 
int main() 
{ 
 
  int count,j,n,time,remain,flag=0,time_quantum; 
  int wait_time=0,turnaround_time=0,a[20],b[20],r[20]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    scanf("%d",&a[count]); 
    scanf("%d",&b[count]); 
    r[count]=b[count]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(r[count]<=time_quantum && r[count]>0) 
    { 
      time+=r[count]; 
      r[count]=0; 
      flag=1; 
    } 
    else if(r[count]>0) 
    { 
      r[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(r[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-a[count],time-a[count]-b[count]); 
      wait_time+=time-a[count]-b[count]; 
      turnaround_time+=time-a[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(a[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  
  return 0; 
}
