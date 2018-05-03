#include <typeinfo>
#include <iostream>
#include <string>
#include <cstring>
#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
//#include <vector>
#include <algorithm>
#include <time.h>
#include <sstream>

using namespace std;

typedef struct BOOK {
	char name[20];
	float price;
	int number;
} Book;

void string_fun();
void assert_fun();
void sizeof_fun();
void pointer_fun();
void pointer_string();
int  getRandomValue();
void pointer_fun_fun();
void file_fun();
void lambda_fun();
void time_fun();
void struct_fun();
void printBook(const Book *book);
void vectorDemo();

void string_fun(){
	char str1[11] = {'H','e','l','l','o','\0'};
	char str2[6] = "world";
	char result[11];

	strcpy(result, str1);
	cout << "strcpy(result ,str1):" << result << endl;
	strcat(str1, str2);
	cout << "strcat(str1, str2)" << str1 << endl;
	int len = strlen(str1);
	cout << "strlen(str1) " << len << endl;

	char str[20] = "hello world";
	char w = 'w';
	char s[10] = "lo";
	char *post = strchr(str, w);

	cout << "pointer:" << strchr(str, w) << endl;
	cout << "pointer: " << post << endl;
	cout << "pointer: " << *post << endl;
	cout << "index: " << strstr(str, s) << endl; 

	char line[20];
	cin.getline(line, 20);
	cout << line << endl;

	string input;
	getline(cin, input);
	cout << input << endl;
}

void assert_fun(){
	int a= 10;
	assert(a == 10);
}

void sizeof_fun(){
	cout << "size of int : " << sizeof(int) << endl;
	cout << "size of unsigned int : " << sizeof(unsigned int) << endl;
}

void limits_fun(){
	printf("The number of bits in a byte %d\n", CHAR_BIT);
	printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
	printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
	printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);

	printf("The minimum value of SHORT INT = %d\n", SHRT_MIN);
	printf("The maximum value of SHORT INT = %d\n", SHRT_MAX); 

	printf("The minimum value of INT = %d\n", INT_MIN);
	printf("The maximum value of INT = %d\n", INT_MAX);
	printf("The minimum value of CHAR = %d\n", CHAR_MIN);

	printf("The maximum value of CHAR = %d\n", CHAR_MAX);

	printf("The minimum value of LONG = %ld\n", LONG_MIN);
	printf("The maximum value of LONG = %ld\n", LONG_MAX);
}

const int MAX = 4;
void pointer_fun(){
	int var[MAX] = {10,200,3000};
	int *ptr[MAX];

	for (int i = 0; i < MAX ; i++ ){
		ptr[i] = &var[i];
	}

	for (int i = 0; i < MAX ; i++ ){
		cout << "value of var[" << i << "]: " << *ptr[i] << endl;
	}

	char char_array[6] = {'H','e','l','l','o','\0'};
	const char *str_ptr = "hello";

	cout << "sizeof :" << sizeof(*str_ptr) << endl;
	cout << "*char_array : " << *char_array << endl;
	cout << "*str_ptr : " << *str_ptr << endl;

	for( ; *str_ptr != '\0' ; str_ptr++){
		cout << *str_ptr;
	}

	cout << endl;
	/* 数组名字可以看做是指向首地址的指针，
	 * 不一样的地方
	 * 数组名不能像指针一样做自增运算，
	 * 只能直接加一个增量*/
	for (int a = 0 ; *(char_array + a) != '\0' ; a++){
		cout << *(char_array + a);
	}
	cout << endl;

}

void pointer_string(){
	string str = "hellostring";
	string *p = &str;
	string str_arr[] = {"hello","world","good"};

	cout << str[0] << endl;
	cout << *p << endl;
	cout << (*p)[0] << endl;
	cout << *str_arr << endl;
	cout << str_arr[0] << endl;

	const char *names[MAX] = {"hello", "world", "good", "job"};
	cout << names << endl;
	cout << names[0] << endl;
	cout << *names << endl;
	cout << *names[0] << endl;
	cout << *(names[0]) << endl;
	//	const char *name = names[0];
	//  cout << "*name" << *name << endl;
	//	for (int i = 0 ; i < MAX ; i++ ){
	//		cout << names[i] << endl;
	//	}

}

