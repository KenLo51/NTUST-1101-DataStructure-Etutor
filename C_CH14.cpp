#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stdint.h>
#include <iostream>

#define BOARD_BLACK 0x01
#define BOARD_WHITE 0x10
#define BOARD_SPACE 0x00
#define BOARD_WHITE_ATK 0x0100
#define BOARD_BLACK_ATK 0x1000

using namespace std;
uint8_t board[15][15];
uint8_t is_atkPoint(uint8_t x, uint8_t y){
	
}
int main(){
	for(int row=0; row<15; row++)
		for(int col=0; col<15; col++)
			cin >> board[row][col];
	
	for(int row=0; row<15; row++){
		for(int col=0; col<15; col++){
			
		}
	}
	
	
	int black_total, white_total;
	black_total = white_total = 0;
	
	
	return 0;
}
