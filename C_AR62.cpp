#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
void scanf_matrix(vector<vector<int>> &out){
	int shape[2];
	int input;
	scanf("%d %d", &(shape[0]), &(shape[1]));
	for(int row=0; row<shape[0]; row++){
		vector<int> row_vector;
		for(int col=0; col<shape[1]; col++){
			cin>>input;
			row_vector.push_back(input);
		}
		out.push_back(row_vector);
	}
}
vector<vector<int>> matrix_mul(vector<vector<int>> &A, vector<vector<int>> &B){
	vector<vector<int>> out;
	for(int row=0; row<A.size(); row++){
		vector<int> row_vector;
		for(int col=0; col<B[0].size(); col++){
			int result = 0;
			for(int i=0; i<A[0].size(); i++)
				result += A[row][i]*B[i][col];
			row_vector.push_back(result);
		}
		out.push_back(row_vector);
	}
	return out;
}
void print_matrix(vector<vector<int>> &M){
	for(int row=0; row<M.size(); row++){
		vector<int> row_vector;
		for(int col=0; col<M[0].size(); col++){
			printf("%d%s", M[row][col], (col==M[0].size()-1? "\n":" "));
		}
	}
}
int main(){
	vector<vector<int>> A, B, out;
	scanf_matrix(A);
	scanf_matrix(B);
	out = matrix_mul(A, B);
	print_matrix(out);
	
	return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
void scanf_matrix(vector<vector<int>> &out){
	int shape[2];
	int input;
	scanf("%d %d", &(shape[0]), &(shape[1]));
	for(int row=0; row<shape[0]; row++){
		vector<int> row_vector;
		for(int col=0; col<shape[1]; col++){
			cin>>input;
			row_vector.push_back(input);
		}
		out.push_back(row_vector);
	}
}
vector<vector<int>> matrix_mul(vector<vector<int>> &A, vector<vector<int>> &B){
	//printf("A:%d*%d\n", A.size(), A[0].size());
	//printf("A:%d*%d\n", B.size(), B[0].size());
	vector<vector<int>> out;
	for(int row=0; row<A.size(); row++){
		vector<int> row_vector;
		for(int col=0; col<B[0].size(); col++){
			//printf("porcess (%d,%d)\n", row, col);
			int result = 0;
			for(int i=0; i<A[0].size(); i++)
				result += A[row][i]*B[i][col];
			row_vector.push_back(result);
			//printf("(%d,%d)=%d\n", row, col, result);
		}
		out.push_back(row_vector);
	}
	return out;
}
void print_matrix(vector<vector<int>> &M){
	for(int row=0; row<M.size(); row++){
		vector<int> row_vector;
		for(int col=0; col<M[0].size(); col++){
			printf("%d ", M[row][col]);
		}
		printf("\n");
	}
}
int main(){
	vector<vector<int>> A, B, out;
	scanf_matrix(A);
	scanf_matrix(B);
	out = matrix_mul(A, B);
	print_matrix(out);
	
	return 0;
}
*/
