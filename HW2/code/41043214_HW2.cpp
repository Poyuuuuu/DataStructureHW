#include <iostream>
#include <cstdlib>
using namespace std;
// 使用遞迴產生冪集，並用 string 來存放當前子集
void findPowerSet(char* s, string res, int n) {
    // 當 n 等於 0 時，表示已經處理完所有元素，輸出結果
    if (n == 0) {	
        cout << '{' << res << '}' << endl;  // 輸出當前子集
        return;
    }
    // 選擇當前元素 s[n-1]，將它加入到子集 res 中
    findPowerSet(s, res + s[n-1], n - 1);
    
    // 不選擇當前元素，直接遞迴處理剩下的元素
    findPowerSet(s, res, n - 1);
}

// powerset 函數，負責呼叫 findPowerSet 來產生冪集 
void powerset(char* s, int n) 
{
    string ans = "";  // 初始化空的子集
    findPowerSet(s, ans, n);  // 呼叫遞迴函數來生成子集
}
int main() {
    while (1) {
        int n;  // 定義集合元素個數
        cout << "How much elements do you want ? n = ";
        cin >> n;  // 輸入元素個數
        char S[n];  // 宣告字元陣列來儲存集合元素
        cout << "Please enter " << n << " elements for the set of S :" << endl;
        // 將使用者輸入的 n 個元素存入集合 S
        for (int i = 0; i < n; i++) cin >> S[i];
        // 呼叫 powerset 函數來生成所有子集
        powerset(S, n);
    }
}

