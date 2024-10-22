#include <iostream>
#include <stack>
using namespace std;
int AckermannRecursive(int m, int n) 
{
	//�p�Gm=0 ,�^��n+1 
    if (m == 0) 
        return n + 1;
    //�p�Gn=0 �i�JAckermannRecursive(m - 1, 1)
    else if (n == 0)  
        return AckermannRecursive(m - 1, 1);
    //�������W�z����A�i�JAckermannRecursive(m - 1, 1)
    else 
        return AckermannRecursive(m - 1, AckermannRecursive(m, n - 1));
    
}
int AckermannNonrecursive(int m,int n)
{
	stack<int> s;// �ΰ��|�Ӽ������j���i�� 
    s.push(m);  //  �N m ���J���|
    while (!s.empty()) 
	{
        m = s.top();//�Nm��J���|������ 
        s.pop();// �N���|���ݤ����u�X
        // �p�G m ���� 0�A���G�� n + 1
        if (m == 0)
            n = n + 1;
        // �p�G m > 0 �B n ���� 0�A�h�N m-1 ���J���|�A�ñN n �]�� 1
        else if (n == 0) 
		{
            n = 1;
            s.push(m - 1);
        } 
         // �p�G m > 0 �B n > 0�A���N m-1 ���J���|�A�A���N m ���J���|�A�ñN n �� 1
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
      cout << "��J m �M n: ";
      cin >> m >> n;
      cout << "Ackermann's Rescursive(" << m << ", " << n << ") = " << AckermannRecursive(m,n) << endl;//�ϥλ��j�覡����X���G 
      cout << "Ackermann's NonRescursive(" << m << ", " << n << ") = " << AckermannRecursive(m,n) << endl;//�ϥΰ��|�覡����X���G 
   }
}

