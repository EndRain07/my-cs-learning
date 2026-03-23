#include<iostream>
#include<vector>  //vector的头文件
#include<algorithm> //算法模板

/*vector基础语法*/
std::vector <int> v;
void do_vector(){
    v.push_back(5);  //1.加入元素（注意读取访问依旧不能越界）
    std::cout<<v[0]<<" 第一个加入的元素"<<'\n';  

    std::cout<<v.size()<<" 当前元素个数1"<<'\n';  //2.获取元素个数
    v.push_back(4);
    for(int i=0;i<v.size();i++){
        std::cout<< v[i] << ' ' ;
    }   std::cout<<"现在的两个元素"<<'\n';

    v.pop_back(); //3.删除最后一个元素(不能空弹vector)
    std::cout<<v.size()<<" 删除一个后的个数"<<'\n';

    v={1,2,3};
    v.clear(); //清空所有元素
    std::cout<<v.size()<<" 清空后的个数"<<'\n';
}

/*vector排序*/
bool cmp(int a,int b){
    return a>b;
}

void sort_vector(){
    v={5,6,2,1,3};
    sort(v.begin(),v.end(),cmp);  //无cmp默认升序
    for(int i=0;i<v.size();i++){
        std::cout<< v[i] << ' ' ;
    }   std::cout<<" 排序后的元素"<<'\n';
    
}    

/*vector多重数组*/

int main(){

    do_vector();
    sort_vector();
}