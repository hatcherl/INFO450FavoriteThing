#include <iostream>
#include <string>
#include "FavoriteThing.h"
#include "FavoriteList.h"

using namespace std;

int main()
{
	//response so the user can choose if they want to continue or not
	char response;
	//created a myAlbums list
	favoriteList myAlbums;
	do {
		myAlbums.addAlbum();
		cout << "Would you like to make another? Select Y/y to continue. Press any other character+Enter to finish." << endl;
		cin >> response;
	} while (response == 'y' || response == 'Y');
	//Calling on the showList function
	myAlbums.showList();


	system("pause");
	return 0;
};