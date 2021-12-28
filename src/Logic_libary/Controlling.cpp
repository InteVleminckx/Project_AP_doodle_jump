#include "Controlling.h"

void Controlling::control(const shared_ptr<logic::Subject> &subject, const string className, const string functionName) {

    try {
        if(subject == nullptr){
            throw nullptrException(className, functionName);
        }
    }
    catch (nullptrException& exception){
        cout << exception.what_() << endl;
        exit(1);
    }

}
