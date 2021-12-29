#include "ControllingPointers.h"

//template<typename T>
//void ControllingPointers::control(const shared_ptr<T>& pointer, const string& className, const string& functionName) {
//
//    try {
//        if(pointer == nullptr){
//            throw nullptrException(className, functionName);
//        }
//    }
//    catch (nullptrException& exception){
//        cout << exception.what_() << endl;
//        exit(1);
//    }
//
//}

void ControllingPointers::control(const shared_ptr<logic::Subject>& subject, const string& className, const string& functionName) {

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

void ControllingPointers::control(const shared_ptr<logic::Observer> &observer, const string &className, const string &functionName) {

    try {
        if(observer == nullptr){
            throw nullptrException(className, functionName);
        }
    }
    catch (nullptrException& exception){
        cout << exception.what_() << endl;
        exit(1);
    }
}

void ControllingPointers::control(const shared_ptr<logic::EntityFactory> &factory, const string& className, const string& functionName) {

    try {
        if (factory == nullptr) {
            throw nullptrException(className, functionName);
        }
    }
    catch (nullptrException &exception) {
        cout << exception.what_() << endl;
        exit(1);
    }
}