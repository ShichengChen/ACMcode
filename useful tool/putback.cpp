#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a whole number��?" ;
    char ch;
    cin >> ch;
    while (isdigit(ch)==false)
        {cin>>ch;cout<<ch;}
    cin.putback(ch);
    int response;
    cin >> response;
    cout<<response<<endl;
    system("pause"); 

    return 0;
}
