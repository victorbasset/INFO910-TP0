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
  string clair = readInput( cin );
  cout << chiffreVigenere( clair, argv[1] ) << endl;
}
