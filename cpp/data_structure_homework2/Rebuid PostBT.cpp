#include <iostream>
#include <string>

class Tree{
public:
    void build(std::string pre,std::string in){
        if(pre.empty()) return;
        char root=pre[0];
        int pos=in.find(root);
        //左
        build(pre.substr(1,pos),in.substr(0,pos));
        //右
        build(pre.substr(pos+1),in.substr(pos+1));
        std::cout<<root;
    }
};

int main(){
    Tree t;
    std::string pre,in;
    while(std::cin>>pre>>in){
        t.build(pre,in);
        std::cout<<'\n';
    }
    return 0;
}