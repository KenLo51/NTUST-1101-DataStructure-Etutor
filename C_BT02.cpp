#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

#define MAZE_BARRIER '1'
#define MAZE_ROAD '0'
#define MAZE_PATH '#'

using namespace std;
bool inRange(int num, int min, int max){
	return (num>=min)&&(num<=max);
}
bool solve_mazeRec(char *map, int *maze_size, int *current_pos, int *start_pos, int *end_pos){
	char (*maze)[maze_size[1]] = (char (*)[maze_size[1]]) map;
	
	int next_pos[2];
	bool success = false;
	maze[current_pos[0]][current_pos[1]] = MAZE_PATH;
	if( (current_pos[0]==end_pos[0]) && (current_pos[1]==end_pos[1]) ) return true;
	
	next_pos[0] = current_pos[0]+1; next_pos[1] = current_pos[1];
	if( inRange(next_pos[0], 0, maze_size[0]) && inRange(next_pos[1], 0, maze_size[1]) ){
		if( maze[next_pos[0]][next_pos[1]] == MAZE_ROAD ) 
			if( solve_mazeRec((char*)maze, maze_size, next_pos, start_pos, end_pos) ) return true;
	}
	
	next_pos[0] = current_pos[0]; next_pos[1] = current_pos[1]+1;
	if( inRange(next_pos[0], 0, maze_size[0]) && inRange(next_pos[1], 0, maze_size[1]) ){
		if( maze[next_pos[0]][next_pos[1]] == MAZE_ROAD ) 
			if( solve_mazeRec((char*)maze, maze_size, next_pos, start_pos, end_pos) ) return true;
	}
	
	next_pos[0] = current_pos[0]-1; next_pos[1] = current_pos[1];
	if( inRange(next_pos[0], 0, maze_size[0]) && inRange(next_pos[1], 0, maze_size[1]) ){
		if( maze[next_pos[0]][next_pos[1]] == MAZE_ROAD ) 
			if( solve_mazeRec((char*)maze, maze_size, next_pos, start_pos, end_pos) ) return true;
	}
	
	next_pos[0] = current_pos[0]; next_pos[1] = current_pos[1]-1;
	if( inRange(next_pos[0], 0, maze_size[0]) && inRange(next_pos[1], 0, maze_size[1]) ){
		if( maze[next_pos[0]][next_pos[1]] == MAZE_ROAD ) 
			if( solve_mazeRec((char*)maze, maze_size, next_pos, start_pos, end_pos) ) return true;
	}
	
	maze[current_pos[0]][current_pos[1]] = MAZE_ROAD;
	return false;
}
int main(){
	string str_in;
	getline(cin, str_in);
	size_t N = count(str_in.begin(), str_in.end(), '1');
	int maze_size[] = {N, N};
	char maze[maze_size[0]][maze_size[1]];
	size_t row=0, column=0;
	while(1){
		for(size_t column=0; column<N; column++){
			while(str_in.find(" ")==0) str_in.erase(0,1);//remove space
			maze[row][column] = str_in[0];
			str_in.erase(0,1);
		}
		row++;
		if(row >= N) break;
		getline(cin, str_in);
	}
	
	int start_pos[] = {1, 1};
	int end_pos[] = {N-2, N-2};
	solve_mazeRec((char*)maze, maze_size, start_pos, start_pos, end_pos);
	for(size_t row=0; row<N; row++){
		for(size_t column=0; column<N; column++){
			printf("%c%s", maze[row][column], (column==N-1? "":" "));
		}
		printf("\n");
	}
	return 0;
}

