#include <stdio.h>

int main()
{
    int choice, size, shape, i, j, t;
    int rows, r, s;
    int tri[12][12];
    double grade, total, average;
    char word[100];
    char leftCh, rightCh;
    int length, isPalindrome;
    char again;

    do
    {
        printf("\n==============================\n");
        printf("     PROGRAM PORTFOLIO\n");
        printf("==============================\n");
        printf("1. Pattern Generator\n");
        printf("2. Pascal's Triangle\n");
        printf("3. Grade Calculator & Evaluator\n");
        printf("4. Palindrome Checker\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');
            choice = 0;
        }

        if (choice == 5)
        {
            printf("Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 4)
        {
            printf("Invalid choice. Please pick 1 to 5.\n");
            again = 'Y';
            continue;
        }

        if (choice == 1)
        {
            printf("\n--- PATTERN GENERATOR ---\n");
            do
            {
                printf("Enter the size/height (greater than 0): ");
                if (scanf("%d", &size) != 1)
                {
                    while (getchar() != '\n');
                    size = 0;
                }
                if (size < 1)
                {
                    printf("Invalid! Enter a number.\n");
                }
            } while (size < 1);

            printf("\nWhich shape do you want to print?\n");
            printf("1. Right Triangle\n");
            printf("2. Square\n");
            printf("3. Isosceles Triangle\n");
            printf("4. Inverted Right Triangle\n");
            printf("5. Christmas Tree\n");
            do
            {
                printf("Enter your choice (1-5): ");
                if (scanf("%d", &shape) != 1)
                {
                    while (getchar() != '\n');
                    shape = 0;
                }
                if (shape < 1 || shape > 5)
                {
                    printf("Invalid shape choice.\n");
                }
            } while (shape < 1 || shape > 5);
            printf("\n");

            if (shape == 1)
            {
                for (i = 1; i <= size; i++)
                {
                    for (j = 1; j <= i; j++)
                    {
                        printf("*");
                    }
                    printf("\n");
                }
            }
            else if (shape == 2)
            {
                for (i = 1; i <= size; i++)
                {
                    for (j = 1; j <= size; j++)
                    {
                        printf("*");
                    }
                    printf("\n");
                }
            }
            else if (shape == 3)
            {
                for (i = 1; i <= size; i++)
                {
                    for (j = 1; j <= size - i; j++)
                    {
                        printf(" ");
                    }
                    for (j = 1; j <= 2 * i - 1; j++)
                    {
                        printf("*");
                    }
                    printf("\n");
                }
            }
            else if (shape == 4)
            {
                for (i = size; i >= 1; i--)
                {
                    for (j = 1; j <= i; j++)
                    {
                        printf("*");
                    }
                    printf("\n");
                }
            }
            else
            {
                for (t = 0; t < 3; t++)
                {
                    for (i = 1; i <= size; i++)
                    {
                        for (j = 1; j <= size + 2 - (i + t); j++)
                        {
                            printf(" ");
                        }
                        for (j = 1; j <= 2 * (i + t) - 1; j++)
                        {
                            printf("*");
                        }
                        printf("\n");
                    }
                }
                for (i = 1; i <= 2; i++)
                {
                    for (j = 1; j <= size; j++)
                    {
                        printf(" ");
                    }
                    printf("***\n");
                }
            }
        }
        else if (choice == 2)
        {
            printf("\n--- PASCAL'S TRIANGLE ---\n");
            do
            {
                printf("Enter the number of rows (1-12): ");
                if (scanf("%d", &rows) != 1)
                {
                    while (getchar() != '\n');
                    rows = 0;
                }
                if (rows < 1 || rows > 12)
                {
                    printf("Invalid! Enter a number from 1 to 12.\n");
                }
            } while (rows < 1 || rows > 12);

            /* each number is the sum of the two numbers above it */
            for (r = 0; r < rows; r++)
            {
                for (j = 0; j <= r; j++)
                {
                    if (j == 0 || j == r)
                    {
                        tri[r][j] = 1;
                    }
                    else
                    {
                        tri[r][j] = tri[r - 1][j - 1] + tri[r - 1][j];
                    }
                }
            }

            printf("\n");
            for (r = 0; r < rows; r++)
            {
                for (s = 0; s < (rows - r - 1) * 2; s++)
                {
                    printf(" ");
                }
                for (j = 0; j <= r; j++)
                {
                    printf("%4d", tri[r][j]);
                }
                printf("\n");
            }
        }
        else if (choice == 3)
        {
            printf("\n--- GRADE CALCULATOR & EVALUATOR ---\n");
            printf("Grades: 1.0 (highest) to 5.0 (lowest). Passing is 3.0 or better.\n");
            total = 0;

            for (i = 1; i <= 4; i++)
            {
                do
                {
                    if (i == 1)
                    {
                        printf("Enter Prelim grade (1.0-5.0): ");
                    }
                    else if (i == 2)
                    {
                        printf("Enter Midterm grade (1.0-5.0): ");
                    }
                    else if (i == 3)
                    {
                        printf("Enter Pre-Final grade (1.0-5.0): ");
                    }
                    else
                    {
                        printf("Enter Final grade (1.0-5.0): ");
                    }

                    if (scanf("%lf", &grade) != 1)
                    {
                        while (getchar() != '\n');
                        grade = 0;
                    }

                    if (grade < 1.0 || grade > 5.0)
                    {
                        printf("Invalid grade. Enter a number from 1.0 to 5.0.\n");
                    }
                } while (grade < 1.0 || grade > 5.0);

                total = total + grade;
            }

            average = total / 4;

            printf("\nFinal Average: %.2f\n", average);
            if (average <= 3.0)
            {
                printf("Status: PASS\n");
            }
            else
            {
                printf("Status: FAIL\n");
            }
        }
        else
        {
            printf("\n--- PALINDROME CHECKER ---\n");
            printf("Enter a word or number: ");
            scanf("%99s", word);
            while (getchar() != '\n');

            length = 0;
            while (word[length] != '\0')
            {
                length++;
            }

            isPalindrome = 1;
            for (i = 0; i < length / 2; i++)
            {
                leftCh = word[i];
                rightCh = word[length - 1 - i];

                /* change capital letters to small letters */
                if (leftCh >= 'A' && leftCh <= 'Z')
                {
                    leftCh = leftCh + 32;
                }
                if (rightCh >= 'A' && rightCh <= 'Z')
                {
                    rightCh = rightCh + 32;
                }

                if (leftCh != rightCh)
                {
                    isPalindrome = 0;
                }
            }

            if (isPalindrome == 1)
            {
                printf("\"%s\" is a palindrome.\n", word);
            }
            else
            {
                printf("\"%s\" is not a palindrome.\n", word);
            }
        }

        printf("\nDo you want to try another operation? (Y/N): ");
        scanf(" %c", &again);

        if (again == 'Y' || again == 'y')
        {
            printf("\n------------------------------\n");
        }

    } while (again == 'Y' || again == 'y');

    return 0;
}