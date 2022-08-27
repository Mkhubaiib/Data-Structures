#include <iostream>
#include <string>
#include "Stack.h"


int main() {
	char ch;
	Stack S;
	string  prefix = "654+-328-/*"; //reverse given prefix expression;
	int length = prefix.size();
	int ans=0;
	int a,b;
	for (int i=0;i<length;i++)
		{
			ch = prefix[i];

			switch (ch)
			{
				case ('+'):
					a=S.pop()-'0';
					b=S.pop()-'0';
					ans = a+b;
					S.push(ans+'0');
					break;
				case ('-'):
					a=S.pop()-'0';
					b=S.pop()-'0';
					ans = a-b;
					S.push(ans+'0');
					break;
				case ('*'):
					a=S.pop()-'0';
					b=S.pop()-'0';
					ans = a*b;
					S.push(ans+'0');					
					break;	
				case ('/'):
					a=S.pop()-'0';
					b=S.pop()-'0';
					ans = a/b;
					S.push(ans+'0');						
					break;
			 	default:
				 	S.push(ch);		
			}
			
		}   
	cout <<" Infix Expression: " << prefix << endl;
	cout <<" Postfix Expression: "<< S.getTop()-'0' << endl;	
	return 0;

}


