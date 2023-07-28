#include <iostream>
#include <vector>


/*
1. i�� 2�� 3���� ��� ������ �������� �ʴ� ���
�� ���� 5,7,11 ��� ���� �����ε� �̷��� ����� ��Ģ�� ��Ȯ�ϰ� ���δ�.
--> i���� 1�� ���ִ� ���� + i-1�� ���ڰ� �����ϰ� �ִ� �ּ� ����

2. i�� 2�� 3���� ��� ������ �������� ���
�� ��쿡�� 2�� �������� �� �� 3���� �������� ���� ���Ͽ� �� ���� ���� �������־�� �Ѵ�.
�׸��� �ű⿡ i�� 2�Ǵ� 3���� ���������� Ƚ���� �߰��ؾ� �Ѵ�.
--> min(dp(i/2),dp(i/3)) + 1

3. i�� 2�θ� ������ �������� ���
i�� 2�θ� ���������� ���� 4,8,10 ���� ��찡 �ִ�.
--> min(dp(i/2),dp(i-1)) + 1


4. i�� 3���θ� ������ �������� ���
-->min(dp(i/3),dp(i-1)) + 1


*/

std::vector<int> v(1000001,0);

int min(int a, int b) {
	if (a >= b) return b;
	else return a;
}

int dp(int i) {
	if (i % 2 == 0 and i % 3 == 0) {
		return min(v[i / 2], v[i / 3]) + 1;
	}
	else if (i % 2 == 0 and i % 3 != 0) {
		return min(v[i / 2], v[i - 1]) + 1;
	}
	else if (i % 2 != 0 and i % 3 == 0) {
		return min(v[i / 3], v[i - 1]) + 1;
	}
	else
		return v[i - 1] + 1;
}



int main() {
	v[2] = 1;
	v[3] = 1;
	
	int n = 0;
	std::cin >> n;
	for (int i = 4; i <= n; i++) {
		v[i] = dp(i);
	}
	std::cout << v[n];

	return 0;
}