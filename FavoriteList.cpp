#include <iostream>
#include <string>
#include "FavoriteThing.h"
#include "FavoriteList.h"

using namespace std;

favoriteList::favoriteList()
{
	numAlbums = 0;
}

void favoriteList::addAlbum()
{
	//Need to ask the user for input, then validate information, and THEN set it.
	//albums[numAlbums].setAlbumInfo();
	//Created variables to send to the set functions
	int i, y;
	string t, a, g;
	bool validated = true; //Bool variable to validate album/object
	cout << "Album ID#: ";
	cin >> i; //Below is my cin.fail loop to make sure the user can only put in a valid value to continue. 
	//Year variable has the same loop.
	if (cin.fail())
	{
		cout << "Please select a valid number!" << endl;
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> i;
		} while (cin.fail());
	}
	cin.ignore(); //cin.ignore to make sure the input stream is prepped for new input. This is repeated down below
	cout << "Album Title : ";
	getline(cin, t, '\n');
	cout << "Arist Name: ";
	getline(cin, a, '\n');
	cout << "Year: ";
	cin >> y;
	if (cin.fail())
	{
		cout << "Please select a valid number!" << endl;
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> i;
		} while (cin.fail());
	}
	cin.ignore();
	cout << "Genre: ";
	getline(cin, g, '\n');


	//Using d b/c i is already a variable outside this loop.
	//This loop and nested loop(s) will be used to check for duplication
	for (int d = 0; d < numAlbums; d++)
	{
		if (albums[d].getID() == i)
		{
			validated = false;
			cout << "Please select a valid ID #" << endl;
		}
		if (albums[d].getTitle() == t && albums[d].getArtist() == a)
		{
			validated = false;
			cout << "This album already exists. An artist can't have an album with the same exact title." << endl;
		}
		if (validated == false)
		{
			break;
		}

	};
	
	//sets the values into the variables
	if (validated == true) 
	{
		albums[numAlbums].setID(i);
		albums[numAlbums].setTitle(t);
		albums[numAlbums].setArtist(a);
		albums[numAlbums].setYear(y);
		albums[numAlbums].setGenre(g);

		numAlbums++;
	}
}

//Shows the list of albums
void favoriteList::showList()
{
	for (int i = 0; i < numAlbums; i++)
	{
		cout << albums[i] << endl;
		totalAlbums = i;
	}
}

void favoriteList::deleteAlbum(int del)
{

}