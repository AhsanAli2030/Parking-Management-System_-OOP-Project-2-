#include<iostream>
#include<string>
#include<ctime>
#include<stdlib.h>
#include<iomanip>
#include<fstream>

#pragma warning(disable : 4996)
using namespace std;
struct vehicle
{
	string Vehicle_Reg_No, Vehicle_Model;
	string Driver_Name, Vehicle_make, Vehicle_Colour, Vehicle_Entry_Time;
	string emptyLine1, emptyLine2;
	int price = 0;
	vehicle* nextptr = NULL;
};

vehicle* fptr = NULL;

void VEHICLE_ENTRY();
void Vehicle_Exit();
void Parking_Fee_Collected();
void Parking_stats();
fstream file; int p = 1;

int main()
{
	cout << "\n\n-----------------------_- Parking Management System -----------------------_-\n\n";
	file.open("Parking Management system.txt", ios::in);
	if (file)
	{
		cout << "\n*filecreated*\n";
		string read;  string temp; string read1;
		char ch;
		while (!file.eof())
		{
			//cout << "\n*filecreated  eof*\n";
			vehicle* Entryagain = new vehicle;
			getline(file, temp);



			/*	file.ignore(25);
				getline(file, read);
				Entryagain->Vehicle_Reg_No = read;*/
			getline(file, read);
			read1 = read.substr(25, 15);
			cout << read1;
			Entryagain->Vehicle_Reg_No = read1;

			/*	file.ignore(25);
				getline(file, read);
				Entryagain->Driver_Name = read;*/

			getline(file, read);
			read1 = read.substr(25, 15);
			cout << read1;
			Entryagain->Driver_Name = read1;

			/*	file.ignore(25);
				getline(file, read);
				Entryagain->Vehicle_Model = read;*/
			getline(file, read);
			read1 = read.substr(25, 15);
			cout << read1;
			Entryagain->Vehicle_Model = read1;


			/*file.ignore(25);
			getline(file, read);
			Entryagain->Vehicle_Colour = read;*/

			getline(file, read);
			read1 = read.substr(25, 15);
			cout << read1;
			Entryagain->Vehicle_Colour = read1;


			/*file.ignore(25);
			getline(file, read);
			Entryagain->Vehicle_Entry_Time = read;
			cin.ignore();
			cin.clear();*/
			getline(file, read);
			read1 = read.substr(25, 15);
			cout << read1;
			Entryagain->Vehicle_Entry_Time = read1;


			if (fptr == NULL)
			{
				fptr = Entryagain;
				Entryagain->nextptr = NULL;
			}
			else
			{
				vehicle* cptrNotFile = fptr;
				while (cptrNotFile->nextptr != NULL)
				{
					cptrNotFile = cptrNotFile->nextptr;
				}
				cptrNotFile->nextptr = Entryagain;
				Entryagain->nextptr = NULL;
			}
			getline(file, read);
			char temp[1024];
			strcpy(temp, read.c_str());
			if (temp[0] == '!')
				break;



		}
	}
	file.close();
	while (1)
	{
	MAINMENU:
		system("Pause");
		system("CLS");
		cout << "\n\n****************** MAIN MENU ******************\n\n";
		cout << "\n1. Vehicle Entry\n2. Vehicle Exit\n3. Parking Fee Collected\n4. Parking Statistics\n5.Exit\nChoose One Option : "; int option; Try_Try_Again:
		cin >> option;
		if (option < 1 || option>5)
		{

			cout << "\nIn_valid Input \nPlease Try Again : ";
			goto Try_Try_Again;

		}
		switch (option)
		{

		case 1:
		vehicle_Entry_again:
			cout << "\n\n************* Vehicle Entry *************\n\n";
			VEHICLE_ENTRY();   // Function
			cout << "\nPress 1 For Adding Vehicle Entry  & 2 For mainMenu : ";
		INVALID:
			int option1;         // goto statement
			cin >> option1;
			switch (option1)
			{
			case 1: goto vehicle_Entry_again;
				break;
			case 2: goto MAINMENU;
				break;
			default:cout << "\nINVALID INPUT\nPlease Try Again : ";
				goto INVALID;
				break;
			}
		case 2:
		vehicle_Exit_again:
			cout << "\n\n************* Vehicle Exit *************\n\n";
			Vehicle_Exit();

			cout << "\nPress 1 For Re_Entering Vehicle Exit  & 2 For mainMenu : ";
		INVALID2:
			int option2;         // goto statement
			cin >> option2;
			switch (option2)
			{
			case 1: goto vehicle_Exit_again;
				break;
			case 2: goto MAINMENU;
				break;
			default:cout << "\nINVALID INPUT\nPlease Try Again : ";
				goto INVALID2;
				break;
			}
			break;
		case 3:
			cout << "\n\n************* Parking Fee Collected *************\n\n";
			Parking_Fee_Collected();
			break;
		case 4:
		vehicle_parking_again:
			cout << "\n\n************* Parking Statistics *************\n\n";
			Parking_stats();

			cout << "\nPress 1 For Re_Entering Vehicle Exit  & 2 For mainMenu : ";
		INVALID4:
			int option3;         // goto statement
			cin >> option3;
			switch (option3)
			{
			case 1: goto vehicle_parking_again;
				break;
			case 2: goto MAINMENU;
				break;
			default:cout << "\nINVALID INPUT\nPlease Try Again : ";
				goto INVALID4;
				break;
			}
			break;
		case 5:

			file.open("Parking Management system.txt", ios::out);



			vehicle* displaylist_parking2 = fptr;

			while (displaylist_parking2 != NULL)
			{
				file << "!!CAR - " << p << " details!!\n";

				file << left << setw(25) << "Registeration Number : " << displaylist_parking2->Vehicle_Reg_No;
				file << left << setw(26) << "\nDriver Name : " << displaylist_parking2->Driver_Name;
				file << left << setw(26) << "\nModel : " << displaylist_parking2->Vehicle_Model;
				file << left << setw(26) << "\nColour : " << displaylist_parking2->Vehicle_Colour;
				file << left << setw(26) << "\nEntry time : " << displaylist_parking2->Vehicle_Entry_Time;

				displaylist_parking2 = displaylist_parking2->nextptr; p++;
			}


			file.close();

			goto exit;


		}

	}
exit:
	return 0;
}
int first_time, second_time;
int VehicleCount = 0;
void VEHICLE_ENTRY()
{
	vehicle* Entry;
	Entry = new vehicle;



	cout << "\n1.Enter Vehicle Registration Number : ";
	cin >> Entry->Vehicle_Reg_No;
	cout << "\n2.Enter Driver Name : ";
	cin >> Entry->Driver_Name;
	cout << "\n3.Enter Vehicle Make : ";
	cin >> Entry->Vehicle_make;
	cout << "\n4.Enter Vehicle Model : ";
	cin >> Entry->Vehicle_Model;
	cout << "\n5.Enter Vehicle Colour(select only from White, Black, Red, Grey) : "; string check;
Invalid_colour:
	cin >> check;



	if ((check == "white" || check == "White") || (check == "Black" || check == "black") || (check == "Red" || check == "red") || (check == "Grey" || check == "grey"))
	{
		Entry->Vehicle_Colour = check;
	}
	else
	{
		cout << "\nInvalid Colour Input.\nPlease Select From White, Black, Red, Grey : ";
		goto Invalid_colour;
	}

	cout << "\n6. Entry Time of Vehicle is ";
	time_t now = time(0);
	tm* ltm = localtime(&now);
	first_time = ltm->tm_min;
	char* dt = ctime(&now);
	Entry->Vehicle_Entry_Time = dt;
	cout << Entry->Vehicle_Entry_Time;


	file.open("Parking Management system.txt", ios::in);

	if (file)
	{
		cout << "\n\n*file here*\n\n";
		vehicle* nextEntry = fptr;
		while (nextEntry->nextptr != NULL)
		{
			nextEntry = nextEntry->nextptr;
		}

		if (Entry == NULL)
		{
			nextEntry->nextptr = Entry;
			Entry->nextptr = NULL;
		}
		else
		{
			vehicle* cptrFor = fptr;
			while (cptrFor->nextptr != NULL)
			{
				cptrFor = cptrFor->nextptr;
			}
			cptrFor->nextptr = Entry;
			Entry->nextptr = NULL;

		}
	}
	file.close();

	if (!file)
	{
		cout << "\n\n*file not  here*\n\n";
		if (fptr == NULL)
		{
			fptr = Entry;
			Entry->nextptr = NULL;

		}
		else
		{
			vehicle* currentptr = fptr;

			while (currentptr->nextptr != NULL)
			{
				currentptr = currentptr->nextptr;
			}
			currentptr->nextptr = Entry;
			Entry->nextptr = NULL;


		}



		VehicleCount++;
	}




}
int k = 0, l = 0;
int fee_collectedfifty[50];
int fee_collectedseventy[50];
int sum = 0, sum1 = 0;

