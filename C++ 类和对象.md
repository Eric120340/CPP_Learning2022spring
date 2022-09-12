# C++ 类和对象

C++在C基础上增加了面向对象编程。类是C++的核心特性，通常被称为用户定义的类型。

类用于指定对象的形式，它包含 了数据表示方法和用于处理数据的方法。类中的数据和方法称为类的成员。函数在一个类中被称为类的成员。



## C++类的定义

定义一个类，本质上是定义一个数据类型的蓝图，这是实际上是没有定义任何数据的，但是却指定了类的名称，定义了类的对象都包括什么，并且都可以执行哪些操作。

```c++
class classname	//指定类名
{
  	Access specifiers:					//访问修饰符：{private/public/protected}
  					Date members/variables;		//声明变量
  					Member functions(){}			//方法
};	//分号结束
```

如对复数进行定义：

```c++
class Complex
{
  public:
  		double real;
  		double img;
};
```

**public** 确定了类对象作用域中，公共成员在类的外部是可以访问的。



### 定义C++对象

上述所说的类定义确定了类的框架，对象是在这个框架下的，因此，对象是根据类来创建的。声明类的对象和一般声明方式相同：`Complex root； ` 其中root 有自己的数据成员。



### 访问数据成员

访问可以在直接通过 **.** 来访问。如 `root.real = 5.0; root.img = 6.0;`

但是需要注意，私有（private）和受保护的（protected）不能直接使用成员访问运算符.来直接访问。



##### 上述内容为对类的基本操作和概念。而类和对象之下还有很多相关联的概念，需要进行解析。



## 1 类成员函数

类的成员函数就是把定义和函数原型都写在class 定义内部的函数，和类中定义其他变量是相同的。成员函数是类的一个成员，因此他可以操作类的任意对象，并且访问对象中的所有成员。

在class 内部定义成员函数：

```c++
class Complex
{
  public:
  	double real;
  	double img;
  	double getfullnum(void);
};
```

在外部则需要加上范围解析运算符：

```c++
double Complex::getfullnum(void){}
```

类定义中定义的成员函数把函数声明为内联的，因此不需要inline标识符。

使用范围解析运算符前必须使用类名，调用成员函数需要在对象上使用.运算符，这样就可以操作与该对象相关的数据 `root.getfullnum` 

一般使用 **get**和 **set** 函数 给类中的数据传值：

```c++
void Complex::getReal(double realPart)
{
  real = realPart;
}
void Complex::getImg(double imgPart)
{
  img = imgPart;
}
```



## 2 C++类访问修饰符

面向对象编程中的一个很重要的特性就是数据的封装，它起到了防止函数直接访问类的内部成员。访问的限制依靠于访问修饰符 **public、private、protected** 。

```c++
class Fundation
{
  public:
  //公有成员
  protected：
 	//受保护的
  private：
  //私有
}
```



### 2.1 public

公有成员在程序中类的外部是可以访问到的。可以不使用任何成员函数来设置和获取公有变量的值。

Example code from **runoob.com**

```c++
#include <iostream>
 
using namespace std;
 
class Line
{
   public:
      double length;
      void setLength( double len );
      double getLength( void );
};
 
// 成员函数定义
double Line::getLength(void)
{
    return length ;
}
 
void Line::setLength( double len )
{
    length = len;
}
 
// 程序的主函数
int main( )
{
   Line line;
 
   // 设置长度
   line.setLength(6.0); 
   cout << "Length of line : " << line.getLength() <<endl;
 
   // 不使用成员函数设置长度
   line.length = 10.0; // OK: 因为 length 是公有的
   cout << "Length of line : " << line.length <<endl;
   return 0;
}
```

### 2.2 private

私有的成员变量或是函数，在累的外部都是不可以访问和查看的。默认的情况下，类的所有成员都是私有的（所以可以不加修饰符）。

```c++
class Rectangle
{
  //private:
  double height;
  public:
  	double width;
}
```

在实际的应用中，我们会在private的范围内定义数据；在public区域定义相关函数，帮助我们在类的外部调用这些函数。

```c++
class Rectangle
{
  private:
  	double height;
  	double width;
  public:
  	void setWidth(double wid);
  	void setHeight(double He);
  	void getWidth(double);
  	void getHeight(double);
}
```

注意在设置class中的数据时，不能再使用.来设置；而是要使用成员函数：`rect.setWidth(20.0);` 



