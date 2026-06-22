#include <iostream>
#include <vector>
#include <string>

struct Student
{
    int id;
    std::string name;
    int seat;
};

class StuQuery
{
private:
    std::vector<Student> stus;
    int targetId;

public:
    void readData()
    {
        int n;
        std::cin >> n;
        stus.resize(n);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> stus[i].id >> stus[i].name >> stus[i].seat;
        }
        std::cin >> targetId;
    }

    void query() const
    {
        for (const auto& s : stus)
        {
            if (s.id == targetId)
            {
                std::cout << s.name << " " << s.seat << std::endl;
                break;
            }
        }
    }
};

int main()
{
    StuQuery sq;
    sq.readData();
    sq.query();
    return 0;
}