void Vehicle_Exit()
{
	cout << "\nEnter Vehicle Registeration # "; string registeration_no;
	cin >> registeration_no; int flag = 0;
	vehicle* search = fptr;
	int count = 0;
	while (search != NULL)
	{
		if (search->Vehicle_Reg_No == registeration_no)
		{
			flag = 1;
			break;
		}
		count++;

		search = search->nextptr;

	}
	if (flag == 1)
	{
		cout << "\nVehicle of Registeration # " << registeration_no << " Found in Records.";
		cout << "\nEntry Time Of Vehicle =" << search->Vehicle_Entry_Time;
		time_t now = time(0);
		tm* ltm = localtime(&now);
		second_time = ltm->tm_min;
		char* dt = ctime(&now);
		search->Vehicle_Entry_Time = dt;
		cout << search->Vehicle_Entry_Time;

		if ((second_time - first_time) <= 1)
		{
			search->price = 50;
			fee_collectedfifty[k] = search->price;
			k++;
			sum = sum + search->price;


		}
		else if ((second_time - first_time) > 1)
		{
			search->price = 70;
			fee_collectedseventy[l] = search->price;
			l++;
			sum1 = sum1 + search->price;
		}
		cout << "\nAmount Collected By car = Rs " << search->price << " By Car # " << registeration_no;
		if (count == 1)                               // Deleting First Node
		{
			vehicle* removeFirstNode;
			removeFirstNode = new vehicle;
			removeFirstNode = fptr;
			fptr = fptr->nextptr;
			delete removeFirstNode;
			cout << "\nCar Data Deleted From Parking Management System.";
		}
		else if (VehicleCount == count)                         // Deleting Last Node
		{
			vehicle* removeLastNocde = fptr;
			vehicle* removePreviousOfLastNocde = fptr;
			while (removeLastNocde->nextptr != NULL)
			{
				removePreviousOfLastNocde = removeLastNocde;

				removeLastNocde = removeLastNocde->nextptr;

			}
			removePreviousOfLastNocde->nextptr = NULL;
			delete removeLastNocde;





			cout << "\nCar Data Deleted From Parking Management System.";
		}
		else                                   // Deleting Node in between
		{

			vehicle* removeInBetw = fptr;
			vehicle* removeInBetwPrevious = fptr;
			for (int i = 1; i < count; i++)
			{
				removeInBetwPrevious = removeInBetw;
				removeInBetw = removeInBetw->nextptr;
			}
			removeInBetwPrevious->nextptr = removeInBetw->nextptr;
			delete removeInBetw;

			cout << "\n Car Data at Entry " << count << " is Successfuly Deleted From Parking Management System.";
		}

	}
	else
	{
		cout << "\nNo vehicle in record of this Registration Number.";

	}
}

int sum3 = 0;
void Parking_Fee_Collected()
{
	sum3 = sum + sum1;
	cout << "\nTotal Fee = " << sum3;
}

void Parking_stats()
{

	cout << endl;
	cout << setw(25) << left << "Reg #" << setw(25) << left << "Name" << setw(20) << left << "Model" << setw(20) << left << "Colour" << setw(40) << left << "Entry Time";
	cout << "\n";

	vehicle* displaylist_parking = fptr;

	while (displaylist_parking != NULL)
	{

		cout << setw(25) << left << displaylist_parking->Vehicle_Reg_No << setw(25) << left << displaylist_parking->Driver_Name << setw(20) << left << displaylist_parking->Vehicle_Model << setw(20) << left << displaylist_parking->Vehicle_Colour << setw(40) << left << displaylist_parking->Vehicle_Entry_Time;
		cout << "\n";

		displaylist_parking = displaylist_parking->nextptr;
	}


}


