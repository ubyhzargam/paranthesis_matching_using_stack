//
//  main.cpp
//  paranthesis_matching_using_stack
//
//  Created by Uby H on 29/07/23.
//

#include <iostream>
using namespace std;
struct Stack
{
    int size;
    int top;
    char *s;
};
int len(char *s)
{
    int i;
    for(i=0;s[i]!='\0';i++){}
        return i;
}
void push(struct Stack *p,char x)
{
    if(p->top==p->size-1)
    {
        cout<<"Stack overflow"<<endl;
    }
    else
    {
        p->top++;
        p->s[p->top]=x;
    }
}
void pop(struct Stack *p)
{
    if(p->top==-1)
        cout<<"Stack underflow"<<endl;
    else
    {
        p->top--;
    }
}
bool isEmpty(struct Stack p)
{
    if(p.top==-1)
        return true;
    else
        return false;
}
int isBalance(char *exp)
{
    struct Stack st;
    st.size=len(exp);
    st.top=-1;
    st.s=new char[st.size];
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
        {
            push(&st,exp[i]);
        }
        else if(exp[i]==')')
        {
            if(isEmpty(st)) return 0;
            else
            {
                pop(&st);
            }
        }
    }
    if(isEmpty(st)) return 1;
    else return 0;
}
int main()
{
    char s[100]="(x+2)*(1!)(+(2))";
    if(isBalance(s))
        cout<<"The paranthesis in the expression are balanced "<<endl;
    else
        cout<<"The paranthesis in the expression are not balanced"<<endl;
    return 0;
}
