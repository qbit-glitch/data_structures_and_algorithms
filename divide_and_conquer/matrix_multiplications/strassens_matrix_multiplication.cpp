#include <iostream>
#include <bits/stdc++.h>
#include <cassert>


/**
 * NOTES: 
 * template<typename Number, typename = typename std::enable_if<std::is_integral<Number>::value || std::is_floating_point<Number>::value, bool>::type>
 
 * The above function means :
    
    “I am defining a template that takes a type Number.  In addition, there is a hidden second template parameter that—by default—will only exist if Number is either an integral type or a floating‐point type.  If Number is anything else, the substitution of that second parameter fails, and this template is removed from overload resolution.”

    In even shorter form:

    “Enable this template only when Number is an integer or a floating‐point type.”
 * 
 */

namespace divide_and_conquer {
    namespace strassens_multiplication {
        // complement of 0 is a max integer
        constexpr size_t MAX_SIZE = ~0ULL;

        template<typename T, typename = typename std::enable_if<std::is_integral<T>:: value || std::is_floating_point<T>:: value, bool> :: type>
        class Matrix {
            std:: vector<std::vector<T>> _mat;

            public:

            template <typename Integer, typename = typename std::enable_if<std::is_integral<Integer>:: value, Integer> :: type>
            explicit Matrix(const Integer size){
                for(size_t i = 0; i < size; i++){
                    _mat.emplace_back(std::vector<T>(size,0));
                }
            }

            template<typename Integer, typename = typename std::enable_if<std::is_integral<Integer>:: value, Integer>::type>
            Matrix(const Integer rows, const Integer cols){
                for(size_t i = 0; i< rows; i++){
                    _mat.emplace_back(std::vector<T>(cols,0));
                }
            }

            // Get the matrix shape. Returns a pair denoting total rows and colums
            inline std::pair<size_t, size_t> size() const {
                return {_mat.size(), _mat[0].size()};
            }

            // returns the address of an element at ith place
            template <typename Integer, typename = typename std::enable_if<std::is_integral<Integer>::value, Integer>::type>
            inline std::vector<T> &operator[](const Integer index){
                return _mat[index];
            }

            // Function to create a new matrix and returns a part of it. 
            // Returns a slice of (row_end - row_start) x (col_end - col_start) size of array starting from row_start row and col_start column
            Matrix slice(const size_t row_start, const size_t row_end = MAX_SIZE, const size_t col_start = MAX_SIZE, const size_t col_end = MAX_SIZE) const {
                
                const size_t h_size = (row_end != MAX_SIZE ? row_end : _mat.size()) - row_start;

                const size_t v_size = (col_end != MAX_SIZE ? col_end : _mat[0].size()) - (col_start != MAX_SIZE ? col_start : 0);

                Matrix result = Matrix<T>(h_size, v_size);

                const size_t v_start = (col_start != MAX_SIZE ? col_start : 0);

                for(size_t i = 0; i < h_size; i++){
                    for(size_t j = 0; j < v_size; j++){
                        result._mat[i][j] = _mat[i + row_start][j + v_start];
                    }
                }

                return result;
            }
            
            /**  
             * Function to horizontally stack the matrix (one after the other)
             * Returns void but modifies the current array. Note that the other array is not modified
            */ 
            template<typename Number, typename = typename std::enable_if<std::is_integral<Number>::value || std::is_floating_point<Number>::value, Number> :: type >
            void hstack(const Matrix<Number> &other){
                assert(_mat.size() == other._mat.size());
                for(size_t i = 0; i < other._mat.size(); i++) {
                    for(size_t j = 0; j < other._mat[i].size(); j++){
                        _mat[i].push_back(other._mat[i][j]);
                    }
                }
            }

            /**
             * Function to vertically stack the matrix (current matrix above the other)
            */
            template<typename Number, typename = typename std::enable_if<std:is_integral<Number> :: value, Number>::type>
            void v_stack(const Matrix<Number> &other){
                assert(_mat[0].size() == other._mat[0].size());
                for(size_t i = 0; i < other._mat.size(); i++){
                    _mat.emplace_back(std::vector<T>(other._mat[i].size()));
                    for(size_t j = 0; j < other._mat[0].size(); j++){
                        _mat.back()[j] = other._mat[i][j];
                    }
                }
            }

            /**
             * Function to add two matrices and returns a new Matrix
            */
            template<typename Number, typename = typename std::enable_if<std::is_integrak<Number>::value || std::is_floating_point<Number>::value, bool>::type>
            Matrix operator+(const Matrix<Number> &other) const {
                assert(this->size() == other.size());
                
                Matrix C = Matrix<Number>(_mat.size(), _mat[0].size());

                for(size_t i = 0; i < _mat.size(); i++){
                    for (size_t j = 0; j < _mat[i].size(); j++){
                        C._mat[i][j] = _mat[i][j] + other._mat[i][j];
                    }
                }
                
                return c;
            }

            /**  
             * Add another matrices to current matrix and returns reference of current matrix
            */
            template<typename Number, typename = typename std::enable_if<std::is_integral<Number>::value || std::is_floating_point<Number>::value, bool>::type>
            Matrix &operator+=(const Matrix<Number> &other) const {
                assert(this->size() == other.size());
                for(size_t i = 0; i < _mat.size(); i++){
                    for(size_t j = 0; j < _mat[i].size(); j++){
                        _mat[i][j] += other._mat[i][j];
                    }
                }
                return this;    
            }

