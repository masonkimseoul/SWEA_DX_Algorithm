/*
#include<list>
#include<string>
#include<unordered_map>
using namespace std;

struct info {
	int a, b, sol;
};
info Nation[8625];
int input_number, parent[8625], nation_index[26][26], nation_cnt;;
unordered_map < string, int > NationMap;
list<int> union_list[625];
list<int> enemy_list[625];

int find(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		parent[b] = a;
		union_list[a].splice(union_list[a].end(), union_list[b]);
		enemy_list[a].splice(enemy_list[a].end(), enemy_list[b]);
	}
}

int isSameUnion(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return 1;
	else return 0;
}

int isEnemy(int a, int b) {
	a = find(a);
	b = find(b);
	for (auto enemy : enemy_list[a]) if (find(enemy) == b) return 1;
	return 0;
}

void makeEnemy(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (isEnemy(a, b)) return;
	enemy_list[a].push_back(b);
	enemy_list[b].push_back(a);
}

void init(int N, int mSoldier[25][25], char mMonarch[25][25][11]) {
	int idx = 0, i, j;
	input_number = N;
	NationMap.clear();

	for (j = 0; j < N; j++) {
		for (i = 0; i < N; i++) {
			NationMap[mMonarch[j][i]] = idx;
			nation_index[j][i] = idx;
			
			Nation[idx].sol = mSoldier[j][i];
			Nation[idx].a = i;
			Nation[idx].b = j;
			parent[idx] = idx;

			union_list[idx].clear();
			enemy_list[idx].clear();
			union_list[idx].push_back(idx);
			idx++;
		}
	}
	nation_cnt = N * N;
}

void destroy(){
}

int ally(char mMonarchA[11], char mMonarchB[11]) {
	int a, b;
	a = NationMap[mMonarchA];
	b = NationMap[mMonarchB];

	if (isSameUnion(a, b)) return -1;
	if (isEnemy(a, b)) return -2;

	Union(a, b);
	return 1;
}

int attack(char mMonarchA[11], char mMonarchB[11], char mGeneral[11]) {
	int a, b, boss_a, boss_b, start_a, end_a, start_b, end_b, i, j, total_a, total_b, move_cnt;
	
	a = NationMap[mMonarchA];
	b = NationMap[mMonarchB];

	boss_a = find(a);
	boss_b = find(b);

	if (boss_a == boss_b) return -1;

	start_a = Nation[b].a - 1;
	end_a = Nation[b].a + 1;
	start_b = Nation[b].b - 1;
	end_b = Nation[b].b + 1;

	if (start_a < 0) start_a = 0;
	if (start_b < 0) start_b = 0;
	if (end_a > input_number - 1) end_a = input_number - 1;
	if (end_b > input_number - 1) end_b = input_number - 1;

	int isThereEnemy = 0;
	for (i = start_b; i <= end_b; i++) {
		for (j = start_a; j <= end_a; j++) {
			if (boss_a == find(nation_index[i][j])) {
				isThereEnemy = 1;
				i = input_number;
				break;
			}
		}
	}

	if (isThereEnemy == 0) return -2;

	makeEnemy(boss_a, boss_b);
	total_a = 0;
	total_b = Nation[b].sol;
	Nation[b].sol = 0;

	for (i = start_b; i <= end_b; i++) {
		for (j = start_a; j <= end_a; j++) {
			if (boss_a == find(nation_index[i][j])) {
				move_cnt = Nation[nation_index[i][j]].sol / 2;
				Nation[nation_index[i][j]].sol -= move_cnt;
				total_a += move_cnt;
			}
			else if (boss_b == find(nation_index[i][j])) {
				move_cnt = Nation[nation_index[i][j]].sol / 2;
				Nation[nation_index[i][j]].sol -= move_cnt;
				total_b += move_cnt;
			}
		}
	}

	if (total_b >= total_a) {
		Nation[b].sol = total_b - total_a;
		return 0;
	}

	union_list[boss_b].remove(b);
	Nation[b].sol = total_a - total_b;
	Nation[nation_cnt] = Nation[b];
	nation_index[Nation[nation_cnt].b][Nation[nation_cnt].a] = nation_cnt;
	NationMap[mGeneral] = nation_cnt;
	parent[nation_cnt] = boss_a;
	union_list[boss_a].push_back(nation_cnt);

	nation_cnt++;
	return 1;
}

int recruit(char mMonarch[11], int mNum, int mOption)
{
	int sum = 0, a, boss;

	if (mOption == 0) {
		a = NationMap[mMonarch];
		Nation[a].sol += mNum;
		sum = Nation[a].sol;
	}
	else {
		boss = find(NationMap[mMonarch]);
		for (auto nation : union_list[boss]) {
			Nation[nation].sol += mNum;
			sum += Nation[nation].sol;
		}
	}
	return sum;
}
*/