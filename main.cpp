#include <vector>
#include <iostream>

size_t max(const size_t &first, const size_t &second);
size_t min(const size_t &first, const size_t &second);
size_t maxPerfectTeams(const size_t &nMath, const size_t &nCoders, const size_t &nUndefined);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t nRequest;
    size_t nMath, nCoders, nUndef;

    std::cin >> nRequest;
    std::vector<size_t> perfectTeams;

    for (size_t i = 0; i < nRequest; ++i) {
        std::cin >> nMath >> nCoders >> nUndef;
        perfectTeams.push_back(maxPerfectTeams(nMath, nCoders, nUndef));
    }

    for (size_t perfectTeam : perfectTeams)
        std::cout << perfectTeam << ' ' ;


}

size_t max(const size_t &first, const size_t &second) {
    return (first > second ? first : second);
}

size_t min(const size_t &first, const size_t &second) {
    return (first < second ? first : second);
}

void detectRange(int &left, int &right) {

}

size_t maxPerfectTeams(const size_t &nMath, const size_t &nCoders, const size_t &nUndefined) {
    const int maximum = max(nMath, nCoders);
    int maxTeams = min(nMath, nCoders);
    const int max_teams = min(nMath, nCoders);
    int undefined = nUndefined;
    int prev = 0;

    while (maxTeams != 0 && ((maximum + undefined) / maxTeams) < 2) {
        prev = maxTeams;
        maxTeams /= 2;
    }

    if(maxTeams == 0)
        return 0;

    int L = maxTeams;
    int R = prev;
    if (L == R)
        return L;

    int mid;
    --L;
    ++R;
    int res;
    while (R - L > 1) {
        mid = (L + R) / 2;
        res = (maximum + undefined + (max_teams - mid)) / mid;
        if (res >= 2) {
            L = mid;
        } else {
            R = mid;
        }
    }
    return L;
}

