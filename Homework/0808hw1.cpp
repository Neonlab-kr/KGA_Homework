#include <iostream>
#include <vector>

template <typename T>
class AnythingVector
{
private:
    std::vector<T> dataVector;
public:
    void push_back(T data);
    void printEveryData() const;
};

int main()
{
    std::vector<AnythingVector<int>> anythingVector;

    AnythingVector<int> first;
    first.push_back(1);

    AnythingVector<int> second;
    second.push_back(2);
    second.push_back(2);

    AnythingVector<int> third;
    third.push_back(3);
    third.push_back(3);
    third.push_back(3);

    anythingVector = { first,second };
    anythingVector.push_back(third);

    for (const AnythingVector<int>& v : anythingVector)
    {
        v.printEveryData();
    }

    return 0;
}

template <typename T>
void AnythingVector<T>::push_back(T data)
{
    dataVector.push_back(data);
}

template <typename T>
void AnythingVector<T>::printEveryData() const
{
    for (const T& data : dataVector)
    {
        std::cout << data << std::endl;
    }
}