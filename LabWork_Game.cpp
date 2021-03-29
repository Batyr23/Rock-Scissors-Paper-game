#include<iostream>	//Input/output library
#include<cstdlib>	//For the rand() function
#include<ctime>		//For the time() function
#include<windows.h> // WinApi header

//Constant variables
const int ROCK = 1,
		  PAPER = 2,
		  SCISSORS = 3;

//Functions, which wil be written after int main()
int inputValidate(int);
int computerChoice(int);
int getUserChoice(int);
int getUser_2Choice(int);
void displayRandomNumber(int);
void winnerSelectionPVC(int, int, bool &);
void winnerSelectionPVP(int, int, bool &);

using namespace std;

int main(){

	int mode;
	int computer_choice, user_number, user2_number;
	
	bool play_again;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout<<"***********************************************\n";
	cout<<"WELCOME TO THE ROCK, PAPER and SCISSORS game!\n";
	cout<<"***********************************************\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	
	int num_rounds, rounds=0;
	cout<<"Please, input number of rounds: \n";
	cin>>num_rounds;
	
	while(rounds != num_rounds){
	cout << "Please, Choose mode: "<< endl << "(1) for the PVP (against player 2)\n(2) for the PVC (against computer)\n";
	//Mode to choose how to play against computer or another player
	cin >> mode;
	
	if(mode == 2) {
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout<<"Player against Computer mode has chosen!\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		/* PVC mode */
		do{
			computer_choice = computerChoice(computer_choice);
			user_number = getUserChoice(user_number);
			displayRandomNumber(computer_choice);
			winnerSelectionPVC(computer_choice, user_number, play_again);
			
		} while(play_again == 1);
		// to calculate quantity of the rounds
		rounds++;		
		cout<<"Rounds played: "<<rounds<<endl;
		
	}else if(mode == 1){
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout<<"Player against Player mode has chosen!\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		/* PVP mode */
		do{
			user2_number = getUser_2Choice(user2_number);
		
			user_number = getUserChoice(user_number);
			
			winnerSelectionPVP(user2_number, user_number, play_again);
			
		} while(play_again == 1);
		// to calculate quantity of the rounds
		rounds++;		
		cout<<"Rounds played: "<<rounds<<endl;
	}
	}
	return 0;
}
//Functions for the ComputerChoice
int computerChoice(int computer_choice){
	
	//Get the system time
	unsigned seed = time(0);
	//Seed the random number generator
	srand(seed);
	//Random nember
	return (rand() % (SCISSORS - ROCK + 1)) + ROCK;
}
//Functions for the UserChoice
int getUserChoice(int user_number){
	
	cout << "\nPLayer 2 \nChoose 'rock, 'paper' or 'scissors'. \n"
		 << "1:ROCK\n2:PAPER\n3:SCISSORS\n";
	user_number = inputValidate(user_number);
	cout<<"SELECTED"<<endl;
	return user_number;
}
//Functions for the UserChoice
int getUser_2Choice(int user2_number){
	
	cout << "\nPLayer 1 \nChoose 'rock, 'paper' or 'scissors'. \n"
		 << "1:ROCK\n2:PAPER\n3:SCISSORS\n";
	user2_number = inputValidate(user2_number);
	cout<<"SELECTED"<<endl;
	return user2_number;
}
//Created validator to check input type 
int inputValidate(int num_1){
	
	//To make input color invisible in the console to us, we give 'black' color for the console text
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	while (!(cin >> num_1) || (num_1 < 1 || num_1 > 3)){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "Error occured! Number must not be " 
			 << " 0 or greater: \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			 cin.clear();
	}
	//To make input color 'white' back again
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	return num_1;
}
//Random number displayer of computer_choice 
void displayRandomNumber(int computer_choice){
	
	cout << "\nComputer Choice = ";
	if(computer_choice == 1)
		cout << "Rock";
	else if(computer_choice == 2)
		cout << "Paper";
	else if(computer_choice == 3)
		cout << "Scissors";
	cout<<endl;	
}
//Winner selector function to the PVC mode 
void winnerSelectionPVC(int computer_choice, int user_number, bool &play_again){
	
	cout << endl;
	if(computer_choice == ROCK){
		if(user_number == PAPER){
			cout << "You win: (Paper covers rock). \n";
			cout<<endl;
			cout<<"Mode: PVC";
			play_again = 0;
		}else if(user_number == SCISSORS){
			cout << "Computer wins: (Rock smashes scissors). \n";
			play_again = 0;
			cout<<endl;
			cout<<"Mode: PVC";
		}else if(user_number == ROCK){
			cout << "Tie. Play again to determine the winner." << endl;
			play_again = 1;
			cout<<endl;
			cout<<"Mode: PVC";
		}
		
	}else if(computer_choice == PAPER){
		if(user_number == ROCK){
			cout << "Computer wins: (Paper covers rock). \n";
			play_again = 0;
			cout<<endl;
			cout<<"Mode: PVC";
		}else if(user_number == SCISSORS){
			cout << "You win: (Scissors cuts the paper). \n";
			play_again = 0;
			cout<<endl;
			cout<<"Mode: PVC";
		}else if(user_number == PAPER){
			cout << "Tie. Play again to determine the winner." << endl;
			play_again = 1;
			cout<<endl;
			cout<<"Mode: PVC";
		}
		
	}else if(computer_choice == SCISSORS){
		
		if(user_number == PAPER){
			cout << "You win: (Scissors cuts the paper). \n";
			play_again = 0;
			cout<<endl;
			cout<<"Mode: PVC";
		}else if(user_number == SCISSORS){
			cout << "Tie. Play again to determine the winner." << endl;
			play_again = 1;
			cout<<endl;
			cout<<"Mode: PVC";
		}else if(user_number == ROCK){
			cout << "You wins: (Rock smashes scissors). \n";
			play_again = 0;
			cout<<endl;
			cout<<"Mode: PVC";
		}
	}
	cout << endl;
}
//Winner selector function to the PVp mode
void winnerSelectionPVP(int user2_number, int user_number, bool &play_again){
	
	cout << endl;
	if(user2_number == ROCK){
		if(user_number == PAPER){
			cout << "PLayer 2 wins: (Paper covers rock). \n";
			play_again = 0;
			cout<<endl;
			cout<<"Mode: PVP";
		}else if(user_number == SCISSORS){
			cout << "Player 1 wins: (Rock smashes scissors). \n";
			play_again = 0;
			cout<<endl;
			cout<<"Mode: PVP";
		}else if(user_number == ROCK){
			cout << "Tie. Play again to determine the winner." << endl;
			play_again = 1;
			cout<<endl;
			cout<<"Mode: PVP";
		}
		
	}else if(user2_number == PAPER){
		if(user_number == ROCK){
			cout << "Player 1 wins: (Paper covers rock). \n";
			play_again = 0;
			cout<<endl;
			cout<<"Mode: PVP";
		}else if(user_number == SCISSORS){
			cout << "Player 2 wins: (Scissors cuts the paper). \n";
			play_again = 0;
			cout<<endl;
			cout<<"Mode: PVP";
		}else if(user_number == PAPER){
			cout << "Tie. Play again to determine the winner." << endl;
			play_again = 1;
			cout<<endl;
			cout<<"Mode: PVP";
		}
	
	}else if(user2_number == SCISSORS){
		if(user_number == PAPER){
			cout << "Player 1 wins: (Scissors cuts the paper). \n";
			play_again = 0;
			cout<<endl;
			cout<<"Mode: PVP";
		}else if(user_number == SCISSORS){
			cout << "Tie. Play again to determine the winner." << endl;
			play_again = 1;
			cout<<endl;
			cout<<"Mode: PVP";
		}else if(user_number == ROCK){
			cout << "Player 2 wins: (Rock smashes scissors). \n";
			play_again = 0;
			cout<<endl;
			cout<<"Mode: PVP";
		}
	}
	cout << endl;
}
