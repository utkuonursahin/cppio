#ifndef CPPIO_HPP
#define CPPIO_HPP
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>

namespace cppIO{
	//Usage: T variableName = input<T>("prompt");
	template <typename T>
	T input(const std::string &prompt){
		std::cout<<prompt;
		T var;
		std::cin>>var;
		return var;
	}
	//Usage: T variableName = input("prompt",T variableName);
	template <typename T>
	void input(const std::string &prompt,T &var){
		std::cout<<prompt;
		std::cin>>var;
	}
	//Usage: log(variableName);
	template <typename T>
	void log(const T &var){
		std::cout<<var<<std::endl;
	}
	//Usage: log(variableName,variableName,...);
	template <typename Arg, typename... Args>
	void log(const Arg &arg, const Args&... args){
		std::cout<<arg;
		log(args...);
	}

	/*
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
	//Usage: log(variableName);
	template <typename T>
	void log(const std::vector<T> &vec){
		std::cout<<"{";
		for(int i : vec){
			std::cout<<i;
			if(i != vec.size()-1) std::cout<<",";
		}
		std::cout<<"}"<<std::endl;
	}
	//Usage: log(variableName);
	template <typename T>
	void log(const std::list<T> &list){
		std::cout<<"{";
		for(int i : list){
			std::cout<<i;
			if(i != list.size()-1) std::cout<<",";
		}
		std::cout<<"}"<<std::endl;
	}
	//Usage: log(variableName);
	template <typename T>
	void log(const std::queue<T> &queue){
		std::queue<T> q = queue;
		std::cout<<"{";
		while(!q.empty()){
			std::cout<<q.front();
			if(q.size() != 1) std::cout<<",";
			q.pop();
		}
		std::cout<<"}"<<std::endl;
	}
	//Usage: log(variableName);
	template <typename T>
	void log(const std::stack<T> &stack){
		std::stack<T> s = stack;
		std::cout<<"{";
		while(!s.empty()){
			std::cout<<s.top();
			if(s.size() != 1) std::cout<<",";
			s.pop();
		}
		std::cout<<"}"<<std::endl;
	}
	//Usage: log(variableName);
	template <typename T, typename T1>
	void log(const std::map<T,T1> &map){
		std::cout<<"{";
		for(auto it = map.begin(); it != map.end(); it++){
			std::cout<<it->first<<":"<<it->second;
			if(it != --map.end()) std::cout<<",";
		}
		std::cout<<"}"<<std::endl;
	}
	//Usage: len(arrayName);
	template <typename T>
	int len(const T &var){
		return sizeof(var)/sizeof(var[0]);
	}
}
#endif //CPPIO_HPP