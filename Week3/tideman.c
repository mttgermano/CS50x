#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
bool cycle(int winner, int loser);
void lock_pairs(void);
void print_winner(void);


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i  = 0; i < candidate_count; i++)
    {
        if (!strcmp(name, candidates[i]))
        {
            ranks[rank] = i;
            //printf("%i\n", ranks[i]);
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i+1; j < candidate_count; j++)
        {
            //preferences: i over j
            //ex: [3,0,1]
            //3 over 0 and 1, 0 over 1
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Goes through the 2Dimensional array
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            //if pair i,j is greater than j,i --> add this pair into the array (pairs)
            if(preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
    return;
}


///// Sort pairs in decreasing order by strength of victory
//sort array:[(3,0), (7,5), (2,1)] --> [3,5,1] --> [5,3,1]
void sort_pairs(void)
{
    int index, checking_pair, current_pair;
    // Goes through each pair in #pairs
    for (int i = 0; i < pair_count; i++)
    {

        ///preferences[pairs[0].winner][pairs[0].loser] - preferences[pairs[0].loser][pairs[0].winner]
        //preferences[MAX] - preferences[MIN]
        current_pair = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
        index = i;
        //j = i + 1 --> So, every time you check i, you check if the subsequences pairs are greater than i
        for (int j = i + 1; j < pair_count; j++)
        {

            checking_pair = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];

            if (current_pair < checking_pair)
            {
                index = j;
                current_pair = checking_pair;
            }
        }

        ////Swapping indexes in the array
        //pair[x] goes to a temporary index
        pair tempIndex = pairs[index];
        //pair[x] recieves pairs[i]
        pairs[index] = pairs[i];
        //pairs[i] swapped to pair[index]
        pairs[i] = tempIndex;
    }
    return;
}

// Assists the following function
bool cycle(int winner, int loser)
{
    if(locked[loser][winner] == true)
    {
        return true;
    }

    for (int j = 0; j < candidate_count; j++)
    {
        if (locked[loser][j] && cycle(winner, j))
        {
            return true;
        }
    }
    return false;
}

// Gets the winner of the election
void lock_pairs(void)
{
    // Goes through each pair
    for (int i =0; i < pair_count; i++)
    {
        if(!cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{

    int arr[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        arr[i] = 0;
    }

    for (int i = 0; i < candidate_count; i ++)
    {
        for (int j = 0; j < candidate_count; j ++)
        {
            arr[i] += locked[j][i];
        }

        if (arr[i] == 0)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
    return;
}