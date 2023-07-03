#include <stdio.h>

#define INPUT_FILE "./input.txt"

#define WIN_POINT 6
#define DRAW_POINT 3

#define SCISSORS_POINT 3
#define PAPER_POINT 2
#define ROCK_POINT 1

#define OPPONENT_ROCK 'A'
#define OPPONENT_PAPER 'B'
#define OPOONENT_SCISSORS 'C'

#define PLAYER_ROCK 'X'
#define PLAYER_PAPER 'Y'
#define PLAYER_SCISSORS 'Z'

int RSP_POINT[3] = {ROCK_POINT, PAPER_POINT, SCISSORS_POINT};

int to_array_table(char one_of_RSP)
{
    if (one_of_RSP == OPPONENT_ROCK || one_of_RSP == PLAYER_ROCK)
    {
        return 0;
    }
    else if (one_of_RSP == OPPONENT_PAPER || one_of_RSP == PLAYER_PAPER)
    {
        return 1;
    }
    else if (one_of_RSP == OPOONENT_SCISSORS || one_of_RSP == PLAYER_SCISSORS)
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

// WOULD BE GREAT IF I HAVE HASMAP
int game_result(char opponent, char player)
{
    int win;
    int opponent_choice = to_array_table(opponent);
    int player_choice = to_array_table(player);

    if (opponent_choice == player_choice)
    {
        return DRAW_POINT + RSP_POINT[player_choice];
    }

    if (opponent == OPPONENT_ROCK)
    {
        win = (player == PLAYER_PAPER) ? 1 : 0;
    }
    else if (opponent == OPPONENT_PAPER)
    {
        win = (player == PLAYER_SCISSORS) ? 1 : 0;
    }
    else
    {
        win = (player == PLAYER_ROCK) ? 1 : 0;
    }

    return (win == 1)
               ? WIN_POINT + RSP_POINT[player_choice]
               : RSP_POINT[player_choice];
}

int how_to_win(int opponent_choice)
{
    if (opponent_choice == 0)
    {
        return 1;
    }
    else if (opponent_choice == 1)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int how_to_lose(int opponent_choice)
{
    if (opponent_choice == 0)
    {
        return 2;
    }
    else if (opponent_choice == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int game_result_part2(char opponent, char condition)
{
    int opponent_choice = to_array_table(opponent);
    int should_choice;

    int extra_point;

    if (condition == 'X')
    {
        extra_point = 0;
        should_choice = how_to_lose(opponent_choice);
    }
    else if (condition == 'Y')
    {
        extra_point = 3;
        should_choice = opponent_choice;
    }
    else
    {
        extra_point = 6;
        should_choice = how_to_win(opponent_choice);
    }

    return RSP_POINT[should_choice] + extra_point;
}

int main()
{
    FILE *input_file = fopen(INPUT_FILE, "r");
    if (input_file == NULL)
    {
        printf("Cannot open file\n");
        return 1;
    }
#if 0
    char c, opponent = 'a', player = 'b';
    int total_point = 0;


    do
    {
        c = getc(input_file);
        if (c == 'A' || c == 'B' || c == 'C')
        {
            opponent = c;
        }
        else if (c == 'X' || c == 'Y' || c == 'Z')
        {
            player = c;
        }

        if (c == '\n' || c == EOF)
        {
            int point = game_result(opponent, player);

            total_point += point;
        }
    } while (c != EOF);
#else

    char c, opponent = 'a', condition = 'b';
    int total_point = 0;

    do
    {
        c = getc(input_file);
        if (c == 'A' || c == 'B' || c == 'C')
        {
            opponent = c;
        }
        else if (c == 'X' || c == 'Y' || c == 'Z')
        {
            condition = c;
        }

        if (c == '\n' || c == EOF)
        {
            int point = game_result_part2(opponent, condition);

            total_point += point;
        }
    } while (c != EOF);
#endif

    printf("TOTAL POINT IS %d\n", total_point);

    fclose(input_file);
    return 0;
}
