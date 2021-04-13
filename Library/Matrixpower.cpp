
typedef vector<unsigned int> row;
typedef vector<row> matrix;
matrix initial(int n, int m, double val = 0) {
	return matrix(n, row(m, val));
}

matrix identity(int n) {
	matrix rt = initial(n, n);
	for (int i = 0; i < n; i++)
		rt[i][i] = 1;
	return rt;
}
matrix addIdentity(const matrix& a) {
	matrix rt = a;
	for (int i = 0; i < sz(a); i++)
		rt[i][i]++;
	return rt;
}

matrix multiply(const matrix& a, const matrix& b) {
	matrix rt = initial(sz(a), sz(b[0]));
	for (int i = 0; i < sz(a); i++)
		for (int k = 0; k < sz(a[0]); k++) {
			if (a[i][k] == 0)
				continue;
			for (int j = 0; j < sz(b[0]); j++)
				rt[i][j] += (a[i][k] * b[k][j]);
		}
	return rt;
}

matrix power(const matrix& a, ll k) {
	if (k == 0)
		return identity(sz(a));
	if (k & 1)
		return multiply(a, power(a, k - 1));
	return power(multiply(a, a), k >> 1);
}

matrix sumPower(const matrix& a, ll k) {
	if (k == 0)
		return initial(sz(a), sz(a));
	if (k & 1)
		return multiply(a, addIdentity(sumPower(a, k - 1)));
	return multiply(sumPower(a, k >> 1), addIdentity(power(a, k >> 1)));
}