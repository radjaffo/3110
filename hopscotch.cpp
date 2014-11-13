/* Hopscotch Hashing
   Jeffrey Dickason
   CSCE 3110.002
   Program 2
   10/4/14
  */

#include <iostream>
#include <string>
#include <iomanip>		//we need moar libaraies!

using namespace std;

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
		case 1:							//attempt to insert an element into the arrays
			cout << "Enter a positive Decimal Value to insert" << endl;
			cin >> value;
			while(value <= 0)					//input is INVALID, keep trying 
			{
				cout << "Error, please re-enter decimal value" << endl;
				cin >> value;					//keep trying until
			} //while
			
			cout << "Decimal entered is " << value << endl;		//debug value statement
			modValue = value%17;			//mod it to check hash index
			
			if(modValue == 16 && element[modValue] != 0)	//can't do the end of the table my friend
			{
				cout << "Error, hit end of table and insert failed" << endl; //print ERROR
				break;
			}

				cout << "Modded value is " << modValue << endl;			//debug modValue
				if(element[modValue] == 0)	//bucket empty, inserting into spot
				{
					element[modValue] = value;
					hopHash(modValue, element, element2);
				}

				else
				{
					tempMod = modValue;
					cout << "bucket is occupied, linear probing time" << endl;
					for(int j = 0; j < 3; j++)
					{
						tempMod++; 	//incrementing tempMod
					if(element[tempMod] == 0)
						{
						element[tempMod] = value;
						hopHash(modValue, element, element2);
						break;
						}
					if(j == 3)
						cout << "All buckets full, nowhere to insert to :(" << endl;
					}
				}

			break;

		case 2:
			cout << "Enter Decimal Value to be deleted" << endl;
			cin >> value;
			while(value <= 0)
			{
				cout << "Error, please re-enter decimal value" << endl;
				cin >> value;
			}

			cout << "Decimal entered is " << value << endl;
			modValue = value%17;
			cout << "Modded value is " << modValue << endl;
				if(element[modValue] == value)
				{
					element[modValue] = 0;
					cout << value << " deleted from array" << endl << endl;
					hopHash(modValue, element, element2);
				}
				else
					cout << "delete went wrong" << endl << endl;
			break;

		case 3:
			cout << "Enter Decimal Value to search for" << endl;
			cin >> value;
			while(value <= 0)
			{
				cout << "Error, please re-enter decimal value" << endl;
				cin >> value;
			}

			cout << "Decimal entered is " << value << endl;
			modValue = value%17;
			cout << "Modded value is " << modValue << endl;
				if(element[modValue] == value)
				{
					cout << value << " found at index " << modValue << endl;
				}
				else
				{
					cout << value << " not found at original index, checking next 3" << endl;
					for(int k = 0; k < 3; k++)
						{
							modValue += 1;
							if(element[modValue] == value)
							{
								cout << value << " found at index " << modValue << endl;
							}
						}

				}
			break;

		case 4:
			cout << "HOPSCOTCH TABLE:" << endl;
			cout << "+------------------------+" << endl;
			cout << "|   #  |  value  |  hop  |" << endl;
			cout << "+------------------------+" << endl;

			for(int i = 0; i < 17; i ++)
				cout << "|" << setw(4) << i << setw(4) << "|"  << setw(5) << element[i] << setw(4) << "|" << setw(5) << element2[i] << setw(3) << "|" << endl;
			cout << "+------------------------+" << endl;
			break;

		case 5:
			quit = 1;
			cout << "Program Terminated by User..." << endl;
			break;

		default:
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
		cout << "Entering hopHash Function" << endl;
		string temp = "";
		int k = modValue + 4;		//temp modvalue looooooper
		int tempMod;
		cout << "Entered function, time to partay" << endl;
		for(int i=modValue; i < k; i++){	//loop next few array values
			
			if(i > 16)
				temp = temp+"0";
			else{
				tempMod = element[i];
				if(tempMod%17 == modValue){	//lets go a little deeper
					temp = temp+"1";

				}
				else
					temp = temp+"0";
			}
		}
		element2[modValue] = temp;
	}