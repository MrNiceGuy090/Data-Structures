#include <iostream>
using namespace std;
struct stiva{
    int info;
    stiva *next;
} *varf;

int pop(){
    int i=-1;
    stiva *stk = varf;
    if(varf!=NULL){
        varf = varf->next;
        i=stk->info;
        delete stk;
    }
    return i;
}
void push(int k){

    stiva *node =new stiva  ;
    node->info = k;
    node->next = varf;
    varf = node;
}
int check(){
    int n,a;
cin>>n;
for (int i=1;i<n;i++){
    cin>>a;
    if(varf == NULL)push(a);
    else {

    if(a > varf->info){
        push(a);
        }
    else if(a == varf->info) pop();
    else return 0;         }

                    }
    return 1;
}
int main()
{
   cout<<check();
    return 0;
}





