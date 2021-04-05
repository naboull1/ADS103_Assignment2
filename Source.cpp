#include <iostream>
#include <string>
#include <chrono> //time stuff
#include <fstream> //file reading/writing stuff
#include <windows.h> //used this for sleep, you wont need it likely
#include <vector>//for storage

using namespace std;

void displayArray(int arr[], int arraySize)
{
	for (int i = 0; i <= arraySize - 1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void mySwap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void bubbleSort(int arr[], int arraySize)
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i <= arraySize - 1 - 1; i++)
		{
			if (arr[i] > arr[i + 1]) // change direction here for ascending/descending
			{
				mySwap(arr, i, i + 1);
				sorted = false;
			}
		}
	}

}

void main()

{
	
	ifstream readFile;
	readFile.open("input-a1q1.txt");
	int firstLineVariable;
	int secondLineVariable;
	int thirdLineVariable;
	int fourthLineVariable;
	int tempVariable;
	int arr1[10];
	vector<int> nums;
	readFile >> firstLineVariable;
	readFile >> secondLineVariable;
	readFile >> thirdLineVariable;
	
	cout << firstLineVariable << endl;
	cout << secondLineVariable << endl;
	cout << thirdLineVariable << endl;


	for (int i = 0; i < thirdLineVariable; i++)
	{
		
		readFile >> tempVariable;
		nums.push_back(tempVariable);
		arr1[i] = tempVariable;
	}



	//checks if 1st line is 0 or 1 and errors if not
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

	}


	//if 1 will sort in decending order
	if (firstLineVariable == 1)
	{
		cout << "Will perform Descending sort" << endl;

	}





	//checks if 2nd line is 0 or 1 and errors if not
	if (secondLineVariable != 0 && secondLineVariable != 1)
	{
		cout << "ERROR cant decide to go easy or complex sorting algorithm" << endl;
		return;
	}

	else
	{
		cout << "line Two checking completed" << endl;
	}


	//if 0 will pick an easy algorithm
	if (secondLineVariable == 0)
	{
		cout << "Will perform using bubble sort" << endl;
		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();



		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	}


	//if 1 will pick a complex algorithm
	if (secondLineVariable == 1)
	{
		cout << "Will perform using complex sort" << endl;
		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();




		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	}


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




	//show numbers
	cout << "numbers in file = " << thirdLineVariable << endl;
	cout << "Numbers before sorting: ";
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;

	//if (thirdLineVariable != permVariable)
	//{
	//	cout << "minimum number of sorting numbers not reached" << endl;
	//	system("pause");
	//}


	//ofstream  writeFile;
	//writeFile.open("output-a1q1.txt");
	readFile.close();

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	cout << "unsorted" << endl;
	displayArray(arr1, 10);
	cout << "BubbleSorted" << endl;
	bubbleSort(arr1, 10);
	displayArray(arr1, 10);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Milliseconds = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
}