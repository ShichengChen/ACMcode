#include<iostream>
using namespace std;
//#define INF 10000;
int list[10000];//lastlist[10000];
int number,num,target,ex,lastindex,iterative;
bool search(int index,int lastindex,int target)
{
	int current=list[index];
	for(int i=0;i<=number-num+1;i++)
	{
		current*=2;
		if(current>target)return false;
	}
	return true;	
}
void dfs(int index,int target)
{
     if(num==number)return;//���߽���ֹ�����ݹ���ȥ��
     if(search(index,lastindex,target)){ex=1;return;}//��֦ 
     for(int i=index;i>=0;i--)
     {
             list[index+1]=list[index]+list[i];
             if(list[index+1]==list[index-1]*2)break;//��֦
             if(list[index+1]>target)continue;
             if(list[index+1]==target)
			 {
                        iterative=0;ex=1;lastindex=index+1;
                        break;
	         }
	         //for(int i=0;i<=index+1;i++)cout<<" ."<<list[i]<<".";
             if(list[index+1]<target)
             {
                        num++;
                        dfs(index+1,target);
                        num--; 
                        if(ex==1)return; //��ס���˳��ݹ�ĵط������˳� 
             }
     }
}
int main()
{
    while(cin>>target)
    {
                 iterative=1;number=3;    //����number ��num����Ԥ�ȿ��Ʊ߽�Ķ�����д����ʱһ��Ҫע��߽��ѡ����ú�index����һ�� 
                 list[0]=1;list[1]=2;
				 if(!target)break;
                 if(target==1){cout<<1<<endl;continue;}
                 else if(target==2){cout<<1<<" "<<2<<endl;continue;}//һ��ע��1.2���ֵı߽�ֵ 
                 while(iterative)
                 {
                                 num=1;number++; ex=0;
                                 dfs(1,target);  
                 }
                 for(int i=0;i<=lastindex;i++)
                 {
                         if(i==0)cout<<list[i];
                         else cout<<" "<<list[i];
                 }
                 cout<<endl;
    }
    return 0;
}
