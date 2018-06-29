bool canPermutePalindrome(string s) {
	bitset<256> b; //256 characters
	for(char c : s) {
		b.flip(c);
	}
	return b.count() < 2;
}