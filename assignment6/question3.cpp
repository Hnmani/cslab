#include <bits/stdc++.h>

void getInput(std::vector<int> &difficulty, std::vector<int> &workers, std::vector<int> &profit, int NUMBER_OF_WORKERS, int NUMBER_OF_JOBS)
{
    for (int i = 0; i < NUMBER_OF_JOBS; i++)
    {
        std::cin >> difficulty[i];
    }
    for (int i = 0; i < NUMBER_OF_JOBS; i++)
    {
        std::cin >> profit[i];
    }
    for (int i = 0; i < NUMBER_OF_WORKERS; i++)
    {
        std::cin >> workers[i];
    }
}

int getMaxProfitSolution(std::vector<int> &profit, std::vector<int> &workers, std::vector<int> &difficulty, int NUMBER_OF_WORKERS, int NUMBER_OF_JOBS)
{
    int solution = 0;
    for (int i = 0; i < NUMBER_OF_WORKERS; i++)
    {
        int maxProfit = 0;
        for (int j = 0; j < NUMBER_OF_JOBS; j++)
        {
            if (difficulty[j] <= workers[i])
            {
                if (maxProfit < profit[j])
                    maxProfit = profit[j];
            }
        }
        solution += maxProfit;
    }
    return solution;
}

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int NUMBER_OF_JOBS;
        int NUMBER_OF_WORKERS;
        std::cin >> NUMBER_OF_JOBS;
        std::cin >> NUMBER_OF_WORKERS;
        std::vector<int> profit(NUMBER_OF_JOBS);
        std::vector<int> workers(NUMBER_OF_WORKERS);
        std::vector<int> difficulty(NUMBER_OF_JOBS);
        getInput(difficulty, workers, profit, NUMBER_OF_WORKERS, NUMBER_OF_JOBS);
        int solution = getMaxProfitSolution(profit, workers, difficulty, NUMBER_OF_WORKERS, NUMBER_OF_JOBS);
        std::cout << solution << std::endl;
    }
}