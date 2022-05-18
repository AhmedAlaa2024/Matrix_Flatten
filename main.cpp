#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::vector;

/* tensor -> 3D Matrix */
/* n -> Default Size of height */
/* m -> Default Size of width */
/* p -> Default Size of depth */

template<class T>
vector<T> flatten(vector<vector<vector<T>>> tensor, int n, int m, int p)
{
    vector<T> _1D_vector(n * m * p);

    int i, j, k;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < p; k++) {
                _1D_vector[i + n * (j + m * k)] = tensor[i][j][k];
            }
        }
    }

    return _1D_vector;
}

template <class T>
vector<vector<vector<T>>> ReadTensor(std::fstream &in, int &n, int &m, int &p)
{
    in >> n;
    in >> m;
    in >> p;

    vector<vector<vector<T>>> tensor(n, vector<vector<T>>(m, vector<T>(p)));
    int i, j, k;

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            for (k = 0; k < p; k++)
                in >> tensor[i][j][k];

    return tensor;
}

int main(void)
{
    int n, m, p;

    std::string filename;
    cout << "Enter the test file name: ";
    cin >> filename;
    std::fstream in(filename);

    if (!in.is_open()) {
        cerr << "Could not open the file - '" << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    int num_test;

    in >> num_test;

    vector<vector<vector<int>>>* tests = new vector<vector<vector<int>>>[num_test];
    vector<vector<int>> results;
    
    int test_id, y;
    for (test_id = 0; test_id < num_test; test_id++)
    {
        cout << "Test[" << test_id + 1 << "]: " << endl;
        tests[test_id] = ReadTensor<int>(in, n, m, p);

        
        results.push_back(flatten<int>(tests[test_id], n, m, p));

        for (y = 0; y < results[test_id].size(); y++)
            cout << results[test_id][y] << " ";

        cout << endl << endl;
    }


    in.close();
    return EXIT_SUCCESS;
}