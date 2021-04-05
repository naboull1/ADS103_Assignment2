#include <iostream>
#include <string>
#include <chrono>									//Library for Time Control
#include <fstream>									//Library for File System control
#include <windows.h>								//Library for controling windows functions
#include <vector>									//Library for creating Containers for Sotring Vectors

using namespace std;


//Function for displaying an arrays content one by one 
void displayArray(int arr[], int arraySize)
{
	for (int i = 0; i <= arraySize - 1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


//Function that swaps variables
void mySwap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


//Function that contains a WHILE statement that LOOPs(FOR) and checks IF number is higher or lower and swaps using the myswap function
void bubbleSort(int arr[], int arraySize)
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i <= arraySize - 1 - 1; i++)
		{
			if (arr[i] > arr[i + 1]) //change + to - to change ascending to decending
			{
				mySwap(arr, i, i + 1);
				sorted = false;
			}
		}
	}
}


//Main master function
void main()
{
	//Declaration of Variables
	int firstLineVariable;
	int secondLineVariable;
	int thirdLineVariable;
	int fourthLineVariable;
	int tempVariable;
	int algorithmOrder;
	int arr1[10];
	vector<int> nums;

	//Reads in textfile and stores information into Variables
	ifstream readFile;
	readFile.open("input-a1q1.txt");
	readFile >> firstLineVariable;
	readFile >> secondLineVariable;
	readFile >> thirdLineVariable;

	//FOR statement that loops up to the (thirdLineVariable) integar amount, and the bracket code reads the numbers in the final line and adds those values to a VectorList
	for (int i = 0; i < thirdLineVariable; i++)
	{
		readFile >> tempVariable;
		nums.push_back(tempVariable);
		arr1[i] = tempVariable;
	}
	readFile.close();

	//IF statement to check if the first line is a valid input (0 or 1)
	if (firstLineVariable != 0 && firstLineVariable != 1)
	{
		cout << "ERROR cant decide to acend or decend sorting algorithm" << endl;
		return;
	}

	else
	{
		cout << "line One checking completed" << endl;
	}


	//if 0 will sort in ascending order
	if (firstLineVariable == 0)
	{
		cout << "Will perform Ascending sort" << endl;
		algorithmOrder = 0;
		
	}

	//if 1 will sort in decending order
	if (firstLineVariable == 1)
	{
		cout << "Will perform Descending sort" << endl;
		algorithmOrder = 1;
	}

	//IF statement to check if the second line is a valid input (0 or 1)
	if (secondLineVariable != 0 && secondLineVariable != 1)
	{
		cout << "ERROR cant decide to go easy or complex sorting algorithm" << endl;
		return;
	}

	else
	{
		cout << "line Two checking completed" << endl;
	}

	//IF statement to check if datacount is higher than 0 otherwise will error
	if (thirdLineVariable <= -1)
	{
		cout << "data count is to low" << endl;
		return;
	}

	else
	{
		cout << "line three checking completed" << endl;
		cout << "will begin sorting " << thirdLineVariable << " numbers" << endl;
	}


	//if 0 will pick an easy algorithm and use bubble sort
	if (secondLineVariable == 0)
	{
		//Time Recording starts now
		cout << "Will perform using bubble sort" << endl;
		std::chrono::steady_clock::time_point begin0 = std::chrono::steady_clock::now();

		//Function bubblesort is run
		cout << "unsorted:" << endl;
		displayArray(arr1, 10);
		cout << "BubbleSorted:" << endl;
		bubbleSort(arr1, 10);
		displayArray(arr1, 10);

		//Time Recording stops and Ms is output
		std::chrono::steady_clock::time_point end0 = std::chrono::steady_clock::now();
		std::cout << "Milliseconds = " << std::chrono::duration_cast<std::chrono::milliseconds>(end0 - begin0).count() << "[ms]" << std::endl;
	}


	//if 1 will pick a complex algorithm, planned for future releases
	if (secondLineVariable == 1)
	{
		//Time Recording starts now
		cout << "Will perform using complex sort" << endl;
		std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();


		//Function bubblesort is run
		cout << "unsorted:" << endl;
		displayArray(arr1, 10);
		cout << "ComplexSorted:" << endl;
		bubbleSort(arr1, 10);
		displayArray(arr1, 10);

		//Time Recording stops and Ms is output
		std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();
		std::cout << "Milliseconds = " << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - begin1).count() << "[ms]" << std::endl;
	}
	return;
}