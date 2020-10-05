class Solution {
public:
	int bitwiseComplement(int N) {
		if (!N)
			return 1;

		int b = log2(N) + 1;
		int T = (1 << b) - 1;
		return T - N;
	}
};