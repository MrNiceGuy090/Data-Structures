#include <iostream>
using namespace std;

struct coada{
    int info;
    coada *prev, *next;
} *first, *last;

int pop_left(){
    int i = -1;
    coada *node = first;
    if (first){
         i = node->info;
         if(first->next)  { first = first->next;
                            first->prev = NULL;
                            }
         else { first=NULL; last=NULL;}
         delete node;
    }

    return i;
}
int pop_right(){
    int i = -1;
    coada *node = last;
    if (last){
            i = node->info;
            if(last->prev) {last = last->prev;
                            last->next = NULL;
                            }
            else {last=NULL; first=NULL;}
            delete node;
    }
    return i;

}
void push_right(int k){

    coada *node =new coada;
    node->info = k;
    node->prev = last;
    node->next = NULL;
    if(last!=NULL){
        last->next = node;
    }
    last = node;
    if(first==NULL)first = node;
}
void push_left(int k){
    coada *node =new coada;
    node->info = k;
    node->next = first;
    node->prev = NULL;
    if(first!=NULL){
        first->prev = node;
    }
    first = node;
    if(last==NULL)last = node;
}


int main()
{

push_left(1);
push_right(2);
pop_right();
pop_left();
push_right(3);

coada *i = first;
while(i){
    cout<<i->info<<" ";
    i = i->next;
}
    return 0;
}
