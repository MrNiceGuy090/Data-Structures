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



int main()
{int n,nr=0,v[10001];
cin>>n;
for (int i=0;i<n;i++)
   {
     cin>>v[i];
     if (varf==NULL)push(v[i]);
     else if(v[i]!=varf->info) pop();
          else push(v[i]);

   }
if(varf){
    for(int i=0;i<n;i++)
       if(v[i]==varf->info) nr++;
    if(nr>n/2) cout<<varf->info<<endl;
    else cout<<"nu exista";
}
else cout<<"nu exista"<<endl;

    return 0;
}
