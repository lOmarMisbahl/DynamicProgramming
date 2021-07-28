#include <bits/stdc++.h>
using namespace std ;
void knapsack(vector<int> Weights, vector<int> Profits, int TotalWeight)
{   int NumberOfWeights = Weights.size();
    int arr[NumberOfWeights][TotalWeight + 1];
    for(int i = 0; i <= TotalWeight; i++)
    {
        if(i >= Weights[0])
            arr[0][i]=Profits[i];
        else arr[0][i]=0;
    }
    for(int i=1; i < NumberOfWeights; i++)
        for(int j =0; j <= TotalWeight; j++)
        {
            if(j >= Weights[i])
                arr[i][j]=max(arr[i-1][j],arr[i-1][j - Weights[i]]+Profits[i]);
            else arr[i][j]= arr[i-1][j];
        }
    for(int i=0; i < NumberOfWeights; i++)
    {
        for(int j =0; j <= TotalWeight; j++)
            cout<<arr[i][j]<<"  ";
        cout<<endl;
    }
    for(int i=1; i < NumberOfWeights; i++)
    {  int f = 1;
        for(int j =0; j <= TotalWeight; j++)
        {
            if(arr[i][j]>arr[i-1][j])
                f= 0 ;
        }
        if(!f)
            cout << "Item Included : " << Weights[i] << endl;
    }
}
void longestPalindromeSubseq(string String) {
    int arr[String.size()][String.size()];
    int n = String.size();
    for(int i = 0 ;i<n;i++)
        arr[i][i]=1;
    for(int i =1; i < n; i++)
    {
        for(int j =0; j + i < n; j++)
        {
            int k = j + i;
            if(i == 1) {
                arr[j][k] = 1 + (String[j] == String[k]);
            }
            else {
                if(String[j] == String[k])
                    arr[j][k] = arr[j + 1][k - 1] + 2;
                else
                    arr[j][k] = max(arr[j + 1][k], arr[j][k - 1]);
            }
        }
    }
    string Output;
    int i =0,j=n-1;
    while(i<=j)
    {
        if(arr[i][j]==arr[i+1][j])
            i=i+1;
        else if(arr[i][j]==arr[i][j-1])
            j=j-1;
        else {
            Output.push_back(String[i]);
            i++;j--;
        }
    }
    cout << Output;
    if(Output.size() & 1)
        Output.pop_back();
    reverse(Output.begin(), Output.end());
    cout << Output << endl;
}

void longestCommonSubsequence(string T1, string T2) {
    int arr[T1.size() + 1][T2.size() + 1];
    for(int i =0 ; i <= T2.size(); i++)
        arr[0][i]=0;
    for(int i =0 ; i <= T1.size(); i++)
        arr[i][0]=0;
    for(int i = 1; i <= T1.size(); i++)
    {
        for(int j=1; j <= T2.size(); j++)
        {
            if(T1[i - 1] == T2[j - 1])
                arr[i][j]=1+arr[i-1][j-1];
            else
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);

        }
    }
    cout<<" ";
    for(int i =0; i < T2.size(); i++)
    {
        cout << " " << T2[i];
    }
    cout<<endl;
    for(int i = 1; i <= T1.size(); i++)
    {  cout << T1[i - 1] << " ";
        for(int j =1; j <= T2.size(); j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    int i = T1.size(),j=T2.size();
    string Output ;
    while(i>0&&j>0)
    {
        if(arr[i][j]==arr[i-1][j])
            i--;
        else if(arr[i][j]==arr[i][j-1])
            j--;
        else {
            Output.push_back(T1[i - 1]);
            i--;j--;
        }
    }
    reverse(Output.begin(),Output.end());
    cout << Output << endl;
}


bool SubSum(vector<int> Set, int Sum)
{   int NumberOfIntegers = Set.size();
    bool arr[NumberOfIntegers+1][Sum + 1];

    for(int i = 0; i <= NumberOfIntegers; i++)
    {
        arr[i][0] = true;
    }

    for(int i = 1; i <= NumberOfIntegers; i++)
    {
        arr[0][i] = false;
    }


    for(int i=1; i <= NumberOfIntegers; i++)
        for(int j =1; j <= Sum; j++)
        {
            if(j >= Set[i])
                arr[i][j]=arr[i-1][j] || arr[i-1][j - Set[i-1]];
            else arr[i][j]= arr[i-1][j];
        }

    return arr[NumberOfIntegers][Sum];
}

int CoinExchange(vector<int> Coins , int Target){
    sort(Coins.begin(), Coins.end());
    int dp[Target + 1];
    dp[0]=0 ;
    for(int i =1; i <= Target; i++){
        dp[i]=INT_MAX;
        for(int j =0; j < Coins.size(); j++)
        {
            if(i < Coins[j])
                break ;
            dp[i]= min(dp[i]-1,dp[i - Coins[j]]) + 1;
        }
    }
    return dp[Target];
}




int main(){
    string Palindrome = "character";
    vector<int> Weights = {5 , 4 , 6 , 3  };
    vector<int> Profits = {10 , 40 , 30 , 50};
    vector<int> Set = {7, 33, 4, 14, 5, 1};
    vector<int> Coins1 = {25, 10, 5};
    vector<int> Coins2 = {9, 6, 5, 1};
    int sum = 9;
    string T1 = "alligator";
    string T2 = "algorithm";
    longestCommonSubsequence(T1, T2);
    longestPalindromeSubseq(Palindrome);
    knapsack(Weights, Profits, 10);
    if(SubSum(Set, sum))
        cout<<"True, There is a subset with sum "<<sum<<endl;
    else
        cout<<"False, There isn't a subset with sum "<<sum<<endl;

    cout << "Minimum " << CoinExchange(Coins2, 11) << " coins required";
}