#include "work1.h"

StringClassd::StringClassd()
{
    data = NULL;
    len=0;
}

StringClassd::~StringClassd()
{
    //delete data; //原來是delete在搞鬼!
    data = nullptr;
}


void StringClassd::strCPY(char* src) //複製
{
    if (data != NULL) {
        delete data;
        data =NULL;
    }
    data = new char[strlen(src) + 1]; //給予動態記憶體配置
    strcpy(data, src);
    len = strlen(data);//不含\0
}


void StringClassd::strCAT(char* str)//串接
{
    int input_len;
    bool flag;
    int temp=0;
    input_len = strlen(str);
    //cout<<"input_len:"<<input_len<<endl;
    char* char_plus = new char[(len+input_len+2)];//有兩組'\0'
    flag = true;//判斷是否為最後一個結尾"\0" T:第一段 F:第二段
    for (int i=0;i<(input_len+len+2);i++)
    {
        if (flag && data[i] !='\0')
        {
            char_plus[i]=data[i];
        }
        else if (flag && data[i] == '\0')
        {
            char_plus[i]=' ';//在此把第一段的'\0'更改為空格
            flag = false;//表示進入第二段
            //cout<<"Part2"<<endl;
            temp = i+1;
        }
        else
        {
            char_plus[i]=str[i-temp];//第二段內容一樣直接copy上去(含\0)
        }
    }

    //delete[] data;//完成後清除舊資料
    //data = NULL;
    len = strlen(char_plus);
    data = char_plus; //將指標轉向新陣列
    return;
}

unsigned StringClassd::strLEN()//回傳字串長度
{
    int len_cpy=0;
    len_cpy = len; 
    return len_cpy;
}

char* StringClassd::GetString()//取得字串
{
    char* data2pub = new char[len+1];
    strcpy(data2pub,data);
    return data2pub;
}

int StringClassd::FindString(char* src)//搜尋字串
{
    int counter =0;
    int goal_point = strlen(src) ;
    while (true)
    {
        if ((strlen(src)+counter) > len)//比對次數用盡時
        {
            return 0;//回傳False
        }

        int point = 0;
        for (int i=0;i<len;i++)
        {
            //cout<<"第"<<i+1<<"次比對"<<endl;
            if (data[i] == src[i-counter])
            {
                point++;
            }
            else
            {
                counter++;
                //cout<<"無效，跳脫迴圈\n";
                continue;
                
            }

            if (point == goal_point)//較驗是否完成比對
            {
                return 1;//回傳True;
            }
        }
    //cout<<"錯誤\n";
    }
    
}

int StringClassd::PrintString()
{
    for(int i=0;i<len;i++)
    {
        char* ptr;
        ptr = GetString();
        cout<<ptr[i];
    }
    cout<<endl;
    //cout<<"len:"<<len<<endl;//驗證
    return 0;
}

void StringClassd::operator=(StringClassd src)//A=B
{
    if (data != NULL)
    {
        delete data;//刪除舊資料
        data = NULL;
    }
    
    len = src.len;
    data = new char[(len+1)];
    strcpy(data,src.data);
    return;
}


StringClassd StringClassd::operator+(StringClassd src)//加號"本身"與"src"不會改變
{
    StringClassd temp;//創建一組class
    temp.len = len;//將len值相加入temp
    temp.data = new char[(temp.len)];
    
    strcpy(temp.data, data); // 複製 this 的內容
    temp.strCAT(src.data);//串接上src的內容
    
    return temp;
}

