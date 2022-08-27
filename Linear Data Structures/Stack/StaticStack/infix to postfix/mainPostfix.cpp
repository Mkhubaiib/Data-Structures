#include <iostream>
#include <cstring>
#include <string>
#include "Stack.h"



int checkPresedence (char c)
{
	if (c=='*')
		return 2;
	else if (c=='/')
		return 2;
	else if(c=='+'||c=='-')
		return 1;
	else if (c=='^')
		return 3;
}

int main() {
	char ch;
	Stack S;
	string  infix = "4*a*c"; //  //(x^3+3*x^2)/(2*x+9)//(a*b-c) //x-c*b //((x+y)-a*b)/(2*d)
	string  postfix = ""; //""new string();
	int length = infix.size();

	cout << "infix length is " << length << endl;

	for (int i=0;i<length;i++)
		{
			ch = infix[i];
			cout << "Symbol " << ch <<endl;
			switch (ch)
			{
				case ('('):
					S.push(ch); 
					break;
				case (')'):
					while (S.getTop()!='('){
						ch = S.pop();
					 	postfix += ch;	
						}
					S.pop();
					break;

				case ('+'):
				case ('-'):
				case ('*'):
				case ('/'):
				case ('^'):
					
					while (!S.isEmpty())
					{
						if (S.getTop()=='(') break;
						if (checkPresedence(S.getTop()) < checkPresedence(ch)) break;
						postfix += S.pop();		
					}
					S.push(ch);
					break;
					
			 	default:
			 		postfix +=  ch;
				
			}
			
		}
	while (!S.isEmpty()) 
	   postfix += S.pop();
	   
	cout <<" Infix Expression:" << infix << endl;
	cout <<" Postfix Expression:" << postfix << endl;	
	
	return 0;
}
