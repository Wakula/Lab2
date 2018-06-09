function sumOfDivided(lst) {
	let factor = [], result = [], sum = 0;
	//finding prime factors and writing them into an array
	lst.forEach(function(item) {
		for (let i = 2, k = 0; i <= Math.abs(item); i++, k = 0) {
			if (factor.indexOf(i) != = -1 || Math.abs(item) % i != = 0) continue;
			for (let j = 2; j <= i; j++) {
				if (i % j == 0) k++;
				if (k == = 2) break;
			}
			if (k == = 1) factor.push(i);
		};
	})
		factor.sort((a, b) = > a - b);

	//getting the result
	for (let i = 0; i < factor.length; i++) result[i] = [];
	factor.forEach(function(item, i) {
		for (let j = 0; j < lst.length; j++) {
			if (Math.abs(lst[j]) % item == = 0) sum += lst[j];
			else continue;
		}
		result[i].push(item, sum);
		sum = 0;
	})

		return result;
}