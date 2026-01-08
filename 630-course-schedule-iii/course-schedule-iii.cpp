class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        priority_queue<int> taken;



        int time = 0;

        for (auto& c : courses) {


            time += c[0];
            taken.push(c[0]);

            if (time > c[1]) {
                time -= taken.top();
                taken.pop();
            }
        }

        return taken.size();
       }


};
