#include <iostream>

class Content {
public:
    explicit Content(int id) : id(id) {
        std::cout << "create " << std::to_string(id) << std::endl;
    }

    ~Content() {
        std::cout << "destroy " << std::to_string(id) << std::endl;
    }

private:
    int id{-1};
    char data[1024]{};
};

class SharedContainer {
public:
    explicit SharedContainer(int mem_id) {
        Content* myContent = new Content(mem_id);
        _data = myContent;
        _ref_count =  new int;
        *_ref_count = 1;
    }

    ~SharedContainer() {
        (*_ref_count)--;
        if (*_ref_count == 0) {
            delete _data;
        }
    }

    SharedContainer(const SharedContainer &other) {
        _data = other._data;
        _ref_count = other._ref_count;
        (*_ref_count)++;
    }
    //TODO
    SharedContainer& operator=(const SharedContainer &other) {
        if (_ref_count != nullptr && *_ref_count != 0) {
            (*_ref_count)--;
            if (*_ref_count == 0) {
                (*_ref_count)++;
                delete _data;
            }
        } 
        _data = other._data;
        _ref_count = other._ref_count;
        (*_ref_count)++;
        return *this;
    }

    int get_count() const {
        return *_ref_count;
    }

    SharedContainer(const SharedContainer &&) = delete;
    SharedContainer &operator=(const SharedContainer &&) = delete;

private:
    Content *_data{nullptr};
    //TODO: design your own reference counting mechanism
    int* _ref_count;
};

void test1(){
    SharedContainer m1(1);
    SharedContainer m2 = m1;
    SharedContainer m3(m2);
    std::cout << m1.get_count() << std::endl;
    std::cout << m2.get_count() << std::endl;
    std::cout << m3.get_count() << std::endl;
}

void test2(){
    SharedContainer m1(1);
    SharedContainer m2 = m1;
    m1 = m1;
    {
        SharedContainer m3 = m1;
        std::cout << m1.get_count() << std::endl;
    }
    std::cout << m1.get_count() << std::endl;
    std::cout << m2.get_count() << std::endl;
}

void test3(){
    SharedContainer m1(1);
    SharedContainer m2(2);
    m1 = m2;
    std::cout << m1.get_count() << std::endl;
    std::cout << m2.get_count() << std::endl;
    {
        SharedContainer m3(3);
        m1 = m3;
        std::cout << m1.get_count() << std::endl;
        std::cout << m2.get_count() << std::endl;
        std::cout << m3.get_count() << std::endl;
    }
    std::cout << m1.get_count() << std::endl;
    std::cout << m2.get_count() << std::endl;

}

int main(){
    test1();
    test2();
    test3();
    return 0;
}