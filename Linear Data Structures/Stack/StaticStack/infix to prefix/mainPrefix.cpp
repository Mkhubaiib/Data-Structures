#include <iostream>
#include <cstring>
#include <string>
#include "Stack.h"



int checkPresedence (char c)
{
	if (c=='^')
		return 3;
	else if(c=='*' )
		return 2;
	else if(c=='/')
		return 2;
	else if(c=='+')
		return 0;
	else if(c=='-')
		return 0;
}
// Function to reverse a string
void reverseStr(string& str)
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
int main() {
	char ch;
	Stack S;
	string  infix = "((x^2-y^2+1)^2)+(4*x^2*y^2)"; 
	reverseStr(infix);//first inverse
	string  prefix = ""; //""new string();
	int length = infix.size();

	cout << "infix length is " << length << endl;

	for (int i=0;i<length;i++)
		{
			ch = infix[i];
			cout << "Symbol " << ch <<endl;
			switch (ch)
			{
				case '(':
					while (S.getTop()!=')'){
					ch = S.pop();
					prefix += ch;	
					}
					 S.pop();
					break;
				case ')':
					S.push(ch); 
					break;

				case ('+'):
				case ('-'):
				case ('*'):
				case ('/'):
				case ('^'):
				{
					while (!S.isEmpty())
					{
						if (S.getTop()==')') break;
						if (checkPresedence(S.getTop()) <= checkPresedence(ch)) break;				
						prefix += S.pop();
					}
					S.push(ch);
					break;
				}
			 	default:
			 		prefix +=  ch;
			} 		
			
			
		}
		while (!S.isEmpty()) 
	   prefix += S.pop();
	   
	cout <<" Inverse Expression: " << prefix << endl;
	
	string nprefix;
	for (int i=prefix.size()-1; i>=0; i--)
	{
		nprefix+=prefix[i];
	}

	cout <<" Prefix Expression: "<< nprefix << endl;	
	return 0;
}
