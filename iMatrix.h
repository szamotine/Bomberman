#pragma once
// int version of dMatrix class with extra row and col for 
// optional i=0 and j=0

class iMatrix {

private:

	int N;
	int M;

public:

	
	int *p;


	iMatrix(int N, int M); 
	
	int & e(int i, int j);

	void print();

	// print elements including row i=0 and col j=0
	void print0();

};

