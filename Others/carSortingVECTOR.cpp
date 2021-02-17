#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Car
{

public:
    string car_name;
    int x, y;

    Car(string n, int x, int y)
    {
        car_name = n;
        this->x = x;
        this->y = y;
    }

    int distance()
    {

        return x * x + y * y;
    }
};

bool compare(Car A, Car B)
{

    int d_a = A.distance();

    int d_b = B.distance();

    if (d_a == d_b)
    {
        return A.car_name < B.car_name;
    }

    return d_a < d_b;
}

int main(int argc, const char **argv)
{

    int n;

    cin >> n;

    vector<Car> v;

    for (size_t i = 0; i < n; i++)
    {
        int x, y;

        string name;

        cin >> name >> x >> y;

        Car temp(name, x, y);

        v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);

    for (auto c : v)
    {
        cout << "Car: " << c.car_name << " Distance: " << c.distance() << " Location: " << c.x << "," << c.y << endl;
    }

    return 0;
}