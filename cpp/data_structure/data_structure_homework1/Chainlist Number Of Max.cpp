#include <iostream>
#include <sstream>
#include <string>
#include <climits>  //使用INT_MIN

class linkedlist{
    private:
    int Maxim;
    struct Node{
    int value;
    Node* next;
    Node (int va) : value(va),next(nullptr) {}
    };

    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    std::size_t size_=0;

    
    public:
    linkedlist() : Maxim(-9999) {};

    ~linkedlist(){
        clear();
    };

    void push_back(int value){
        
        if(value > this->Maxim){
            Maxim=value;
        }
        Node* new_node = new Node(value);
        if(size_==0){
            tail_=new_node;
            head_=new_node;
        }
        else{
            tail_->next=new_node;
            tail_=new_node;
        }
        size_++;  //要在结点建造完成后再更新size_
    }

    int get_Number_of_Maximum(){
        Node* find=head_;
        int Maxnum=0;
        while(find!=nullptr){
            if(find->value==Maxim) Maxnum++;
            find=find->next;
        }
        return Maxnum;
    }
    void clear(){
        while(head_!=nullptr){
            Node* Cnode=head_;
            head_=head_->next;
            delete Cnode;
        }

        tail_=nullptr;
        size_=0;
    }
};



int main(){
    std::string s;
    getline(std::cin,s);
    std::istringstream ass(s);
    linkedlist list;
    int va;
    while(ass >> va){list.push_back(va);}
    std::cout<<list.get_Number_of_Maximum();

}