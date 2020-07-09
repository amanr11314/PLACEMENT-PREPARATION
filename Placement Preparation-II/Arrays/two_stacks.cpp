//To implement two stacks in an array of size n efficiently.
//Expected Time Complexity: O(1) for all the four methods.
//Expected Auxiliary Space: O(1) for all the four methods.

class twoStacks{
    int *arr;
    int size;
    int top1,top2;
    public:
    twoStacks(int n=100){
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }
    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();
};
/* The method push to push element into the stack 2 */
void twoStacks :: push1(int x){
    //checking if there's an empty space for an element to be pushed
    if(
        abs(this->top2-this->top1) > 1
    ){
        this->top1++;
        arr[this->top1] = x;
    }
}
   
/* The method push to push element into the stack 2*/
void twoStacks ::push2(int x){
    //checking if there's an empty space for an element to be pushed
    if(
        abs(this->top2-this->top1) > 1
    ){
        this->top2--;
        this->arr[this->top2] = x;
    }
}
   
/* The method pop to pop element from the stack 1 */
//Return the popped element
int twoStacks ::pop1(){
    //checking underflow
    if(this->top1==-1)  return -1;
    int val =  this->arr[this->top1];
    this->arr[this->top1] = 0;
    this->top1--;
    return val;
}

/* The method pop to pop element from the stack 2 */
//Return the popped element
int twoStacks :: pop2(){
    //checking underflow
    if(this->top2==this->size)  return -1;
    int val =  this->arr[this->top2];
    this->arr[this->top2] = 0;
    this->top2++;
    return val;
}