#include "Password.h"
#include <string>
#include <cctype>

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


/* Implementation A
bool Password::has_mixed_case(string str)
{
  bool has_lower = false;
  bool has_upper = false;
  for (char ch : str)
  {
    if (std::islower(ch))
    {
      has_lower = true;
    }
    else if (std::isupper(ch))
    {
      has_upper = true;
    }
  }
  return has_lower && has_upper;
}
*/
/*
// Implementation B
bool Password::has_mixed_case(string str)
{
  int count_lower = 0;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      count_lower++;
    }
  }
  return count_lower > 0 && count_lower < str.length();
}
*/
/*
// Implementation C
bool Password::has_mixed_case(string str)
{
  bool lower = false;
  bool upper = false;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      lower = true;
    }
    else if (str[i] >= 'A' && str[i] <= 'Z')
    {
      upper = true;
    }
  }
  return upper && lower;
}
*/
/*
// Implementation D
#include <cctype>
bool Password::has_mixed_case(string str)
{
  bool is_lower = false;
  bool is_upper = false;
  for (char c : str)
  {
    if (std::islower(c))
    {
      is_lower = true;
    }
    else
    {
      is_upper = true;
    }
  }
  return is_lower && is_upper;
}
*/
// Implementation E
bool Password::has_mixed_case(string str)
{
  bool found = false;
  for(char c : str){
    if( !found && c >= 'A' && c <= 'Z' ){
      found = true;
    }
    else if( found && c >= 'a' && c <= 'z'){
      return true;
    }
  }
  return false;
}
/*
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
*/

/*
  constructor sets the default password to "ChicoCA-95929"
  */
  Password::Password() {
    pass_history.push_back("ChicoCA-95926");

  }

  /*
  receives a password and sets the latest in pass_history to it if and only
  if it meets all criteria:
    1. The password is at least 8 letters long, but no longer than 20
    2. It has no more than 3 of the same leading characters
    3. It has mixed case (at least one upper case and at least one lower case)
    4. It was not a previous password in the history
  */
  void Password::set(string pass) {
    bool prevPass = true;
    bool firstThree = false;
    if(pass.length() >= 8 && pass.length() <= 20 && (count_leading_characters(pass) <= 3) && (has_mixed_case(pass) == true)) {
      firstThree = true;
    }
    for(int i=0; i < pass_history.size(); i++) {
      if(pass.compare(pass_history[i]) == 0) {
        prevPass = false;
      }
    }
    if(prevPass == true && firstThree == true) {
      pass_history.push_back(pass);
    }
  }

  /*
  receives a string and authenticates it against the latest password in the
  pass_history, returning true for an exact match or false when it does not match
  or if a password has not been set.
  */
  bool Password::authenticate(string pass) {
    int latest = pass_history.size() - 1;
    if(pass.compare(pass_history[latest]) == 0) {
        return true;
    }
    return false;
  }