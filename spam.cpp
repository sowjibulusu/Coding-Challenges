//https://open.kattis.com/problems/spam

#include <iostream> 
#include <cstring> 
#include <algorithm>
#define max_chars 100000 
using namespace std; 
void k_ones(int k, string &s) 
{ 
    int u = 0; 
    int n = s.length(); 
    float number_of_successful_email_classified = 0;
    int length_of_subsequence = 0;
    float success_rate = 0;
    float success_rate_max = 0;
    string sub_string;
    float sub_string_length = 0;
    float number_of_ones;
    int my_index = 0;
    int max_length = 0;
    for (int i = 0; i <= n-k ; i++) 
    { 
        for (float i1 = k; i1 + i <= n ; i1++) 
        {  
           sub_string = s.substr(i,  i1);
           sub_string_length = sub_string.length();
           number_of_ones = std::count(sub_string.begin(), sub_string.end(), '1');
           success_rate = (number_of_ones / sub_string_length )*100;
           if(success_rate >= success_rate_max)
           {
            success_rate_max = success_rate;
            max_length = sub_string_length;
            my_index = i +1;
            }
        }
    } 
cout << my_index
         << " " << max_length << endl; 
} 
int main() 
{ 
    string s;
    int k;
    cin>>k;
    cin>>s;
    k_ones(k, s); 
    return 0; 
}
