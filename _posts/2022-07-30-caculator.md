'''cpp

#include <iostream>
#include <fstream>
#include <stack>


using namespace std;

template <typename T>
class Base {
protected:
	T operand;
public:
	Base(T operand = 0) { this->operand = operand; }
	virtual double operator& (Base op2) { // 가상함수. 피연산자에 따라 서로 다른 연산을 하도록 동일한 
		double newOperand;               // 연산자를 중복해서 작성(operator overloading)
		newOperand = this->operand + op2.operand;
		return newOperand;
	}
};

template <typename T> // 계산기 클래스는 기본 클래스를 상속
class Plus : public Base<T> { // 사칙 연산을 연산자 (operator)로 구현
public:
	Plus(T operand = 0) { this->operand = operand; }
	virtual double operator& (Plus op2) { // 가상함수 오버라이딩. Base의 operator&은 존재감 상실
		double newOperand;
		newOperand = this->operand + op2.operand;
		return newOperand;
	}
};

template <typename T>
class Minus : public Base<T> { // 사칙 연산을 연산자 (operator)로 구현
public:
	Minus(T operand = 0) { this->operand = operand; }
	virtual double operator& (Minus op2) { // 피연산자에 따라 서로 다른 연산을 하도록 동일한 
		double newOperand;               // 연산자를 중복해서 작성(operator overloading)
		newOperand = this->operand - op2.operand;
		return newOperand;
	}
};

template <typename T>
class Multiply : public Base<T> { // 사칙 연산을 연산자 (operator)로 구현
public:
	Multiply(T operand = 0) { this->operand = operand; }
	virtual double operator& (Multiply op2) { // 피연산자에 따라 서로 다른 연산을 하도록 동일한 
		double newOperand;               // 연산자를 중복해서 작성(operator overloading)
		newOperand = this->operand * op2.operand;
		return newOperand;
	}
};

template <typename T>
class Divide : public Base<T> { // 사칙 연산을 연산자 (operator)로 구현
public:
	Divide(T operand = 0) { this->operand = operand; }
	virtual double operator& (Divide op2) { // 피연산자에 따라 서로 다른 연산을 하도록 동일한 
		double newOperand;               // 연산자를 중복해서 작성(operator overloading)
		newOperand = this->operand / op2.operand;
		return newOperand;
	}
};

void findMDOperand(double& operand2, double& operand1, stack<double>& operandSt, double& newOperand, stack<char>& symbolSt) {
	operand2 = operandSt.top(); // 스택은 후입선출. 현재 top은 연산자 뒤 피연산자이므로 operand2에 저장
	operandSt.pop();
	operand1 = operandSt.top(); // 현재 top은 연산자 앞 피연산자이므로 operand1에 저장
	operandSt.pop();
	if (symbolSt.top() == '*') {
		Multiply<double> multiply1(operand1);
		Multiply<double> multiply2(operand2);
		newOperand = multiply1 & multiply2; // Base의 operator& 재정의한 연산(*) 수행
	}
	else if (symbolSt.top() == '/') {
		Divide<double> divide1(operand1);
		Divide<double> divide2(operand2);
		newOperand = divide1 & divide2; // Base의 operator& 재정의한 연산(/) 수행
	}
	symbolSt.pop(); // 수행한 연산자 삭제
	operandSt.push(newOperand); // 연산 결과 연산자 스택에 저장
}

void findPMOperand(double& operand2, double& operand1, stack<double>& operandSt, double& newOperand, stack<char>& symbolSt) {
	operand1 = operandSt.top(); // 스택의 순서 뒤집어 주었기 때문에 현재 top은 연산자 앞 피연산자
	operandSt.pop();
	operand2 = operandSt.top(); // 현재의 top은 연산자 뒤 피연산자
	operandSt.pop();
	if (symbolSt.top() == '+') {
		Plus<double> plus1(operand1);
		Plus<double> plus2(operand2);
		newOperand = plus1 & plus2; // Base의 operator& 재정의한 연산(+) 수행
	}
	else if (symbolSt.top() == '-') {
		Minus<double> Minus1(operand1);
		Minus<double> Minus2(operand2);
		newOperand = Minus1 & Minus2; // Base의 operator& 재정의한 연산(-) 수행
	}
	symbolSt.pop();
	operandSt.push(newOperand);
}

int main() {
	ofstream fout("c:\\temp\\output.txt"); // 파일 열기. output.txt 파일을 열고, 출력 스트림 생성
	int num; // 피연산자 수
	double operand1, operand2, newOperand; // operand: 특정 연산자의 피연산자1,2 newOperand: 특정 연산자의 연산 결과
	stack<double> operandStack; // *, / 연산에 사용할 피연산자 스택 --> +, - 보다 *, /이 우선순위 높으므로 스택 따로 생성
	stack<double> operandStack2; // +, - 연산에 사용할 피연산자 스택
	stack<char> symbolStack; // *, / 연산에 사용할 연산자 스택
	stack<char> symbolStack2; // +, - 연산에 사용할 연산자 스택

	while (true) {

		cout << "피연산자의 개수를 입력하세요(종료: 0) >> ";
		cin >> num;

		if (num == 0) {
			cout << "계산기를 종료합니다.";
			break;
		}

		double* operand = new double[num]; // 피연산자 개수만큼 피연산자(double)배열 동적할당
		char* symbol = new char[num - 1]; // 연산자 개수만큼 연산자(char)배열 동적할당 --> 연산자는 피연산자보다 하나 적음

		cout << "식을 입력하세요 ( +, -, *, / ) >> ";
		for (int i = 0; i < num - 1; i++) {
			cin >> operand[i] >> symbol[i];
		}
		cin >> operand[num - 1]; // 피연산자가 연산자보다 하나 많으므로 피연산자배열의 n-1인덱스에 한 번 더 입력받음

		try { // 0으로 나누는 경우 오류를 탐지하고 예외 처리한다
			for (int i = 0; i < num - 1; i++) {
				if (symbol[i] == '/' && operand[i + 1] == 0) // 연산자 symbol[i]의 피연산자는 operand[i]와 operand[i+1]
					throw operand[i + 1];
			}
		}

		catch (double x) {
			cout << "예외 발생!! " << x << "으로 나눌 수 없음" << endl;
			cout << endl;
			continue;
		}

		operandStack.push(operand[0]); // 피연산자의 수 = 연산자의 수 + 1  (연산자 앞 피연산자)
		for (int i = 0; i < num - 1; i++) {
			symbolStack.push(symbol[i]); // 입력받은 순서대로 연산자 스택에 연산자 저장
			operandStack.push(operand[i + 1]); // 입력받은 순서대로 피연산자 스택에 피연산자 저장  (연산자 뒤 피연산자)
			if (symbolStack.top() == '*' || symbolStack.top() == '/') { // +, -, *, / 중 *와 /을 먼저 계산해야함 --> 스택에 연산자 넣을 때마다 검사
				findMDOperand(operand2, operand1, operandStack, newOperand, symbolStack); // *와 /의 피연산자 찾아서 계산
			}
		}

		int stsize = symbolStack.size();
		operandStack2.push(operandStack.top()); // 스택은 후입선출. 식의 앞에서부터 연산하기 위해 스택의 순서 뒤집기
		operandStack.pop();
		for (int t = 0; t < stsize; t++) {
			symbolStack2.push(symbolStack.top());
			symbolStack.pop();
			operandStack2.push(operandStack.top());
			operandStack.pop();
		}

		while (symbolStack2.size() != 0) { // 모든 연산 완료할 때까지
			if (symbolStack2.top() == '+' || symbolStack2.top() == '-') {
				findPMOperand(operand1, operand2, operandStack2, newOperand, symbolStack2);  // +와 -의 피연산자 찾아서 계산
			}
		}

		cout << "연산 결과: " << operandStack2.top() << endl << endl; // operandStack2에 연산 완료한 값만 남아있음
		fout << operandStack2.top() << endl; // 파일에 출력

		delete[] operand;
		delete[] symbol;
	}
	fout.close();
}
'''
