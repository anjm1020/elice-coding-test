#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int prime_list[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int arr[] = {4, 6, 8, 10, 12, 14, 16};

void problem1() {
    int N;
    cin >> N;

    while (N != 1) {
        if (N % 2 == 0) {
            N /= 2;
        } else {
            N = N * 3 + 1;
        }
        printf("%d\n", N);
    }
}

void problem2() {
    string original, modified;
    cin >> original;

    modified = original;
    reverse(modified.begin(), modified.end());

    int N = stoi(original);
    int M = stoi(modified);

    cout << (N > M ? N : M) << '\n';
}

void problem3(const string code) {
    map<char, char> signal = {
        {'a', 'n'}, {'b', 'd'}, {'c', 'a'}, {'d', 'b'}, {'e', 'e'}, {'f', 'l'}, {'g', 'j'}, {'h', 'o'}, {'i', 'z'}, {'j', 'u'}, {'k', 'y'}, {'l', 'v'}, {'m', 'w'}, {'n', 'q'}, {'o', 'x'}, {'p', 'r'}, {'q', 'p'}, {'r', 'f'}, {'s', 'g'}, {'t', 't'}, {'u', 'm'}, {'v', 'h'}, {'w', 'i'}, {'x', 'c'}, {'y', 'k'}, {'z', 's'}};

    string res = "";
    for (char c : code) {
        if (signal.find(c) == signal.end()) {
            res = res + c;
        } else {
            res = res + signal.at(c);
        }
    }
    cout << res << '\n';
}

void problem4() {
    int N, M;
    cin >> N >> M;

    int multi = N * M;

    if (N < M) {
        int tmp = N;
        N = M;
        M = tmp;
    }

    int tmp;
    while (M != 0) {
        tmp = N;
        N = M;
        M = tmp % M;
    }

    printf("%d\n", (int)(multi / N));
}

void problem5() {
    int arrLen = (sizeof(arr) / sizeof(arr[0]));
    int pirmeLen = (sizeof(prime_list) / sizeof(prime_list[0]));

    int target, lt, rt, mid;
    int i = 0;
    while (i < arrLen) {
        target = arr[i++];

        lt = 0;
        rt = pirmeLen;

        while (lt <= rt) {
            mid = (lt + rt) / 2;
            if (prime_list[mid] > (target / 2)) {
                rt = mid - 1;
            } else {
                lt = mid + 1;
            }
        }

        lt = rt;
        int sum = prime_list[lt] + prime_list[rt];
        while (sum != target) {
            if (sum > target) {
                lt--;
            } else {
                rt++;
            }
            sum = prime_list[lt] + prime_list[rt];
        }
        printf("%d %d\n", prime_list[lt], prime_list[rt]);
    }
}

int main() {
    printf("Problem1\n");
    problem1();

    printf("Problem2\n");
    problem2();

    printf("Problem3\n");
    string code = "w fhle khj";
    problem3(code);

    printf("Problem4\n");
    problem4();

    printf("Problem5\n");
    problem5();
}
