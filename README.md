# `c_iolib` Simple C++ library for console based input/output operations.
Have you ever been in a situation where you write lines of `cout<<` and
`cin>>` statements to get input from the user and display the output on the
console? If yes, then this library is for you. It provides a simple and powerful
interface to get input from the user and display the output on the console.
```c++
    #include "iostream"
    #include <string>
    using namespace std;
    int main(){
        cout<<"Enter a number: ";
        int num = cin>>num;
        cout << "You entered: " << num << endl;
        cout<<"Enter a string: ";
        string str = cin>>str;
        cout << "You entered: " << str << endl;
        return 0;
    }
```
_Not that good, there should be a prettier and simple way to do this._

## Installation
Download the source code from this repository and include the `c_io.hpp` file
in your environment. Then you are free to use the library.
## Usage
The library provides a simple interface to get input from the user and display
the output on the console. The library is divided into two parts:
1. `input()` - This function is used to get input from the user. It takes a
   string as a parameter which is displayed on the console to ask the user for input. 
   Also, you need to specify the type that the function will return, before
   the function call parenthesis `input<type>("prompt message")`. It returns the input entered by the user.
   An example of this function is:
```c++
    #include "c_io.hpp"
    #include<string>
    using namespace std;
    int main(){
        int num = input<int>("Enter an integer: ");
        cout << "You entered: " << num << endl;
        //You don't even need to declare the type of the variable
        auto str = input<string>("Enter a string: ");
        cout << "You entered: " << str << endl;
        return 0;
    } //You don't need the cout statements as well, but we are not there yet :)    
```

2. `log()` - This function is used to display the output on the console. It takes
   only one argument which is the output to be displayed on the console. It displays 
   the output on the console and returns nothing.
   An example of this function is:
```c++
    #include "c_io.hpp"
    #include<string>
    using namespace std;
    int main(){
        int num = input<int>("Enter an integer: ");
        log(num);
        auto str = input<string>("Enter a string: ");
        log(str)
        return 0;
    } 
```
```c++
    #include "c_io.hpp"
    #include<string>
    using namespace std;
    int main(){
        auto name = input<string>("Enter your name: ");
        auto surname = input<string>("Enter your surname: ");
        log("Hello, " + name + " " + surname);
        /*Without log function you would have to write:
        cout << "Hello, " << name << " " << surname << endl;*/
        return 0;
    } 
```
Also, the `log()` function has a support for arrays, vectors, lists, queues, stacks and maps. Once you
give one of these as the parameter to the `log()` function, it will display the contents of the
container on the console. Some examples are:
```c++
    #include "c_io.hpp"
    using namespace std;
    int main(){
        int array[] = {1,2,3,4,5};
        //For arrays, log function needs to array's length as second argument
        //You can pass the length manually or use the len() function provided by the library
        log(array, 5); //Output: [1,2,3,4,5]
        log(array,len(array));
        log(array,sizeof(array)/sizeof(array[0]));
        //Or you can pass its type instead of length
        log(array, type="ARR"); //Output: [1,2,3,4,5]
        //ATTENTION! only ARR is allowed as type parameter
        return 0;
    }
```
If you want to write the STL containers, you have second parameter which is the separator
between the elements of the container. The default separator is a one width space (`" "`). Some examples are:
```c++
    #include "c_io.hpp"
    #include<vector>
    using namespace std;
    int main(){
        //define a vector
        vector<int> vec;
        //push 1,2,3,4,5 into the vector
        for(int i = 1; i <= 5; i++)
            vec.push_back(i);
        //log the vector
        log(vec,","); //Output: 1,2,3,4,5
        return 0;		
    } 
```
```c++
    #include "c_io.hpp"
    #include<list>
    using namespace std;
    int main(){
        //define a list
        list<int> list;
        //push 1,2,3,4,5 into the list
        for(int i = 1; i <= 5; i++)
            list.push_back(i);
        //log the list
        log(list,"->"); //Output: 1->2->3->4->5
        return 0;
    } 
```
```c++
    #include "c_io.hpp"
    #include<queue>
    using namespace std;
    int main(){
        //define a queue
        queue<int> queue;
        //push 1,2,3,4,5 into the queue
        for(int i = 1; i <= 5; i++)
            queue.push(i);
        //log the queue
        log(queue,"|"); //Output: 1|2|3|4|5
        return 0;		
    } 
```
```c++
    #include "c_io.hpp"
    #include<stack>
    using namespace std;
    int main(){
        //define a stack
        stack<string> stack;
        //push "A","B","C" into the stack
        stack.push("library!");
        stack.push("amazing");
        stack.push("What an");
        //log the stack
        log(stack); //Output: What an amazing library!
        return 0;		
    } 
```
```c++
    #include "c_io.hpp"
    #include<map>
    using namespace std;
    int main(){
      //define a map
      map<string, int> map;
      //insert some key-value pairs into the map
      map.insert({"one",1});
      map.insert({"two",2});
      map.insert({"three",3});
      //log the map
      log(map); //Output: {one:1,two:2,three:3}
      int my_value = map["one"]; //my_value = 1
      //define a hash_map
      log(my_value); //Output: 1       
      return 0;
    } 
```
## Contributing
Pull requests are welcome. For major changes, 
please open an issue first to discuss what you would like to change.
Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)

## Version
1.1.0

## What does `c_iolib` mean?
It stands for `console input/output library`.

### Developer Notes
I'm not a C++ guru. This library only aims to provide a simple and powerful interface to get 
input from the user and display the output on the console. For these reasons I built this library
on top of the `iostream` library. I'm aware of there are some more performant ways of what I did
via dealing with more low-level details. If you have any suggestions or improvements, please feel 
free to open an issue or a pull request. I'll be happy to learn from you.