### 2.3 **protected**

**Protected** 与 **private** 相似，但是不同的在于，protected成员在子类中是可以访问的。

```c++
class Rectangle
{
  protected:
  	double height;
  public:
  	double width;
}
//子类
class sonRectangle:Rectangle
{
  public:
  	void setSonWidth(double wid);
  	double getSonWidth(void);
}

// 子类的成员函数
double sonRectangle::getSonWidth(void)
{
    return width ;
}
 
void sonRectangle::setSonWidth( double wid )
{
    width = wid;
}
 
// 程序的主函数
int main( )
{
   //使用子类的定义
   sonRectangle rec;
 
   // 使用成员函数设置宽度
   rec.setSonWidth(5.0);
   cout << "Width of rec : "<< rec.getSonWidth() << endl;
 
   return 0;
}
```



### 2.4 继承下的访问修饰符

需要提前声明的是，任何一种继承方式，private成员只能被本类成员和友元访问，不能被派生类访问到；protected可以被派生类访问到。

**并且，若继承时不说明继承类型，则默认为private**，导致使用无法访问。

- public：最根本的父类成员 public、protected、private的访问属性在派生之后依然不变。
- protected：最根本的父类成员的访问属性，只有public被改编为protected，其余两个不变。
- private：最根本的父类成员的访问属性，所有访问属性均变为private

##### Example from runoob.com

public

```c++
#include<iostream>
#include<assert.h>
using namespace std;
 
class A{
public:
  int a;
  A(){
    a1 = 1;
    a2 = 2;
    a3 = 3;
    a = 4;
  }
  void fun(){
    cout << a << endl;    //正确
    cout << a1 << endl;   //正确
    cout << a2 << endl;   //正确
    cout << a3 << endl;   //正确
  }
public:
  int a1;
protected:
  int a2;
private:
  int a3;
};
class B : public A{
public:
  int a;
  B(int i){
    A();
    a = i;
  }
  void fun(){
    cout << a << endl;       //正确，public成员
    cout << a1 << endl;       //正确，基类的public成员，在派生类中仍是public成员。
    cout << a2 << endl;       //正确，基类的protected成员，在派生类中仍是protected可以被派生类访问。
    cout << a3 << endl;       //错误，基类的private成员不能被派生类访问。
  }
};
int main(){
  B b(10);
  cout << b.a << endl;
  cout << b.a1 << endl;   //正确
  cout << b.a2 << endl;   //错误，类外不能访问protected成员
  cout << b.a3 << endl;   //错误，类外不能访问private成员
  system("pause");
  return 0;
}
```



## 3 constructor and destructor构造函数和析构函数



### 3.1 constructor构造函数

构造函数是一种特殊的成员变量，他会在每次创建类的新对象的时候执行。构造函数的名称与类的名称完全相同，并且不会返回任何类型（void也没有）。构造函数可用来为一些成员变量设置初始值。

```c++
class Rectangle
{
  	public:
  			Rectangle(); // 构造函数
}；
```

默认的构造函数没有参数，但是我们可以设置参数。这就可以达到创建对象的时候就给对象赋初始值。

```c++
class Rectangle
{
  	public:
  			Rectangle(doubel len); // 构造函数
  	private:
  			double length;
  			double width;
}；
  
Rectangle::Rectangle(double wid,double len)
{
  width = wid;
  length = len;
}

int main()
{
  Rectangle rec(1.0,2.0);
  return 0;
}
```

使用初始化列表来初始化字段,功能和上述构造函数相同。

```c++
Rectangle::Rectangle(double wid,double len):length(len),width(wid){}
```

假设有一个类 ，具有多个字段需要进行初始化，同理地，您可以使用上面的语法，只需要在不同的字段使用逗号进行分隔。

默认构造器只初始化，但是不进行任何赋值

只有在没有设置构造器的时候才会自动出现默认构造器，一般设置好初始值



### 3.2 destructor析构函数

类的**析构函数**是类的一种特殊的成员函数，它会在每次删除所创建的对象时执行。析构函数的名称与类的名称是完全相同的，只是在前面加了个波浪号（~）作为前缀，它不会返回任何值，也不能带有任何参数。析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。

当不承担任何工作的时候：

```c++
~Stock::Stock()
{
}
```

编译器决定调用析构函数：

