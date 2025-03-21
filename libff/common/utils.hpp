/** @file
 *****************************************************************************
 Declaration of misc math and serialization utility functions
 *****************************************************************************
 * @author     This file is part of libff, developed by SCIPR Lab
 *             and contributors (see AUTHORS).
 * @copyright  MIT license (see LICENSE file)
 *****************************************************************************/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace libff {

typedef std::vector<bool> bit_vector;

size_t get_power_of_two(size_t n);

/// returns ceil(log2(n)), so 1ul<<log2(n) is the smallest power of 2, that is not less than n
size_t log2(size_t n);

inline size_t exp2(size_t k) { return size_t(1) << k; }

size_t to_twos_complement(int i, size_t w);
int from_twos_complement(size_t i, size_t w);

size_t bitreverse(size_t n, const size_t l);
bit_vector int_list_to_bits(const std::initializer_list<unsigned long> &l, const size_t wordsize);
long long div_ceil(long long x, long long y);

bool is_little_endian();

std::string FORMAT(const std::string &prefix, const char* format, ...);

/* A variadic template to suppress unused argument warnings */
template<typename ... Types>
void UNUSED(Types&&...) {}

#ifdef DEBUG
#define FMT libff::FORMAT
#else
#define FMT(...) (libff::UNUSED(__VA_ARGS__), "")
#endif

void serialize_bit_vector(std::ostream &out, const bit_vector &v);
void deserialize_bit_vector(std::istream &in, bit_vector &v);

template<typename T>
size_t size_in_bits(const std::vector<T> &v);

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

} // libff

#include <libff/common/utils.tcc> /* note that utils has a templatized part (utils.tcc) and non-templatized part (utils.cpp) */
#endif // UTILS_HPP_
