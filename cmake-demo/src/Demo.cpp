#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include "../include/Calc.h"
#include "book/Book.hpp"

using namespace std;

void base_fun(int argc, char *argv[]);

int main(int argc, char *argv[]){
	base_fun(argc, argv);
	return 0;
}

void base_fun(int argc, char *argv[]){
/**********************************************/
//test hello world
	printf("Hello world!\n");
	puts("Hello World!");
	cout << "Hello world!" << endl;
	
	//cout << "params count: "<< argc << endl;
	//cout << "params content:" << endl;
	
	//for(int i=0; i < argc; i++){
	//	cout << argv[i] << endl;
	//}

	int i = 123;
	int *p = &i;

	cout << "i = " << i << endl;
	cout << "&i = " << &i << endl;
	cout << "p = " << p << endl;
	cout << "&p = " << &p <<endl;
	cout << "*p = " << *p << endl;
	
	int *pc;
	pc = p;//copy pointer

	cout << "*p= " << *p << endl;
/*******************************************/
//test function
	int a, b;
	if(argc > 2){
		a = atoi(argv[1]);//assic to int
		b = atoi(argv[2]);
	} else {
		a = 5;
		b = 6;
	}

	cout << "a = "<< a << ", b = "<< b <<endl<<endl;
	cout << "a + b = "<< add(a, b)<<endl;
	cout << "a - b = "<< reduce(a, b)<<endl;
	cout << "a x b = "<< multi(a, b)<<endl;
	cout << "a ÷ b = "<< divi(a, b)<<endl;
/*******************************************/
	Book book;
	book.setId(1);
	book.setPrice(12.5);
	book.setName("mlxg");

	book.display();
}
