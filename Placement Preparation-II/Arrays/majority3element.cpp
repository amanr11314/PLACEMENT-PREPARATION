//element that occurs more than n/3 times in array
//here maximum 2 elements are possible, so we create manuaally two variables for 
//candidates of answer..

///this is more generalised version of morethanNdk and majority element algorithm

void majorityElement3(int arr[],int n){

    int c_one = arr[0];
    int c_two = 0;

    int c_one_count = 1;
    int c_two_count = 0;

    for(int i=1;i<n;++i){
        //first candidate
        if(arr[i]==c_one){
            c_one_count++;
        }
        //first candidate
        else if(arr[i]==c_two){
            c_two_count++;
        }
        else{
            //if container available:
            if(!c_one_count){
                c_one = arr[i];
                c_one_count = 1;
            }
            else if(!c_two_count){
                c_two = arr[i];
                c_two_count = 1;
            }
            else{
                c_one_count--;
                c_two_count--;
                if(!c_one_count){
                    c_one = arr[i];
                    c_one_count = 1;
                }
                else if(!c_two_count){
                    c_two = arr[i];
                    c_two_count = 1;
                }
            }
        }
        
    }

    //check for candidate
    int c1,c2;
    c1 = c2 = 0;
    for(int i=0;i<n;++i){
        if(arr[i]==c_one)   c1++;
        if(arr[i]==c_two)   c2++;
    }

    bool ans = false;
    if(c1>n/3){
        cout<<"Candidate 1: "<<c_one<<'\n';
        ans = true;
    }
    if(c2>n/3)  cout<<"Candidate "<<(ans ? 2 : 1)<<": "<<c_two<<'\n';
    if(!ans)    cout<<"No element occurs more than n/3 times in array!!!";
}
