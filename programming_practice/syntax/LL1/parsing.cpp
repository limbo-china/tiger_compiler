#include <iostream>
#include <list>
#include <string.h>
using namespace std;

#define N 100 // 输入符号串最大长度
const char NT[]="EWTRFDP";//非终结符数组
const char T[]="i+-*/()^#";//终结符数组
char s[N];  //输入符号串

//产生式右部数组
const char* Gene[]={
  "",
  "TW",
  "+TW",
  "-TW",
  "FR",
  "*FR",
  "/FR",
  "PD",
  "^F",
  "i",
  "(E)"
};

//预测分析表
const int Analy[7][9]={
      /* i + - * / ( ) ^ # */
  /*E*/ {1,-1,-1,-1,-1,1,-1,-1,-1},
  /*W*/ {-1,2,3,-1,-1,-1,0,-1,0},
  /*T*/ {4,-1,-1,-1,-1,4,-1,-1,-1},
  /*R*/ {-1,0,0,5,6,-1,0,-1,0},
  /*F*/ {7,-1,-1,-1,-1,7,-1,-1,-1},
  /*D*/ {-1,0,0,0,0,-1,0,8,0},
  /*P*/ {9,-1,-1,-1,-1,10,-1,-1,-1}
};

//分析栈
list<char> sta;

bool isNT(char c); //判断是否为非终结符
bool isT(char c); //判断是否为终结符
int indNT(char c); //返回非终结符在分析表中的下标
int indT(char c); //返回终结符在分析表中的下标

bool isNT(char c){
  for(int i=0;i<strlen(NT);i++){
    if(c==NT[i])
      return true;
  }
  return false;
}
bool isT(char c){
  for(int i=0;i<strlen(T);i++){
    if(c==T[i])
      return true;
  }
  return false;
}
int indNT(char c){
  for(int i=0;i<strlen(NT);i++){
    if(c==NT[i])
      return i;
  }
  return -1;
}
int indT(char c){
  for(int i=0;i<strlen(T);i++){
    if(c==T[i])
      return i;
  }
  return -1;
}
int main(){
  cin>>s;
  int a=0;//当前输入符号下标
  char c;  //栈顶符号
  int itemp; //产生式右部数组下标
  char atemp[5];  //产生式右部字符串
  int num=1; //步骤数

  //初始化
  while(!sta.empty())
    sta.pop_back();
  sta.push_back('#');
  sta.push_back('E');
  cout<<"\tnum\tstack\tstring\tuse"<<endl;

  while(1){
    //输出分析过程
    cout<<"\t"<<num<<"\t";
    for(list<char>::iterator it=sta.begin();it!=sta.end();it++)
      cout<<*it;
    cout<<"\t";
    for(int i=a;i<strlen(s);i++)
      cout<<s[i];
    cout<<"\t";

    c=sta.back();
    if(c=='#'){ //如果栈顶是'#'
      if(c!=s[a])
        cout<<"error!"<<endl;
      else
        cout<<"accepted!"<<endl;
      break;
    }
    else if(isNT(c)){ //如果栈顶是非终结符
      itemp=Analy[indNT(c)][indT(s[a])];// 取对应的产生式右部数组下标
      if(itemp==-1){  //对应的分析表元素出错
        cout<<"error!"<<endl;
        break;
      }
      if(itemp==0)  //如果为空
        cout<<c<<"->"<<"null"<<endl;
      else
        cout<<c<<"->"<<Gene[itemp]<<endl;
      strcpy(atemp,Gene[itemp]); //取产生式右部
      sta.pop_back(); //栈顶出栈
      for(int i=strlen(atemp)-1;i>=0;i--) //从尾至头入栈
        sta.push_back(atemp[i]);
    }
    else if(isT(c)){ //如果栈顶是终结符
      if(c==s[a]){ //终结符相匹配
        a++; //读入下一个字符
        sta.pop_back();  //栈顶出栈
        cout<<"'"<<c<<"'"<<"matched"<<endl;
      }
      else{  //不匹配
        cout<<"'"<<c<<"'"<<"not matched"<<endl;
        break;
      }
    }
    num++;
  }
}
