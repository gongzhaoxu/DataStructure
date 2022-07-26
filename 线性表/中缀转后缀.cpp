/*
* 中缀表达式转后缀表达式
*
*/

#include <iostream>
#include <vector>
#include <stack>


using namespace std;

vector<string> RPN(vector<string> notation) {
	stack<string> s;//操作符栈，暂存不能确定顺序的运算符
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
								res.push_back(s.top());
								s.pop();
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
								res.push_back(s.top());
								s.pop();
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
				res.push_back(s.top());
				s.pop();
			}
			s.pop();//弹出 ( ，(不加入逆波兰式
		}
		else {//遇到操作数
			res.push_back(str);
		}
	}
	//处理完所有字符后，将栈中剩余运算符一次弹出加入后缀表达式。
	while (!s.empty()) {
		res.push_back(s.top());
		s.pop();
	}
	return res;
}

int main() {
	vector<string> notation1 = { "A","+","B","*","(","C","-","D",")","-","E","/","F" };
	vector<string> notation2 = { "(","(","15","/","(","7","-","(","1","+","1",")",")",
		")","*","3",")","-","(","2","+","(","1","+","1" ,")",")" };
	vector<string> notation3 = { "(","(","6","/","2","*","(","3","+","4",")",")",
		"+","1",")","*","3","/","(","(","32","+","4",")" ,"-","3" ,"*","11",")" };//22
	vector<string> res1 = RPN(notation1);
	vector<string> res2 = RPN(notation2);
	vector<string> res3 = RPN(notation3);
	for (string str : res1) {
		cout << str << " ";
	}
	cout << endl;
	for (string str : res2) {
		cout << str << " ";
	}
	cout << endl;
	for (string str : res3) {
		cout << str << " ";
	}
	cout << endl;

}
