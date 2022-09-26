/*
program info comment
Your Name:
CSC 161- section
Date:
Summary: 


Credit: Ascii code picture idea to student, Dustin McDowell, Fall 2020
*/

#include <iostream>	
#include <string>
#include <iomanip>

#include "player.h"
#include "contestants.h"

void drawContestants(Contestants players);
std::string getContestant1();
std::string getContestant2();
std::string getContestant3();
std::string getContestant4();

int main()
{
	Contestants players;							

	players.readFile("player.dat");							// Get the players from the file.	
	
	drawContestants(players);

	players.clearAll();

	Player p1, p2, p3;
	p1.setName(getContestant1());
	p2.setName(getContestant2());
	p3.setName(getContestant3());

	players.addPlayer(p1);
	players.addPlayer(p2);
	players.addPlayer(p3);

	drawContestants(players);

	players.writeFile("player.dat");
	return 0;
}

void drawContestants(Contestants players) {
	std::cout << "\n" << 
		"    .xxxx.     " << "    \\\\||//    " << "    \\|||||/     \n" <<
		"   |(o)(o)|    " << "    ~ .. '~     " << "  ( ~  ~ )     \n" <<
		"  (  (__)  )   " << "    (  \\  )    " << "  @( 0  0 )@    \n" <<
		"    | __ |     " << "     \\ c /     " << "   (   C  )     \n" <<
		"     \\__/     " << "    __\\ /__    " << "     \\ \\_//    \n" <<
		"   ___||___    " << "   /       \\   " << "  ___|  |___    \n" <<
		"  /        \\  " << "    |       |   " << "  /        \\   \n";
	std::cout << "_______________________________________________\n";
	
	std::cout << "| ";
	for (int i = 0; i < players.getSize(); i++){
		std::cout << " " << 
		std::left << std::setw(13) << players[i].getName() << " ";
    }
	std::cout << "|\n| ";
 for (int i = 0; i < players.getSize(); i++){
		std::cout << "   " << 
		std::left << std::setw(11) << players[i].getScore() << " ";
    }
	std::cout << "|\n";
	std::cout << "''''''''''''''''''''''''''''''''''''''''''''''''\n";
	std::cout << "\n\n";
}

/*Thank you for visiting https ://asciiart.website/
	This ASCII pic can be found at
	https ://asciiart.website/index.php?art=people/faces
*/
std::string getContestant1() {
	std::cout << "\n" <<
		"\n    .xxxx." <<
		"\n   |(o)(o)|" <<
		"\n  (  (__)  )" <<
		"\n    | __ |" <<
		"\n     \\__/ " <<
		"\n   ___||___" <<
		"\n  /        \\";
	std::cout << "\nEnter name of contestant 1: ";
	std::string name;
	std::cin >> name;
	std::cout << "\n\n";
	return name;
}

/* https://www.asciiart.eu/people/occupations/artists */
std::string getContestant2() {
	std::cout << "\n" <<
		"\n    \\\\||//" <<
		"\n    ~ .. '~" <<
		"\n    (  \\  )" <<
		"\n     \\ c /" <<
		"\n    __\\ /__" <<
		"\n   /       \\"
		"\n   |        |";
	std::cout << "\nEnter name of contestant 3: ";
	std::string name;
	std::cin >> name;
	std::cout << "\n\n";
	return name;
}

/*Thank you for visiting https://asciiart.website/
This ASCII pic can be found at
https://asciiart.website/index.php?art=people/faces
*/
std::string getContestant3() {
	std::cout << "\n" <<
		"\n    \\|||||/" <<
		"\n    ( ~  ~ )" <<
		"\n   @( 0  0 )@" <<
		"\n    (   C  )" <<
		"\n     \\ \\_//" <<
		"\n   ___|  |___" <<
		"\n   /        \\  ";
	std::cout << "\nEnter name of contestant 2: ";
	std::string name;
	std::cin >> name;
	std::cout << "\n\n";
	return name;
}

/* https://www.asciiart.eu/people/women */
std::string getContestant4() {
	std::cout << "\n" <<
		"\n     ____" <<
		"\n  /((   ))" <<
		"\n  ( )6  6( )" <<
		"\n  (_)  l (_)" <<
		"\n    \\ <> )" <<
		"\n_____)  (_____" <<
		"\n( \\         / )";
	std::cout << "\nEnter name of contestant 4: ";
	std::string name;
	std::cin >> name;
	std::cout << "\n\n";
	return name;
}