- 静态存储类对象：程序结束时调用
- 动态存储类对象：完成程序该定义的代码块时调用 在对象定义的时候赋值给一个指针
- 通过new来调用：在delete释放内存的时候调用
- 定义临时对象：在使用完成对象后调用。



## 4 C++拷贝构造函数

拷贝构造函数创建对象时是使用同一类中之前的对象来初始化新创建的对象。拷贝构造函数通使用于

- 通过另一个类型的对象来初始化新创建的对象
- 复制对象，并把他作为参数传递给函数
- 复制对象，并从函数返回这个对象

当class中没有拷贝函数时，编译器会自动定义一个。如果有指针变量，并有动态内存分配，那就必须要有一个拷贝函数。

```c++
classname (const classname &obj)
{
  //函数主体
}
```

**obj**是一个对象的引用，这个对象被用来初始化另外一个对象。

```c++
//调用拷贝构造函数并为指针 temp 分配内存空间
Rectangle::Rectangle(const Rectangle &obj)
{
  temp = new int;
  *temp = *obj.temp;
}
```



## 5 friend function 友元函数-扩展接口

友元在class里声明，作为这个class的朋友，可以访问对象的私有部分。

三类友元：

- 友元函数
- 友元类
- 友元成员函数

比如说`A = B * 2;`通过operator*(int)来实现，但是当`A = 2 * B`左侧的2不是对象。所以这里使用非成员函数（左边为参数1，右边为参数2）：`friend Class operator * (int b, const & a);`所以在顺序相反时就可以调用友元函数，

class 的friend function是在class 外部定义的，但是可以访问class所有private和protected的成员。即便是friend function在类的定义中出现了，但是友元函数不是class 的成员。

friend修饰的可以是一个函数，也可以是一个class。如果是一个friend class 那么这个class 的所有成员都是友元。

Friend function 在声明时只需要在函数前加 **friend**。`friend void RectangleShow(Rectangle rect);`

Friend class在声明所有成员为 **class A** 的友元时，需要在 **class A** 的定义中放置声明。

```c++
class ClassA
{
  protected:
  	int member;
  	double score;
  public:
  	friend void ClassAshow(ClassA cla);
  	friend class ClassB;
}

class ClassB
{
  public:
  	friend void print(int member, double score)
}

```

常用的友元是<<重载来显示对象。

## 6 内联函数

内联函数inline function 在编译的时候会把该函数的代码副本放在每一个函数被调用的位置。this被设置成调用该函数的对象的地址。

如果想把一个函数定义为内联函数，则需要在函数名前面放置关键字 **inline**，在调用函数之前需要对函数进行定义。如果已定义的函数多于一行，编译器会忽略 inline 限定符。

**在class 内定义的函数都是内联函数，即使没有使用inline的说明符号**

==TIP：只有当函数只有10行或更少的时候才能定义为内联函数==



## 7 this pointer

调用操作涉及到两个对象时，使用this。比如说要compare两个对象，box1.compare(box2),在compare内，this指针就是指的box1。

每个对象都可以用 **this** 来访问地址，this指针是所有成员函数的隐含函数。所以在成员函数**内部**，他可以用来指向调用对象。

```c++
#include <iostream>
 
using namespace std;
 
class Box
{
   public:
      // 构造函数定义
      Box(double l=2.0, double b=2.0, double h=2.0)
      {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
      }
      double Volume()
      {
         return length * breadth * height;
      }
      int compare(Box box)
      {
         return this->Volume() > box.Volume();
      }
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};
 
int main(void)
{
   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2
 
   if(Box1.compare(Box2))
   {
      cout << "Box2 is smaller than Box1" <<endl;
   }
   else
   {
      cout << "Box2 is equal to or larger than Box1" <<endl;
   }
   return 0;
}
```

如果是比较两个值，最后返回较大的：

```c++
const Box & compare(const & Box2) const
{
  if(this.length > Box2.lengrh)
  {
    return Box2;
  }else
  {
    return *this;
  }
}
```



## 8 指向类的指针

一个指向 C++ 类的指针与指向结构的指针类似，访问指向类的指针的成员，需要使用成员访问运算符 **->**，就像访问指向结构的指针一样。与所有的指针一样，您必须在使用指针之前，对指针进行初始化。

