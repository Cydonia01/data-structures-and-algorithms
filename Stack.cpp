#include<iostream>
#include<stdlib.h>

using namespace std;

class StackArray {
public:
	int size;
	int *A;
	int top;
	
	StackArray(int size) {
		this->size = size;
		A = new int[size];
		top = -1;
	}
	
	~StackArray() {
		delete []A;
	}
	
	void push(int x) {
		if (top == size - 1) cout<<"Stack Overflow";
		else A[++top] = x;
	}
	
	int pop() {
		int x = -1;
		if (top == -1) {
			cout<<"Stack Underflow ";
			return x;
		}
		else {
			x = A[top];
			A[top--] = 0;
			return x;
		}
	}
	
	int peek(int pos) {
		int index = top - pos + 1;
		
		if (index < 0 || index > top) {
			cout<<"Invalid Position ";
			return -1;
		}
		else return A[index];
	}
	
	int StackTop() {
		if (top == -1) return -1;
		return A[top];
	}
	
	
	int isEmpty() {
		return (top == -1);
	}
	
	int isFull() {
		return (top == size - 1);
	}
	
	void Display() {
		for (int i = 0; i < top + 1; i++)
			cout<<A[i]<<" ";
	}
};


// Parenthesis Matching

int isBalance(char *infix) {
	StackArray stack(100);
	for (int i = 0; i < infix[i] != '\0'; i++) {
		if (infix[i] == '(') stack.push(infix[i]);
		else if (infix[i] == ')') {
			if (stack.isEmpty()) return false;
			stack.pop();
		}	
	}
	if (stack.isEmpty()) return true;
	else return false;
}

int isBalanceAdvanced(char *infix) {
	StackArray stack(100);
	for (int i = 0; i < infix[i] != '\0'; i++) {
		if (infix[i] == '(' || infix[i] == '[' || infix[i] == '{') stack.push(infix[i]);
		else {
			if (stack.isEmpty()) return false;
			if (infix[i] == ')') {
				if (stack.StackTop() == '(') stack.pop();
				else return false;
			}
			
			if (infix[i] == ']') {
				if (stack.StackTop() == '[') stack.pop();
				else return false;
			}
			
			if ( infix[i] == '}') {
				if (stack.StackTop() == '{') stack.pop();
				else return false;
			}
		}
	}
	if (stack.isEmpty()) return true;
	return false;
}

int isBalanceAdvancedV2(char *infix) {
	StackArray stack(100);
	for (int i = 0; i < infix[i] != '\0'; i++) {
		if (infix[i] == '(' || infix[i] == '[' || infix[i] == '{') stack.push(infix[i]);
		else if (infix[i] == ')' || infix[i] == ']' || infix[i] == '}') {
			if (stack.isEmpty()) return false;
			
			int x = infix[i];
			int top = stack.StackTop();
			
			if (x + top == 81 || x + top == 184 || x + top == 248) stack.pop();
			else return false;
		}
	}
	if (stack.isEmpty()) return true;
	return false;
}


// Infix to Postfix

int pre(char c) {
	if (c == '+' || c == '-') return 1;
	else if (c == '*' || c == '/') return 2;
}

int pre2(char c) {
	if (c == '+' || c == '-') return 1;
	else if (c == '*' || c == '/') return 2;
	else return 3;
}

int strlen(char* str) {
	int i = 0;
	while (str[i] != '\0') i++;
	return i;
}

char* InfixToPostfixV1(char *infix) {
	StackArray stack(10);
	int i = 0, j = 0;
	char *postfix = new char[strlen(infix) + 1];
	
	while (infix[i] != '\0') {
		if (infix[i] != '+' && infix[i] != '-' && infix[i] != '*' && infix[i] != '/')
			postfix[j++] = infix[i++];
		else {
			if (pre(infix[i]) > pre(stack.StackTop())) 
				stack.push(infix[i++]);
			else {
				postfix[j++] = stack.pop();
			}
		}
	
	}
	while (!stack.isEmpty())
		postfix[j++] = stack.pop();
	
	postfix[j] = '\0';
	return postfix;
}

char* InfixToPostfixV2(char *infix) {
	StackArray stack(4);
	char *postfix = new char[strlen(infix) + 1];
	int p = 0;
	for (int i = 0; infix[i] != '\0'; i++) {
		if (pre2(infix[i]) <= pre2(stack.StackTop())) {
			while (!stack.isEmpty() && pre2(infix[i]) <= pre2(stack.StackTop()))
				postfix[p++] = stack.pop();
				
			stack.push(infix[i]);
		}
		else stack.push(infix[i]);
	}

	while (!stack.isEmpty()) {
		postfix[p++] = stack.pop();
	}
	
	postfix[p] = '\0';
	return postfix;
}

int EvalPostfix(char *postfix) {
	StackArray stacks(10);
	int ans;
	int first, second;
	int i = 0;
	char op;
	for (int i = 0; i < postfix[i] != '\0'; i++) {
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
			op = postfix[i];
			second = stacks.pop();
			first = stacks.pop();
			switch (op) {
				case '+':
					ans = first + second;
					break;
				case '-':
					ans = first - second;
					break;
				case '*':
					ans = first * second;
					break;
				case '/':
					ans = first / second;
					break;
			}
			stacks.push(ans);
		}
		else {
			stacks.push(postfix[i] - '0');
		}
	}
	return ans;
}

int main() {
	
	return 0;
}
