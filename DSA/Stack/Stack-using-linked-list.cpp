#include<bits/stdc++.h>
using namespace std;
#define SIZE 1000
int stk[SIZE],top=-1;    

void Push()
{
    if(top+1==SIZE)
    {
        cout<<"stk full";
        return;
    }
    int el;
    cin>>el;
    stk[++top]=el;
}
void Pop()
{
    if(top==-1)
        cout<<"stk Empty\n";
    else
        top--;
}
void display()
{
    int i;
    for(i=top;i>=0;i--)
        cout<<stk[i]<<"->";
    cout<<"\n";
}

int main()
{
    int ch;
    while(true)
    {
        cout<<"OPTIONS:\n";
        cout<<"1. Push\n2. Pop\n3. Print the stk\n0. Exit\nEnter choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: Push();
                    break;
            case 2: Pop();
                    break;
            case 3: display();
                    break;
            case 0: exit(0);
        }
    }
}