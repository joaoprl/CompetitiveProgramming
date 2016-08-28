// F. Print Mix Strings

#include <iostream>
#include <cstdio>

using namespace std;

string old;

void printOut(string s1, int n1, string s2, int n2, char* s3, int n3){
  
  if(s1[n1] == 0){
    s3[n3] = 0;

    string cur;
    cur += s3;
    cur += s2.substr(n2);

    if(cur.compare(old) != 0){
      cout << cur << "\n";
      old = cur;
    }
    return;
  }

  if(s2[n2] == 0){
    s3[n3] = 0;

    string cur; 
    cur += s3;
    cur += s1.substr(n1);

    if(cur.compare(old) != 0){    
      cout << cur << "\n";
      old = cur;
    }
    return;
  }
    

  if(s2[n2] < s1[n1]){
    s3[n3] = s2[n2];
    printOut(s1, n1, s2, n2 + 1, s3, n3 + 1);
    
    s3[n3] = s1[n1];
    printOut(s1, n1 + 1, s2, n2, s3, n3 + 1);    

    return;
  }

  if(s1[n1] < s2[n2]){
    s3[n3] = s1[n1];
    printOut(s1, n1 + 1, s2, n2, s3, n3 + 1);
    
    s3[n3] = s2[n2];
    printOut(s1, n1, s2, n2 + 1, s3, n3 + 1);    

    return;
  }

  if(s1[n1] == s2[n2]){
    if(s1.substr(n1).compare(s2.substr(n2)) < 0){
      s3[n3] = s1[n1];
      printOut(s1, n1 + 1, s2, n2, s3, n3 + 1);

      int i = 0;
      while(s1[n1 + i] == s2[n2 + i]){
	s3[n3 + i] = s2[n2 + i];
	i++;
      }
      s3[n3 + i] = s2[n2 + i];
      i++;
      
      printOut(s1, n1, s2, n2 + i, s3, n3 + i);
    }

    else if (s1.substr(n1).compare(s2.substr(n2)) > 0){
      s3[n3] = s2[n2];
      printOut(s1, n1, s2, n2 + 1, s3, n3 + 1);

      int i = 0;
      while(s1[n1 + i] == s2[n2 + i]){
	s3[n3 + i] = s1[n1 + i];
	i++;
      }
      s3[n3 + i] = s1[n1 + i];
      i++;

      printOut(s1, n1 + i, s2, n2, s3, n3 + i);
    }
    else {
      printOut(s1, n1, s2, n2 + 1, s3, n3 + 1);
    }      
  }
}

int main(){
  int t;
  cin >> t;

  while(t--){
    string s1, s2;
    char* s3 = new char[20];
    cin >> s1 >> s2;
    printOut(s1, 0, s2, 0, s3, 0);
    cout << "\n";
  }
  
  return 0;  
}
