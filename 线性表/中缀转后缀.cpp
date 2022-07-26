/*
* ��׺���ʽת��׺���ʽ
*
*/

#include <iostream>
#include <vector>
#include <stack>


using namespace std;

vector<string> RPN(vector<string> notation) {
	stack<string> s;//������ջ���ݴ治��ȷ��˳��������
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
			s.push(str);//ѹ�뵱ǰ�����
		}
		else if (str == "(") {
			s.push(str);
		}
		else if (str == ")") {
			while (s.top() != "(") {//���ε���ջ��������������沨��ʽ
				res.push_back(s.top());
				s.pop();
			}
			s.pop();//���� ( ��(�������沨��ʽ
		}
		else {//����������
			res.push_back(str);
		}
	}
	//�����������ַ��󣬽�ջ��ʣ�������һ�ε��������׺���ʽ��
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
