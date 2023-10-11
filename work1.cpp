//#include <iostream>
#include "work1.h"
#include "work1_function.cpp"
using namespace std;

int main(){
    int **num;//double ptr
    int m=0;//列
    int n=0;//高
    cout<<"矩陣類型[m]x[n]"<<endl;
    cout<<"請輸入陣列[m]值:";
    cin>>m;
    cout<<"請輸入陣列[n]值:";
    cin>>n;

    num = new int*[m];//生成m個arr
    
    // 創建二維列
    int**  two_dimensional_array = new int*[m];//利用雙指標先創建列
    for (int i = 0; i < m; i++) 
    {
        two_dimensional_array[i] = new int[n];//使用for迴圈，將行補齊    
    }

    //插入亂數
    srand( time(NULL) );
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            two_dimensional_array[i][j] = rand() % 10;
        }
    }

    //顯示亂數
    cout<<"[";
    for (int i=0;i<m;i++)//m
    {
        cout<<"[";
        for (int j=0;j<n;j++)//n
        {
            if (j == n-1)
            {
                cout << two_dimensional_array[i][j];
            }
            else
            {
                cout << two_dimensional_array[i][j] << " ";
            }
        }
        if (i == m-1)
        {
            cout<<"]]"<<endl;
        }
        else
        {
            cout<<"]"<<endl;
        }
    }

  for (int i = 0; i < m; i++) 
    {
        delete[] two_dimensional_array[i];
    }
    delete[] two_dimensional_array;




    //class
    StringClassd str;
    StringClassd str2;
    char a[] ="apple";
    char b[] ="pen";
    char c[] ="PPAP";
    str.strCPY(a);
    cout<<"str 新插入的字串:";
    str.PrintString();
    cout<<"回傳字串str的長度:"<<str.strLEN()<<endl;
    cout<<"=========串聯b後========"<<endl;
    str.strCAT(b);
    str.PrintString();
    cout<<"設定新class str2:"<<endl;
    str2.strCPY(c);
    str2.PrintString();
    cout<<"將str+str2:";

    StringClassd str_add;
    str_add = (str + str2);
    str_add.PrintString();

    cout<<"在添加後的字串搜尋PPAP"<<endl;
    char find[] = "PPAP";
    if (str_add.FindString(find))
    {
        cout<<"有包含字串\n";
    }
    else
    {
        cout<<"查無字串"<<endl;
    }
    //cout<<"回傳值為:"<<str2.FindString(find)<<endl;
    cout<<"將str等化為str2後,str:";
    str = str2;
    str.PrintString();
    return 0;

}