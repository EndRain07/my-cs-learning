#include <iostream>
#include <vector>

class TreeRebuild
{
private:

    std::vector<int> pre;
    std::vector<int> post;
    std::vector<int> in;
    bool is_unique;

    int findPos(const std::vector<int>& arr, int l, int r, int val);
    void build(int preL, int preR, int postL, int postR);

public:

    TreeRebuild();
    void readData();
    void generate();
    bool isUnique() const;
    const std::vector<int>& getInOrder() const;
};

int TreeRebuild::findPos(const std::vector<int>& arr, int l, int r, int val)
{
    for (int i = l; i <= r; ++i)
    {
        if (arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}

void TreeRebuild::build(int preL, int preR, int postL, int postR)
{
    if (preL > preR)
        return;

    int root = pre[preL];
    if (preL == preR)
    {
        in.push_back(root);
        return;
    }

    int leftRoot = pre[preL + 1];
    int pos = findPos(post, postL, postR - 1, leftRoot);

    int leftSize = pos - postL + 1;
    int rightSize = postR - pos - 1;
    if (leftSize == 0 || rightSize == 0)
    {
        is_unique = false;
    }

    if (leftSize > 0 && rightSize > 0)
    {
        build(preL + 1, preL + leftSize, postL, pos);
        in.push_back(root);
        build(preL + leftSize + 1, preR, pos + 1, postR - 1);
    }
    else
    {
        build(preL + 1, preL, postL, pos);
        in.push_back(root);
        build(preL + 1, preR, postL, postR - 1);
    }
}

TreeRebuild::TreeRebuild()
{
    is_unique = true;
    pre.clear();
    post.clear();
    in.clear();
}

void TreeRebuild::readData()
{
    int n;
    std::cin >> n;
    pre.resize(n);
    post.resize(n);
    in.clear();
    is_unique = true;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> pre[i];
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> post[i];
    }
}

void TreeRebuild::generate()
{
    int n = pre.size();
    build(0, n - 1, 0, n - 1);
}

bool TreeRebuild::isUnique() const
{
    return is_unique;
}

const std::vector<int>& TreeRebuild::getInOrder() const
{
    return in;
}

int main()
{
    TreeRebuild tr;
    tr.readData();
    tr.generate();

    if (tr.isUnique())
        std::cout << "Yes\n";
    else
        std::cout << "No\n";

    const std::vector<int>& res = tr.getInOrder();
    for (std::size_t i = 0; i < res.size(); ++i)
    {
        if (i > 0)
            std::cout << " ";
        std::cout << res[i];
    }
    std::cout << std::endl;

    return 0;
}