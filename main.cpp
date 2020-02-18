void updateVarStack() {
    int a = 2;
    int b = 3;
    int c = 4;
    int* ptr = &b;
    b=6;  //updates to stack variables can be done either directly or with pointers
    *(ptr+1) = 5; // this demonstrates how variables on stack are allocated continuously
                  // therefore we can update it with pointer arithmatics
    cout<<"a=" << a<<endl;
    cout<<"b=" << b<<endl;
    cout<<"c=" << c<<endl;
}
void updateVarHeap() {
    int * ptr = new int(5);
    *ptr = 4; //updates to heap variable can only be done by pointers
    count<<*ptr<<endl;
}
/* this method demonstrates how heap variables can be resized whereas stack variables cannot*/
void reallocateOnHeap() {
    int *ptr = (int*) malloc(3*sizeof(int));
    for(int i = 0; i < 3; i++) {
        ptr[i] = i;
    }
    int *reallocPtr = (*int)realloc(ptr,5*sizeof(int));
    for(int i = 3; i<5;i++) {
        reallocPtr[i] = i;
    }
    cout<<"Values in reallocated array"<<endl;
    for(int i =  0; i<5;i++) {
        cout<<reallocPtr[i]<<endl;
    }
    free(reallocPtr);
}
int main()
{
    cout<<"test update variable on heap"<<endl;
    updateVarStack();
    cout<<"test update variable on stack"<<endl;
    updateVarHeap();
    cout<<"test reallocation on heap"<<endl;
    reallocateOnHeap();
}
