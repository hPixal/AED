#include <iostream>
#include <version>
#include <vector>
#include <map>
#include <list>
//#include "tree.hpp"
#include "btree.hpp"
//#include "util_tree.hpp"
//#include "str_convs.hpp"
using namespace aed;
using namespace std;

//typedef btree<int>::iterator bnode;

/*
    Este archivo es solo de ejemplo. Usalo para resolver los ejercicios, ya que este
    en esta carpeta especifica y con este nombre especifico, es el unico con el que 
    funciona la utilería de la catedra. Se puede usar como plantilla para luego cam
    biarle el nombre a uno más apropiado y entregarlo como resolción.
*/

////////////////////////////////////////////////////////////////////////////

bool isThere(const list<char> &l, const char &value){
    for(auto x : l){
        if(x == value) return true;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////

list<char> getProbList(const map<char,float> &A){
    list<char> probList;
    auto add = A.begin();
    while(probList.size() != A.size()){
        auto it = A.begin(); 
        while(it != A.end()){
            if(add->second > it->second && !isThere(probList,it->first)){
                add = it;
            }
        }
    }

    return probList;
}

////////////////////////////////////////////////////////////////////////////

void make_huffman_tree(btree<char> &huff,list<char> &prob,btree<char>::iterator add,list<char>::iterator lit)
{
    if(lit == prob.end()) return;
    add = huff.insert(add,*lit);

    btree<char>::iterator nextr = add.right();
    btree<char>::iterator nextl = add.left();
    
    make_huffman_tree(huff,prob,nextr,lit++);
    make_huffman_tree(huff,prob,nextl,lit++);
}

////////////////////////////////////////////////////////////////////////////


btree<char> make_huffman_tree(map<char,float> &A){
    auto prob = getProbList(A);
    btree<char> huff;
    make_huffman_tree(huff,prob,huff.begin(),prob.begin());

    return huff;
}

////////////////////////////////////////////////////////////////////////////
/*Extra: crear un arbol binario */
////////////////////////////////////////////////////////////////////////////

void create_btree(btree<int> &tr,btree<int>::iterator it,int level,int count){
    if(count > level) return;
    it = tr.insert(it,count/*int(rand()%40)*/);

    btree<int>::iterator nextr = it.right();
    btree<int>::iterator nextl = it.left();

    create_btree(tr,nextr,level,count+1);
    create_btree(tr,nextl,level,count+1);
}

void create_btree(btree<int> &tr,int level){
    tr.clear();
    create_btree(tr,tr.begin(),level,0);
}

int main(){
    btree<int> tr; btree<int> tr2;
    create_btree(tr,3); create_btree(tr2,4);


    // if(balanced(tr)) cout << "funciona" << endl;
    return 0;
}
