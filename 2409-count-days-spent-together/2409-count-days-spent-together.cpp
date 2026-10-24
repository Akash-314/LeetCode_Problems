class Solution {
public:
    int countDaysTogether(string arriveA, string leaveA, string arriveB,
                          string leaveB) {
        int monA = stoi(leaveA.substr(0, 2));
        int dayA = stoi(leaveA.substr(3));
        int monB = stoi(leaveB.substr(0, 2));
        int dayB = stoi(leaveB.substr(3));

        int monA2 = stoi(arriveA.substr(0, 2));
        int dayA2 = stoi(arriveA.substr(3));
        int monB2 = stoi(arriveB.substr(0, 2));
        int dayB2 = stoi(arriveB.substr(3));

        if (max(monA2, monB2) > min(monA, monB))
            return 0;

        int ansMon = 0;
        int ansDay = 0;

        int startMon = max(monA2, monB2);
        int endMon = min(monA, monB);

        int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (startMon == endMon) {
            for (int i = max(monA2 == startMon ? dayA2 : 1,
                             monB2 == startMon ? dayB2 : 1);
                 i <= min(monA == endMon ? dayA : days[endMon],
                          monB == endMon ? dayB : days[endMon]);
                 i++) {
                ansDay++;
            }
            return ansDay;
        }

        for (int i = startMon; i <= endMon; i++) {
            if (i == startMon) {
                int startDay =
                    max(monA2 == i ? dayA2 : 1, monB2 == i ? dayB2 : 1);

                for (int j = startDay; j <= days[i]; j++) {
                    ansMon++;
                }
            } else if (i == endMon) {
                int endDay =
                    min(monA == i ? dayA : days[i], monB == i ? dayB : days[i]);

                for (int j = 1; j <= endDay; j++) {
                    ansMon++;
                }
            } else {
                ansMon += days[i];
            }
        }

        return ansMon;
    }
};