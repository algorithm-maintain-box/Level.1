using namespace std;
//구글링함
long long solution(int w, int h)
{
	long long sum = (long long)w * (long long)h;
	int gcd;

	for (int i = (w < h) ? w : h; i > 0; i--)
	{
		if ((w % i == 0) && (h % i == 0)) {
			gcd = i;
			break;
		}
	}

	if (w == h)
	{
		return sum - w;
	}

	return sum - ((w / gcd) + (h / gcd) - 1) * gcd;
}