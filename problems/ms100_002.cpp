#include <stack>
#include <iostream>
using namespace std;

class StackMin {
public:
	int top() {
		return raw_.top();
	}
	void push(int t) {
		raw_.push(t);
		if (min_.empty() || t <= min_.top()) {
			min_.push(t);
		}
	}
	void pop() {
		if (top() == min_.top()) {
			min_.pop();
		}
		raw_.pop();
	}
	int min() {
		return min_.top();	
	}
private:
	stack<int> raw_;
    stack<int> min_;
};

int main() {
	int i = 0;
	StackMin sk;
	sk.push(10);
	sk.push(7);
	sk.push(3);
	sk.push(3);
	sk.push(8);
	sk.push(5);
	sk.push(2);
	sk.push(6);
	cout << "min: " << sk.min() << endl;
	
	sk.pop();
	sk.pop();
	sk.pop();
	sk.pop();
	sk.pop();
	sk.pop();
	cout << "min: " << sk.min() << endl;

	sk.push(1);
	sk.push(9);
	cout << "min: " << sk.min() << endl;
}
