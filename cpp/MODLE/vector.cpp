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
    std::sort(v.begin(),v.end(),cmp);  //无cmp默认升序
    for(int i=0;i<v.size();i++){
        std::cout<< v[i] << ' ' ;
    }   std::cout<<" 排序后的元素"<<'\n';
    
}    

/*vector多重数组*/

void do_multiple_vector(){
    std::vector<std::vector<int>> b;
    std::vector<std::vector<int>> a(3,std::vector<int>(4));//三个，每个四个int，默认0
    a[0][0] = 1;
    a[1][2] = 5;
    a[2][3] = 9;

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[i].size(); j++){
            std::cout << a[i][j] << ' ';
        }
        std::cout << '\n';
    }
/*很有用：可以不同长度
std::vector<std::vector<int>> a = {
    {1, 2},
    {3, 4, 5},
    {6}
};
*/
}

/*vector强化循环*/
void range_for_vector(){
    std::vector<int> v = {1, 2, 3, 4, 5};

    for(int x : v){
        std::cout << x << ' ';
    }

    /*！！！如果要修改元素，要饮用：！！！！*/
    for(int& x : v){
    x *= 2;
    }
}

/*vector插入*/
void insert_vector(){
    std::vector<int> v = {1, 2, 4, 5};

    v.insert(v.begin() + 2, 3);//第二个位置（后）

    for(int x : v){
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

/*vector删除*/
void erase_vector(){
    std::vector<int> v = {1, 2, 3, 4, 5};

    v.erase(v.begin() + 2);
    //删除区间：v.erase(起点, 终点);  左闭右开 如：begin+1 ~ begin+4 是删除1-3
    for(int x : v){
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

/*resize, front, back, empty*/
void other_vector_operations(){
    std::vector<int> v = {1, 2, 3};

    v.resize(5, 9);

    std::cout << "resize 后：" << '\n';
    for(int x : v){
        std::cout << x << ' ';
    }
    std::cout << '\n';

    if(!v.empty()){
        std::cout << "第一个元素：" << v.front() << '\n';
        std::cout << "最后一个元素：" << v.back() << '\n';
    }//front 和 back空vector不能用
}



int main(){
    do_vector();
    sort_vector();
    do_multiple_vector();
    range_for_vector();
    insert_vector();
    erase_vector();
    other_vector_operations();

    return 0;
}