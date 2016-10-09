#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

double dropSingleChip(int slotMenu, bool print) {

	double finalSlot;
	finalSlot = slotMenu;
	for (int currentRow = 12; currentRow >=1; --currentRow) {
		if ((((rand() % 2) == 0) && (finalSlot > 0.25)) || (finalSlot > 7.75)) {
			finalSlot -= 0.5;
		}
		else {
			finalSlot += 0.5;
		}

		if (print) {
			cout << finalSlot;
		}
		if ((currentRow > 1) && (print)){
			cout << " ";
		}
	}
return finalSlot;
}

double getWinnings(double finalSlot) {

	double userWinnings = 0.0;
	const double WINNINGS_08 =   100.0; //$$ amount for slots 0 & 8
	const double WINNINGS_17 =   500.0; //$$ amount for slots 1 & 7
	const double WINNINGS_26 =  1000.0; //$$ amount for slots 2 & 6
	const double WINNINGS_35 =     0.0; //$$ amount for slots 3 & 5
	const double WINNINGS_4  = 10000.0; //$$ amount for slots 4

	if ((finalSlot == 0.0) || (finalSlot == 8.0)) {
		userWinnings = WINNINGS_08;
	}
	else if ((finalSlot == 1.0) || (finalSlot == 7.0)) {
		userWinnings = WINNINGS_17;
	}
	else if ((finalSlot == 2.0) || (finalSlot == 6.0)) {
		userWinnings = WINNINGS_26;
	}
	else if ((finalSlot == 3.0) || (finalSlot == 5.0)) {
		userWinnings = WINNINGS_35;
	}
	else if (finalSlot == 4.0) {
		userWinnings = WINNINGS_4;
	}
	return userWinnings;
}

int main() {
	srand(42);


	int userMenu   = 1; //User menu selection
	int slotMenu   = 0; //User slot selection
	int numChips   = 0; //Number of chips used for muliple chips
	double totalWinnings = 0.0; //For multiple chips
	double avgWinnings   = 0.0; //Average winnings for multiple chips
	double currentSlot   = 0.0; //Current slot of plinko chip;
	double userWinnings  = 0.0; //Total money won by user
	double finalSlot     = 0.0;



	cout << "Welcome to the plinko simulator!" << endl
		<< endl;

	while (userMenu != 0) {
		cout << "MENU: Please select one of the following options:" << endl
			<< endl
			<< "0 - Quit the program" << endl
			<< "1 - Drop a single chip into one slot" << endl
			<< "2 - Drop multiple chips into one slot" << endl
			<< endl
			<< "Enter your selection now: ";
		cin >> userMenu;
		cout << endl;
		if ((userMenu != 2) && (userMenu != 1) && (userMenu != 0)) {
			cout << "INVALID SELECTION.  Please enter 0, 1 or 2" << endl
			   << endl;
			continue;
		}
		if (userMenu == 1) {
			cout << "*** DROP SINGLE CHIP ***" << endl
				<< endl
				<< "Which slot do you want to drop the chip in (0-8)? ";
			cin >> slotMenu;
			cout << endl;
			if (!((slotMenu <= 8) && (slotMenu >=0))) {
				cout << "INVALID SLOT.";
				cout << endl
				   << endl;
				continue;
			}
			else {
				currentSlot = slotMenu;
				cout << "*** DROPPING CHIP INTO SLOT " << slotMenu << " ***" << endl;
				cout << "PATH: [";
				cout << fixed << setprecision(1);
				cout << currentSlot << " ";
				finalSlot = dropSingleChip(slotMenu, true);
				cout << "]";
				userWinnings = getWinnings(finalSlot);
				cout << endl;
				cout << "WINNINGS: $";
				cout << setprecision(2);
				cout << userWinnings
					<<endl;
			}
			cout << endl;
		}
		if (userMenu == 2) {
			cout << "*** DROP MULTIPLE CHIPS ***" << endl
				<< endl
				<< "How many chips do you want to drop (>0)? " << endl;
			cin >> numChips;
			if (numChips < 1) {
			   cout << "INVALID NUMBER OF CHIPS." << endl
			      << endl;
			   continue;
			}
			cout << "Which slot do you want to drop the chip in (0-8)? " << endl;
			cin >> slotMenu;
			if (((slotMenu > 8) || (slotMenu < 0))) {
				cout << "INVALID SLOT." << endl
				   << endl;
				continue;
			}
			currentSlot = slotMenu;
			totalWinnings = 0.0;
			if (numChips > 0) {
				for (int i = numChips; i > 0; --i) {
					finalSlot = dropSingleChip(slotMenu, false);
					totalWinnings += getWinnings(finalSlot);
				}
			avgWinnings = (totalWinnings / numChips);
			cout << "Total Winnings on " << numChips << " chips: ";
			cout << fixed << setprecision(2) << totalWinnings << endl;
			cout << "Average winnings per chip: " << avgWinnings << endl
			   << endl;
			}
			else {
				cout << "INVALID NUMBER OF CHIPS." << endl;
				continue;
			}
		}
		if (userMenu == 0) {
			cout << "GOODBYE!";
			break;
		}
	}
	//system ("pause");
	return 0;
}
