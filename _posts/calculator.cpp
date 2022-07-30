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
	virtual double operator& (Base op2) { // �����Լ�. �ǿ����ڿ� ���� ���� �ٸ� ������ �ϵ��� ������ 
		double newOperand;               // �����ڸ� �ߺ��ؼ� �ۼ�(operator overloading)
		newOperand = this->operand + op2.operand;
		return newOperand;
	}
};

template <typename T> // ���� Ŭ������ �⺻ Ŭ������ ���
class Plus : public Base<T> { // ��Ģ ������ ������ (operator)�� ����
public:
	Plus(T operand = 0) { this->operand = operand; }
	virtual double operator& (Plus op2) { // �����Լ� �������̵�. Base�� operator&�� ���簨 ���
		double newOperand;
		newOperand = this->operand + op2.operand;
		return newOperand;
	}
};

template <typename T>
class Minus : public Base<T> { // ��Ģ ������ ������ (operator)�� ����
public:
	Minus(T operand = 0) { this->operand = operand; }
	virtual double operator& (Minus op2) { // �ǿ����ڿ� ���� ���� �ٸ� ������ �ϵ��� ������ 
		double newOperand;               // �����ڸ� �ߺ��ؼ� �ۼ�(operator overloading)
		newOperand = this->operand - op2.operand;
		return newOperand;
	}
};

template <typename T>
class Multiply : public Base<T> { // ��Ģ ������ ������ (operator)�� ����
public:
	Multiply(T operand = 0) { this->operand = operand; }
	virtual double operator& (Multiply op2) { // �ǿ����ڿ� ���� ���� �ٸ� ������ �ϵ��� ������ 
		double newOperand;               // �����ڸ� �ߺ��ؼ� �ۼ�(operator overloading)
		newOperand = this->operand * op2.operand;
		return newOperand;
	}
};

template <typename T>
class Divide : public Base<T> { // ��Ģ ������ ������ (operator)�� ����
public:
	Divide(T operand = 0) { this->operand = operand; }
	virtual double operator& (Divide op2) { // �ǿ����ڿ� ���� ���� �ٸ� ������ �ϵ��� ������ 
		double newOperand;               // �����ڸ� �ߺ��ؼ� �ۼ�(operator overloading)
		newOperand = this->operand / op2.operand;
		return newOperand;
	}
};

void findMDOperand(double& operand2, double& operand1, stack<double>& operandSt, double& newOperand, stack<char>& symbolSt) {
	operand2 = operandSt.top(); // ������ ���Լ���. ���� top�� ������ �� �ǿ������̹Ƿ� operand2�� ����
	operandSt.pop();
	operand1 = operandSt.top(); // ���� top�� ������ �� �ǿ������̹Ƿ� operand1�� ����
	operandSt.pop();
	if (symbolSt.top() == '*') {
		Multiply<double> multiply1(operand1);
		Multiply<double> multiply2(operand2);
		newOperand = multiply1 & multiply2; // Base�� operator& �������� ����(*) ����
	}
	else if (symbolSt.top() == '/') {
		Divide<double> divide1(operand1);
		Divide<double> divide2(operand2);
		newOperand = divide1 & divide2; // Base�� operator& �������� ����(/) ����
	}
	symbolSt.pop(); // ������ ������ ����
	operandSt.push(newOperand); // ���� ��� ������ ���ÿ� ����
}

void findPMOperand(double& operand2, double& operand1, stack<double>& operandSt, double& newOperand, stack<char>& symbolSt) {
	operand1 = operandSt.top(); // ������ ���� ������ �־��� ������ ���� top�� ������ �� �ǿ�����
	operandSt.pop();
	operand2 = operandSt.top(); // ������ top�� ������ �� �ǿ�����
	operandSt.pop();
	if (symbolSt.top() == '+') {
		Plus<double> plus1(operand1);
		Plus<double> plus2(operand2);
		newOperand = plus1 & plus2; // Base�� operator& �������� ����(+) ����
	}
	else if (symbolSt.top() == '-') {
		Minus<double> Minus1(operand1);
		Minus<double> Minus2(operand2);
		newOperand = Minus1 & Minus2; // Base�� operator& �������� ����(-) ����
	}
	symbolSt.pop();
	operandSt.push(newOperand);
}

