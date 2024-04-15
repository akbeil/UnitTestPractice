#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}


bool Password::has_mixed_case(string phrase) {
  bool mixed = false;
  bool uppercase = false;
  bool lowercase = false;

  for(int i=0; i < phrase.length(); i++) {
    if(phrase[i] >= 65 && phrase[i] <= 90) {
      uppercase = true;
    }
    if(phrase[i] >= 97 && phrase[i] <= 122) {
      lowercase = true;
    }
  }
  if(uppercase == true && lowercase == true){
    mixed = true;
  }

  return mixed;
}