```c++
#include <iostream>
 
using namespace std;

class Box
{
   public:
      // 构造函数定义
      Box(double l=2.0, double b=2.0, double h=2.0)
      {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
      }
      double Volume()
      {
         return length * breadth * height;
      }
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

int main(void)
{
   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2
   Box *ptrBox;                // Declare pointer to a class.

   // 保存第一个对象的地址
   ptrBox = &Box1;

   // 现在尝试使用成员访问运算符来访问成员
   cout << "Volume of Box1: " << ptrBox->Volume() << endl;

   // 保存第二个对象的地址
   ptrBox = &Box2;

   // 现在尝试使用成员访问运算符来访问成员
   cout << "Volume of Box2: " << ptrBox->Volume() << endl;
  
   return 0;
}
```



## 9 class 静态成员

static 关键词可以把class 成员变成静态的。当成员被声明成静态的，那么不论创建多少个类的对象，静态成员都只有一个副本。

静态成员在类的所有对象都是共享的。如果没有其他的初始化语句，则在创建第一个对象的时候，所有的静态数据都会被初始化为0。

我们不能把静态成员的初始化放置在类的定义中，但是可以在类的外部通过使用范围解析运算符::来重新声明静态变量从而对它进行初始化。

```c++
#include <iostream>
 
using namespace std;
 
class Box
{
   public:
      static int objectCount;
      // 构造函数定义
      Box(double l=2.0, double b=2.0, double h=2.0)
      {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
         // 每次创建对象时增加 1
         objectCount++;
      }
      double Volume()
      {
         return length * breadth * height;
      }
   private:
      double length;     // 长度
      double breadth;    // 宽度
      double height;     // 高度
};
 
// 初始化类 Box 的静态成员，在class外部进行声明
int Box::objectCount = 0;
 
int main(void)
{
   Box Box1(3.3, 1.2, 1.5);    // 声明 box1
   Box Box2(8.5, 6.0, 2.0);    // 声明 box2
 
   // 输出对象的总数
   cout << "Total objects: " << Box::objectCount << endl;
 
   return 0;
}
```

创建的objectCount是一个常量，将与其他静态变量存储在一起，而不是和类在一起。

### 9.1 静态成员函数

声明为静态函数之后，就可以把函数与class任何特定对象独立开来。静态成员函数即使在class对象不存在的情况下也可以被调用，静态函数只要使用类名范围解析运算符::就可以访问。

静态成员函数只能访问静态成员数据、其他静态成员函数和类外部的其他函数。

静态成员函数有一个类范围，他们不能访问类的 this 指针。可以使用静态成员函数来判断类的某些对象是否已被创建。

**静态成员函数与普通成员函数的区别：**

- 静态成员函数没有 this 指针，只能访问静态成员（包括静态成员变量和静态成员函数）。
- 普通成员函数有 this 指针，可以访问类中的任意成员；而静态成员函数没有 this 指针。

```c++
#include <iostream>
 
using namespace std;
 
class Box
{
   public:
      static int objectCount;
      // 构造函数定义
      Box(double l=2.0, double b=2.0, double h=2.0)
      {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
         // 每次创建对象时增加 1
         objectCount++;
      }
      double Volume()
      {
         return length * breadth * height;
      }
      static int getCount()	//静态成员函数，只能访问静态成员数据
      {
         return objectCount;
      }
   private:
      double length;     // 长度
      double breadth;    // 宽度
      double height;     // 高度
};
 
// 初始化类 Box 的静态成员
int Box::objectCount = 0;
 
int main(void)
{
  
   // 在创建对象之前输出对象的总数
   cout << "Inital Stage Count: " << Box::getCount() << endl;
 
   Box Box1(3.3, 1.2, 1.5);    // 声明 box1
   Box Box2(8.5, 6.0, 2.0);    // 声明 box2
 
   // 在创建对象之后输出对象的总数
   cout << "Final Stage Count: " << Box::getCount() << endl;
 
   return 0;
}
```



# C++ 重载运算符和重载函数overload

C++ 允许在同一作用域中的某个**函数**和**运算符**指定多个定义，分别称为**函数重载**和**运算符重载**。

**重载声明**是指一个与之前已经在该作用域内声明过的函数或方法具有相同名称的声明，但是参数列表和定义不同。

调用一个重载函数或者重载运算时，编译器会把使用的参数类型与定义中的参数类型进行比较（数目和类型），最后选用最合适的定义。

