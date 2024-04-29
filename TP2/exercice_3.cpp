#include <iostream>
#include <string>

using namespace std;

class GrammaticallyCorrectMessage{
private : 
	string _number, _verb, _pluralModifier;
	
        void thereAreNoCandidates(){
        _number = string("no");
        _verb = string("are");
        _pluralModifier = string("s");
        }
	
        void thereIsOneCandidate(){
	_number = string("1");
        _verb = string("is");
        _pluralModifier = string("");
        }
	
        void thereAreMultipleCandidates(int count){
	char countTypeChar = char(count);
        _number = countTypeChar;
        _verb = string("are");
        _pluralModifier = string("s");
        }
public : 
	void assignValuesToMessageParts(int count){
                if (count == 0) thereAreNoCandidates();
                else if (count == 1) thereIsOneCandidate();
                else thereAreMultipleCandidates(count);
        }
        
        void createMessage(string candidate, int count){
        assignValuesToMessageParts(count);
        string message = "There " + _verb + " " + _number + " " + candidate + _pluralModifier + ".";
        cout << message << endl;
        } 
};
int main() {
    GrammaticallyCorrectMessage message;
    cout << endl;
    message.createMessage(string("Ambiance"),2);
    return 0;
}
