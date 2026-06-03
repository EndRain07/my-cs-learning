#include <iostream>
#include <string>
using namespace std;

class BinTree
{
private:
    string inOrd;  
    string postOrd; 
public:
    BinTree(string in, string post) : inOrd(in), postOrd(post) {}
    //获左
    string getLeftPost()
    {
        char root = postOrd.back();
        int pos = inOrd.find(root);
        return postOrd.substr(0, pos);
    }

    //右
    string getRightPost()
    {
        char root = postOrd.back();
        int pos = inOrd.find(root);
        int leftLen = pos;
        return postOrd.substr(leftLen, postOrd.size() - leftLen - 1);
    }
};

int main()
{
    string in, post;
    char c;
    cin >> in >> post >> c;

    BinTree tree(in, post);
    if (c == 'L')
        cout << tree.getLeftPost();
    else
        cout << tree.getRightPost();

    return 0;
}