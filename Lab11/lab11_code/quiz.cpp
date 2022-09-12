 #include <iostream>
/*
class Pair{   

int X,Y;   

public:       

Pair (int initX, int initY): X(initX), Y(initY){}       

int sumXY(){ 

return X+Y;       

}
};

int main(){    Pair A1(5,3);    std::cout << A1.sumXY();    return 0;} */

/* int week11q2(int u, int v){   

      int w;   

      while(v){       

          w = u%v;       

          u = v;       

          v = w;    }   

return u;
}
int main(){     int a = 24, b = 16, c;   c = week11q2(a,b);   printf("%d\n", c);} */

class info {   
      public:       
           info(int age){           
                this->age = age;           
                std::cout << age << std::endl;       
           }   
       private:       
           int age;};
int main(){    info a(8);    return 0;}