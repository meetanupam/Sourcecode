import java.util.ArrayList;

static long dp[][][] = new long[20][180][2];

static void getDigits(long x, ArrayList<Integer> digit) {
    while (x != 0) {
        digit.add((int)(x % 10));
        x /= 10;
    }
}

static long digitSum(int idx, int sum, int tight,
                     ArrayList<Integer> digit) {
    if (idx == -1)
        return sum;

    if (dp[idx][sum][tight] != -1 && tight != 1)
        return dp[idx][sum][tight];

    long ret = 0;

    int k = (tight != 0) ? digit.get(idx) : 9;

    for (int i = 0; i <= k; i++) {
        int newTight = (digit.get(idx) == i) ? tight : 0;
        ret += digitSum(idx - 1, sum + i, newTight,
                        digit);
    }

    if (tight != 0)
        dp[idx][sum][tight] = ret;

    return ret;
}

static int rangeDigitSum(int a, int b) {
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 180; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = -1;

    ArrayList<Integer> digitA = new ArrayList<Integer>();
    getDigits(a - 1, digitA);

    long ans1 = digitSum(digitA.size() - 1, 0, 1, digitA);

    ArrayList<Integer> digitB = new ArrayList<Integer>();
    getDigits(b, digitB);

    long ans2 = digitSum(digitB.size() - 1, 0, 1, digitB);

    return (int)(ans2 - ans1);
}

public static void main(String[] args) {
    int a = 123, b = 1024;
    System.out.println("digit sum for given range : " + rangeDigitSum(a, b));
}
