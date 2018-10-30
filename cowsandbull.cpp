#include<iostream>
#include<vector>
#include<ctime>
#include <chrono>
#include<ctype.h>
using namespace std;
using namespace std::chrono;

int main()
{
	vector<int> compSeq;	 //Computer Vector Initialization
	vector<int> userSeq;	//User Vector Initialization
	int a; 								//UserInput (4 integers at the same time)
	bool isBull = false; //Setting whether there's a bull
	srand(time(0));
	vector<int> numbers = { 0,1,2,3,4,5,6,7,8,9 }; //Numbers where to pick a random value for computer Vector
	for (int i = 0; i < 4; i++) {
		int randIndex = (int)(rand() % numbers.size());
		compSeq.push_back(numbers[randIndex]);
		numbers.erase(numbers.begin() + randIndex); //Delete the number from the numbers vector so that it doesn't get picked again
	}
	int bull = 0;
	int cow = 0;
	int tries = 0;


	while (bull > -1)
	{
		high_resolution_clock::time_point t1 = high_resolution_clock::now(); //Starting my time

		cout << "Enter a 4 digit number(unique digits): ";

		cin >> a;
		tries++;


		userSeq.push_back(a / 1000 % 10); userSeq.push_back(a / 100 % 10); userSeq.push_back(a / 10 % 10); userSeq.push_back(a % 10); //Getting each digit of userinput, a, as an index of user Vector



		cout << endl;

		for (int m = 0; m <= 3; m++)
		{

			for (int n = 0; n <= 3; n++)
			{
				if (compSeq[m] == userSeq[n])
				{
					if (m == n)  bull++;
					else cow++;
				}

			}
		}
		if (bull == 4)
		{
			high_resolution_clock::time_point t2 = high_resolution_clock::now();  //Stopping my time when user correctly inputs all the values in the correct index as the Computer Vector
			duration<int> time_span = duration_cast<duration<int>>(t2 - t1);
			int time = time_span.count();
			cout << endl;
			cout << "You guessed it in " << tries << " tries, taking " << time << " seconds" << endl;
			break;
		}

		cout << "bulls = "<< bull << " and cows = " << cow << endl;
		cout << endl;
		//reset everything before the next try
		userSeq.clear();
		bull = 0;
		cow = 0;
	}
	system("pause");
	return 0;
}
