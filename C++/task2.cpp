#include <iostream>

using namespace std;

class B1 {
public:
    B1() { cout << "Building object" << name << endl; }
    ~B1() { cout << "Removing object" << name << endl; }
private:
    string name = "B1";
};

class V1: public B1 {
public:
    V1() { cout << "Building object" << name << endl; }
    ~V1() { cout << "Removing object" << name << endl; }
private:
    string name = "V1";
};
class D1: virtual public V1 {
public:
    D1() { cout << "Building object" << name << endl; }
    ~D1() { cout << "Removing object" << name << endl; }
private:
    string name = "D1";
};

class B2 {
public:
    B2() { cout << "Building object" << name << endl; }
    ~B2() { cout << "Removing object" << name << endl; }
private:
    string name = "B2";
};
class B3 {
public:
    B3() { cout << "Building object" << name << endl; }
    ~B3() { cout << "Removing object" << name << endl; }
private:
    string name = "B3";
};
class V2: public B1, public B2 {
public:
    V2() { cout << "Building object" << name << endl; }
    ~V2() { cout << "Removing object" << name << endl; }
private:
    string name = "V2";
};
class D2: virtual public V2, public B3 {
public:
    D2() { cout << "Building object" << name << endl; }
    ~D2() { cout << "Removing object" << name << endl; }
private:
    string name = "D2";
};

class M1 {
public:
    M1() { cout << "Building object" << name << endl; }
    ~M1() { cout << "Removing object" << name << endl; }
private:
    string name = "M1";
};
class M2 {
public:
    M2() { cout << "Building object" << name << endl; }
    ~M2() { cout << "Removing object" << name << endl; }
private:
    string name = "M2";
};

class X: public D1, public D2 {
public:
    X() { cout << "Building object" << name << endl; }
    ~X() { cout << "Removing object" << name << endl; }
private:
    string name = "X";
    M1 m1;
    M2 m2;
};

int main(int argc, const char * argv[]) {

    X objectX;
    
    return 0;
}
