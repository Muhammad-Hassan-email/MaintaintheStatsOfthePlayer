#include <stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

string Firstname[20] =      {"Babar", "Muhammad", "Virat ", "Jasprit", "David", "Mitchell", "David", "Kagiso", "Kane", "Trent", "Rashid", "Shaheen", "Jos", "Kieron", "Thisara"};

string Lastname[20] =      {"Azam", "Rizwan", "Kohli", "Bumrah", "Warner", "Starc", "Miller", "Rabada", "Williamson", "Boult", "Khan", "Afridi", "Buttler", "Pollard", "Perera"};

	
string country[20] =   {"PAK", "PAK", "IND", "IND", "AUS", "AUS", "RSA", "RSA", "NZ", "NZ", "AFG", "PAK", "ENG", "WI", "SL"};
	
int matches[20] =      {73, 55, 95, 55, 88, 50, 95, 40, 74, 44, 56, 39, 88, 98, 84};

int runs[20] =         {2620, 1639, 3227, 8, 2554, 84, 1786, 121, 2021, 30, 182, 19, 2140, 1537, 1204};
	
float average[20] =    {45.2, 51.2, 52.0, 4.0, 32.7, 9.3, 31.9, 30.2, 32.6, 6.0, 12.0, 19.0, 34.5, 25.2, 23.15};
	
float strikeRate[20] = {129.1, 128.9, 137.9, 61.5, 140.8, 102.4, 140.6, 116.3, 123.9, 75.0, 123.8, 105.5, 141.2, 135.7, 151.6};
	
int wickets[20] =      {0, 0, 4, 66, 0, 60, 0, 49, 6, 62, 103, 45, 0, 42, 51};
	
float economy[20] =    {0.0, 0.0, 8.13, 6.52, 0.0, 7.57, 0.0, 8.57, 8.33, 8.12, 6.20, 7.82, 0.0, 8.28, 9.34};


void printPlayer(int index)
{
	cout << Firstname[index] << " " <<Lastname[index] << "\t";
	cout << "(" << country[index] << ")\t\t";
	cout << matches[index] << "\t";
	cout << runs[index] << "\t";
	cout << average[index] << "\t";
	cout << strikeRate[index] << "\t";
	cout << wickets[index] << "\t";
	cout << economy[index] << "\t";
	cout << endl;
}

int PlayersData(int count)
{
	
	string playername;
	string countryname;

	if(count==20)
	{
		cout << "No space available." <<endl;	
		return count;
	}	
	else if(count<20)
	{
		cout<<"Enter the new data"<<endl;	
	cout<<"Enter the First name of the player:";
	cin>>playername;
	Firstname[count]=playername;
	
	cout<<"Enter the Last name of the player:";
	cin>>playername;
	Lastname[count]=playername;
	

	cout<<"How many matches play:";
	cin>>matches[count];

	cout<<"Enter the average of the player:";
	cin>>average[count];

	cout<<"Enter the runs of the player:";
	cin>>runs[count];

	cout<<"Enter the strike rate of the player:";
	cin>>strikeRate[count];
		
	cout<<"Enter the wickets of the player:";
	cin>>wickets[count];
	
	cout<<"Enter the economy of the player:";
	cin>>economy[count];
	
	cout<<"Enter the name of the the country:";
	cin>>countryname;
	country[count]=countryname; 

	cout << "The player has been added successfully."<<endl;
	count++;
	
	return count;	
	}
	
}


void SearchPlayer(int count)
{
	string player;
	cout<<"Enter the First Name: ";
	cin>>player;
	cout << player<<endl;
	for (int k = 0; k < count; k++)
	{
		if (Firstname[k] == player)
		{
			
			cout<<"\nPlayer Name\tCountry\t\tMatches\tRuns\tAverage\tSR\tWickets\tEconomy"<<endl;
			printPlayer(k);
			return;
		}
	}
	cout << "Player not found." << endl;
}


