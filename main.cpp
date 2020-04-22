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
    // ���� �� ���� ����Ʈ �׽�Ʈ�� �ڵ�
    int mode, selectNumber, tmpItem;
    LinkedList<int> *p;
    bool flag = false;

    cout<<"Choose  data structure(1: Stack, Other: Linked List): ";
    cin>>mode;


    if(mode == 1)
        p = new Stack<int>();    // ������ �����ϴ� ����
    else
        p = new LinkedList<int>();    // ������ �����ϴ� ���� ����Ʈ

	// ó�� �κ�
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
