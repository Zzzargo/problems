#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

struct Project {
	int start, end, reward;
};

bool compareProjectsByEnd(Project &p1, Project &p2) {
	return p1.end < p2.end;
}

/*
* https://cses.fi/problemset/task/1140/
* There are n projects you can attend. For each project, you know its starting and ending days and the amount of money
* you would get as reward. You can only attend one project during a day. What is the maximum amount of money you can
* earn?
*/

int main() {
	int numProj;

	cin >> numProj;
	vector<Project> projects(numProj);
	for (int i = 0; i < numProj; i++) {
		cin >> projects[i].start >> projects[i].end >> projects[i].reward;
	}

	// Use a greedy approach to facilitate the later search involved in the dp algorithm
	// Sort the projects ascending by end date
	sort(projects.begin(), projects.end(), compareProjectsByEnd);

	// dp[i] = max profit using the first i (sorted) projects
	vector<long long> dp(numProj + 1, 0);
	
	for (int i = 1; i <= numProj; i++) {
		// Choose whether it's best to take or not the current project
		long long dontTakeTotalProfit = dp[i - 1];

		long long takeTotalProfit = projects[i - 1].reward;
		// Calculate the total profit if taking the current project.
		// For that first find the project that ended at least a day before the currently chosen one starts
		auto it = lower_bound(
			projects.begin(),
			projects.begin() + i - 1,
			projects[i - 1].start,
			[](const Project &proj, int startDate) {
				return proj.end < startDate;
		});
		int idx = distance(projects.begin(), it) - 1;

		// If there was such a project we can add it to the potential solution
		if (idx >= 0)
			takeTotalProfit += dp[idx + 1];

		dp[i] = max(dontTakeTotalProfit, takeTotalProfit);
	}

	cout << dp[numProj] << endl;
}
