#define USECHRONO
#undef HAVE_MPI
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
using namespace aed;
using namespace std;

// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Gareis Nahuel
int DNI=43538493;

set<int> set_union(set<int> &A,set<int> &B){
    set<int> C;
    C.insert(A.begin(), A.end());
    C.insert(B.begin(), B.end());
    return C;
}
    
set<int> set_intersection(set<int> &A,set<int> &B){
    set<int> C;
    set<int>::iterator itA = A.begin(); 
    while(itA != A.end()){ 
        if(B.find(*itA) != B.end()){ 
            C.insert(*itA); 
        }
        ++itA; 
    }
    return C;
}
set<int> set_difference(set<int> &A,set<int> &B){
    set<int> C;
    set<int>::iterator itA = A.begin(); 
    while(itA != A.end()){ 
        if(B.find(*itA) == B.end()){ 
            C.insert(*itA); 
        }
        ++itA; 
    }
    return C;
}//

void set_classify(vector<set<int>> &VS,set<int> &S0,
                  int &asuperset,int &asubset,int &adisjoint,
                  int &aequal,int &aother) {
  asuperset = 0; asubset = 0; adisjoint = 0; aequal = 0;
  aother = 0;
  
  for(auto it = VS.begin(); it != VS.end() ; it++){
      auto auxsub = set_difference(*it,S0);
      auto auxsub2 = set_difference(S0,*it);
      
      auto auxad = set_intersection(S0,*it);
      
      auto auxsuper = set_difference(S0,*it);
      auto aux2super = set_difference(*it,S0);
      
      auto auxeq = set_difference(*it,S0);
      auto aux2eq= set_difference(S0,*it);
      
      if ((auxsub.size() == 0) && (auxsub2.size() != 0) )
      {
        asubset++;
      }else if( auxad.empty() )
      { 
        adisjoint++;
      }else if( (auxsuper.empty()) xor (aux2super.empty()) )
      { 
        asuperset++;
      }else if(auxeq.empty() && aux2eq.empty()){ 
        aequal++;
      }else{
       aother++;
      }
  }

}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(set_classify,vrbs);
  return 0;
} 