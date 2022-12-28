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
        int a = cin>>a;
        cout << "You entered: " << a << endl;
        cout<<"Enter a string: ";
        string b = cin>>b;
        cout << "You entered: " << b << endl;
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
   string as an argument which is displayed on the console to prompt the user
   for input. Also, you need to specify the type that function will return, before
   the function call parenthesis `input<type>("prompt")`. It returns the input entered by the user.
    An example of this function is:
```c++
    #include "c_io.hpp"
    #include<string>
    using namespace std;
    int main(){
        int a = input<int>("Enter an integer: ");
        cout << "You entered: " << a << endl;
        //You don't even need to declare the type of the variable
        auto b = input<string>("Enter a string: ");
        cout << "You entered: " << b << endl;
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
        int a = input<int>("Enter an integer: ");
        log(a);
        auto b = input<string>("Enter a string: ");
        log(b)
        return 0;
    } 
```
Also, log function has a support for arrays, vectors, lists, queues and stacks. Once you
give one of these as the argument to the log function, it will display the contents of the
container on the console. Some examples are:
```c++
    #include "c_io.hpp"
    using namespace std;
    int main(){
        int array[] = {1,2,3,4,5};
        //For arrays, log function needs to array's length as second argument
        //You can pass the length manually or use the len() function provided by the library
        log(array, 5);
        log(array,len(array));
        log(array,sizeof(array)/sizeof(array[0]));
        //Or you can pass its type instead of length
        log(array, type="ARR");
        //ATTENTION! only ARR is allowed as type parameter
        return 0;
    } 
```
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
        log(vec);
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
        log(list);
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
        log(queue);
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
        stack.push("A");
        stack.push("B");
        stack.push("C");
        //log the stack
        log(stack);
        return 0;		
    } 
```
## Contributing
Pull requests are welcome. For major changes, 
please open an issue first to discuss what you would like to change.
Please make sure to update tests as appropriate.
## License
[MIT](https://choosealicense.com/licenses/mit/)

### What does `c_iolib` mean?
It stands for `console input/output library`.

### Developer Notes
I'm not a C++ guru. This library only aims to provide a simple and powerful interface to get 
input from the user and display the output on the console. For these reasons I built this library
on top of the `iostream` library. I'm aware of there are some more performant ways of what I did
via dealing with more low-level details. If you have any suggestions or improvements, please feel 
free to open an issue or a pull request. I'll be happy to learn from you.