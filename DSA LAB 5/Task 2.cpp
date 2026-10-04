#include <iostream>
using namespace std;

class TextEditor{
    string curr[10];
    string prev[10];
    int topC;
    int topP;

public:

    TextEditor(){
        topC = 0;
        topP = 0;

        for(int i = 0; i < 10; i++){
            curr[i] = "";
            prev[i] = "";
        }
    }

    void type(string s){
        if(topC == 10){
            cout << "Document is full" << endl;
            return;
        }

        curr[topC] = s;
        topC++;

        // New typing destroys redo history
        topP = 0;
    }

    void undo(){
        if(topC == 0)
            return;

        topC--;

        prev[topP] = curr[topC];
        topP++;
    }

    void redo(){
        if(topP == 0)
            return;

        topP--;

        curr[topC] = prev[topP];
        topC++;
    }

    void print(){
        for(int i = 0; i < topC; i++){
            cout << curr[i];

            if(i < topC - 1)
                cout << " ";
        }

        cout << endl;
    }
};

int main(){

    TextEditor t;

    t.type("Hello");
    t.print();

    t.type("World");
    t.print();

    t.undo();
    t.print();

    t.redo();
    t.print();

    t.undo();
    t.print();

    t.type("There");
    t.print();

    t.redo();       // Should do nothing
    t.print();

    return 0;
}