选择最合适的重载函数或者重载运算符的过程，就是**重载决策**。

## 函数重载

在同一个作用域内，可以声明几个功能类似的同名函数，但是这些同名函数的形式参数（指参数的个数、类型或者顺序）必须不同。您不能仅通过返回类型的不同来重载函数。

```c++
#include <iostream>
using namespace std;
 
class printData
{
   public:
  		//分别重载int double char传入参数的函数
      void print(int i) {
        cout << "整数为: " << i << endl;
      }
 
      void print(double  f) {
        cout << "浮点数为: " << f << endl;
      }
 
      void print(char c[]) {
        cout << "字符串为: " << c << endl;
      }
};
 
int main(void)
{
   printData pd;
 
   // 输出整数
   pd.print(5);
   // 输出浮点数
   pd.print(500.263);
   // 输出字符串
   char c[] = "Hello C++";
   pd.print(c);
 
   return 0;
}
```



## 运算符的重载

可以重新定义或重载大部分 C++ 内置的运算符。这样就能使用自定义类型的运算符。重载的运算符是带有特殊名称的函数，函数名是由关键字 operator 和其后要重载的运算符符号构成的。与其他函数一样，重载运算符有一个返回类型和一个参数列表。运算符左侧为重载函数的调用对象，右边的为传入参数。当然还是可以使用一般的函数调用：`t1.operator+(t2)`

```c++
Complex operator+(const complex&);
```

以加法运算符为例，把两个complex对象相加，返回最终的complex。大多数的重载运算符可以被定义为普通的非成员函数或者被定义的类成员函数。

定义函数为class非成员函数，那么就要每次操作两个参数（传两个参数）。

```c++
Complex operator+(const complex&，const complex&);
```

##### 运算符重载为成员函数还是非成员函数？

区别在与：`T1 = T2 + T3;`

成员函数：`T1 = T2.operator+(T3);`

非成员函数：`T1 = operator+(T2, T3);`

operator+函数：

```c++
Complex operator+(const complex& right)
{
  Complex result;
  result.real = this->real + right.real;
  result.img = this->img + right.img;
  return result;
}
```

| 双目算术运算符 | + (加)，-(减)，*(乘)，/(除)，% (取模)                        |
| -------------- | ------------------------------------------------------------ |
| 关系运算符     | ==(等于)，!= (不等于)，< (小于)，> (大于)，<=(小于等于)，>=(大于等于) |
| 逻辑运算符     | \|\|(逻辑或)，&&(逻辑与)，!(逻辑非)                          |
| 单目运算符     | + (正)，-(负)，*(指针)，&(取地址)                            |
| 自增自减运算符 | ++(自增)，--(自减)                                           |
| 位运算符       | \| (按位或)，& (按位与)，~(按位取反)，^(按位异或),，<< (左移)，>>(右移) |
| 赋值运算符     | =, +=, -=, *=, /= , % = , &=, \|=, ^=, <<=, >>=              |
| 空间申请与释放 | new, delete, new[ ] , delete[]                               |
| 其他运算符     | **()**(函数调用)，**->**(成员访问)，**,**(逗号)，**[]**(下标) |

上述为可重载的运算符。

不可重载的有

**
.**：成员访问运算符

**.\***, **->\***：成员指针访问运算符

**::**：域运算符

**sizeof**：长度运算符

**?:**：条件运算符

**#**： 预处理符号

### 一元运算符重载

一元就是只对一个操作数进行操作：

- [递增运算符（ ++ ）和递减运算符（ -- ）]
- 一元减运算符，即负号（ - ）
- 逻辑非运算符（ ! ）

一元运算符会出现在操作对象的左侧或者右侧，不同情况需要不同的重载（参数不同）

```c++
Complex Complex::operator ++() {	//前缀自增
    ++i;
    ++j;
    return *this;
}

Complex Complex::operator ++(int) {	//后缀自增
    Complex temp =*this;
    ++*this;
    return temp;
}
```

### 二元运算符重载

两个对象想加的时候是没有顺序要求的，但是重载与一个数字相加是有顺序要求的，可以通过加入友元函数使另外一个顺序成立。