int partitionMatches (int low, int high)
{
	int pivot = matches[high]; 
	int i = (low - 1); 
	for (int j = low; j <= high - 1; j++)
	{
		
		if (matches[j] <= pivot)
		{
			i++; 
			swap(matches[i], matches[j]);
			swap(Firstname[i], Firstname[j]);
			swap(Lastname[i], Lastname[j]);
			swap(runs[i], runs[j]);
			swap(average[i], average[j]);
			swap(country[i], country[j]);
			swap(strikeRate[i], strikeRate[j]);
			swap(wickets[i], wickets[j]);
			swap(economy[i], economy[j]);
		}
	}
	swap(matches[i + 1], matches[high]);
	swap(Firstname[i+1], Firstname[high]);
	swap(Lastname[i+1], Lastname[high]);
	swap(runs[i + 1], runs[high]);
	swap(average[i+1], average[high]);
	swap(country[i+1], country[high]);
	swap(strikeRate[i+1], strikeRate[high]);
	swap(wickets[i+1], wickets[high]);
	swap(economy[i+1], economy[high]);
	
	return (i + 1);
}



void quickSortMatches(int low, int high)
{
	if (low < high)
	{
		int location = partitionMatches(low, high);

		quickSortMatches(low, location - 1);
		quickSortMatches(location + 1, high);
	}
}




int partitionRuns (int low, int high)
{
	int pivot = runs[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		
		if (runs[j] <= pivot)
		{
			i++; 
			swap(runs[i], runs[j]);
			swap(Firstname[i], Firstname[j]);
			swap(Lastname[i], Lastname[j]);
			swap(country[i], country[j]);
			swap(matches[i], matches[j]);
			swap(average[i], average[j]);
			swap(strikeRate[i], strikeRate[j]);
			swap(wickets[i], wickets[j]);
			swap(economy[i], economy[j]);
		}
	}
	swap(runs[i + 1], runs[high]);
	swap(Firstname[i+1], Firstname[high]);
	swap(Lastname[i+1], Lastname[high]);
	swap(country[i+1], country[high]);
	swap(matches[i + 1], matches[high]);
	swap(average[i+1], average[high]);
	swap(strikeRate[i+1], strikeRate[high]);
	swap(wickets[i+1], wickets[high]);
	swap(economy[i+1], economy[high]);
	
	return (i + 1);
}

void quickSortRuns(int low, int high)
{
	if (low < high)
	{
		int location = partitionRuns(low, high);

		quickSortRuns(low, location - 1);
		quickSortRuns(location + 1, high);
	}
}

int partitionEconomy (int low, int high)
{
	int pivot = economy[high]; 
	int i = (low - 1); 
	for (int j = low; j <= high - 1; j++)
	{
		if (economy[j] <= pivot)
		{
			i++; 
			swap(economy[i], economy[j]);
			swap(matches[i], matches[j]);
			swap(Firstname[i], Firstname[j]);
			swap(Lastname[i], Lastname[j]);
			swap(runs[i], runs[j]);
			swap(average[i], average[j]);
			swap(country[i], country[j]);
			swap(strikeRate[i], strikeRate[j]);
			swap(wickets[i], wickets[j]);
		}
	}
	swap(economy[i+1], economy[high]);
	swap(matches[i + 1], matches[high]);
	swap(Firstname[i+1], Firstname[high]);
	swap(Lastname[i+1], Lastname[high]);		
	swap(runs[i + 1], runs[high]);
	swap(average[i+1], average[high]);
	swap(country[i+1], country[high]);
	swap(strikeRate[i+1], strikeRate[high]);
	swap(wickets[i+1], wickets[high]);
	
	return (i + 1);
}

void quickSortEconomy(int low, int high)
{
	if (low < high)
	{
		int location = partitionEconomy(low, high);

		quickSortEconomy(low, location - 1);
		quickSortEconomy(location + 1, high);
	}
}


