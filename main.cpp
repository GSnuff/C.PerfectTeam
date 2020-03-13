#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

#define nREQUESTS_MAX 1e4
#define nPARTICIPANT_MAX 1e8

size_t maxPerfectTeams(size_t &nMath, size_t &nCoders, size_t &nUndefined);


size_t max(const size_t &first, const size_t &second) {
    return (first > second ? first : second);
}

size_t min(const size_t &first, const size_t &second) {
    return (first < second ? first : second);
}


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
        std::cout << ' ' << perfectTeam;


}

class BinarySearch {
public:
    BinarySearch(size_t math, size_t coders, size_t undefined);

    size_t binarySearch(const size_t &L, const size_t &R);

private:
    size_t nMath{0};
    size_t nCoders{0};
    size_t nUndef{0};

    bool check(const size_t &numerator, const size_t &denom);

    std::vector<size_t> vectorInit(const size_t L, const size_t R);


    size_t &max(size_t &first, size_t &second);

    size_t &min(size_t &first, size_t &second);

};

BinarySearch::BinarySearch(const size_t math, const size_t coders, const size_t undefined)
        : nMath(math), nCoders(coders), nUndef(undefined) {}


size_t BinarySearch::binarySearch(const size_t &L, const size_t &R) {
    return 0;
}

size_t &BinarySearch::max(size_t &first, size_t &second) {
    return (first > second ? first : second);
}

size_t &BinarySearch::min(size_t &first, size_t &second) {
    return (first < second ? first : second);
}

bool BinarySearch::check(const size_t &numerator, const size_t &denom) {
    return (numerator / denom) > 2;
}

std::vector<size_t> BinarySearch::vectorInit(const size_t L, const size_t R) {
    const size_t N = R - L;
    std::vector<size_t> v(N);
    size_t i = L;
    for (auto p = v.begin();  p < v.end(); ++p, ++i) {
        v[*p] = i;
    }

}


size_t maxPerfectTeams(size_t &nMath, size_t &nCoders, size_t &nUndefined) {
    size_t mx = max(nMath, nCoders);
    size_t mn = min(nMath, nCoders);
    size_t others = nUndefined;
    size_t L = mn;
    size_t R = mn;

    if( ((mx + others) / mn) > 2 ) {
        R = mn;
        mn /= 2;
    } else {
        L = mn;
    }


    return 0;

}

