// User function template for C++

class Solution {

	bool isVowel(char ch) {
		if(ch == 'a' || ch == 'e' ||ch == 'i' || ch == 'o' || ch == 'u') return true;
	}

  public:
    int isGoodorBad(string S) {
			// code here
			int consonentCount = 0, vowelCount = 0;			
			int n = S.size();
			for(int i = 0;i<n;i++) {
				
				if(S[i] == '?') {
					vowelCount++;
					consonentCount++;
				}

				else if(isVowel(S[i])) {
					vowelCount++;
					consonentCount = 0;
				}		
				else {
					consonentCount++;
					vowelCount = 0;
				}				

				consonentCount = min(consonentCount, 3);
				vowelCount = min(vowelCount, 5);

				if(consonentCount >=3 || vowelCount >=5) {
					return 0;
				}
			}

			return 1;
    }
};