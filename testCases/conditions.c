int main() {
	int a = 100;
	if (1 < a) {
		writeInt(a);
	}
	a = a + 1;
	if (a > 1) {
		writeInt(a);
	}
	a = a + 1;
	if (1 <= a) {
		writeInt(a);
	}
	a = a + 1;
	if (a >= 1) {
		writeInt(a);
	}
	a = a + 1;
	if (a == a) {
		writeInt(a);
	}
	a = a + 1;
	if (1 != a) {
		writeInt(a);
	}
	a = a + 1;
	return 0;
}