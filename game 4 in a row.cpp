#include<iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

char winner;
char player = 'O';
char maps[4][10]=
	{
		"| | | | |", 
		"| | | | |",
		"| | | | |",
		"| | | | |"
	};

//untuk mencetak maps
void printMap(){
	system("CLS");
	cout<<"=== GAME 4 in Row ===\n\n";
	for(int i=0;i<4;i++){
		for(int j=0;j<9;j++){
			cout<<maps[i][j];
		}
		cout<<endl;
	}
}

bool isEnd() {
	bool status = false;
	char sym;
	
	for(int i = 0; i < 4; i++) {
		sym = maps[i][1];
		
		if(sym == ' ')
			continue;
			
		for(int j = 0; j < 4; j++) {
			if(maps[i][j*2+1] != sym)
				break;
			else if(j == 3) {
				winner = sym;
				status = true;
			}
		}
	}
	
	return status;
}

bool insertBlock(int column) {
	if(column < 1 || column > 4 || maps[0][column*2-1] != ' ')
		return false;
	
	for(int i = 3; i >= 0; i--) {
		if(maps[i][column*2-1] == ' ') {
			maps[i][column*2-1] = player;
			break;
		}
	}
	
	return true;
}

main() {
	int col;
	
	while(!isEnd()) {
		printMap();
		
		cout<<"\nGILIRAN PEMAIN "<<player<<endl;
		
		while(true) {
			cout<<"Masukkan kolom: ";
			cin>>col;
			
			if(insertBlock(col)) {
				if(player == 'X')
					player = 'O';
				else
					player = 'X';
				
				break;
			}
			else {
				cout<<"\nInput kolom tidak valid\n";
			}
		}
			
	}
	
	printMap();
	cout<<"\nPermainan selesai, pemenangnya pemain "<<winner<<"!!!";
}
