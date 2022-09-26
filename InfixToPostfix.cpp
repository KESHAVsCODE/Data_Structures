#include<iostream>
#include<vector>
#include<stack>
using namespace std;  //    WRONG CODE NOT RECCOMENDED NOT FULL FILL ACTUAL ALGO STEPS
int main()
{
    string q;
    string p;
    stack<char>s;
    stack<double>s1;
    cin>>q;
    for(int i=0;i<q.size();i++){
        if(q[i]>=48&&q[i]<=57){
            p+=q[i];
        }
        else if(q[i]=='(')
        {
            s.push('(');
        }
        else if(q[i]=='+'||q[i]=='-'){
            if(s.top()=='+'||s.top()=='-'||s.top()=='*'||s.top()=='/'){
                    p+=s.top();
                    s.pop();
                    s.push(q[i]);
            }
            else{
                s.push(q[i]);
            }

        }
        else if(q[i]=='*'||q[i]=='/'){
            if(s.top()=='*'||s.top()=='/'){
                p+=s.top();
                s.pop();
                s.push(q[i]);
            }
            else{
                s.push(q[i]);
            }

        }
        else if(q[i]==')'){
            while(s.top()!='('){
                    p+=s.top();
                    s.pop();
                  }
            s.pop();
        }
    }
    cout<<" "<<p;
//    double flag,you;
//    for(int i=0;i<p.size();i++){
//        if(p[i]>=48&&p[i]<=57){
//            s1.push(p[i]);
//        }
//        else if(p[i]=='+'||p[i]=='-'||p[i]=='*'||p[i]=='/'){
//            flag=s1.top();
//            s1.pop();
//            you=s1.top();
//            s1.pop();
//            if(p[i]=='+')
//                s1.push(flag+you);
//            else if(p[i]=='-')
//                s1.push(flag-you);
//            else if(p[i]=='*')
//                s1.push(flag*you);
//            else if(p[i]=='/')
//                s1.push(flag/you);
//        }
//    }
//    cout<<endl<<s1.top();
}
