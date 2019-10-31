#include "DoublyLinkedList.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include "string.h"
#include <bits/stdc++.h> 

using namespace std;
int main(){
	DoublyLinkedList *List = new DoublyLinkedList();

	fstream file;
	string word, fs;
	int sec;

	// fs of the file 
	fs = "Number.txt";

	// opening file 
	file.open(fs.c_str());

	// extracting words form the file 
	while (file >> word)
	{
		// displaying content 
		List->Add(word);
		
		//cout << word;
	}


	do{
		cout << "1.Scroll left" << endl;
		cout << "2 Scroll right" << endl;
		cout << "3.write all" << endl;
		cin>>sec;
		switch(sec){
			case 1:
				List->MoveLeft();
			break;

			case 2:
				List->MoveRight();
				break;

			case 3:
				cout << *List;
				break;
			default:
				cout << endl << "Wrong chose!" << endl;
				cin.ignore();
				cin.get();
			break;
		}
		cout << endl;
	}while(sec != 0);
	delete List;
}