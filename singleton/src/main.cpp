#include <iostream>
#include <functional>

struct SingletonTester
{
    template <typename T>
    bool is_singleton(std::function<T *()> factory)
    {
        return factory() == factory();
    }
};

class SingletonClass 
{
    static int instances_created;

    static std::shared_ptr<SingletonClass> instance;

protected:
    SingletonClass(){ SingletonClass::instances_created++; }

public:    
    SingletonClass(const SingletonClass& rhs) = delete;
    void operator= (const SingletonClass& rhs) = delete;

    static std::shared_ptr<SingletonClass> get()
    {
        if(!SingletonClass::instance)
            SingletonClass::instance.reset(new SingletonClass());

        return SingletonClass::instance;
    }

    friend std::ostream& operator<< (std::ostream& o, const SingletonClass& s)
    {
        o << "Instances created so far " << s.instances_created;
        return o;
    }
};

int SingletonClass::instances_created = 0;
std::shared_ptr<SingletonClass> SingletonClass::instance;

struct NotSingleton {};

int main(void)
{
    SingletonTester tester;
    std::cout << "Is singleton SingletonClass? " << tester.is_singleton<SingletonClass>([](){ return SingletonClass::get().get(); }) << std::endl;
    std::cout << "Is singleton NotSingleton? " << tester.is_singleton<NotSingleton>([](){ return new NotSingleton(); }) << std::endl;

    return 0;
}