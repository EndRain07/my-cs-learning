#include <iostream>

struct Node
{
    char val;
    Node* child[5];
    int num;
    Node(char c) : val(c), num(0)
    {
        for(int i = 0; i < 5; i++)
            child[i] = nullptr;
    }
};

class Tree
{
private:
    Node* nodeArr[26] = {nullptr};
    bool isSon[26] = {false};
public:
    Node* getNode(char ch)
    {
        int idx = ch - 'A';
        if(nodeArr[idx]==nullptr)
            nodeArr[idx] = new Node(ch);
        return nodeArr[idx];
    }

    void build(char fa, char ch)
    {
        Node* f = getNode(fa);
        Node* c = getNode(ch);
        f->child[f->num++] = c;
        isSon[ch-'A'] = true;
    }

    Node* findRoot()
    {
        for(int i=0;i<26;i++)
        {
            if(nodeArr[i]!=nullptr && !isSon[i])
                return nodeArr[i];
        }
        return nullptr;
    }

    void postOrder(Node* root, bool &first)
    {
        if(root == nullptr) return;
        //递归所有孩子
        for(int i=0;i<root->num;i++)
        {
            postOrder(root->child[i], first);
        }
        //2最后输出自己
        if(!first) std::cout << " ";
        first = false;
        std::cout << root->val;
    }
};

int main()
{
    Tree t;
    char f,s;
    while(std::cin >> f >> s)
    {
        t.build(f,s);
    }
    Node* root = t.findRoot();
    bool first = true;
    t.postOrder(root, first);
    return 0;
}