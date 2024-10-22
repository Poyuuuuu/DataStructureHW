#include <iostream>
#include <cstdlib>
using namespace std;
// �ϥλ��j���;����A�å� string �Ӧs���e�l��
void findPowerSet(char* s, string res, int n) {
    // �� n ���� 0 �ɡA��ܤw�g�B�z���Ҧ������A��X���G
    if (n == 0) {	
        cout << '{' << res << '}' << endl;  // ��X��e�l��
        return;
    }
    // ��ܷ�e���� s[n-1]�A�N���[�J��l�� res ��
    findPowerSet(s, res + s[n-1], n - 1);
    
    // ����ܷ�e�����A�������j�B�z�ѤU������
    findPowerSet(s, res, n - 1);
}

// powerset ��ơA�t�d�I�s findPowerSet �Ӳ��;��� 
void powerset(char* s, int n) 
{
    string ans = "";  // ��l�ƪŪ��l��
    findPowerSet(s, ans, n);  // �I�s���j��ƨӥͦ��l��
}
int main() {
    while (1) {
        int n;  // �w�q���X�����Ӽ�
        cout << "How much elements do you want ? n = ";
        cin >> n;  // ��J�����Ӽ�
        char S[n];  // �ŧi�r���}�C���x�s���X����
        cout << "Please enter " << n << " elements for the set of S :" << endl;
        // �N�ϥΪ̿�J�� n �Ӥ����s�J���X S
        for (int i = 0; i < n; i++) cin >> S[i];
        // �I�s powerset ��ƨӥͦ��Ҧ��l��
        powerset(S, n);
    }
}

