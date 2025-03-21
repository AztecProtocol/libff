/** @file
 *****************************************************************************

 Implementation of interfaces for (square-and-multiply) exponentiation.

 See exponentiation.hpp .

 *****************************************************************************
 * @author     This file is part of libff, developed by SCIPR Lab
 *             and contributors (see AUTHORS).
 * @copyright  MIT license (see LICENSE file)
 *****************************************************************************/

#ifndef EXPONENTIATION_TCC_
#define EXPONENTIATION_TCC_

#include <libff/common/utils.hpp>

namespace libff {

template<typename FieldT, mp_size_t m>
FieldT power(const FieldT &base, const bigint<m> &exponent)
{
    FieldT result = FieldT::one();

    bool found_one = false;

    for (long i = static_cast<long>(exponent.max_bits() - 1); i >= 0; --i)
    {
        if (found_one)
        {
            result = result * result;
        }

        if (exponent.test_bit(static_cast<size_t>(i)))
        {
            found_one = true;
            result = result * base;
        }
    }

    return result;
}

template<typename FieldT>
FieldT power(const FieldT &base, const unsigned long exponent)
{
    return power<FieldT>(base, bigint<1>(exponent));
}

} // libff

#endif // EXPONENTIATION_TCC_
