/**
 *
 * @author VICTOR LUDO
 */
#include <string>
#include <iostream>
#include <iomanip>
#include "utils.h"
#include "freqs.h"

using namespace std;

int main( int argc, char** argv )
{
  string s = readInput( cin );
  vector<float> freqs;
 
  for(unsigned int n = 1; n <= (s.size()/10); n++){
    unsigned int nb_fr = 0;
    for(unsigned int shift = 0; shift <= n-1 ; shift++) {
        freqs = frequencies( subtext(s, n, shift) );
        if(isFrench(freqs)){
            nb_fr++;
        }
    }
    if(nb_fr == n){
        vector<char> cle(n);
        char c;
        for(unsigned int i = 0; i <= n-1; i++){
            cle[i] = c;
        }
       
    }
  }
}
