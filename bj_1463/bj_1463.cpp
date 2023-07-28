#include <iostream>
#include <vector>


/*
1. i가 2와 3으로 모두 나누어 떨어지지 않는 경우
이 경우는 5,7,11 등과 같은 숫자인데 이러한 경우의 규칙은 명확하게 보인다.
--> i에서 1을 빼주는 연산 + i-1의 숫자가 저장하고 있는 최소 연산

2. i가 2와 3으로 모두 나누어 떨어지는 경우
이 경우에는 2와 나누었을 때 와 3으로 나누었을 때를 비교하여 더 작은 값을 저장해주어야 한다.
그리고 거기에 i가 2또는 3으로 나누어지는 횟수도 추가해야 한다.
--> min(dp(i/2),dp(i/3)) + 1

3. i가 2로만 나누어 떨어지는 경우
i가 2로만 나누어지는 경우는 4,8,10 같은 경우가 있다.
--> min(dp(i/2),dp(i-1)) + 1


4. i가 3으로만 나누어 떨어지는 경우
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