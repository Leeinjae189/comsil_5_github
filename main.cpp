#include <iostream>
#include "LinkedList.h"
using namespace std;

void prnMenu(){
    cout<<"*******************************************"<<endl;
    cout<<"* 1. Insert    2. Delete    3. Print   4. Quit *"<<endl;
    cout<<"*******************************************"<<endl;
    cout<<endl;
    cout<<"choose menu: ";
}

int main(){
    // 스택 및 연결 리스트 테스트용 코드
    int mode, selectNumber, tmpItem;
    LinkedList<int> *p;
    bool flag = false;

    cout<<"Choose  data structure(1: Stack, Other: Linked List): ";
    cin>>mode;


    if(mode == 1)
        p = new Stack<int>();    // 정수를 저장하는 스택
    else
        p = new LinkedList<int>();    // 정수를 저장하는 연결 리스트

	// 처리 부분
    do{
        prnMenu();
        cin>>selectNumber;
        switch(selectNumber){ 
        case 1:
            cout<<"Insert Vaule: ";
            cin>>tmpItem;    p->Insert(tmpItem);
            cout<<tmpItem<<" has been inserted."<<endl;
            break;
        case 2:
            if(p->Delete(tmpItem)==true)
                cout<<tmpItem<<" has been deleted."<<endl;
            else cout<<" empty. failed"<<endl;
            break;
        case 3:
            cout<<"size: "<<p->GetSize()<<endl;
            p->Print();
            break;
        case 4:
            flag = true;     break;
        default:
            cout<<" wrong inserted."<<endl;
            break;
        }
        if(flag) break;
    } while(1);
    return 0;
}
