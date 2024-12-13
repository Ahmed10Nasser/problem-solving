// problem link: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/


class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int one_students = 0, zero_students=0;
        for(auto& student : students){
            if(student == 1) one_students++;
            else zero_students++;
        }
        for(auto& sandwiche : sandwiches){
            if(sandwiche == 1){
                if(one_students > 0)
                    one_students--;
                else
                    return zero_students;
            }
            else{
                if(zero_students > 0)
                    zero_students--;
                else
                    return one_students;
            }
        }
        return 0;
    }
};