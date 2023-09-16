#include <bits/stdc++.h>

void constructResults(const std::string &startWord, const std::string &currentWord, const std::unordered_map<std::string, std::vector<std::string>> &parentMap, std::vector<std::string> &path, std::vector<std::vector<std::string>> &results)
{
    if (currentWord == startWord)
    {
        path.push_back(startWord);
        std::vector<std::string> temp = path;
        reverse(temp.begin(), temp.end()); // Reverse the path to get the correct order
        results.push_back(temp);
        path.pop_back();
        return;
    }

    path.push_back(currentWord);

    for (const std::string &parent : parentMap.at(currentWord))
    {
        constructResults(startWord, parent, parentMap, path, results);
    }

    path.pop_back();
}
std::vector<std::vector<std::string>> findLadders(std::string startWord, std::string endWord, std::vector<std::string> &wordList)
{
    std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
    std::vector<std::vector<std::string>> results;

    if (wordSet.find(endWord) == wordSet.end())
    {
        return results; // endWord is not in the wordList, no transformation possible
    }

    std::queue<std::string> bfsQueue;
    bfsQueue.push(startWord);

    std::unordered_map<std::string, std::vector<std::string>> parentMap;
    parentMap[startWord] = std::vector<std::string>();

    bool foundEndWord = false;

    while (!bfsQueue.empty() && !foundEndWord)
    {
        int currentSize = bfsQueue.size();
        std::unordered_set<std::string> currentLevelWords;

        for (int i = 0; i < currentSize; i++)
        {
            std::string word = bfsQueue.front();
            bfsQueue.pop();

            for (int j = 0; j < word.length(); j++)
            {
                std::string newWord = word;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    newWord[j] = ch;

                    if (wordSet.find(newWord) != wordSet.end())
                    {
                        if (newWord == endWord)
                        {
                            foundEndWord = true;
                        }

                        if (parentMap.find(newWord) == parentMap.end())
                        {
                            bfsQueue.push(newWord);
                            currentLevelWords.insert(newWord);
                            parentMap[newWord] = {word};
                        }
                        else
                        {
                            parentMap[newWord].push_back(word);
                        }
                    }
                }
            }
        }

        // Remove words at the current level from wordSet to avoid revisiting them
        for (const std::string &word : currentLevelWords)
        {
            wordSet.erase(word);
        }
    }

    if (foundEndWord)
    {
        std::vector<std::string> path;
        constructResults(startWord, endWord, parentMap, path, results);
    }

    return results;
}

int main()
{
    std::string startWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    std::vector<std::vector<std::string>> sequences = findLadders(startWord, endWord, wordList);

    if (sequences.empty())
    {
        std::cout << "No transformation sequences found." << std::endl;
    }
    else
    {
        std::cout << "Shortest transformation sequences:" << std::endl;
        for (const std::vector<std::string> &sequence : sequences)
        {
            for (const std::string &word : sequence)
            {
                std::cout << word << " -> ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}