//https://open.kattis.com/problems/justaminute

#include <stdio.h>

int main()
{
    int num_of_observations;
    scanf("%d",&num_of_observations);
    int total_displayed_time=0,total_wait_time=0;
    int display_time,wait_time;
    for(int i=0;i<num_of_observations;i++)
    {
        scanf("%d %d",&display_time,&wait_time);
        total_displayed_time+=display_time*60;
        total_wait_time+=wait_time;
    }
    double average_time=(double)total_wait_time/total_displayed_time;
    if(average_time<=1)
    {
        printf("measurement error");
    }
    else{
        printf("%.10g",average_time);
    }


    return 0;
}