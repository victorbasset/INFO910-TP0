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
  
  if(argc > 2){
    freqs = frequencies( subtext(s, atoi(argv[1]), atoi(argv[2])) );
  }else{
    freqs = frequencies( s );
  }

  for(unsigned int i = 0; i < freqs.size(); i++){
    cout << (char) ('A' + i) << "=" << freqs[i] << " ";
  }

  cout << endl;
  cout << "Ic=" << coincidence(freqs) << " Ifrench=" << coincidence(frequenciesFrench()) << " Irand=" << coincidence(frequenciesRandom()) << endl;
}
