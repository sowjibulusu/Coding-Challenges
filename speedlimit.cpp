//https://open.kattis.com/problems/speedlimit

#include <iostream>
using namespace std;
int n;
int main()
{
int no_of_data_sets;
cin>>no_of_data_sets;
n=no_of_data_sets;
while(n!=-1)
{
if(no_of_data_sets>0 && no_of_data_sets<10)
{
int speed[no_of_data_sets],time[no_of_data_sets];
int i,j;
int time_diff[no_of_data_sets],multiply[no_of_data_sets],sum=0;
    for(i=0;i<no_of_data_sets;i++)
    {
    cin>>speed[i];
    cin>>time[i];
    }
    for(i=0;i<no_of_data_sets;i++)
    {
      time_diff[0]=time[0];
      time_diff[i+1]=time[i+1]-time[i];
      multiply[i]=time_diff[i]*speed[i];
      sum=sum+multiply[i];
    }
    cout<<sum<<" miles"<<endl;
    cin>>no_of_data_sets;
    n=no_of_data_sets;
}
else
cout<<"";
}
if(n==-1)
cout<<"";
}