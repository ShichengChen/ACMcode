#include<iostream>
#include<string>
using namespace std; 
string order(string preorder,string inorder)   
{   
    if(preorder.size() == 1 || preorder.size() == 0)   //�ݹ���˳����� 
        return preorder;   
    else  
    if(inorder.size() == 1 || inorder.size() == 0)   //�ݹ���˳����� 
        return inorder;   
    else  
    {   
        int index = inorder.find(preorder[0]);   // �������һ���������е�λ��index 
        string lpo = preorder.substr(1,index);     
        string lio = inorder.substr(0,index);    
        
        string rpo = preorder.substr(index+1);   
        string rio = inorder.substr(index+1);   //��������������index��Ϊ������ 
        
        return order(lpo,lio) + order(rpo,rio) + inorder[index];   //����ѭ���ݹ� 
    }   
}

int main(){
    string s1,s2;
    cout<<"�������������У� "; 
    cin>>s1;
    cout<<"�������������У� "; 
    cin>>s2;
    cout<<"��������Ϊ�� "; 
    cout<<order(s1,s2)<<endl;
    system("pause");
    return 0;
}
