//https://open.kattis.com/problems/speedlimit

#include <iostream>

int main()
{

int no_of_datasets;

std::cin >> no_of_datasets;
while (no_of_datasets != -1)
{
int diff_variable = 0;
int speed, time;
int distance = 0;
for (int i = 0; i < no_of_datasets; i++)
{
std::cin >> speed >> time;
distance += speed*(time-diff_variable);
diff_variable = time;
}
std::cout << distance <<" "<<"miles"<<std::endl;

std::cin >> no_of_datasets;
}

}