//prototype
/*
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>
#include <bits/stdc++.h>

#define MAZE_BARRIER '1'
#define MAZE_ROAD '0'
#define MAZE_PATH '#'

using namespace std;

bool inRange(int num, int min, int max){
	return (num>=min)&&(num<=max);
}
bool solve_DistanceRec(char *map, int *maze_size, int *current_pos, int *start_pos, int *end_pos){
	char (*maze)[maze_size[1]] = (char (*)[maze_size[1]]) map;
	printf("map--%d-%d,%d:%c\n",maze,current_pos[0], current_pos[1], maze[current_pos[0]][current_pos[1]]);
	char c = maze[current_pos[0]][current_pos[1]];
	printf("mmmmmm:%c\n", c);
	printf("\n");
	int a=current_pos[0], b=current_pos[1];
	maze[a][b] = '8';
	maze[current_pos[0]][current_pos[1]] = MAZE_PATH;
	for(size_t row=0; row<maze_size[0]; row++){
		for(size_t column=0; column<maze_size[1]; column++){
			printf("%c ", maze[row][column]);
		}
		printf("\n");
	}
	
	int next_pos[2];
	bool success = false;
	//maze[current_pos[0]][current_pos[1]] == MAZE_PATH;
	if( (current_pos[0]==end_pos[0]) && (current_pos[1]==end_pos[1]) ) return true;
	
	next_pos[0] = current_pos[0]+1; next_pos[1] = current_pos[1];
	if( inRange(next_pos[0], 0, maze_size[0]) && inRange(next_pos[1], 0, maze_size[1]) ){
		if( maze[next_pos[0]][next_pos[1]] == MAZE_ROAD ) 
			if( solve_DistanceRec((char*)maze, maze_size, next_pos, start_pos, end_pos) ) return true;
	}
	
	next_pos[0] = current_pos[0]; next_pos[1] = current_pos[1]+1;
	if( inRange(next_pos[0], 0, maze_size[0]) && inRange(next_pos[1], 0, maze_size[1]) ){
		if( maze[next_pos[0]][next_pos[1]] == MAZE_ROAD ) 
			if( solve_DistanceRec((char*)maze, maze_size, next_pos, start_pos, end_pos) ) return true;
	}
	
	next_pos[0] = current_pos[0]-1; next_pos[1] = current_pos[1];
	if( inRange(next_pos[0], 0, maze_size[0]) && inRange(next_pos[1], 0, maze_size[1]) ){
		if( maze[next_pos[0]][next_pos[1]] == MAZE_ROAD ) 
			if( solve_DistanceRec((char*)maze, maze_size, next_pos, start_pos, end_pos) ) return true;
	}
	
	next_pos[0] = current_pos[0]; next_pos[1] = current_pos[1]-1;
	if( inRange(next_pos[0], 0, maze_size[0]) && inRange(next_pos[1], 0, maze_size[1]) ){
		if( maze[next_pos[0]][next_pos[1]] == MAZE_ROAD ) 
			if( solve_DistanceRec((char*)maze, maze_size, next_pos, start_pos, end_pos) ) return true;
	}
	
	maze[current_pos[0]][current_pos[1]] = MAZE_ROAD;
}

void solve_maze(char **map, vector<size_t> maze_size, vector<int> start_pos, vector<int> end_pos){
	//use BFS
	int map_BFS[maze_size[0]][maze_size[1]];//build a map for BFS
	for(size_t row = 0; row < maze_size[0]; row++){
		for(size_t column = 0; column < maze_size[1]; column++){
			if(map[row][column]==MAZE_BARRIER)	map_BFS[row][column] = -1;//barrier
			if(map[row][column]==MAZE_ROAD)		map_BFS[row][column] = numeric_limits<int>::min();//road
		}
	}
	
	
}
int main(){
	string str_in;
	getline(cin, str_in);
	size_t N = count(str_in.begin(), str_in.end(), '1');
	//printf("maze size: %dx%d\n", N, N);
	int maze_size[] = {N, N};
	char maze[maze_size[0]][maze_size[1]];
	//char maze[maze_size[0]][maze_size[1]];
	//maze = (char**)malloc(maze_size[0] * maze_size[1])
	size_t row=0, column=0;
	while(1){
		//read a row of input maze
		//printf("read row %d\n", row);
		for(size_t column=0; column<N; column++){
			while(str_in.find(" ")==0) str_in.erase(0,1);//remove space
			maze[row][column] = str_in[0];
			str_in.erase(0,1);
		}
		row++;
		if(row >= N) break;
		getline(cin, str_in);
	}
	
	printf("map--%d\n", (char(*)[5])maze);
	
	int start_pos[] = {1, 1};
	int end_pos[] = {N-2, N-2};
	solve_DistanceRec((char*)maze, maze_size, start_pos, start_pos, end_pos);
	printf("\n");
	for(size_t row=0; row<N; row++){
		for(size_t column=0; column<N; column++){
			printf("%c ", maze[row][column]);
		}
		printf("\n");
	}
	return 0;
}*/