int main() {
	ofstream fout("c:\\temp\\output.txt"); // ���� ����. output.txt ������ ����, ��� ��Ʈ�� ����
	int num; // �ǿ����� ��
	double operand1, operand2, newOperand; // operand: Ư�� �������� �ǿ�����1,2 newOperand: Ư�� �������� ���� ���
	stack<double> operandStack; // *, / ���꿡 ����� �ǿ����� ���� --> +, - ���� *, /�� �켱���� �����Ƿ� ���� ���� ����
	stack<double> operandStack2; // +, - ���꿡 ����� �ǿ����� ����
	stack<char> symbolStack; // *, / ���꿡 ����� ������ ����
	stack<char> symbolStack2; // +, - ���꿡 ����� ������ ����

	while (true) {

		cout << "�ǿ������� ������ �Է��ϼ���(����: 0) >> ";
		cin >> num;

		if (num == 0) {
			cout << "���⸦ �����մϴ�.";
			break;
		}

		double* operand = new double[num]; // �ǿ����� ������ŭ �ǿ�����(double)�迭 �����Ҵ�
		char* symbol = new char[num - 1]; // ������ ������ŭ ������(char)�迭 �����Ҵ� --> �����ڴ� �ǿ����ں��� �ϳ� ����

		cout << "���� �Է��ϼ��� ( +, -, *, / ) >> ";
		for (int i = 0; i < num - 1; i++) {
			cin >> operand[i] >> symbol[i];
		}
		cin >> operand[num - 1]; // �ǿ����ڰ� �����ں��� �ϳ� �����Ƿ� �ǿ����ڹ迭�� n-1�ε����� �� �� �� �Է¹���

		try { // 0���� ������ ��� ������ Ž���ϰ� ���� ó���Ѵ�
			for (int i = 0; i < num - 1; i++) {
				if (symbol[i] == '/' && operand[i + 1] == 0) // ������ symbol[i]�� �ǿ����ڴ� operand[i]�� operand[i+1]
					throw operand[i + 1];
			}
		}

		catch (double x) {
			cout << "���� �߻�!! " << x << "���� ���� �� ����" << endl;
			cout << endl;
			continue;
		}

		operandStack.push(operand[0]); // �ǿ������� �� = �������� �� + 1  (������ �� �ǿ�����)
		for (int i = 0; i < num - 1; i++) {
			symbolStack.push(symbol[i]); // �Է¹��� ������� ������ ���ÿ� ������ ����
			operandStack.push(operand[i + 1]); // �Է¹��� ������� �ǿ����� ���ÿ� �ǿ����� ����  (������ �� �ǿ�����)
			if (symbolStack.top() == '*' || symbolStack.top() == '/') { // +, -, *, / �� *�� /�� ���� ����ؾ��� --> ���ÿ� ������ ���� ������ �˻�
				findMDOperand(operand2, operand1, operandStack, newOperand, symbolStack); // *�� /�� �ǿ����� ã�Ƽ� ���
			}
		}

		int stsize = symbolStack.size();
		operandStack2.push(operandStack.top()); // ������ ���Լ���. ���� �տ������� �����ϱ� ���� ������ ���� ������
		operandStack.pop();
		for (int t = 0; t < stsize; t++) {
			symbolStack2.push(symbolStack.top());
			symbolStack.pop();
			operandStack2.push(operandStack.top());
			operandStack.pop();
		}

		while (symbolStack2.size() != 0) { // ��� ���� �Ϸ��� ������
			if (symbolStack2.top() == '+' || symbolStack2.top() == '-') {
				findPMOperand(operand1, operand2, operandStack2, newOperand, symbolStack2);  // +�� -�� �ǿ����� ã�Ƽ� ���
			}
		}

		cout << "���� ���: " << operandStack2.top() << endl << endl; // operandStack2�� ���� �Ϸ��� ���� ��������
		fout << operandStack2.top() << endl; // ���Ͽ� ���

		delete[] operand;
		delete[] symbol;
	}
	fout.close();
}
