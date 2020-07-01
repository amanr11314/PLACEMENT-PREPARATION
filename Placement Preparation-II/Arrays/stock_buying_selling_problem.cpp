void maxProfit1(int prices[],int n){
    ///only 1 transaction allowed..

    int maxProfit = 0,minPrice = 0;
    for(int i=0;i<n;++i){
        maxProfit = max(maxProfit,prices[i]-minPrice);
        minPrice = min(minPrice,prices[i]);
    }

    cout<<maxProfit;
}

void maxProfit2(int prices[],int n){
    //at most 2 stocks limited...
    //space optimised method..

    int maxProfit = 0,minPrice = 0;

    int profit[n] = {0};

    
    for(int j = 0;j<n;++j){
        maxProfit = max(maxProfit,prices[j]-minPrice);
        profit[j] = maxProfit;
        minPrice = min(minPrice,prices[j]);
    }

    int maxPrice = prices[n-1];

    for(int i=n-2;i>=0;--i){
        maxPrice = max(maxPrice,prices[i]);
        profit[i] = max(
            profit[i+1], profit[i] + maxPrice-prices[i]
        );
        maxProfit = profit[i];
    }
    cout<<maxProfit;
}

void maxProfit(int prices[],int n,int k){
    ///maximum profit by selling atmost k stocks
    ///can buy only 1 stock at a time
    ///a transaction can be made only after selling all previous stocks
    int T[k+1][MAX] = {0};
    
    ///Fast Optimized method
    for(int i=1;i<=k;++i){
        //initial maxdiff as 0 - price[0] since no share sold
        int maxdiff = -prices[0];
        for(int j = 1;j<n;++j){

            //max of not transacting on j-th day or adding up maxdiff to price[j]
            ///in other words selling on j-th day and buying on best m-th day 
            ///also such that diff. b/w  one less transaction till m-th day
            ///and profit by buying on m-th day price price[m] is maximum
            
            ///i.e after buing we have maximum possible amount left to us
            ///maxdiff = max(T[i-1][0...m]-price[0....m])
            T[i][j] = max(
                T[i][j-1],
                prices[j]+maxdiff
            );

            ///maxdiff = after buing maximum possible amount left to us
            maxdiff = max( maxdiff,
                (T[i-1][j] - prices[j])
            );
        }
    }

    for(int i=0;i<=k;++i){
        for(int j=0;j<n;++j){
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"__________________________\n";

    int t[k+1][MAX] = {0};

    ///Slow method
    for(int i=1;i<=k;++i){
        for(int j = 1;j<n;++j){
            //by not transacting on j-th day and continuing previous profit
            int maxProfit = 0;
            for(int m = 0;m<j;++m){
                //t[i-1][m] -> by completing one less transaction till m-th day
                maxProfit = max(
                    maxProfit,
                    prices[j]-prices[m]+t[i-1][m]
                );
            }
            t[i][j] = max(t[i][j-1],maxProfit);
        }
    }

    for(int i=0;i<=k;++i){
        for(int j=0;j<n;++j){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }

}