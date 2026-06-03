#include <iostream>

struct Node
{
    char val;
    Node* child[5];
    int num; //实际孩子数量
    Node(char c) : val(c), num(0)
    {
        for(int i = 0; i < 5; ++i)
            child[i] = nullptr;
    }
};

class Tree
{
private:
    Node* nodeArr[26] = {nullptr}; 
    bool isSon[26] = {false};      //标记是否当过孩子
public:
    Node* getNode(char ch)
    {
        int pos = ch - 'A';
        if(nodeArr[pos] == nullptr)
            nodeArr[pos] = new Node(ch);
        return nodeArr[pos];
    }

    void build(char fa, char ch)
    {
        Node* f = getNode(fa);
        Node* c = getNode(ch);
        f->child[f->num++] = c;
        isSon[ch - 'A'] = true;
    }

    Node* findRoot()
    {
        for(int i = 0; i < 26; ++i)
        {
            if(nodeArr[i] != nullptr && isSon[i] == false)
                return nodeArr[i];
        }
        return nullptr;
    }

    //先根遍历
    void preOrder(Node* root)
    {
        static int first = 1;
        if(root == nullptr) return;
        if(!first) std::cout << " ";
        first = 0;
        std::cout << root->val;
        for(int i = 0; i < root->num; ++i)
        {
            preOrder(root->child[i]);
        }
    }
};

int main()
{
    Tree t;
    char f, s;
    while(std::cin >> f >> s)
    {
        t.build(f, s);
    }
    Node* root = t.findRoot();
    t.preOrder(root);
    return 0;
}