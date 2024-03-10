#include <stdio.h>

void findScoreCombinations(int score) {
    int td, fg, safety, td2pt, td1pt;
    printf("Possible combinations of scoring plays for a score of %d:\n", score);
    for (td = 0; td * 6 <= score; td++) {
        for (fg = 0; fg * 3 + td * 6 <= score; fg++) {
            for (safety = 0; safety * 2 + fg * 3 + td * 6 <= score; safety++) {
                for (td2pt = 0; td2pt * 8 + safety * 2 + fg * 3 + td * 6 <= score; td2pt++) {
                    for (td1pt = 0; td1pt * 7 + td2pt * 8 + safety * 2 + fg * 3 + td * 6 <= score; td1pt++) {
                        if (td * 6 + fg * 3 + safety * 2 + td2pt * 8 + td1pt * 7 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, td1pt, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        findScoreCombinations(score);
    }

    return 0;
}
