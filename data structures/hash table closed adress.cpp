#include <iostream>
#include <list>
#include <vector>

static constexpr double phi = 0.6180339887498948482;

class hash_table {
public:
	hash_table() : bucket_size(541), max_load_factor(0.5f),
		total_elements(0), avg(0) {
		buckets.resize(bucket_size);
	}

	std::list<std::pair<int, int>>::iterator find(int key);
	void insert(int key, int val);
	void erase(int key);
	int get_avg() {
		return (total_elements == 0 ? 0 : avg / total_elements);
	}
	int get_max() {
		int max = 0;
		for (auto it = maxes.begin(); it != maxes.end(); ++it) {
			if ((*it) > max)
				max = (*it);
		}
		return max;
		//return maxes.back();
	}

private:
	int bucket_size;
	int64_t avg;
	int total_elements;
	float max_load_factor;
	std::vector<std::list<std::pair<int, int>>> buckets;
	std::list<int> maxes;

	int hash(int key);
	void rehash();
};

int hash_table::hash(int key) {
	auto temp = key * phi;
	return bucket_size * (temp - static_cast<int>(temp));
}

void hash_table::rehash()
{
	if (total_elements / bucket_size <= max_load_factor)
		return;
	bucket_size *= 2;
	std::vector<std::list<std::pair<int, int>>> new_buckets(bucket_size);
	for (int i = 0; i < bucket_size / 2; ++i) {
		for (auto it = buckets[i].begin(); it != buckets[i].end(); ++it)
			new_buckets[hash(it->first)].push_back(*it);
	}
	buckets = std::move(new_buckets);
}

std::list<std::pair<int, int>>::iterator hash_table::find(int key) {
	int temp_hash = hash(key);
	for (auto it = buckets[temp_hash].begin(); it != buckets[temp_hash].end(); ++it) {
		if (it->first == key)
			return it;
	}
	return buckets[temp_hash].end();
}

void hash_table::insert(int key, int val)
{
	auto it = find(key);
	int temp_hash = hash(key);
	//if (it != buckets[temp_hash].end()) {
	//	//if (val >= maxes.back())
	//		//maxes.push_back(val);
	//	it->second = val;
	//	return;
	//}
	maxes.push_back(val);
	buckets[temp_hash].push_back({ key, val });

	avg += val;

	++total_elements;

	//if (val >= maxes.back())
		//maxes.push_back(val);

	rehash();
}

void hash_table::erase(int key)
{
	int temp_hash = hash(key);
	auto it = find(key);

	if (it == buckets[temp_hash].end())
		return;

	avg -= it->second;

	--total_elements;

	for (auto del_it = maxes.begin(); del_it != maxes.end(); ++del_it) {
		if ((*del_it) == it->second) {
			maxes.erase(del_it);
			break;
		}
	}

	//if (it->second >= maxes.back())
		//maxes.pop_back();

	buckets[temp_hash].erase(it);
	rehash();
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;

	std::vector<hash_table> groups(n);

	int k;
	std::cin >> k;

	char request;
	int group_num, student, points;
	for (int i = 0; i < k; ++i) {
		std::cin >> request;
		if (request == '+') {
			std::cin >> group_num >> student >> points;
			groups[group_num - 1].insert(student, points);
		}
		else if (request == '-') {
			std::cin >> group_num >> student;
			groups[group_num - 1].erase(student);
		}
		else if (request == 'a') {
			std::cin >> group_num;
			std::cout << groups[group_num - 1].get_avg() << '\n';
		}
		else if (request == 'm') {
			std::cin >> group_num;
			std::cout << groups[group_num - 1].get_max() << '\n';
		}
	}

	return 0;
}