int partitionAverage (int low, int high)
{
	int pivot = average[high]; 
	int i = (low - 1); 
	for (int j = low; j <= high - 1; j++)
	{
		
		if (average[j] <= pivot)
		{
			i++; 
			swap(average[i], average[j]);
			swap(matches[i], matches[j]);
			swap(Firstname[i], Firstname[j]);
			swap(Lastname[i], Lastname[j]);
			swap(runs[i], runs[j]);
			swap(country[i], country[j]);
			swap(strikeRate[i], strikeRate[j]);
			swap(wickets[i], wickets[j]);
			swap(economy[i], economy[j]);
		}
	}
	swap(average[i+1], average[high]);
	swap(matches[i + 1], matches[high]);
	swap(Firstname[i+1], Firstname[high]);
	swap(Lastname[i+1], Lastname[high]);		
	swap(runs[i + 1], runs[high]);
	swap(country[i+1], country[high]);
	swap(strikeRate[i+1], strikeRate[high]);
	swap(wickets[i+1], wickets[high]);
	swap(economy[i+1], economy[high]);
	
	return (i + 1);
}

void quickSortAverage(int low, int high)
{
	if (low < high)
	{
		int location = partitionAverage(low, high);

		quickSortAverage(low, location - 1);
		quickSortAverage(location + 1, high);
	}
}


int partitionWickets (int low, int high)
{
	int pivot = wickets[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		
		if (wickets[j] <= pivot)
		{
			i++; 
			swap(wickets[i], wickets[j]);
			swap(matches[i], matches[j]);
			swap(Firstname[i], Firstname[j]);
			swap(Lastname[i], Lastname[j]);
			swap(runs[i], runs[j]);
			swap(average[i], average[j]);
			swap(country[i], country[j]);
			swap(strikeRate[i], strikeRate[j]);
			swap(wickets[i], wickets[j]);
			swap(economy[i], economy[j]);
		}
	}
	swap(wickets[i+1], wickets[high]);
	swap(Firstname[i+1], Firstname[high]);
	swap(Lastname[i+1], Lastname[high]);
	swap(matches[i + 1], matches[high]);
	swap(runs[i + 1], runs[high]);
	swap(average[i+1], average[high]);
	swap(country[i+1], country[high]);
	swap(strikeRate[i+1], strikeRate[high]);
	swap(economy[i+1], economy[high]);
	
	return (i + 1);
}

void quickSortWickets(int low, int high)
{
	if (low < high)
	{
		int location = partitionWickets(low, high);

		quickSortWickets(low, location - 1);
		quickSortWickets(location + 1, high);
	}
}

int partitionstrikeRate (int low, int high)
{
	int pivot = strikeRate[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		
		if (strikeRate[j] <= pivot)
		{
			i++; 
			swap(strikeRate[i], strikeRate[j]);
			swap(matches[i], matches[j]);
			swap(Firstname[i], Firstname[j]);
			swap(Lastname[i], Lastname[j]);
			swap(runs[i], runs[j]);
			swap(average[i], average[j]);
			swap(country[i], country[j]);
			swap(wickets[i], wickets[j]);
			swap(economy[i], economy[j]);
		}
	}
	swap(strikeRate[i+1], strikeRate[high]);
	swap(matches[i + 1], matches[high]);
	swap(Firstname[i+1], Firstname[high]);
	swap(Lastname[i+1], Lastname[high]);
	swap(runs[i + 1], runs[high]);
	swap(average[i+1], average[high]);
	swap(country[i+1], country[high]);
	swap(wickets[i+1], wickets[high]);
	swap(economy[i+1], economy[high]);
	
	return (i + 1);
}

void quickSortstrikeRate(int low, int high)
{
	if (low < high)
	{
		int location = partitionstrikeRate(low, high);

		quickSortstrikeRate(low, location - 1);
		quickSortstrikeRate(location + 1, high);
	}
}



