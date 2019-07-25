//#include <cstdio>
//#include <iostream>
//#include <cstring>
//#include <string>
//using namespace std;
//
//class information
//{
//public:
//	information()
//	{
//		cout << "information Construct1" << endl;
//		return;
//	}
//	information(string ID, string password)
//	{
//		this->ID = ID;
//		this->password = password;
//		cout << "information Construct2" << endl;
//	}
//	information(string ID,int ID_number,string password,int level)
//	{
//		this->ID = ID;
//		this->ID_number = ID_number;
//		this->password = password;
//		this->level = level;
//		cout << "information Construct3" << endl;
//	}
//	virtual void Hello()
//	{
//		cout << "Hello"<<" ";
//		cout << ID << endl;
//	}
//protected:
//	string ID;
//	int ID_number;
//	string password;
//	int level;
//};
//
//class test :public information
//{
//public:
//	test()
//	{
//		cout << "test Construct" << endl;
//	}
//	test(string ID, string password) :information(ID, password)
//	{
//
//	}
//	void Hello()
//	{
//		cout << "Hi" << endl;
//	}
//};
//
//int main()
//{
//	string ID = "zhangxin";
//	test X(ID, "111");
//	X.Hello();
//	X.information::Hello();
//	return 0;
//}