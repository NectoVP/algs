#include <iostream>
#include <vector>

class hash_table {
public:
	hash_table(uint64_t n) : bucket_size(n) {
		buckets1.resize(bucket_size);
	}

	uint64_t hash1(const std::string& key) {
		uint64_t sum = 0;
		for (int i = 0; i < key.size(); ++i)
			sum += key[i];
		return sum % bucket_size;
	}

	uint64_t hash2(const std::string& key) {
		uint64_t hashed_val = 0;
		uint64_t p = 1;
		for (int i = 0; i < key.size(); ++i, p*=77)
			hashed_val = (hashed_val + (key[i] + 1) * p);
		return hashed_val % bucket_size;
	}

	bool find(const std::string& key);
	void insert(const std::string& key);

	std::vector<std::string> buckets1;
private:
	uint64_t bucket_size;
};

bool hash_table::find(const std::string& key) {
	return buckets1[hash1(key)] == key || buckets1[hash2(key)] == key;
}

void hash_table::insert(const std::string& key)
{
	std::string temp = key;

	while (true) {
		uint64_t temp_hash1 = hash1(temp);
		uint64_t temp_hash2 = hash2(temp);

		if (buckets1[temp_hash1].empty() || buckets1[temp_hash1] == temp) {
			buckets1[temp_hash1] = temp;
			return;
		}
		else if (buckets1[temp_hash2].empty() || buckets1[temp_hash2] == temp) {
			buckets1[temp_hash2] = temp;
			return;
		}

		std::swap(buckets1[temp_hash1], temp);
		
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	hash_table h1(1010000);
	hash_table h2(1010000);

	int n;
	std::cin >> n;

	int count_first = 0, count_second = 0, count_third = 0;

	std::string s;

	for (int i = 0; i < n; ++i) {
		std::cin >> s;
		h1.insert(s);
		count_first += 3;
	}

	for (int i = 0; i < n; ++i) {
		std::cin >> s;
		count_second += 3;
		h2.insert(s);
		if (h1.find(s)) {
			count_first -= 2;
			count_second -= 2;
		}
	}

	for (int i = 0; i < n; ++i) {
		std::cin >> s;
		count_third += 3;
		bool find1 = h1.find(s);
		bool find2 = h2.find(s);
		if (find1 && find2) {
			count_first -= 1;
			count_second -= 1;
			count_third -= 3;
		}
		else if (find1) {
			count_first -= 2;
			count_third -= 2;
		}
		else if (find2) {
			count_second -= 2;
			count_third -= 2;
		}
	}

	std::cout << count_first << " " << count_second << " " << count_third;

	return 0;
}