int main()
{
	int count = 15;
	char option=' ';
	mainmenu:
	cout << "\t\t--------------------------------------------" <<endl;
	cout << "\t\t\t\tWelcome to the stats portal." <<endl;
	cout << "\t\t--------------------------------------------" <<endl;
	
	cout << "Choose the options from the below list." <<endl;
	cout << "a. Search a player." <<endl;
	cout << "b.Insert a player information." <<endl;
	cout << "c.Sort the data according to your choice." <<endl;
	cout << "d.Print all info."<<endl;
	cout << "e.Exit the program."<<endl;
	cin>>option;
	
	if(option=='a')
	{
		SearchPlayer(count);
		goto mainmenu;
	}
	else if(option == 'b')
	{
		count=PlayersData(count);
		goto mainmenu;
	}
	else if(option == 'c')
	{
		sortmenu:
		int optionnum=0;
		cout << "Enter how do you want to sort your data:" <<endl;
		cout << "1.Matches 2.Runs 3.Average 4.Economy 5.Strike Rate 6.Wickets" <<endl;
		cin>>optionnum;
	
		if(optionnum==1)
		{
			cout<<"The data set sorted according to matches are:"<<endl;
			quickSortMatches(0,count-1);
			cout<<"\nPlayer Name\tCountry\t\tMatches\tRuns\tAverage\tSR\tWickets\tEconomy"<<endl;
			for(int i=0;i<count;i++)
			{
				printPlayer(i);	
			}
			goto mainmenu;
		}
	
		else if(optionnum==2)
		{
			cout<<"The data set sorted according to Runs are:"<<endl;
			quickSortRuns(0,count-1);
			cout<<"\nPlayer Name\tCountry\t\tMatches\tRuns\tAverage\tSR\tWickets\tEconomy"<<endl;
			for(int i=0;i<count;i++)
			{
				printPlayer(i);	
			}
			goto mainmenu;
		}	
		else if(optionnum==3)
		{
			cout<<"The data set sorted according to Average are:"<<endl;
			quickSortAverage(0,count-1);
			cout<<"\nPlayer Name\tCountry\t\tMatches\tRuns\tAverage\tSR\tWickets\tEconomy"<<endl;
			for(int i=0;i<count;i++)
			{
				printPlayer(i);	
			}
			goto mainmenu;
		}
		else if(optionnum==4)
		{
			cout<<"The data set sorted according to Economy are:"<<endl;
			quickSortEconomy(0,count-1);
			cout<<"\nPlayer Name\tCountry\t\tMatches\tRuns\tAverage\tSR\tWickets\tEconomy"<<endl;
			for(int i=0;i<count;i++)
			{
				printPlayer(i);	
			}
			goto mainmenu;
		}	
		else if(optionnum==5)
		{
			cout<<"The data set sorted according to Strike Rate are:"<<endl;
			quickSortstrikeRate(0,count-1);
			cout<<"\nPlayer Name\tCountry\t\tMatches\tRuns\tAverage\tSR\tWickets\tEconomy"<<endl;
			for(int i=0;i<count;i++)
			{
				printPlayer(i);	
			}
			goto mainmenu;
		}
			else if(optionnum==6)
		{
			cout<<"The data set sorted according to Strike Rate are:"<<endl;
			quickSortWickets(0,count-1);
			cout<<"\nPlayer Name\tCountry\t\tMatches\tRuns\tAverage\tSR\tWickets\tEconomy"<<endl;
			for(int i=0;i<count;i++)
			{
				printPlayer(i);	
			}
			goto mainmenu;
		}
		else
		{
			cout<<"The option you have chosen is invalid."<<endl;
			goto sortmenu;
		}					
	}
		
	
	else if(option == 'd')
	{
		cout<<"\nPlayer Name\tCountry\t\tMatches\tRuns\tAverage\tSR\tWickets\tEconomy"<<endl;
		for(int i=0;i<count;i++)
		{
			printPlayer(i);	
		}
		goto mainmenu;
	}
	return 0;
}
