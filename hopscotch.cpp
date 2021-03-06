/* Hopscotch Hashing
   Jeffrey Dickason
   CSCE 3110.002
   Program 2
   10/4/14 
  */

//essentially this program takes in user input, then mods it, and performs appropriate insert/delete/search functions

#include <iostream>		//include libraries
#include <string>
#include <iomanip>		//not even sure why i put this one in?

using namespace std;	//so i dont have to type std::cout or whatever

void hopHash(int modValue, int element[17], string element2[17]);

int main(){

	int element[17];		//initialize variables
	string element2[17];
	string temp;
	
	int quit = 0;			//exit code
	int tempMod;

	int value = 0;			//user input variables
	int modValue = 0;
	

	int menuChoice;			//explains itself

	for(int i=0; i < 17; i++)		//fill the dual array's with zero's
	{
		element[i] = 0;
		element2[i] = "0000";
	} //for

	//Program description
	cout << endl << endl << "Hopscotch Hashing C++ program written by Jeffrey Dickason" << endl << "CSCE 3110.002" << endl << "Program 2" << endl <<"10/4/14" << endl;
	do{							//loop dat menu


	cout << "HOPSCOTCH HASHING MENU" << endl;
	cout << "1 - Insert Value" << endl;
	cout << "2 - Delete Value" << endl;
	cout << "3 - Search Value" << endl;
	cout << "4 - Output Table" << endl;
	cout << "5 - Exit Program" << endl;
	cin >> menuChoice;					//take user input
	switch(menuChoice)
	{
		case 1:			//attempt to insert an element into the arrays
			cout << "Enter a positive Decimal Value to insert" << endl;
			cin >> value;
			while(value <= 0)					//input is INVALID, keep trying 
			{
				cout << "Error, please re-enter decimal value" << endl;
				cin >> value;					//keep trying until
			} //while
			
			//cout << "Decimal entered is " << value << endl;		//debug value statement
			modValue = value%17;			//mod it to check hash index
			
			if(modValue == 16 && element[modValue] != 0)	//can't do the end of the table my friend
			{
				cout << "Error, hit end of table and insert failed" << endl; //print ERROR
				break;
			}

			//	cout << "Modded value is " << modValue << endl;			//debug modValue
				if(element[modValue] == 0)	//bucket empty, inserting into spot
				{
					element[modValue] = value;
					cout << value << " inserted at position " << modValue << endl;
					hopHash(modValue, element, element2);
				}

				else
				{
					tempMod = modValue;
					for(int j = 0; j < 3; j++)
					{
						tempMod++; 	//incrementing tempMod
						if(tempMod == 16 && element[tempMod] != 0)	//can't do the end of the table my friend
						{
							cout << "Error, hit end of table and insert failed" << endl; //print ERROR
							break;
						}

					if(element[tempMod] == 0)
						{
						element[tempMod] = value;
						cout << value << " inserted at position " << tempMod << endl;
						hopHash(modValue, element, element2);
						break;
						}
					if(j == 3)
						cout << "Error, All buckets full, insert failed" << endl;
					}
				}

			break;

		case 2:		//delete
			cout << "Enter Decimal Value to be deleted" << endl;
			cin >> value;
			while(value <= 0)
			{
				cout << "Error, please re-enter decimal value" << endl;
				cin >> value;
			}

			//cout << "Decimal entered is " << value << endl;
			modValue = value%17;
			//cout << "Modded value is " << modValue << endl;
			
			tempMod = modValue;
			for(int i=0; i < 4; i++)
			{
				if(tempMod == 16 && element[tempMod] != value)	//can't do the end of the table my friend
						{
							cout << "Error, hit end of table and delete failed" << endl; //print ERROR
							break;
						}

				if(element[tempMod] == value)
				{
					element[tempMod] = 0;
					cout << value << " deleted from position " << tempMod << endl;
					hopHash(modValue, element, element2);
				}
				if(i == 4)
				{
					cout << "Error, element not found in table, Delete failed" << endl;
				}
				tempMod++;
			}
			break;

		case 3:		//search
			cout << "Enter Decimal Value to search for" << endl;
			cin >> value;
			while(value <= 0)
			{
				cout << "Error, please re-enter decimal value" << endl;
				cin >> value;
			}

			//cout << "Decimal entered is " << value << endl;
			modValue = value%17;
			//cout << "Modded value is " << modValue << endl;
				if(element[modValue] == value)
				{
					cout << value << " found at position " << modValue << endl;
				}
				else
				{
					//cout << value << " not found at original index, checking next 3" << endl;	//debug
					for(int k = 0; k < 3; k++)		//loop to find it
						{
							modValue += 1;
							if(element[modValue] == value)
							{
								cout << value << " found at position " << modValue << endl;
							}
						}

				}
			break;

		case 4:		//print
			cout << "HOPSCOTCH TABLE:" << endl;				//format the table correctly
			cout << "+------------------------+" << endl;
			cout << "|   #  |  value  |  hop  |" << endl;
			cout << "+------------------------+" << endl;

			for(int i = 0; i < 17; i ++)
				cout << "|" << setw(4) << i << setw(4) << "|"  << setw(5) << element[i] << setw(4) << "|" << setw(5) << element2[i] << setw(3) << "|" << endl;
			cout << "+------------------------+" << endl;
			break;

		case 5:		//exit statement
			quit = 1;
			cout << "Program Terminated by User..." << endl;
			break;

		default:	//error printing
			cout <<"Error, incorrect entry" << endl;
			break;
	}


	}while(quit != 1);

return 0;
}




/// hopHash checks the next 3 entries to see hash value assigned
/// param1 modded value of user input
/// param2 original integer array
/// param3 pass by reference address of the array of strings to manipulate before returning

//should be easy to fix this, just dont remember how to pass an int array as a function argument.... Fucccck!
	void hopHash(int modValue, int element[17], string element2[17])
	{
		//cout << "Entering hopHash Function" << endl;
		string temp = "";
		int k = modValue + 4;		//temp modvalue looooooper
		int tempMod;
		//cout << "Entered function, time to partay" << endl;
		for(int i=modValue; i < k; i++){	//loop next few array values
			if(i == 0){				//case 1: bucket is 0, elements are 0,
				for(int j = 0; j < 4; j++)
				{
					tempMod = element[j];
					if(tempMod%17 == modValue && element[j] != 0)	//if it finds it
						temp = temp+"1";
					else
						temp = temp+"0";
				}
			break;
			}
			if(i > 16)				//case 2: Hit end of list
				temp = temp+"0";
			else{					//case 3: legitimate value
				tempMod = element[i];
				if(tempMod%17 == modValue){	//check 
					temp = temp+"1";

				}
				else
					temp = temp+"0";
			}
		}
		element2[modValue] = temp;		//assign final string to 2nd array
	}