            /**
             * Subtract two matrices and returns a new matrix
             * returns new matrix
             */
            template<typename Number, typename = typename std::enable_if<std::is_integral<Number>::value || std::is_floating_point<Number>::value, bool>::type>
            Matrix operator-(const Matrix<Number> &other) const {
                assert(this->size() == other.size());
                Matrix C = Matrix<Number>(_mat.size(), _mat[0].size());
                for(size_t i = 0; i < _mat.size(); i++) {
                    for(size_t j = 0; j < _mat[i].size(); j++) {
                        C._mat[i][j] = _mat[i][j] - other._mat[i][j]; 
                    }
                }
                return C;
            }

            /**
             * Function to subract another matrices to the current matrix
             * returns a reference of the current matrix
             */
            template <typename Number, typename = typename std::enable_if<std::is_integral<Number>::value || std::is_floating_point<Number>::value, bool>::type>

            Matrix &operator-=(const matrix<Number> &other) const {
                assert(this->size() == other.size());
                for(size_t i = 0; i < _mat.size(); i++){
                    for(size_t j=0; j < _mat[i].size(); ++j){
                        _mat[i][j] -= other._mat[i][j];
                    }
                }
                return this;
            }
            
            /**
             * Function to multiply two matrices and returns a new matrix
             */
            template<typename Number, typename = typename std::enable_if<std::is_integral<Number>::value || std::is_floating_point<Number>::value, bool>::type>
            inline Matrix operator*(const Matrix<Number> &other) const {
                assert(_mat[0].size() == other._mat.size());
                auto size = this -> size();
                const size_t row = size.first, col = size.second;
                // Main condition for applying strassen's method:
                // 1. matrix should be a square matrix
                // 2. matrix should be of even size (mat.size() % 2 == 0)
                return (row == col && (row & 1) == 0) ? this->strassens_multiplication(other) : this->naive_multiplication(other);
            }


            // Function to Multiply matrix with a number and returns a new matrix
            template <typename Number, typename = typename std::enable_if<std::is_integral<Number>::value || std::is_floating_point<Number>::value, bool>::type>
            inline Matrix operator*(const Number other) const {
                Matrix C = Matrix<Number>(_mat.size(), _mat[0].size());
                for(size_t i = 0; i < _mat.size(); i++){
                    for(size_t j = 0; j < _mat[i].size(); j++){
                        C._mat[i][k] = _mat[i][j] * other;
                    }
                }
                return C;
            }

            // Function to multiply a number to current matrix and returns a reference of current matrix
            template <typename Number, typename = typename std::enable_if<std::is_integral<Number>::value || std::is_floating_point<Number>::value, bool>::type>
            Matrix &operator*=(const Number other) const {
                for(size_t i = 0; i < _mat.size(); i++){
                    for(size_t j = 0; j < _mat[i].size(); ++j){
                        _mat[i][j] *= other;
                    }
                }
                return this;
            }


            // Function to perform naive multiplication
            template<typename Number, typename = typename std::enable_if<std::is_integral<Number>:: value || std::is_floating_point<Number>::value, bool>::type>
            Matrix naive_multiplication(const Matrix<Number> &other) const {
                Matrix C = Matrix<Number>(_mat.size(), other._mat[0].size());
                for(size_t i = 0; i < _mat.size(); i++){
                    for(size_t k = 0; k < _mat[0].size(); k++){
                        for(size_t j = 0; j < other._mat[0].size(); j++){
                            C._mat[i][j] += _mat[i][k] * other._mat[k][j];
                        }
                    }
                }
                return C;
            }

            // Function to perform Strassens method of matrix multiplication and returns a new matrix
            template<typename Number, typename = typename std::enable_if<std::is_integral<Number>::value || std::is_floating_point<Number>::value, bool>::type>
            Matrix strassens_multiplication(const Matrix<Number &other>) const {
                const size_t size = _mat.size();
                // Base case: when a matrix is small enough for faster naive multiplication, or the matrix is of odd size then go with anive multiplication route;
                // else: go with strassen's method
                
                if(size <= 64ULL || (size & 1ULL)){
                    return this -> naive_multiplication(other);
                } else {
                    const Matrix<Number>
                        A = this -> slice(0ULL, size >> 1, 0ULL, size >> 1),
                        B = this -> slice(0ULL, size >> 1, size >> 1, size),
                        C = this -> slice(size>>1, size, 0ULL, size>>1),
                        D = this -> slice(size>>1, size, size>>1, size),
                        E = other.slice(0ULL, size>>1, 0ULL, size>>1 ),
                        F = other.slice(0ULL, size>>1, size>>1, size),
                        G = other.slice(size>>1, size, 0ULL, size>>1),
                        H = other.slice(size>>1, size, size>>1, size);

                    Matrix P1 = A.strassens_multiplication(F-H);
                    Matrix P2 = (A + B).strassens_multiplication(H);
                    Matrix P3 = (C+D).strassens_multiplication(E);
                    Matrix P4 = D.strassens_multiplication(G-E);
                    Matrix P5 = (A+D).strassens_multiplication(E + H);
                    Matrix P6 = (B-D).strassens_multiplication(G+H);
                    Matrix P7 = (A-C).strassens_multiplication(E+F);

                    // Building the Final Matrix C would be
                    //     [      |      ]
                    //     [ C11  |  C12 ]
                    // C = [ ____ | ____ ]
                    //     [      |      ]
                    //     [ C21  |  C22 ]
                    //     [      |      ]

                    Matrix C11 = P5 + P4 - P2 + P6;
                    Matrix C12 = P1 + P2;
                    Matrix C21 = P3 + P4;
                    Matrix C22 = P1 + P5 - P3 - P7;

                    C21.h_stack(C22);
                    C11.h_stack(C12);
                    C11.v_stack(C21);

                    return C11;
                }
            }















        }












    ;}
}