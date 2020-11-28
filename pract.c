#include <stdio.h>  
int main()  
{  
    int x = 10, *y, **z;  
    
    y = &x;  
    z = &y;  
    printf("%d %d", *y, **z);  
    return 0;  
}  