```c++
A A::operator +(const A& obj)//重载+号用于 对象相加 
{
    return this->a+obj.a;
}
A A::operator+(const int b)//重载+号用于  对象与数相加
{
    return A(a+b);
}
A operator+(const int b,  A obj)
{
    return obj+b;//友元函数调用第二个重载+的成员函数  相当于 obj.operator+(b); 
}

Box operator+(const Box& a, const Box& b)
{
    Box box;
    box.length = a.length + b.length;
    box.breadth = a.breadth + b.breadth;
    box.height = a.height + b.height;
    // cout << box.length << "--" << box.breadth << "--" << box.height << endl; 
    return box;
}
```



### 关系运算符重载

C++ 语言支持各种关系运算符（ < 、 > 、 <= 、 >= 、 == 等等），它们可用于比较 C++ 内置的数据类型。

我们可以重载任何一个关系运算符，重载后的关系运算符可用于比较类的对象。

```c++
bool operator <(const Distance& d)
      {
         if(feet < d.feet)
         {
            return true;
         }
         if(feet == d.feet && inches < d.inches)
         {
            return true;
         }
         return false;
      }
```

### 输入/输出运算符重载

c++使用的是>> 和<< 来输入和输出内置的数据类型。重载这两个来操作对象等用户自定义的数据类型。这里需要把运算符函数声明为类的友元函数，这样就可以不创建对象，直接调用函数。

```c++
      friend ostream &operator<<( ostream &output, 
                                       const Distance &D )
      { 
         output << "F : " << D.feet << " I : " << D.inches;
         return output;            
      }
 
      friend istream &operator>>( istream  &input, Distance &D )
      { 
         input >> D.feet >> D.inches;
         return input;            
      }
```

#### 1.重载<<第一个版本

使用ostream类对象cout

```c++
void operator<<(ostream & os, const Time & t)
{
  os << t.hour << " hours, " << t.minutes << " minutes";
}
```

直接访问了Time，所以必须为友元

但是这样就不能使用cout这种形式，因为ostream将<< 函数实现返回为一个指向ostream对象的引用。就是返回一个指向调用对象的引用。

#### 2.重载<<版本2

改进前面的版本。

```c++
ostream & operator<<(ostream & os, const Time & t)
{
  os << t.hour << " hours, " << t.minutes << " minutes";
  return os;//返回的是ostream的引用
}
```



### 赋值运算符重载

就像其他运算符一样，您可以重载赋值运算符（ = ），用于创建一个对象，比如拷贝构造函数。

```c++
void operator=(const Distance &D )
      { 
         feet = D.feet;
         inches = D.inches;
      }
```

### 函数调用运算符（）重载

函数调用运算符 () 可以被重载用于类的对象。当重载 () 时，您不是创造了一种新的调用函数的方式，相反地，这是**创建一个可以传递任意数目参数的运算符函数。**

```c++
#include <iostream>
using namespace std;
 
class Distance
{
   private:
      int feet;             // 0 到无穷
      int inches;           // 0 到 12
   public:
      // 所需的构造函数
      Distance(){
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i){
         feet = f;
         inches = i;
      }
      // 重载函数调用运算符
      Distance operator()(int a, int b, int c)
      {
         Distance D;
         // 进行随机计算
         D.feet = a + c + 10;
         D.inches = b + c + 100 ;
         return D;
      }
      // 显示距离的方法
      void displayDistance()
      {
         cout << "F: " << feet <<  " I:" <<  inches << endl;
      }
      
};
int main()
{
   Distance D1(11, 10), D2;

   cout << "First Distance : "; 
   D1.displayDistance();

   D2 = D1(10, 10, 10); // invoke operator()
   cout << "Second Distance :"; 
   D2.displayDistance();

   return 0;
}
```



### 下标运算符[]重载

[]通常用于访问数组元素。重载该运算符用于增强操作C++数组的功能。

```c++
class safearay
{
   private:
      int arr[SIZE];
   public:
      safearay() 
      {
         register int i;
         for(i = 0; i < SIZE; i++)
         {
           arr[i] = i;
         }
      }
      int& operator[](int i)
      {
          if( i >= SIZE )
          {
              cout << "索引超过最大值" <<endl; 
              // 返回第一个元素
              return arr[0];
          }
          return arr[i];
      }
};
```

### class成员访问运算符->重载

类成员访问运算符（ -> ）可以被重载，但它较为麻烦。它被定义用于为一个类赋予"指针"行为。运算符 -> 必须是一个成员函数。如果使用了 -> 运算符，返回类型必须是指针或者是类的对象。

