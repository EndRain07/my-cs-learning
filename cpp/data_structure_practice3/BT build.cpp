#include <iostream>
#include <stack>
#include <cstdio>

class BinaryTree
{
private:
    struct BiTNode
    {
        char data;
        BiTNode* lchild;
        BiTNode* rchild;
    };

    BiTNode* root;
    const char EMPTY = ' ';

    void destroyTree(BiTNode* node)
    {
        if (node != nullptr)
        {
            destroyTree(node->lchild);
            destroyTree(node->rchild);
            delete node;
            node = nullptr;
        }
    }

    void visit(char ch)
    {
        std::cout << ch << " ";
    }

    void create(BiTNode*& node)
    {
        char ch = getchar();
        if (ch == EMPTY)
        {
            node = nullptr;
        }
        else
        {
            node = new BiTNode;
            node->data = ch;
            create(node->lchild);
            create(node->rchild);
        }
    }

    void preTraverse(BiTNode* node)
    {
        if (node != nullptr)
        {
            visit(node->data);
            preTraverse(node->lchild);
            preTraverse(node->rchild);
        }
    }

public:
    BinaryTree()
    {
        root = nullptr;
    }

    ~BinaryTree()
    {
        destroyTree(root);
        root = nullptr;
    }

    void createTree()
    {
        create(root);
    }

    void preOrder()
    {
        preTraverse(root);
    }

    void inOrder1()
    {
        std::stack<BiTNode*> st;
        BiTNode* p = root;

        while (p != nullptr || !st.empty())
        {
            if (p != nullptr)
            {
                st.push(p);
                p = p->lchild;
            }
            else
            {
                p = st.top();
                st.pop();
                visit(p->data);
                p = p->rchild;
            }
        }
    }

    void inOrder2()
    {
        std::stack<BiTNode*> st;
        BiTNode* p;
        st.push(root);

        while (!st.empty())
        {
            while (!st.empty() && st.top() != nullptr)
            {
                st.push(st.top()->lchild);
            }
            st.pop();

            if (!st.empty())
            {
                p = st.top();
                st.pop();
                visit(p->data);
                st.push(p->rchild);
            }
        }
    }
};

int main()
{
    BinaryTree tree;
    tree.createTree();

    tree.preOrder();
    std::cout << std::endl;

    tree.inOrder1();
    std::cout << std::endl;

    tree.inOrder2();
    std::cout << std::endl;

    return 0;
}