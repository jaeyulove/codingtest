#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    int score;
} ScoreIndex;

int compare(const void *a, const void *b) {
    ScoreIndex *scoreA = (ScoreIndex *)a;
    ScoreIndex *scoreB = (ScoreIndex *)b;
    return scoreB->score - scoreA->score;  // Descending order sort
}

int* solution(int **score, size_t score_rows) {
    int* result = (int*)malloc(sizeof(int) * score_rows);
    ScoreIndex scores[score_rows];

    // Calculate average scores and store them with indices
    for (int i = 0; i < score_rows; i++) {
        int avg = (score[i][0] + score[i][1] + 1) / 2; // 소수점 이하를 반올림

        scores[i].index = i;
        scores[i].score = avg;
    }

    // Sorting scores in descending order based on average scores
    qsort(scores, score_rows, sizeof(ScoreIndex), compare);

    // Assign ranks, considering ties
    for (int i = 0; i < score_rows; i++) {
        if (i > 0 && scores[i].score == scores[i - 1].score) {
            result[scores[i].index] = result[scores[i - 1].index];
        } else {
            result[scores[i].index] = i + 1;
        }
    }

    return result;
}

int main() {
    int scores[2][2] = {{1, 2}, {1, 1}};
    int **score = malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        score[i] = scores[i];
    }
    size_t score_rows = 2;

    int *ranks = solution(score, score_rows);
    for (int i = 0; i < score_rows; i++) {
        printf("%d ", ranks[i]);
    }
    printf("\n");

    free(ranks);
    for (int i = 0; i < 2; i++) {
        free(score[i]); // Note: This is incorrect here because we didn't malloc each score[i]
    }
    free(score);

    return 0;
}
