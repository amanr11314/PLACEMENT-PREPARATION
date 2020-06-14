// To find the factorial of a large number.

//int return type to return original size of array after multiplication
int multiply(int x,int res[],int size){
    /*
        if x is to be multiplied to 5189
        then res = [9,8,1,5], to preserve extra space
    */
    int carry = 0;
    for(int i=0;i<size;++i){
        int pro = res[i]*x + carry;
        res[i] = pro%10;
        carry = pro/10;
    }

    while(carry){
        res[size++] = carry%10;
        carry/=10;
    }
    return size;
}

void factorial(int n){
    //can handle maximum factorial having 10000 digits in it.
    int res[10000];
    res[0] = 1;
    int size = 1;
    for(int i=2;i<=n;++i){
        size = multiply(i,res,size);
    }
    cout<<"Factorial of "<<n<<" is: ";
    for(int i=size-1;i>=0;--i){
        cout<<res[i];
    }
    cout<<'\n';
}

//another utility funtion for calculating factorial using mathematics...
string factorial(long long n) { 
    /*
        n! => for i in (1,n) product(i) ....(1)
        also, ln(a,b) = ln(a) + ln(b)

        apply ln on eq(1):
        ln(n!) = ln( 1*2*3*...*n )
        so, from eq(2) we can say that:
        ln(n!) = ln(1) + ln(2) + ln(3) +....+ ln(n)

        Futher, we see that :
            _______________
           |               |
           | e^ln(n!) = n! |
           |_______________|
        so, we just caclculated factorial using some advanced maths..!!

    */
     
    long long counter; 
    long double sum = 0; 
  
    if (n == 0) 
        return "1"; 
  
    for (counter = 1;counter <= n;counter++) { 
        sum = sum + log(counter); 
    }

    //here we round the e^sum since it is not perfectly accurate
    //futher to store it we convert it to_string

    string result = to_string(round(exp(sum))); 
  
    return result; 
} 