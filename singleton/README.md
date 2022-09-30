# Singleton

A component that is instantiated only once.

Even the Gang of Four now considers it a code smell.

## Multiton

A variation is the Multiton, in which each singleton instance is associated with some sort of identification.

```cpp
template <typename T, typename Key = std::string>
class Multiton
{
    public:
        static std::shared_ptr<T> get(const Key& key)
        {
            if(const auto it = instances.find(key); it != instances.end())
                return it->second;
            
            auto instance = std::make_shared<T>();
            instances[key] = instance;
            return instance;
        }
    
    protected:
        Multiton() = default;
        virtual ~Multiton() = default;

    private:
        static std::map<Key, std::shared_ptr<T>> instances;
};

template <typename T, typename Key>
std::map<Key, std::shared_ptr<T>> Multiton<T,Key>::instances;
```

## Exercise solution

The solution is as simple as follows:

```cpp
#include <functional>
using namespace std;

struct SingletonTester
{
  template <typename T>
  bool is_singleton(function<T*()> factory)
  {
    return factory() == factory();
  }
};
```
