#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std; 

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  // dat.push_front("hello");
  // dat.push_back("good");
  // dat.push_back("bye");
  // dat.push_front("New");
  // dat.pop_front(); 

  dat.pop_front(); 
  cout << dat.size() << endl;
  for (int i = 0; i < dat.size(); i++) {
    cout << dat.get(i) << " "; 
  }
  cout << endl; 
  cout << "Front: " << dat.front() << "  Back: " << dat.back() << endl; 

}
