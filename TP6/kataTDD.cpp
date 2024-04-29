#include <unordered_map>
#include <stdexcept>
#include <stdexcept>
#include <iostream>

using namespace std;

string hello() {
  return "Hello World!";
}


class RomanToDecimal {
public:
  RomanToDecimal(string romanNumeral) : mRomanNumeral(romanNumeral) {
    romanLetters = {{"I",1},{"V",5},{"X",10},{"C",50},{"L",100},{"D",500},{"M",1000}};

  }


  int getDecimal() {

    try{
        isRomanLetter("V");
    }
    catch(invalid_argument& e){
        cerr << e.what() << endl;
        
    }
    return romanLetters["mRomanNumeral"];
}
string getRomanNumeral(){
    return mRomanNumeral;
}
bool isRomanLetter(string romanLetter){
    bool test = romanLetters.find(romanLetter) == romanLetters.end();
    if (test) throw(invalid_argument("Ce n'est pas une lette romaine"));
    else return test;
}

private:
  string mRomanNumeral;
  unordered_map<string, int> romanLetters;
  int decimal = 0;

};

int main(){
    return 0;
}