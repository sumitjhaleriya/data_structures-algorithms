#include <iostream>
#include <string>

int getMinOperations(const std::string &series)
{
    int operations = 0;
    int n = series.length();

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while (i + 1 < n && series[i] == series[i + 1])
        {
            i++;
            count++;
        }
        operations++;
    }

    return operations/2 +1;
}

int main()
{
    std::string series;
    series = "abcddcba"; // Read the series of nodes

    int minOperations = getMinOperations(series);

    std::cout << minOperations << std::endl;

    return 0;
}
