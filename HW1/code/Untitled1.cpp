#include <iostream>
#include <stack>
using namespace std;
int AckermannRecursive(int m, int n) 
{
	//如果m=0 ,回傳n+1 
    if (m == 0) 
        return n + 1;
    //如果n=0 進入AckermannRecursive(m - 1, 1)
    else if (n == 0)  
        return AckermannRecursive(m - 1, 1);
    //不滿足上述條件，進入AckermannRecursive(m - 1, 1)
    else 
        return AckermannRecursive(m - 1, AckermannRecursive(m, n - 1));
    
}
int AckermannNonrecursive(int m,int n)
{
	stack<int> s;// 用堆疊來模擬遞迴的進行 
    s.push(m);  //  將 m 推入堆疊
    while (!s.empty()) 
	{
        m = s.top();//將m放入堆疊的頂端 
        s.pop();// 將堆疊頂端元素彈出
        // 如果 m 等於 0，結果為 n + 1
        if (m == 0)
            n = n + 1;
        // 如果 m > 0 且 n 等於 0，則將 m-1 推入堆疊，並將 n 設為 1
        else if (n == 0) 
		{
            n = 1;
            s.push(m - 1);
        } 
         // 如果 m > 0 且 n > 0，先將 m-1 推入堆疊，再次將 m 推入堆疊，並將 n 減 1
		else  
		{
            s.push(m - 1);
            s.push(m);
            n = n - 1;
        }
    }
    return n;
}
int main() 
{
	while(1)
	{
      int m, n;
      cout << "輸入 m 和 n: ";
      cin >> m >> n;
      cout << "Ackermann's Rescursive(" << m << ", " << n << ") = " << AckermannRecursive(m,n) << endl;//使用遞迴方式的輸出結果 
      cout << "Ackermann's NonRescursive(" << m << ", " << n << ") = " << AckermannRecursive(m,n) << endl;//使用堆疊方式的輸出結果 
   }
}

