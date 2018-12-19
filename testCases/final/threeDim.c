int main() {
	char newLine = 10;
	int i;
	int j;
	int arr[2][2][2];
	arr[0][0][1] = 1;
	arr[0][1][0] = 2;
	arr[1][0][0] = 3;
	i = 1;
	while (i == 1) {
		j = arr[i][0][0];
		writeInt(j);
		writeChar(newLine);
		j = arr[0][i][0];
		writeInt(j);
		writeChar(newLine);
		j = arr[0][0][i];
		writeInt(j);
		writeChar(newLine);
		i = i + 1;
	}
	j = 0;
	return 0;
}