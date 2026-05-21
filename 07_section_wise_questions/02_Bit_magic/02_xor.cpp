int* game_with_number(int arr[], int n) {

	int *answer = new int[n - 1];

	for(int i = 0; i < n - 1; i++) {
		answer[i] = arr[i] ^ arr[i + 1];
	}

	return answer;
}