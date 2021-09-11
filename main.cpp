//面向对象编程技术
#include<iostream>
#include<string>
#include<math.h>
#include<ctime>
using namespace std;

////代码区：存放函数体的二进制代码，由操作系统进行管理的
////全局区：存放全局变量和静态变量以及常量，地址在很近的地方
////栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
////堆区：由程序员分配和释放，若程序员不释放，程序结束后由操作系统回收
////内存四区意义：不同区域存放的数据，赋予不容的生命周期，给我们更大的灵活编程
//
////代码区是共享的，也是只读的
//
//
//
////全局区，该区域的全局区在编译完成后由编译器释放
//
////创建全局变量
//int g_a = 10;
//int g_b = 20;
//
//const int c_g_a = 10;
//const int c_g_b = 20;


//栈区的注意事项--不要返回局部变量的地址
//栈区的数据由编译器管理开辟和释放

//int* func(int b) //形参数据也会放在栈区
//{
//	int a = 10;//局部变量存放在栈区，栈区的数据在函数执行完后自动释放
//	return &a;//返回局部变量的地址
//	b = 20;
//}

//int* func2()
//{
//	//利用new关键字，可以将数据开辟到堆区
//	//指针 本质上也是局部变量，放在栈上，指针保存的数据是放在堆区
//	int* p = new int(10);
//	return p;
//}

//1、new的基本语法
int* func()
{
	//在堆区创建整型数据
	//new返回是 该数据类型的指针
	int* p = new int(10);
	return p;
}

//在堆区利用new开辟整型数据
void test01()
{
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//堆区的数据，由程序员管理开辟，程序员管理释放
	//如果想释放堆区的数据，利用关键字delete

	//delete p;
	//cout << *p << endl;//内存已经被释放，再次访问就是非法操作，会报错

}

//在堆区利用new开辟数组
void test02()
{
	//创建10整型数据的数组，在堆区
	int* arr = new int[10];
	for (int i = 0;i < 10;i++)
	{
		arr[i] = i + 100;//给10个元素赋值 100~109
	}
	for (int i = 0;i < 10;i++)
	{
		cout << arr[i] << endl;
	}
	//释放堆区数组
	//释放数组的时候 要加[]才可以
	delete[] arr;
}



int main()
{
	////创建普通局部变量

	//int a = 10;
	//int b = 20;

	////静态常量 在普通变量前面加上statics，属于静态常量
	//static int s_a = 10;
	//static int s_b = 20;


	//cout << "局部变量a的地址为：" << (int)&a << endl;
	//cout << "局部变量b的地址为：" << (int)&b << endl;
	//cout << "全局变量g_a的地址为：" << (int)&g_a << endl;
	//cout << "全局变量g_b的地址为：" << (int)&g_b << endl;
	//cout << "静态常量s_a的地址为：" << (int)&s_a << endl;
	//cout << "静态常量s_b的地址为：" << (int)&s_b << endl;

	////常量
	////字符串常量
	//cout << "字符串常量的地址为：" << (int) &"hello world" << endl;

	////const 修饰的变量
	////const 修饰的全局变量
	//cout << "全局常量c_g_a的地址为：" << (int)&c_g_a << endl;
	//cout << "全局常量c_g_b的地址为：" << (int)&c_g_b << endl;

	////const 修饰的局部变量
	//const int c_a = 10;
	//const int c_b = 20;
	//cout << "局部常量c_a的地址为：" << (int)&c_a << endl;
	//cout << "局部常量c_a的地址为：" << (int)&c_b << endl;

	////全局修饰的常量在全局区域中，
	////局部变量 const 修饰的局部变量 不在全局区中
	////全局变量 常量（全局常量，字符串常量*字符串常量比较特殊）在全局区域中

	//int* p = func(10);
	//cout << *p << endl;//第一次可以打印正确的数字，是因为编译器做了保留
	//cout << *p << endl;//第二次这个数据就不再保留了


	//在堆区开辟数据

	//int* m = func2();
	//cout << *m << endl;
	//cout << *m << endl;

	test02();


	system("pause");
	return 0;
}