运算符 -> 通常与指针引用运算符 * 结合使用，用于实现"智能指针"的功能。这些指针是行为与正常指针相似的对象，唯一不同的是，当您通过指针访问对象时，它们会执行其他的任务。比如，当指针销毁时，或者当指针指向另一个对象时，会自动删除对象。

间接引用运算符 -> 可被定义为一个一元后缀运算符。

```c++
#include <iostream>
#include <vector>
using namespace std;
 
// 假设一个实际的类
class Obj {
   static int i, j;
public:
   void f() const { cout << i++ << endl; }
   void g() const { cout << j++ << endl; }
};
 
// 静态成员定义
int Obj::i = 10;
int Obj::j = 12;
 
// 为上面的类实现一个容器
class ObjContainer {
   vector<Obj*> a;
public:
   void add(Obj* obj)
   { 
      a.push_back(obj);  // 调用向量的标准方法
   }
   friend class SmartPointer;
};
 
// 实现智能指针，用于访问类 Obj 的成员
class SmartPointer {
   ObjContainer oc;
   int index;
public:
   SmartPointer(ObjContainer& objc)
   { 
       oc = objc;
       index = 0;
   }
   // 返回值表示列表结束
   bool operator++() // 前缀版本
   { 
     if(index >= oc.a.size() - 1) return false;
     if(oc.a[++index] == 0) return false;
     return true;
   }
   bool operator++(int) // 后缀版本
   { 
      return operator++();
   }
   // 重载运算符 ->
   Obj* operator->() const 
   {
     if(!oc.a[index])
     {
        cout << "Zero value";
        return (Obj*)0;
     }
     return oc.a[index];
   }
};
 
int main() {
   const int sz = 10;
   Obj o[sz];
   ObjContainer oc;
   for(int i = 0; i < sz; i++)
   {
       oc.add(&o[i]);
   }
   SmartPointer sp(oc); // 创建一个迭代器
   do {
      sp->f(); // 智能指针调用
      sp->g();
   } while(sp++);
   return 0;
}
```

### 重载的限制

1. 重载后的运算符必须至少一个操作数是用户定义的类型。防止用户为标准类型重载运算符
2. 不能改变运算符的原本语法规则（`int x; %x//not ok`）；不能修改运算优先级
3. 不能创建新的运算符
4. 还有不能重载的运算符



# 类和动态内存分配

最好在运行的时候确定有多少内存（而不是编译的时候），比如一个string，在class constructor函数中使用new运算符在程序运行时分配所需要的内存。string类可以替我处理内存管理细节。构造函数必须提供内存来存储字符串。初始化对象时，可以给构造函数传递一个字符串指针。

字符串不是保存在对象中的，字符串单独保存在堆内存中，对象仅保存了指出到哪里去找字符串的信息。

C++使用new和delete运算符来动态控制内存。但是会导致很多问题。析构函数是必不可少的。有的时候必须重载赋值运算符（overloading） 

不能在类的声明中初始化静态成员变量，是因为声明会描述内存的分配，但不分配内存。

在构造函数中使用new分配内存后时必须在相应的析构函数使用delete来释放内存。如果使用new[]分配就要对应delete[]释放内存



下面是编译器自动生成的成员函数（如果没有定义的话）

## 默认构造函数

一个不接受任何参数、也不进行任何操作的构造函数，其值在开始时候是未知的

## 复制构造函数 Copy Constructor

将一个对象复制到新创建的对象当中。用于初始化过程（按值传递参数）而不是按照常规的方式进行赋值

`StringBad(const StringBad &);`

### 何时调用？

将新对象显式初始化为现有的对象，或者说是新建一个对象，将其初始化为同类现有对象时，CopyConstructor都会被调用。以下例子都会调用

```c++
//motto exists already
StringBad ditto(motto);
StringBad metoo = motto;	
StringBad also = StringBad(motto);
StringBad * ptrStringBad = new StringBad(motto);
```

最后一个就是用motto初始化匿名的对象，新对象的地址给了ptrStringBad

当函数按值传递对象（使用引用，节省构造时间和存储对象的空间），或者函数返回对象、编译器生成临时返回对象时，都会调用复制构造函数

### 功能？

默认的事逐个复制非静态成员（浅复制），复制的是值。如果成员是类，那就用这个成员类的copyconstructor来复制成员对象。静态成员属于整个类，而不是各个对象，所以不受影响。



