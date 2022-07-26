/*
* 算术表达式求值，包括中缀表达式转后缀表达式，并对后缀表达式求值。
*
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;
/*
* 计算函数，包括弹出操作符栈顶符号，以及弹出操作数栈顶2个元素进行运算
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

	stack<string> s;//操作符栈，暂存不能确定顺序的运算符
	stack<int> operand;//操作数栈

	vector<string> res;//存储逆波兰式

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
			s.push(str);//压入当前运算符
		}
		else if (str == "(") {
			s.push(str);
		}
		else if (str == ")") {
			while (s.top() != "(") {//依次弹出栈内运算符并加入逆波兰式

				CalCulate(s, operand);

			}
			s.pop();//弹出 ( ，(不参与运算
		}
		else {//遇到操作数
			operand.push(stoi(str));
		}
	}
	//处理完所有字符后，将栈中剩余运算符一次弹出加入后缀表达式。
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
