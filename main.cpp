#include <vector>
#include <iostream>

uint32_t max(const uint32_t &first, const uint32_t &second);
uint32_t min(const uint32_t &first, const uint32_t &second);
uint32_t maxPerfectTeams(const uint32_t &nMath, const uint32_t &nCoders, const uint32_t &nUndefined);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint32_t nRequest;
    uint32_t nMath, nCoders, nUndef;

    std::cin >> nRequest;
    std::vector<uint32_t > perfectTeams;

    for (uint32_t i = 0; i < nRequest; ++i) {
        std::cin >> nMath >> nCoders >> nUndef;
        perfectTeams.push_back(maxPerfectTeams(nMath, nCoders, nUndef));
    }

    for (uint32_t perfectTeam : perfectTeams)
        std::cout << perfectTeam << ' ' ;


}

uint32_t max(const uint32_t &first, const uint32_t &second) {
    return (first > second ? first : second);
}

uint32_t min(const uint32_t &first, const uint32_t &second) {
    return (first < second ? first : second);
}

uint32_t maxPerfectTeams(const uint32_t &nMath, const uint32_t &nCoders, const uint32_t &nUndefined) {
    const uint32_t maxOfMathAndCoders = max(nMath, nCoders);
    const uint32_t maxTeams = min(nMath, nCoders);

    // detecting range
    uint32_t L = maxTeams, R=maxTeams;
    while (L != 0 && ((maxOfMathAndCoders + nUndefined) / L) < 2) {
        R = L;
        L /= 2;
    }

    if(R == 0)
        return 0;

    while (R - L > 1) {
        uint32_t mid = (L + R) / 2;
        uint32_t res = (maxOfMathAndCoders + nUndefined + (maxTeams - mid)) / mid;
        if (res >= 2) {
            L = mid;
        } else {
            R = mid;
        }
    }
    return L;
}

