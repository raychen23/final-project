#include <stdlib.h>
#include <stdio.h>


int main() {
	srand((unsigned int)time(NULL));
	char answer[5];

	generalRandomAnswer(answer);

	printf("歡迎來到猜數字遊戲");
	playGame(answer);

	return 0;


}

void playGame(const char *answer) {
	int max = 10;
	char guess[5];
	int a, b;
	int attempts = 0;
	for (int i = 0; i < 10; i++) {
		printf("輸入猜的數字\n");
		scanf("%s", guess);
		while (!isValidGuess(guess)) {
			printf("請輸入正確格式\n");
			scanf("%s", guess);
		}
		calculateAB(answer, guess, &a, &b);

		printf("結果為%dA,%dB\n", a, b);
		attempts = attempts + 1;

		if (a == 4) {
			printf("恭喜你猜對了\n");
			displayGameStats(attempts);
			break;
		}

	}

	if (attempts = max) {
		printf("你10次都沒猜對,正確答案是%s\n", answer);
		displayGameStats(attempts);
	}
}