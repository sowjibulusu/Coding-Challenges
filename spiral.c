//https://open.kattis.com/problems/spiral 
#include <stdio.h>
#include <stdbool.h>

#define ROW 105
#define SIZE 105*105

struct Points {
	char x;
	char y;
}source_point, destination_point;

struct QueueItems {
	char queue_items_x[SIZE];
	char queue_items_y[SIZE];
	int index_items[SIZE];
}queue_items;


bool ulam_spiral_matrix[ROW][ROW] = { 0 };
bool visited_block[ROW][ROW] = { false };
int max_value = ROW*ROW;
int total_count = 0;
//Queue initializations
int  start_value = -1, end_value = -1;
int source_value, destination_value;

//Check Prime
bool checkPrime(int);
void createUlamMatrix();
void updateUlamMatrix(int x, int y);
void breadthFirstSearch();

int main()
{
	int case_number = 1;

	while (scanf("%d %d", &source_value, &destination_value) != EOF)
	{
		if (checkPrime(source_value) || checkPrime(destination_value))
		{
			printf("\nCase %d: impossible\n", case_number);

		}
		else {
			createUlamMatrix();
			breadthFirstSearch();
			if (total_count == -1)
			{
				printf("\nCase %d: impossible\n", case_number);
			}
			else {
				printf("\nCase %d: %d\n", case_number, total_count);
			}
			
		}
		case_number++;
		start_value = -1;
		end_value = -1;
		max_value = ROW*ROW;
		memset(visited_block, false, SIZE);
	}


	return 0;
}

bool checkPrime(int number)
{

	if (number == 1) { return false; }
	if (number == 12 || number == 72 || number<1) { return true; }
	for (int i = 2; i <= number / 2; i++)
	{
		if (number%i == 0) { return false; }
	}
	return true;
}

void createUlamMatrix()
{
	/*Creating Ulam Matrix*/
	int i, top_index = 0, left_index = 0;
	int bottom_index = ROW;
	int right_index = ROW;

	while (top_index < bottom_index && left_index < right_index)
	{
		if (top_index < bottom_index)
		{
			for (i = right_index - 1; i >= left_index; --i)
			{
				updateUlamMatrix(bottom_index - 1, i);
			}
			bottom_index--;
		}

		if (left_index <right_index)
		{
			for (i = bottom_index - 1; i >= top_index; --i)
			{
				updateUlamMatrix(i, left_index);
			}
			left_index++;
		}

		for (i = left_index; i < right_index; ++i)
		{
			updateUlamMatrix(top_index, i);
		}
		top_index++;

		for (i = top_index; i < bottom_index; ++i)
		{
			updateUlamMatrix(i, right_index - 1);
		}
		right_index--;

	}

	/*	for (int i = 0; i < ROW; i++)
	{
	for (int j = 0; j < ROW; j++)
	{
	printf("%d ", ulam_spiral_matrix[i][j]);

	}
	printf("\n");
	}*/

}

void updateUlamMatrix(int x, int y)
{
	if (source_value == max_value) { source_point.x = x; source_point.y = y; }
	if (destination_value == max_value) { destination_point.x = x; destination_point.y = y; }
	if (checkPrime(max_value))
	{
		ulam_spiral_matrix[x][y] = 0;
		visited_block[x][y] = true;
	}
	else {
		ulam_spiral_matrix[x][y] = 1;
		visited_block[x][y] = false;
	}


	max_value--;
}


void addQueueElement(int row, int column,int index) {
	if (end_value == SIZE - 1)
		return;
	else {
		if (start_value == -1) { start_value = 0; }
		end_value++;
		queue_items.queue_items_x[end_value] = row;
		queue_items.queue_items_y[end_value] = column;
		queue_items.index_items[end_value] = index;
	}
}

bool removeQueueElement() {
	if (start_value == -1)
		return false;
	else {
		start_value++;
		if (start_value > end_value)
		{
			start_value = -1;
			end_value = -1;
		}

	}
	return true;
}
bool checkQueueEmpty()
{
	if (start_value == -1)
		return true;

	return false;
}
bool isValid(int row, int col)
{

	return (row >= 0) && (row < ROW) && (col >= 0) && (col <ROW);
}



void breadthFirstSearch()
{
	if (!checkQueueEmpty())
	{
		start_value = -1;
		end_value = -1;
	}


	total_count = 0;

	addQueueElement(source_point.x, source_point.y,0);
	visited_block[source_point.x][source_point.y] = true;
	bool check = false;
	

	while (!checkQueueEmpty())
	{
		check = false;
		int queue_x = queue_items.queue_items_x[start_value];
		int queue_y = queue_items.queue_items_y[start_value];
		int queue_index = queue_items.index_items[start_value];

		if (queue_x == destination_point.x &&queue_y == destination_point.y)
		{
			total_count = queue_index;
			return;
		}
		removeQueueElement();

		if (isValid(queue_x - 1, queue_y) && !visited_block[queue_x - 1][queue_y] && ulam_spiral_matrix[queue_x - 1][queue_y])
		{
			addQueueElement(queue_x - 1, queue_y,queue_index+1);
			visited_block[queue_x - 1][queue_y] = true;

		}

		if (isValid(queue_x + 1, queue_y) && !visited_block[queue_x + 1][queue_y] && ulam_spiral_matrix[queue_x + 1][queue_y])
		{
			addQueueElement(queue_x + 1, queue_y,queue_index+1);
			visited_block[queue_x + 1][queue_y] = true;

		}

		if (isValid(queue_x, queue_y + 1) && !visited_block[queue_x][queue_y + 1] && ulam_spiral_matrix[queue_x][queue_y + 1])
		{
			addQueueElement(queue_x, queue_y + 1,queue_index+1);
			visited_block[queue_x][queue_y + 1] = true;
		}

		if (isValid(queue_x, queue_y - 1) && !visited_block[queue_x][queue_y - 1] && ulam_spiral_matrix[queue_x][queue_y - 1])
		{
			addQueueElement(queue_x, queue_y - 1,queue_index+1);
			visited_block[queue_x][queue_y - 1] = true;

		}

	}
	total_count = -1;
}
