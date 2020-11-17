#include <iostream>
using namespace std;

struct rez{
    int i,j;
};
struct coada{
    int lin, col;
    coada *prev, *next;
} *first, *last;

rez pop_left(){
    rez sol;
    sol.i = -1;
    sol.j = -1;
    coada *node = first;
    if (first){
         sol.i = node->lin;
         sol.j = node->col;
         if(first->next)  { first = first->next;
                            first->prev = NULL;
                            }
         else { first=NULL; last=NULL;}
         delete node;
    }
    return sol;
}
rez pop_right(){
    rez sol;
    sol.i = -1;
    sol.j = -1;
    coada *node = last;
    if (last){
            sol.i = node->lin;
            sol.j = node->col;
            if(last->prev) {last = last->prev;
                            last->next = NULL;
                            }
            else {last=NULL; first=NULL;}
            delete node;
    }
    return sol;
}

void push_right(int i, int j){
    coada *node =new coada;
    node->lin = i;
    node->col = j;
    node->prev = last;
    node->next = NULL;
    if(last!=NULL){
        last->next = node;
    }
    last = node;
    if(first==NULL)first = node;
}

void push_left(int i, int j){
    coada *node =new coada;
    node->lin = i;
    node->col = j;
    node->next = first;
    node->prev = NULL;
    if(first!=NULL){
        first->prev = node;
    }
    first = node;
    if(last==NULL)last = node;
}

int main()
{ int m, v[100][100],i,j, linie, coloana;
cin>>m;
for(i=1;i<=m;i++)
    for (j=1;j<=m;j++)
    cin>>v[i][j];

int nr=1;
for(i=1;i<=m;i++)
    for (j=1;j<=m;j++)
        if( v[i][j]==1 )
        {
            nr++;
            linie = i;
            coloana = j;
            push_right(i,j);
            v[i][j]=nr;

            while(first)
            {
                v[first->lin][first->col]=nr;
                if( v[first->lin+1][first->col]==1 ) push_right(first->lin+1, first->col);
                if( v[first->lin][first->col+1]==1 ) push_right(first->lin, first->col+1);
                if( v[first->lin-1][first->col]==1 ) push_right(first->lin-1, first->col);
                if( v[first->lin][first->col-1]==1 ) push_right(first->lin, first->col-1);
                pop_left();
            }

        }
cout<<endl;
for(int i=1;i<=m;i++){
    for (int j=1;j<=m;j++)
    cout<<v[i][j]<<" ";
    cout<<endl;}

    return 0;
}
