#include <iostream>
using namespace std;

class Stack{
	int arr[10];
	int top;
	int max;
	public:
		Stack(){
			top = 0;
			for(int i = 0; i < 10; i++){
				arr[i] = -1;
			}
			max = 10;
		}
		
		void Push(int a){
			if(top == max){
				cout  << " Stack is full" << endl;
				return;
			}
			arr[top] = a;
			top++;
			cout << "Added sucesfully" << endl;	
		}
		void Pop(){
			if(top == 0){
				cout << "Stack is empty" << endl;
			}
			else{
				top -= 1;
				arr[top] = -1;
				cout << "Removed sucessfully" << endl;
			}
		}
		void display(){
			for(int i = 0; i < 10 ; i++){
				cout << arr[i] << " " ;
			}
			cout << endl;
		}
};
int main(){
	Stack s1;
	s1.Push(12);
	s1.Push(25);
	s1.Push(17);
	s1.Push(31);
	s1.Push(44);
	s1.Push(19);
	s1.display();
	s1.Pop();
	s1.Pop();
	s1.Pop();
	s1.display();
	s1.Push(52);
	s1.display();
	s1.Pop();
	s1.Pop();
	s1.display();
	return 0;
}
