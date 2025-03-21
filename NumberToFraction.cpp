//By UnqGit or Vishesh
#include <iostream>
#include <limits>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

static constexpr long double PI = 3.141592653589793238462643383279502884L;
static constexpr long double E = 2.718281828459045235360287471352662497L;
static constexpr long double PHI = 1.618033988749894848204586834365638118L;
static constexpr long double SQRT2 = 1.414213562373095048801688724209698079L;
static constexpr long double LN2 = 0.693147180559945309417232121458176568L;

bool isValidNumber(const string& str){
  bool decimalPoint = false;
  for(size_t i = 0; i < str.length(); i++) {
    if(!isdigit(str[i])){
      if(str[i] == '.' && !decimalPoint)decimalPoint = true;
      else if((str[i] == '-' || str[i] == '+') && i == 0)continue;
      else return false;
    }
  }
  return true;
}

int main(){
  cout.precision(0);
  cout << "Hi, this program will convert any number\ninto a fraction!\n";
  cout << "\nNOTE: if values are close to any real\nworld constants like pi, ln2, √2, phi or e,\n";
  cout << "the error will be shown about the precomputed\nvalues stored for those constants otherwise\nerror would be 0!\nBut the fractional value will be computed about\nthe value you provided!\n\n";
  cout << "———————————————————————————————————————————\n";
  while(true){  
    string input;
    double numb, midnum = 1, midden = 1, leftnum = 0, leftden = 1, rightnum = 1, rightden = 1;  
    cout << "Enter a number: ";
    getline(cin, input);
    if(!isValidNumber(input)) {
      cout << "\nTry a number dumbo!\n\n";
      continue;
    }
    numb = stod(input);
    if(numb == 0) cout << "\n0\n\n";
    else{
      bool neg = numb < 0;
      numb = neg ? -numb : numb;
      long double reference_num = 
      (abs(numb - PI) < 1e-6) ? PI :
      (abs(numb - E) < 1e-6) ? E :
      (abs(numb - PHI) < 1e-6) ? PHI :
      (abs(numb - SQRT2) < 1e-6) ? SQRT2 :
      (abs(numb - LN2) < 1e-6) ? LN2 :
      numb;
      long int improper_part = floor(numb);
      numb -= improper_part;
      if(numb > 0){
        for(int i = 0; abs(numb - midnum / midden) > 1e-12; i++){
          midnum = leftnum + rightnum;
          midden = leftden + rightden;
          if(numb == midnum / midden) break;
          else if(numb > midnum / midden) {
            leftnum = midnum;
            leftden = midden;
          }
          else{
            rightnum = midnum;
            rightden = midden;
          }
        }
      }
     if(improper_part > 0){
       if(midnum / midden != 1){
         cout.precision(0);
         if(neg){
           cout << "\n" << fixed << -improper_part << " - " << fixed << midnum << "/" << fixed << midden << "\n";
           cout << "Or: " << fixed << -improper_part * midden - midnum << "/" << fixed << midden << "\n";
         }
         else{
           cout << "\n" << fixed << improper_part << " + " << fixed << midnum << "/" << midden << "\n";
           cout << "Or: " << fixed << improper_part * midden + midnum << "/" << fixed << midden << "\n";
         }
         long double error = 100.0 * abs((improper_part * midden + midnum) / midden - reference_num) / reference_num;
         cout.precision(10);
         if(error == 0) cout << "Error: 0%\n\n";
         else cout << "Error: " << fixed << error << "%\n\n";
         }
         else{
           cout.precision(0);
           cout << "\n" << fixed << (neg ? -improper_part : improper_part) << "\n";
           cout << "Error: 0%\n\n";
         }
      }
      else{
        cout.precision(0);
        cout << "\n" << fixed << (neg ? -midnum : midnum) << "/" << fixed << midden << "\n";
        long double error = 100.0 * abs(midnum / midden - reference_num) / reference_num;
        cout.precision(10);
        if(error == 0) cout << "Error: 0%\n\n";
        else cout << "Error: " << fixed << error << "%\n\n";
      }
    }
    cout << "———————————————————————————————————————————\n";
  }
  return 0;
}
