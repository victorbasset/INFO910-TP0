#include <string>
#include <iostream>
#include <sstream>
#include "utils.h"

using namespace std;

string readInput( istream & in )
{
  ostringstream s( ostringstream::out );
  while ( in.good() )
    {
      char c;
      in >> c;
      s << c;
    }
  return s.str();
}

string filter_az( const std::string & s )
{
  ostringstream s2( ostringstream::out );
  for ( unsigned int i = 0; i < s.size(); ++i )
    {
      char c = s[ i ];
      if ( ( c >= 'a' ) && ( c <= 'z' ) )
	s2 << c;
      else if ( ( c >= 'A' ) && ( c <= 'Z' ) )
	s2 << (char) ( c-'A'+'a' );
    }
  return s2.str();
}

string filter_AZ( const std::string & s )
{
  ostringstream s2( ostringstream::out );
  for ( unsigned int i = 0; i < s.size(); ++i )
    {
      char c = s[ i ];
      if ( ( c >= 'a' ) && ( c <= 'z' ) )
	s2 << (char) ( c-'a'+'A' );
      else if ( ( c >= 'A' ) && ( c <= 'Z' ) )
	s2 << c;
    }
  return s2.str();
}

string subtext( const string & s, int every, int shift )
{
  ostringstream s2( ostringstream::out );
  for ( unsigned int i = shift; i < s.size(); i += every )
    s2 << s[ i ];
   return s2.str(); 
}

/**
   Le clair en minuscule.
   La clé est écrite en majuscule ("ADEF..DB").
   La sortie est en majuscule.
*/
string chiffreVigenere( const std::string & clair, const std::string & cle )
{
  ostringstream s2( ostringstream::out );
  for ( unsigned int i = 0; i < clair.size(); ++i ){
    char c = (toupper(clair[ i ]) + toupper(cle[i%cle.size()])) % 26 + 'A';
    s2 << c;
  }
  return s2.str();
}


vector<float> frequencies( const std::string & s )
{
  std::vector<float> result(26,0.0);
  for ( unsigned int i = 0; i < s.size(); ++i ){
    result[s[i] - 'A']+= 1.0 / s.size();
  }
  return result;
}

float coincidence( const std::vector<float> & f )
{
  float result = 0.0;
  for ( unsigned int i = 0; i < f.size(); ++i ){
    result += f[i] * f[i];
  }

  return result;
}
