#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Subgroup {
    int size;
    int *items;
} Subgroup;

void add_subgroup(Subgroup *subgroup, int element) {
   int size = subgroup->size;
   int *newArr = malloc(sizeof(int) * (size + 1));
   for (int i = 0; i < size; i++) *(newArr + i) = subgroup->items[i];
   newArr[size] = element;
   subgroup->items = newArr;
   subgroup->size++;
}

void extend_subgroup(Subgroup *subgroup, Subgroup *elements) {
    int aS = subgroup->size, eS = elements->size;

    int *newArr = malloc(sizeof(int) * (aS + eS)), index = 0;
    for (int i = 0; i < aS; i++, index++) *(newArr + index) = subgroup->items[i];
    for (int i = 0; i < eS; i++, index++) *(newArr + index) = elements->items[i];
    subgroup->items = newArr;
    subgroup->size += eS;
}

int index_subgroup(Subgroup subgroup, int element) {
    for (int i = 0; i < subgroup.size; i++)
        if (subgroup.items[i] == element) return i;
    return -1;
}

void merge(Subgroup arr, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
    int i, j, k;

    Subgroup L = { .size = 0 }, R = { .size = 0 };
	for (i = 0; i < n1; i++) add_subgroup(&L, arr.items[l + i]);
	for (j = 0; j < n2; j++) add_subgroup(&R, arr.items[m + j + 1]);

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L.items[i] <= R.items[j]) {
			arr.items[k] = L.items[i];
			i++;
		} else {
			arr.items[k] = R.items[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr.items[k] = L.items[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr.items[k] = R.items[j];
		j++;
		k++;
	}
}

void mergeSort(Subgroup arr, int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

typedef struct Group {
    int size;
    Subgroup *values;
    struct Group *next;
} Group;

void add_group(Group *group, Subgroup subgroup) {
    int size = group->size;
    Subgroup *newArr = malloc(sizeof(Subgroup) * (size + 1));
    for (int i = 0; i < size; i++) *(newArr + i) = group->values[i];
    newArr[size] = subgroup;
    group->values = newArr;
    group->size++;
}

int index_group(Group group, int element) {
    for (int i = 0; i < group.size; i++)
        if (index_subgroup(group.values[i], element) != -1)
            return i;
    return -1;
}

void remove_group(Group *group, int index) {
    int size = group->size, array_index = 0;
    Subgroup *newArr = malloc(sizeof(Subgroup) * (size - 1));
    for (int i = 0; i < size; i++) {
        if (i != index) {
            *(newArr + array_index) = group->values[i];
            array_index++;
        }
    }
    group->values = newArr;
    group->size--;
}

int equals(char str[], char to[]) {
    int size_str = strlen(str), size_to = strlen(to);
    if (size_str != size_str) return 0;
    for (int i = 0; i < size_str; i++)
        if (str[i] != to[i])
            return 0;
    return 1; 
}

char delim[] = " ";
int main(void) {
    int P, E;
    scanf("%d %d", &P, &E);
    getchar();
    
    Group seguros = { .size = 0 }, inseguros = { .size = 0 };
    for (int s = 1; s <= P; s++) {
        Subgroup tmp = { .size = 0 };
        add_subgroup(&tmp, s);
        add_group(&seguros, tmp);
    }

    for (int e = 0; e < E; e++) {
        char cmd_[20];
        scanf("%[^\n]s", cmd_); 
        getchar();

        char *cmd = strtok(cmd_, delim);
        if (equals(cmd, "c")) {
            cmd = strtok(NULL, delim);
            int P1 = atoi(cmd);
            cmd = strtok(NULL, delim);
            int P2 = atoi(cmd);

            int iP1 = index_group(seguros, P1);
            int iP2 = index_group(seguros, P2);
            
            if (iP1 != -1 && iP2 != -1) {
                if (iP1 == iP2) continue;
                if (iP1 > iP2) {
                    int tmp = iP2;
                    iP2 = iP1;
                    iP1 = tmp;

                    tmp = P2;
                    P2 = P1;
                    P1 = tmp;
                }

                extend_subgroup(&seguros.values[iP1], &seguros.values[iP2]);
                remove_group(&seguros, iP2);
            }
            else if (iP1 == -1 && iP2 != -1) {
                iP1 = index_group(inseguros, P1);
                extend_subgroup(&inseguros.values[iP1], &seguros.values[iP2]);
                remove_group(&seguros, iP2);
            }
            else if (iP1 != -1 && iP2 == -1) {
                iP2 = index_group(inseguros, P2);
                extend_subgroup(&inseguros.values[iP2], &seguros.values[iP1]);
                remove_group(&seguros, iP1);
            }
            else {
                iP1 = index_group(inseguros, P1);
                iP2 = index_group(inseguros, P2);
                if (iP1 == iP2) continue;
                extend_subgroup(&inseguros.values[iP1], &inseguros.values[iP2]);
                remove_group(&inseguros, iP2);
            }
        }
        else if (equals(cmd, "p")) {
            cmd = strtok(NULL, delim);
            int P = atoi(cmd);
            int iP = index_group(seguros, P);
            
            if (iP != -1) {
                add_group(&inseguros, seguros.values[iP]);
                remove_group(&seguros, iP);
            }
        }
        else if (equals(cmd, "n")) printf("%d\n", seguros.size + inseguros.size);
        else if (equals(cmd, "ns")) printf("%d\n", seguros.size);
        else if (equals(cmd, "ni")) printf("%d\n", inseguros.size);
        else if (equals(cmd, "ii")) {
            if (inseguros.size == 0) printf("vazio\n");
            else {
                Subgroup tmp = { .size = 0 };
                for (int i = 0; i < inseguros.size; i++) extend_subgroup(&tmp, &inseguros.values[i]);
                mergeSort(tmp, 0, tmp.size - 1);
                for (int i = 0; i < tmp.size; i++) {
                    printf("%d", tmp.items[i]);
                    if (i + 1 < tmp.size) printf(" ");
                }
                printf("\n");
            }
        }
    }

    return 0;
}