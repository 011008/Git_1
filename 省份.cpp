#include<iostream>
#include<fstream>
#include<string>
using namespace std;

 
 int main()
 {
//用两个字符串数组来分别存放省份province[]与城市city[]
 	string province[50],city[50]; 
//数组sum[]来存放数字；	
int sum[50];
//ifstream—从已有的文件中读。
 	ifstream inFile("C:\\Users\\SYS\\Desktop\\软件工程\\yq_in.txt",ios::in);
 	if(!inFile)
	 {
	 	cout<<"error file."<<endl;
	 	return 0;
	 }
	 
	 ofstream outFile("C:\\Users\\SYS\\Desktop\\软件工程\\yq_out1.txt",ios::trunc);
	 if(!outFile)
	 {
	 	inFile.close(); //关闭输入流
	 	cout<<"error file."<<endl;
	 	return 0;
	 }
	 //将文件里的内容输入进数组
	for(int i = 0 ; i < 50 ; i++)
	{
		inFile >> province[i] >> city[i] >> sum[i];
	}
//定义s和flag,用于比较
	string s = province[0];
	int flag = 0;
//开始循环
	for(int i =0 ; i < 50 ; i++)
	{
//第一省份相同的要输出省份
		if( flag == 0 &&province[i] == s){
			outFile << province[i] <<endl;
			flag = 1;
			outFile << city[i] << "	" << sum[i] <<endl;
		}
//后面的相同的不能输出省份
		else if(flag == 1 &&province[i] == s){
			outFile << city[i] << "	" << sum[i] <<endl;
		}
//当省份不在相同时，更换省份
		else if(province[i] != s){
			s = province[i];
			outFile << endl;
			outFile << province[i] <<endl;
			outFile << city[i] << "	" << sum[i] <<endl;
		}
	}
		 
		 outFile.close();
		 inFile.close();
		 return 0;
 	
 }
