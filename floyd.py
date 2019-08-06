import sys

max_size = sys.maxsize


def print_matrix(mat: list) -> None:
    for r in mat:
        for i in r:
            print(i if i <= max_size-1 else '*', end=',')
        print()


def init_r_matrix(mat: list) -> list:
    return [[j+1 if mat[i][j] <= max_size-1 else 0 for j in range(0, len(mat))] for i in range(0, len(mat))]


def floyd(mat: list):
    v_len = len(mat)
    r_matrix = init_r_matrix(mat)
    print('init r matrix')
    print_matrix(r_matrix)
    for step in range(0, v_len):
        # if step+1 == 5:
        #     continue
        for i in range(0, v_len):
            for j in range(0, v_len):
                new_path_weight = mat[i][step]+mat[step][j]
                if new_path_weight < mat[i][j]:
                    mat[i][j] = new_path_weight
                    r_matrix[i][j] = r_matrix[i][step]
        print('=========================')
        print('k={}\n,w_mat'.format(step+1))
        print_matrix(mat)
        print('r_mat')
        print_matrix(r_matrix)
        print('=========================')


if __name__ == '__main__':
    mat = [
        [0, 4, max_size, 3, max_size, max_size, max_size],
        [4, 0, 2, max_size, 2, max_size, max_size],
        [max_size, 2, 0, max_size, 3, 2, max_size],
        [3, max_size, max_size, 0, 5, max_size, 3],
        [max_size, 2, 3, 5, 0, 1, 1],
        [max_size, max_size, 2, max_size, 1, 0, 2],
        [max_size, max_size, max_size, 3, 1, 2, 0]
    ]
    print_matrix(mat)
    floyd(mat)
