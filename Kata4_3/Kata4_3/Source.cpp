char* mix(char* s1, char* s2) {
	int sum1 = 0, sum2 = 0, k = 0, *szs;
	char *result, *ltrs, *strs;
	//start memory allocation for intermediate results
	strs = malloc(1);
	szs = malloc(1);
	ltrs = malloc(1);
	//creating three arrays with:
	//1) numbers of strings with more letters;
	//2) with letters;
	//3) the amount of letters;
	for (int i = 97, counter = 0; i < 123; i++, sum1 = 0, sum2 = 0) {
		char ltr = (char)i;
		for (int j = 0; j < strlen(s1); j++) if (s1[j] == ltr) sum1++;
		for (int j = 0; j < strlen(s2); j++) if (s2[j] == ltr) sum2++;
		if (sum1 <= 1 && sum2 <= 1) continue;
		counter++;
		strs = realloc(strs, counter * sizeof(char));
		ltrs = realloc(ltrs, counter * sizeof(char));
		szs = realloc(szs, counter * sizeof(int));
		if (sum1 > sum2) {
			strs[k] = '1';
			ltrs[k] = ltr;
			szs[k] = sum1;
			k++;
		}
		else if (sum1 < sum2) {
			strs[k] = '2';
			ltrs[k] = ltr;
			szs[k] = sum2;
			k++;
		}
		else {
			strs[k] = '=';
			ltrs[k] = ltr;
			szs[k] = sum1;
			k++;
		}
	}
	strs[k] = '\0';
	ltrs[k] = '\0';
	//sorting the arrays so that they correspond to the correct output
	int len = strlen(strs), count = 0, changed = 1;
	while (changed) {
		changed = 0;
		for (int i = 0; i < len - count - 1; i++) {
			if (szs[i + 1] > szs[i] || (szs[i] == szs[i + 1] && (int)strs[i] > (int)strs[i + 1])) {
				int c = szs[i + 1];
				szs[i + 1] = szs[i];
				szs[i] = c;
				char a = strs[i + 1];
				strs[i + 1] = strs[i];
				strs[i] = a;
				char b = ltrs[i + 1];
				ltrs[i + 1] = ltrs[i];
				ltrs[i] = b;

				changed = 1;
			}
		}
		count++;
	}
	//building a result string combining information from 3 arrays
	for (int i = 0; i < len; i++) sum1 += szs[i];
	result = malloc(sizeof(char) * (3 * len + sum1));
	k = 0;
	for (int i = 0; i < len; i++) {
		result[k] = strs[i];
		k++;
		result[k] = ':';
		k++;
		for (int j = 0; j < szs[i]; j++, k++) result[k] = ltrs[i];
		result[k] = '/';
		k++;
	}
	result[k - 1] = '\0';
	return result;
}