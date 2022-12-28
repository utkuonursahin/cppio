#ifndef C_IO_HPP
#define C_IO_HPP
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
/*
Prototype: T input(string):T
Usage: T variableName = input<T>("prompt");
*/
template <typename T>
T input(const std::string &prompt){
	std::cout<<prompt;
	T var;
	std::cin>>var;
	return var;
}
/*
Prototype: void log(T):NULL
Usage: log(variableName);
*/
template <typename T>
void log(const T &var){
	std::cout<<var<<std::endl;
}
/*
Prototype: void log(T,int):NULL
Usage: log(variableName,len);
If you want to print the array, you must specify the length.
General formula for the length that you can use is: sizeof(arr)/sizeof(arr[0]) or
you can use the len() function that is provided by the library.
*/
template <typename T>
void log(T var[], int len){
	for(int i = 0; i < len; i++)
		std::cout<<var[i]<<" ";
	std::cout<<std::endl;
	delete var;
}
/*
Prototype: void log(T,string):NULL
Usage: log(variableName,type="ARR");
If you want to print the array, you must specify the type.
The only parameter that is allowed is "ARR" for the type.
Do not pass anything than "ARR" as the type otherwise you get an error.
*/
template <typename T>
void log(const T &var, const std::string &type){
	if(type == "ARR"){
		for(int i = 0; i < sizeof(var)/sizeof(var[0]); i++)
			std::cout<<var[i]<<" ";
		std::cout<<std::endl;
	} else std::cout<<"Invalid type"<<std::endl;
}
/*Prototype: void log(vector<T>,string):NULL
Usage: log(variableName);*/
template <typename T>
void log(const std::vector<T> &vec){
	for(int i : vec)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
/*Prototype: void log(list<T>,string):NULL
Usage: log(variableName);*/
template <typename T>
void log(const std::list<T> &list){
	for(int i : list)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
/*Prototype: void log(queue<T>,string):NULL
Usage: log(variableName);*/
template <typename T>
void log(const std::queue<T> &queue){
	std::queue<int> q = queue;
	while(!q.empty()){
		std::cout<<q.front()<<" ";
		q.pop();
	}
	std::cout<<std::endl;
}
/*Prototype: void log(stack<T>,string):NULL
Usage: log(variableName);*/
template <typename T>
void log(const std::stack<T> &stack){
	std::stack<T> s = stack;
	while(!s.empty()){
		std::cout<<s.top()<<" ";
		s.pop();
	}
	std::cout<<std::endl;
}
/*Prototype: int len(T):length of the array
Usage: len(arrayName);*/
template <typename T>
int len(const T &var){
	return sizeof(var)/sizeof(var[0]);
}
#endif //C_IO_HPP