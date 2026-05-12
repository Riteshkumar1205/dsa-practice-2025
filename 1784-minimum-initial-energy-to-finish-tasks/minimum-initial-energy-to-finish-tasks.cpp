class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return (a[1] - a[0]) > (b[1] - b[0]);
             });

        int currentEnergy = 0;
        int minimumInitialEnergy = 0;

        for (const auto& task : tasks) {

            int actualEnergy  = task[0];
            int requiredEnergy = task[1];

            // Increase initial energy if current energy
            // is not enough to start this task
            if (currentEnergy < requiredEnergy) {

                minimumInitialEnergy +=
                    (requiredEnergy - currentEnergy);

                currentEnergy = requiredEnergy;
            }

            // Finish task
            currentEnergy -= actualEnergy;
        }

        return minimumInitialEnergy;
    }
};