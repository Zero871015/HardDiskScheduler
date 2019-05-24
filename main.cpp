#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

vector<pair<int,int>> ReadFile(ifstream& fin);
int Distance(vector<pair<int,int>> v);
vector<pair<int,int>> stairSort(vector<pair<int,int>> nums, int Qos, int offset = 0, bool isIncreaseFirst = true);
vector<pair<int, int>> randomSort(vector<pair<int, int>> nums, int Qos);
bool canPlaceHere(pair<int, int> num, int place, int Qos);
bool chacker(vector<pair<int, int>> nums, int Qos);

int main(int argc, char* argv[])
{
	srand(time(NULL));	//set random number seed.

	//Read file
	int Qos;
	if (argc < 2)
	{
		cout << "Parameter error!" << endl;
		return -1;
	}
	else if (argc == 2)
	{
		cout << "Qos: ";
		cin >> Qos;
	}
	else
	{
		Qos = stoi(argv[2]);
	}
	ifstream fin(argv[1]);
	if (!fin)
	{
		cout << "File error!" << endl;
		return -2;
	}

	vector<pair<int,int>> numbers = ReadFile(fin);
	vector<pair<int,int>> ans = numbers;
	//Stair Sort
	for (int i = 0; i < Qos; i++)
	{
		vector<pair<int,int>> temp = stairSort(numbers, Qos, i, false);
		if (Distance(temp) < Distance(ans) && chacker(temp,Qos))ans = temp;
		temp = stairSort(numbers, Qos, i, true);
		if (Distance(temp) < Distance(ans) && chacker(temp, Qos))ans = temp;
	}

	//Random Sort
	for (int i = 0; i < 100; i++)
	{
		vector<pair<int, int>> temp = randomSort(numbers, Qos);
		if (Distance(temp) < Distance(ans) && chacker(temp, Qos))ans = temp;
	}

	//Show result
	cout << Distance(ans) << endl;
	for (int i = 0; i < (int)ans.size(); i++)
	{
		cout << i + 1 << ":" << ans[i].second + 1 << endl;
	}

	system("PAUSE");
	return 0;
}

//TODO: Follow the format read file, return a vector mean disk position.
vector<pair<int,int>> ReadFile(ifstream& fin)
{
	vector<pair<int,int>> v;
	for (int i = 0; !fin.eof(); i++)
	{
		string str;
		fin >> str;
		if (str == "")continue;
		for (int j = 0; j < (int)str.length(); j++)
		{
			if (str[j] == ':')
			{
				str = str.substr(j + 1, str.length() - 1);
				break;
			}
		}
		pair<int, int> p(stoi(str), i);
		v.push_back(p);
	}
	return v;
}

//TODO: Given a vector, return the disk distance.
int Distance(vector<pair<int,int>> v)
{
	if (v.size() == 1)return v[0].first;
	else if (v.size() == 0)return 0;
	int sum = 0;
	for (int i = 1; i < (int)v.size(); i++)
	{
		sum += abs(v[i].first - v[i-1].first);
	}
	return sum + v[0].first;
}

//TODO: Devide vector to some groups, and sort every group incrementally and decreasingly respectively.
//The number of groups depend on Qos.
//You can devide first group by offset to make more combination.
vector<pair<int,int>> stairSort(vector<pair<int,int>> nums,int Qos,int offset,bool isIncreaseFirst)
{
	int group_size = (int)ceil((float)nums.size() / Qos) + 1;	//plus one for offset
	vector<pair<int,int>> *groups = new vector<pair<int, int>>[group_size]();
	vector<pair<int, int>> ans;

	//get offset group
	for (int i = 0; i < offset; i++)
	{
		pair<int, int> p(nums[i].first, nums[i].second);
		groups[0].push_back(p);
	}

	//devide nums by Qos
	for (int i = offset; i < (int)nums.size(); i++)
	{
		pair<int, int> p(nums[i].first, nums[i].second);
		groups[(i / Qos) + 1].push_back(p);
	}

	//sort every group
	for (int i = 0; i < group_size; i++)
	{
		if((bool)(i%2) ^ isIncreaseFirst)
			sort(groups[i].begin(), groups[i].end());
		else
			sort(groups[i].rbegin(), groups[i].rend());
	}

	//combine all groups
	for (int i = 0; i < group_size; i++)
	{
		for (int j = 0; j < (int)groups[i].size(); j++)
		{
			ans.push_back(groups[i][j]);
		}
	}

	return ans;
}

//TODO: Randomly pick up two numbers and exchange them.
//If the number already moved, skip it.
//This function may follow Qos to change numbers.
vector<pair<int, int>> randomSort(vector<pair<int, int>> nums, int Qos)
{
	for (int i = 0; i < (int)nums.size(); i++)
	{
		if (nums[i].second == i)
		{
			int min = MAX(0, i - Qos);
			int max = MIN((int)nums.size() - 1, i + Qos);
			int r = rand() % (max - min + 1) + min;

			if (canPlaceHere(nums[r], i, Qos))
			{
				pair<int, int> temp = nums[i];
				nums[i] = nums[r];
				nums[r] = temp;
			}
		}
	}
	return nums;
}

//TODO: Chack the number can be this place or not.
bool canPlaceHere(pair<int, int> num, int place, int Qos)
{
	return (num.second - Qos <= place) && (num.second + Qos >= place);
}

//TODO: Chack the vector is vaild or not.
//This function should always return true, use it just in case.
bool chacker(vector<pair<int, int>> nums, int Qos)
{
	for (int i = 0; i < (int)nums.size(); i++)
	{
		if (nums[i].second - Qos > i || nums[i].second + Qos < i)
			return false;
	}
	return true;
}