#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

namespace CP {
template <typename T>
class queue {
protected:
    vector<T> mVect;

public:
    void push(const T& element) {
        mVect.push_back(element);
    }
    void pop(){
        mVect.erase(mVect.begin(),mVect.begin()+1);
    }
    bool empty() {
        return mVect.empty();
    }
    size_t size() {
        return mVect.size();
    }
    T& front() {
        return mVect.front();
    }
    T& back() {
        return mVect.back();
    }

};
}

void test1() {
    CP::queue<int> q;
    q.push(10);
    q.push(20);
    assert(q.back()==20);
    assert(q.front()==10);
}

void test2() {
    CP::queue<int> q;
    q.push(10);
    q.push(20);
    assert(q.back()==20);
    assert(q.front()==10);
    q.pop();
    assert(q.front()==20);
}

void test3() {
    CP::queue<int> q;
    for (int i=0; i<1000000; i++) {
        q.push(i%10);
    }
    assert(q.front()==0);
    assert(q.size()==1000000);
    assert(q.back()==9);
    q.pop();
    assert(q.empty()==false);
    assert(q.front()==1);
}

void test4() {
    CP::queue<int> q;
    for (int i=0; i<1000; i++) {
        q.push(i%10);
    }
    assert(q.size()==1000);
    vector<int> v;
    while (q.size()!=0) {
        v.push_back(q.front());
        q.pop();
    }
    assert(q.size()==0);
    assert(q.empty()==true);
    for (auto pos = v.end()-1; pos>=v.begin(); pos--) {
        q.push(*pos);
    }
    assert(q.size()==1000);
    assert(q.front()==9);
    assert(q.back()==0);
    assert(q.empty()==false);
}

int main() {
    test1(); cout << "test1 OK " << endl;
    test2(); cout << "test2 OK " << endl;
    test3(); cout << "test3 OK " << endl;
    test4(); cout << "test4 OK " << endl;

}