int getRandomValue(int seed){
	srand(seed);
	return rand();
}

int invoke_function(int _seed, int (*fun_ptr)(int)){
	return fun_ptr(_seed);
}

void pointer_fun_fun(){
	//int (*ptr_fun)(int) = &getRandomValue;

	int a = invoke_function(time(NULL), getRandomValue);

	cout << "result:" << a << endl;
}

void file_fun(){
	/*lines=123*/
	int time;
	char buff[100];
	char count_str[10];
	int count_int;

	FILE *_fp = fopen("records.txt","a+");//create file if not exist
	if(_fp){
		fclose(_fp);
	}

	FILE *fp = fopen("records.txt","r+");

	if(!fp){
		cout << "open file exception" << endl;
	} else {
		if (fgets(buff, sizeof buff, fp) == NULL){
			cout << "empty file. init..." << endl;
			fprintf(fp, "record=1");
		} else {
			cout << "old content : " << buff << endl;
			int len = (strlen(buff));
			if( len > 7 ){
				fseek(fp, 7, SEEK_SET);
				fgets(buff, sizeof buff, fp);//get old count 
				strcpy(count_str, buff);
				count_int = atoi(count_str);
				cout << "old number: " << count_int << endl;
				fseek(fp, 7, SEEK_SET);
				fprintf(fp, "%d",++count_int);//increase and cover
				cout << "current number: " << count_int << endl;
			} else {
				fseek(fp, 0, SEEK_SET);
				fputs("record=1", fp);
			}

		}
		fclose(fp);
	}
}
//计算偶数个数
void lambda_fun(){
	vector<int> v = { 1, 2, 3, 4, 5, 6 , 234234, 232};
	int even_count = 0;
	for_each(v.begin(), v.end(), [&even_count](int val){
			if(!(val & 1)){
			++ even_count;
			}
			});
	cout << "number of event is :" << even_count << endl;

	vector<int> scores = {34, 67, 89, 32, 78, 98};
	int count = count_if(scores.begin(), scores.end(), [](int x){ return x > 60; });
	cout << ">60 count : " << count << endl; 
	count = count_if(scores.begin(), scores.end(), [](int x){ return x > 90; });
	cout << ">90 count : " << count << endl; 
}

string format_time(const tm timee){
	stringstream ss;
	ss << ( 1900 + timee.tm_year ) << "年 " << ( timee.tm_mon + 1 ) << "月 " << timee.tm_mday << "日 "
		<< timee.tm_hour << "时 " << timee.tm_min << "分 " << timee.tm_sec << "秒 ";
	return ss.str();
}

void time_fun(){
	//系统当前时间
	time_t now = time(NULL);
	//转成字符串
	char *dt = ctime(&now);
	cout << "本地时间：" << dt << endl;

	//转换成tm结构
	tm *gmtm = gmtime(&now);
	dt = asctime(gmtm);
	cout << "标准时间" << dt << endl;

	tm *localtm = localtime(&now);

	string tm_str = format_time(*localtm);
	cout << tm_str << endl;
}

void printBook(const Book *book){
	cout << "name:" << book->name << endl;
	cout << "price:" << book->price << endl;
	cout << "number:" << book->number << endl;
}

void struct_fun(){
	Book book;
	char name[] = "C++教程";
	strcpy(book.name, "C++教程");
	book.price = 2.334f;
	book.number = 8;

	printBook(&book);
}

void vectorDemo(){
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	cout << "size:" << vec.size() << endl;

	vec.erase(vec.begin()+1);

	cout << "size:" << vec.size() << endl;
}
int main(){

	//string_fun();
	//assert_fun();
	//sizeof_fun();
	//limits_fun();
	//pointer_fun();
	//pointer_string();
	//pointer_fun_fun();
	//file_fun();
	//[]{};
	//lambda_fun();
	//time_fun();
	//struct_fun();
	vectorDemo();

	return 0;
}
