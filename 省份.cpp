#include<iostream>
#include<fstream>
#include<string>
using namespace std;

 
 int main()
 {
//�������ַ����������ֱ���ʡ��province[]�����city[]
 	string province[50],city[50]; 
//����sum[]��������֣�	
int sum[50];
//ifstream�������е��ļ��ж���
 	ifstream inFile("C:\\Users\\SYS\\Desktop\\�������\\yq_in.txt",ios::in);
 	if(!inFile)
	 {
	 	cout<<"error file."<<endl;
	 	return 0;
	 }
	 
	 ofstream outFile("C:\\Users\\SYS\\Desktop\\�������\\yq_out1.txt",ios::trunc);
	 if(!outFile)
	 {
	 	inFile.close(); //�ر�������
	 	cout<<"error file."<<endl;
	 	return 0;
	 }
	 //���ļ�����������������
	for(int i = 0 ; i < 50 ; i++)
	{
		inFile >> province[i] >> city[i] >> sum[i];
	}
//����s��flag,���ڱȽ�
	string s = province[0];
	int flag = 0;
//��ʼѭ��
	for(int i =0 ; i < 50 ; i++)
	{
//��һʡ����ͬ��Ҫ���ʡ��
		if( flag == 0 &&province[i] == s){
			outFile << province[i] <<endl;
			flag = 1;
			outFile << city[i] << "	" << sum[i] <<endl;
		}
//�������ͬ�Ĳ������ʡ��
		else if(flag == 1 &&province[i] == s){
			outFile << city[i] << "	" << sum[i] <<endl;
		}
//��ʡ�ݲ�����ͬʱ������ʡ��
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
