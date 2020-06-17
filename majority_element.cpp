//to find the element which occurs more than half the size of array.
//Also known as Moore’s Voting Algorithm:-
/*
This is a two-step process.
    >The first step gives the element that maybe the majority element in the array.
    If there is a majority element in an array, then this step will definitely 
    return majority element, otherwise, it will return candidate for majority element.

    >Check if the element obtained from the above step is majority element. This step is necessary as there might be no majority element.
*/

void majorityElement(int arr[],int n){

    //since majority element occurs more than (n/2) ..
    //there is only one majority element.

    int major = arr[0];
    int c = 0;

    //if element is equal to majority element increase the count
    //else decrese the count
    //if count becomes zero.. then make current element majority element and increase count to 1

    ///finding candidate for majority element..
    
    for(int i=1;i<n;++i){
        if(arr[i]==major){
            c++;
        }
        else    c--;

        if(!c)  major = arr[i];
    }

    //count frequency of major elemeny in array and if it occurs more than half of array then it is majority element..
    //otherwise, there's no majority element in array..

    int cnt = 0;
    for(int i=0;i<n;++i){
        if(arr[i]==major){
            c++;
        }
        if(c>n/2)  {
            cout<<majorityElement<<" is majority element\n";
            return;
        }
    }

    cout<<"No majority element found!!";

}