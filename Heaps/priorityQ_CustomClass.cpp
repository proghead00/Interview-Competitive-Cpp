#include <iostream>
#include <queue>
using namespace std;

class Person
{
public:
    string name;
    int age;

    Person(string n, int a)
    {
        name = n;
        age = a;
    }
};

class PersonCompare
{
public:
    bool operator()(Person p1, Person p2)
    {
        return p1.age < p2.age;
    }
};

int main()
{
    int n;
    cin >> n;

    priority_queue<Person, vector<Person, PersonCompare>> pq;

    for (size_t i = 0; i < n; i++)
    {
        string name;
        int age;

        cin >> name >> age;

        Person p(name, age);
        pq.push(p);
    }
    int k = 3;
    for (size_t i = 0; i < k; i++)
    {
        Person P = pq.top();
        cout << P.name << " " << P.age << endl;
        pq.pop();
    }
}
