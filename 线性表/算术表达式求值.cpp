/*
* �������ʽ��ֵ��������׺���ʽת��׺���ʽ�����Ժ�׺���ʽ��ֵ��
*
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;
/*
* ���㺯������������������ջ�����ţ��Լ�����������ջ��2��Ԫ�ؽ�������
*/
void  CalCulate(stack<string>& s, stack<int>& operand) {
	string op = s.top();
	s.pop();

	int right = operand.top();
	operand.pop();
	int left = operand.top();
	operand.pop();

	if (op == "+") {
		operand.push(left + right);
	}
	else if (op == "-") {
		operand.push(left - right);
	}
	else if (op == "*") {
		operand.push(left * right);
	}
	else {
		operand.push(left / right);
	}
}

int RPN(vector<string> notation) {

	stack<string> s;//������ջ���ݴ治��ȷ��˳��������
	stack<int> operand;//������ջ

	vector<string> res;//�洢�沨��ʽ

	for (string str : notation) {
		if (str == "+" || str == "-" || str == "*" || str == "/") {
			if (str == "+" || str == "-") {
				if (!s.empty()) {
					while (true) {
						if (!s.empty()) {
							if (s.top() == "(") {
								break;
							}
							else {
								CalCulate(s, operand);
							}
						}
						else {
							break;
						}
					}
				}
			}
			else {// * or /
				if (!s.empty()) {
					while (true) {
						if (!s.empty()) {
							if (s.top() == "(" || s.top() == "+" || s.top() == "-") {
								break;
							}
							else {
								CalCulate(s, operand);
							}
						}
						else {
							break;
						}
					}
				}
			}
			s.push(str);//ѹ�뵱ǰ�����
		}
		else if (str == "(") {
			s.push(str);
		}
		else if (str == ")") {
			while (s.top() != "(") {//���ε���ջ��������������沨��ʽ

				CalCulate(s, operand);

			}
			s.pop();//���� ( ��(����������
		}
		else {//����������
			operand.push(stoi(str));
		}
	}
	//�����������ַ��󣬽�ջ��ʣ�������һ�ε��������׺���ʽ��
	while (!s.empty()) {
		CalCulate(s, operand);
	}
	return operand.top();
}

int main() {
	vector<string> notation1 = { "(","(","15","/","(","7","-","(","1","+","1",")",")",
		")","*","3",")","-","(","2","+","(","1","+","1" ,")",")" };//5

	vector<string> notation2 = { "(","(","6","/","2","*","(","3","+","4",")",")",
		"+","1",")","*","3","/","(","(","32","+","4",")" ,"-","3" ,"*","11",")" };//22

	int res1 = RPN(notation1);
	int res2 = RPN(notation2);
	cout << res1 << endl;
	cout << res2;
}
