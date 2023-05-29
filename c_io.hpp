#ifndef C_IO_HPP
#define C_IO_HPP
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
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
Prototype: input(string,T&):NULL
Usage: 	T variableName = input("prompt",T variableName);
*/
template <typename T>
void input(const std::string &prompt,T &var){
	std::cout<<prompt;
	std::cin>>var;
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
Prototype: void log(T[],int):NULL
Usage: log(variableName,len);
If you want to print the array, you must specify the length.
General formula for the length that you can use is: sizeof(arr)/sizeof(arr[0]) or
you can use the len() function that is provided by the library.
*/
template <typename T>
void log(T var[], int len){
	std::cout<<"{";
	for(int i = 0; i < len; i++){
		std::cout<<var[i];
		if(i != len-1) std::cout<<",";
	}
	std::cout<<"}"<<std::endl;
	delete var;
}
/*Prototype: void log(vector<T>,string):NULL
Usage: log(variableName);*/
template <typename T>
void log(const std::vector<T> &vec, const std::string &sep=" "){
	for(int i : vec){
		std::cout<<i;
		if(i != vec.size()-1) std::cout<<sep;
	}
	std::cout<<std::endl;
}
/*Prototype: void log(list<T>,string):NULL
Usage: log(variableName);*/
template <typename T>
void log(const std::list<T> &list, const std::string &sep=" "){
	for(int i : list){
		std::cout<<i;
		if(i != list.size()-1) std::cout<<sep;
	}
	std::cout<<std::endl;
}
/*Prototype: void log(queue<T>,string):NULL
Usage: log(variableName);*/
template <typename T>
void log(const std::queue<T> &queue, const std::string &sep=" "){
	std::queue<T> q = queue;
	while(!q.empty()){
		std::cout<<q.front();
		if(q.size() != 1) std::cout<<sep;
		q.pop();
	}
	std::cout<<std::endl;
}
/*Prototype: void log(stack<T>,string):NULL
Usage: log(variableName);*/
template <typename T>
void log(const std::stack<T> &stack, const std::string &sep=" "){
	std::stack<T> s = stack;
	while(!s.empty()){
		std::cout<<s.top();
		if(s.size() != 1) std::cout<<sep;
		s.pop();
	}
	std::cout<<std::endl;
}
/*Prototype: void log(map<T,T1>):NULL
Usage: log(variableName);*/
template <typename T, typename T1>
void log(const std::map<T,T1> &map){
	std::cout<<"{";
	for(auto it = map.begin(); it != map.end(); it++){
		std::cout<<it->first<<":"<<it->second;
		if(it != --map.end()) std::cout<<",";
	}
	std::cout<<"}"<<std::endl;
}
/*Prototype: int len(T):length of the array
Usage: len(arrayName);*/
template <typename T>
int len(const T &var){
	return sizeof(var)/sizeof(var[0]);
}
#endif //C_IO_HPP