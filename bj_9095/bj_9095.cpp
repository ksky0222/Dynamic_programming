//1,2,3 더하기 9095번
#include <iostream>
#include <vector>
/*



문제
: 정수 n이 주어졌을 때, n을 1,2,3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

입력
: 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.

출력
: 각 테스트 케이스마다, n을 1,2,3의 합으로 나타내는 방법의 수를 출력한다.



*/

int main() {
	std::vector<int> dp(1000000,0);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		std::cin >> N;
		for (int j = 4; j <= N; j++) {
			if (dp[j] == 0) {
				dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
			}
		}
		std::cout << dp[N] << std::endl;
	}
}