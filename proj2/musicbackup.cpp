#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <array>

//Made my Samantha Mallett
//needs songs.txt to run

using namespace std;


struct Song {
        char    title[100]; //title of song
        char    artist[100]; //artist name
	char	album[100]; //album
        int     durmin; //duration minutes
        int     dursec; //duration minutes
        };

int display(char filename[], Song element[], int i); //display all songs
int newsong(char filename[], Song element[], int i); //add new song
void removesong(char filename[],Song element[], int i); //remove by index
void search(Song element[], int i); //search for a song

int main(){
int i =0;
Song element[100];
ifstream infile; //read from file, whats in file 
ofstream outfile; //write to file, whats going to file

char 	input=1;
char filename[100]="songs.txt";
//file tester

while (input !='q'){
	cout << "\n~Menu~\n";
	cout << "1. Display all songs" << endl;
	cout << "2. Add a new song" << endl;
	cout << "3. Remove a song" << endl;
	cout << "4. Search for a song" << endl;
	cout << "q. Exit program\n" << endl;
	cout << "What would you like to do?: ";
	cin >> input;

 
	switch (input){
	case '1':
		{
		display(filename, element, i);
		break;
		}

	case '2':
		{
		i=newsong(filename, element, i);
		i=display(filename, element, i);
		break;
		}

	case '3':
		{
		i=display(filename, element, i);
		removesong(filename, element, i);
		i=display(filename, element, i);
		break;
		}

	case '4':
		{
		i=display(filename, element, i);
		search(element, i);	
		break;
		}

	case 'q':
		{
		cout << "See you next time!" << endl;
		return 0;
		}

	default:
		{
		cout << "\nYou entered something wrong, try again please!" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		input = 1;
		break;
		}
	}
}

return 0;
}
//end of main


int display(char filename[], Song element[], int i){//read from file 
	ifstream infile;
	infile.open("songs.txt"); //thats how big the music library is
	i=0;
	while (!infile.eof()){
		cout << i+1 << ". ";
		infile.getline (element[i].title, 100, ';');
		cout  << element[i].title << " - ";
		
		infile.getline (element[i].artist, 100, ';');
		cout << element[i].artist << " | ";
		
		infile >> element[i].durmin;
		cout  << element[i].durmin << ":";
		infile.ignore(); //remove delim

		infile  >> element[i].dursec;
		cout  << element[i].dursec << " - ";
		infile.ignore(); //remove delim

		infile.getline (element[i].album, 100, '\n');
		cout << element[i].album << endl;
		
		int check = infile.peek();
		if (check == EOF){
			infile.ignore();
			break;
		}
		i++;		
	}
	
	infile.close();	
return i;
}

int newsong(char filename[], Song element[], int i){
//ofstream myfile;
//myfile.open ("example.bin", ios::out | ios::app | ios::binary); 
	ofstream outfile;
	outfile.open("songs.txt", ios::out | ios::app);

	cout << "\nEnter title of new song: ";
	cin >> element[i].title;
	outfile << element[i].title << ";";

	cout << "\nEnter artist of new song: ";
	cin >> element[i].artist;
	outfile << element[i].artist << ";";

	cout << "\nEnter Duration of new song(Mins Secs): ";
	cin >> element[i].durmin;
	cin >> element[i].dursec;
	outfile << element[i].durmin << ";" << element[i].dursec << ";";
	
	cout << "\nEnter album title of new song: ";
	cin >> element[i].album;
	outfile << element[i].album << "\n";	
	i++;
	outfile.close();
return i;
}

void removesong(char filename[], Song element[], int i){
	ofstream outfile;
	outfile.open("songs.txt");
	ifstream infile;
	infile.open("song.txt");
	int choice=0;
	int val = i;

	cout << "What song do you want to remove?(indexnumber): ";
	cin >> choice;
	while (choice > val+1 || choice <0){
		cout << "You entered something wrong, please try again:\n";
		cin >> choice;
	}
	cout <<'\n';
	for (int i=0;i < choice-1; i++){
		outfile << element[i].title << ";";
		outfile << element[i].artist << ";";
		outfile << element[i].durmin << ";";
		outfile << element[i].dursec << ";";
		outfile << element[i].album << "\n";
		}

	for(int i=choice-1;i <=val-1; i++){
		strcpy(element[i].title, element[i+1].title);
		outfile << element[i].title << ";";

		strcpy(element[i].artist, element[i+1].artist);
		outfile << element[i].artist << ";";
	
		element[i].durmin = element[i+1].durmin;
		outfile << element[i].durmin << ";";

		element[i].dursec = element[i+1].dursec;
		outfile << element[i].dursec << ";";

		strcpy(element[i].album, element[i+1].album);
		outfile << element[i].album << "\n";
		}
	val--;
	infile.close();
	outfile.close();
return;
}
void search(Song element[], int i) {
	char answer;
	char compair[100];
	cout << "\n1. Search by Album";
	cout << "\n2. Search by Artist";
	cout << "\nWhat would you like to search for?: ";
	cin >> answer;
	switch (answer){
	
	case '1':
		{
			cout << "\nWhat Album do you want to search for?: ";
			cin >> compair;
			for (int k=i, i =0; i < k; i++){
				if (strcmp(compair, element[i].album))
					cout << "\n" << element[i].title << " in " << element[i].album; 
			}
		} 
	case '2':
		{
	
		}
	default:
		{
		cout << "\nYou made an input error, try again!";
		}
	}
return;
}