## 构造函数中使用new

- 构造中使用了new，对应析构中必须使用delete
- new对应delete，new[]对应delete[]
- 多个构造函数，那new 的格式应该一致
- 应该定义一个复制构造函数，通过深度复制将一个对象初始化为另一个对象。复制构造器应该要分配足够的空间来存储复制的数据（不仅仅是地址）还有收到影响的静态成员。
- 定义一个赋值运算符，通过深度复制将一个对象复制给另一个对象。需要完成：自我检查赋值情况，释放成员指针之前的指向的内存，复制数据（不仅是地址），返回一个指向调用对象的地址。 

# 继承

继承允许我们依据另一个类来定义一个类。

当创建一个类时，您不需要重新编写新的数据成员和成员函数，只需指定新建的类继承了一个已有的类的成员即可。这个已有的类称为**基类**，新建的类称为**派生类**。



代码的重用

两个部分

父类的成员，只要不是static的都继承了；（也没有构造器）

派生类中的新成员

父类中保护的成员，子类可以访问，孙子也可以访问，但是继承

父类的构造器是不能继承的。先创建父类object 再子类的object

```c++
SalariedEmployee(const char* name, const char* ssn, double s) : Employee(name, ssn), salary(s)
{
  cout << "The derived class constructor is invoked." << endl;
}
```

调父类的object 必须把父类和子类的参数都表示，不然就会调默认的父类constructor（无参）

分工明确，父类创建父类，子类创建子类

**SalariedEmployee(const char* name, const char* ssn, double s)**  前两个是父类的后一个是子类添加的，初始化列表的方式 “**：**”

**Employee(name, ssn)** 调用父类的构造器，把前面的salariedEmployee里的参数放进来，创建一个父类的object

**salary(s)** 派生中的成员



```c++
SalariedEmployee(const Employee& e, double s) : Employee(e), salary(s){}
```

用父类拷贝函数创建父类对象，子类没有copyconstructor，但父类一定有，因为有指针



析构器先销毁子类对象，再销毁父类



list 调用copy constructor就OK，但是如果分别写就需要调构造器和assignment，所以现在这种效率更高

```c++
Employee(const string& n, const string& s) : name(n), ssn(s){}
```

string已经都new好了，所以这里只需要赋值就可以

和下面的相同



初始化列表只能用在构造器；

reference数据必须用初始化列表，因为直接初始化，直接等号，没有赋值过程；

编译器是根据class关系而不是书写顺序编译（先父类）

1. 子类的对象可以非private的父类成员
2. 父类指针或引用，可以指向子类对象
3. function参数是父类的指针或引用，就可以访问父类和子类的成员，但是访问的成员参数的范围限定于传入的对象类型，如果是传入的是父类，那么子类的只能穿入父类的成员，自己的就不行。



### Virtual Function虚函数

一定是成员函数，在父类里有，但是在子类也必须重新定义，因为功能不同。

应用于运行中的多态。

子类的Virtual 函数如果不作为父函数，则不用再写virtual。

那么调用的数据类型是什么就调用哪个的虚函数



当父类指针指向子类对象时，如果父类析构器是非virtual的，那么在析构的时候之后调用父类的部分，子类的object就不会被释放掉。所以在base的时候就应该声明成virtual的，所以析构的时候就会先子类，再父类



## Polymorphism

动态绑定过程，只有在运行的时候才能找到，编译的时候不行。静态就是相反，静态就能知道绑定的是谁

一定子类中重写父类的，必须是virtual的

同一个函数，不同调用

函数中，不知道是子类调用还是父类调用，如果直接传，类型会不同（一个数组必须都是相同元素）。这个时候就通过父类指针（引用） 数组存储new的子类



当函数的参数是父类的时候，如果调用时输入一个子类，那么这个函数只会调用父类的成员，不会调用子类的；

当函数参数时父类的参考值或者指针的时候，调用时输入什么就是谁的对象，调相应的对象。





overloading vs overriding

overloading 名字相同，参数列表不同，返回值也可以不同，在原有的内容上增加

是在编译的过程中静态poly，可以没有继承

overriding 名字参数返回值都相同，但是操作不同。运行动态poly，必须有继承



#### 动态内存分配

子类没有动态内存分配，就不用管；但是new了，添加了*成员就要管理好

自己管好自己的（析构器）