#include <iostream>

class MyContainer {
public:
    MyContainer(int size) : _size(size) {
        _data = new int[size];
        _size = size;
        _count++;
    }

    ~MyContainer() {
        _data = nullptr;
        _count--;
        _size = 0;
    }

    MyContainer(const MyContainer &Other) {
        _size = Other.size();
        _data = new int[_size];
        for (int i = 0; i < _size; i++) {
            *(_data + i) = *(Other.data() + i);
        }
        _count++;
    }

    MyContainer &operator=(const MyContainer &Other) {
        delete _data;
        _size = Other.size();
        _data = new int[_size];
        for (int i = 0; i < _size; i++) {
            *(_data + i) = *(Other.data() + i);
        }
        return *this;
    }

    int size() const {
        return _size;
    }

    int* data() const {
        return _data;
    }

    static int count() {
        return _count;
    }

    static int _count;

private:
    // C++11 引入的 initializer_list
    int *_data{nullptr};
    int _size{0};
};

int MyContainer::_count = 0;

void test1(){
    MyContainer m(5);
    std::cout << m.count() << std::endl;

    MyContainer m2(m);
    std::cout << m2.count() << std::endl;

    MyContainer m3 = m2;
    std::cout << m3.count() << std::endl;
}

void test2(){
    MyContainer m1(5);
    std::cout << m1.count() << std::endl;

    MyContainer m2 = m1;
    std::cout << m2.count() << std::endl;
    std::cout << (m2.data() == m1.data()) << std::endl;
}

void test3(){
    MyContainer m1(3);
    std::cout << m1.count() << std::endl;

    MyContainer m2 = m1;
    std::cout << m2.count() << std::endl;
    std::cout << (m2.data() == m1.data()) << std::endl;

    m1 = m2;
    std::cout << m1.count() << std::endl;
    std::cout << (m2.data() == m1.data()) << std::endl;

    m2 = m1;
    std::cout << m2.count() << std::endl;
    std::cout << (m2.data() == m1.data()) << std::endl;

    int * prev_ptr = m1.data();
    m1 = m1;
    std::cout << m1.count() << std::endl;
    std::cout << (m1.data() == prev_ptr) << std::endl;

}

void test4(){
    MyContainer m1(3);
    std::cout << m1.count() << std::endl;

    {
        MyContainer m2 = m1;
        std::cout << m2.count() << std::endl;
        std::cout << (m2.data() == m1.data()) << std::endl;

        m1 = m2;
        std::cout << m1.count() << std::endl;
        std::cout << (m2.data() == m1.data()) << std::endl;

        m2 = m1;
        std::cout << m2.count() << std::endl;
        std::cout << (m2.data() == m1.data()) << std::endl;

    }

    std::cout << m1.count() << std::endl;
}


int main(){
    test1();
    test2();
    test3();
    test4();
    return 0;
}