#include <iostream>    
using namespace std;    
 struct Rectangle    {      
   int width, height;      
  Rectangle(int w, int h)      
    {      
        width = w;      
        height = h;      
    } 

   // OR
    // Rectangle(int width, int height)      
    // {      
    //     this->width = width;      
    //     this->height = height;      
    // }      
  void areaOfRectangle() {       
    cout<<"Area of Rectangle is: "<<(width*height); }      
 };      
int main(void) {    
    struct Rectangle rec=Rectangle(4,6);    
    rec.areaOfRectangle();    
   return 0;    
}   