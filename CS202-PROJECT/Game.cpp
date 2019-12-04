#include "Game.h"

Game::Game() {

}

void Game::menu() {
	crossyZoo();

	int t = 23;
	int y = t+3;
	int cursorColor = 176;
	int colour = 11;
	vector<std::string> command;
	command.push_back("   Start New Game   ");
	command.push_back("  Load Saved Game   ");
	command.push_back("      Settings      ");
	command.push_back("      About Us      ");
	command.push_back("        Exit        ");
	for (int i = 0; i < 5; ++i)
	{
		stringCentralization(command[i], t += 3, colour);
	}
	int line = 0;
	stringCentralization(command[line], line*3+y, cursorColor);
	int k = _getch();
	while (k != 13) {
		stringCentralization(command[line], 3*line+y, colour);
		moveCursor(k,line);
		stringCentralization(command[line], line*3+y, cursorColor);
		k = _getch();
	}
	color(8);
	if (line == 0)
		cout << "New game" << endl;//startGame();
	else if (line == 1)
		cout << "Load Game" << endl;//loadGame();
	else if (line == 2)
		cout << "Settings" << endl;//settings();
	else if (line == 3)
		cout << "About Us" << endl;//aboutUs();
	else if (line == 4)
		cout << "Exit game" << endl;//exitGame();

}

void Game::moveCursor(int key, int& y)
{
	if (y > 0 && (key == 'w' || key == 'W'))
		y -= 1;
	else if (y < 4 && (key == 's' || key == 'S'))
		y += 1;
	else if (key == 224)
	{
		key = _getch();
		if (y > 0 && key==72)
			y -= 1;
		else if (y < 4 && key==80)
			y += 1;
	}
}

void Game::stringCentralization(std::string str, int r, int colour)
{
	int len = str.length();
	const int width = 210 - len;
	int mid = width / 2;
	go(mid, r+1);
	color(colour);
	std::cout << str;
/*
	int c = mid-1;
	color(14);
	go(c, r++);

	cout << (char)201;
	for (int i = 1; i < len; ++i)
		cout << (char)205;
	cout << (char)187;

	go(c, r);
	cout << (char)186;
	go(c + len, r++);
	cout << (char)186;

	go(c, r);
	cout << (char)200;
	for (int i = 1; i < len; ++i)
		cout << (char)205;
	cout << (char)188;
*/
}

void Game::resetGame() {

}

void Game::exitGame(HANDLE) {

}

void Game::startGame() {

}

string Game::inputFileName() {
	cout << "Type file name: ";
	std::string fileName;
	getline(cin, fileName, '\n');
	cin.ignore();
	/*string path;
	int k = 0, s = 0;
	do {
		if (k == 27) break;
		if (k > 31 && k < 127) {
			std::cout << char(k);
			path.push_back(k);
			++s;
		}
		else if (k == 8 && s > 0) {
			std::cout << '\b' << ' ' << '\b';
			path.pop_back(); --s;
		}
		k = _getch();
	} while (k != 13);*/
	return fileName;
}

void Game::loadOption() {
	string fileName = inputFileName();
	loadGame(fileName);
}

void Game::loadGame(string fileName) {
	ifstream file;
	file.open(fileName + ".bin", ios::binary);
	// file<<(char*)   -> level
	int life = human.getLife();
	file.read((char*)& life, sizeof(life));
	file.close();
}

void Game::saveOption() {
	string fileName = inputFileName();
	saveGame(fileName);
}

void Game::saveGame(string fileName) {
	ofstream file;
	file.open(fileName + ".bin", ios::binary);
	// file<<(char*)   -> level
	int life = human.getLife();
	file.write((char*)&life, sizeof(life));
	file.close();
}

void Game::pauseGame(HANDLE) {

}

void Game::resumeGame(HANDLE) {

}

People Game::getPeople() {
	return human;
}


void Game::crossyZoo() {
	ifstream fin("crossyZoo.txt");
	if (fin.is_open()) {
		int n;
		fin >> n;
		int x = 50, y = 5;
		color(14);
		for (int i = 0; i < n; ++i) {
			string str;
			getline(fin, str, '\n');
			go(x, y++);
			cout << str;
		}
	}
	fin.close();
}

void Game::instructor()
{
	int x = 165, y = 3;
	color(4);
	ifstream fin("crossy.txt");
	if (fin.is_open()) {
		string line;
		while (getline(fin, line, '\n')) {
			go(x, y++);
			cout << line;
		}
	}
	fin.close();

	x += 10;
	color(11);
	fin.open("zoo.txt");
	if (fin.is_open()) {
		string line;
		while (getline(fin, line, '\n')) {
			go(x, ++y);
			cout << line;
		}
	}
	fin.close();

	x = 175;
	y = 17;
	color(7);
	go(x, y);
	cout << "LEVEL: " << "//something will be here";
	go(x, y+=3);
	cout << "LIVES: " << "//something will be here 2";
	
	go(160, y += 3);
	cout << (char)195;
	for (int i = 0; i < 50; ++i)
		cout << (char)196;

	x = 165;
	go(x, y = 25);
	cout << "Press W to UP";
	go(x, y += 2);
	cout << "Press S to DOWN";
	go(x, y += 2);
	cout << "Press A to LEFT";
	go(x, y += 2);
	cout << "Press D to RIGHT";

	go(x+=20, y = 33);
	cout << setw(20) << "Press P to PAUSE";
	go(x, y += 2);
	cout << setw(20) << "Press R to RESUME";
	go(x, y += 2);
	cout << setw(20) << "Press L to SAVE";
	go(x, y += 2);
	cout << setw(20) << "Press T to LOAD";
	go(x, y += 2);
	cout << setw(20) << "Press ESC to EXIT";
}
