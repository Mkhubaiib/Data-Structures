#include<iostream>
#include<stack>
using namespace std;
class Quee
{
    private:
        stack <int> S1, S2;
    public:
        void inquee(int n)
        {
        S1.push(n);
        }
        int dequee()
        {    
            while (!S1.empty())
            {
            S2.push(S1.top());
            S1.pop(); 
            }
            int m=S2.top();
            S2.pop();

            while (!S2.empty()) {
                S1.push(S2.top());
                S2.pop();
        }
        return m;}
        

        int getFront()
        {
             while (!S1.empty())
            {
            S2.push(S1.top());
            S1.pop(); 
            }
            int n =  S2.top();
            while (!S2.empty()) {
                S1.push(S2.top());
                S2.pop();
        }
        return n;
        }
};

int main()
{
    Quee Q;
    Q.inquee(10);
    Q.inquee(20);
    Q.inquee(30);
    Q.inquee(40);
    Q.inquee(50);
    Q.inquee(60);
    Q.inquee(70);
    cout << Q.dequee();
    cout << Q.dequee();
    cout << " \n" << Q.getFront() << endl;
    cout << Q.dequee();
    cout << Q.dequee();
    cout << " \n" << Q.getFront() << endl;
    cout << Q.dequee();
    Q.inquee(90);
    cout << Q.dequee();

    return 0;
}