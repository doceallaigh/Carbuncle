#include "Sample.hpp"
#include <iostream>

BEGIN_PRIVATE_IMPLEMENTATION (Sample)
DEFINE_PRIVATE_METHOD(Sample, void, Test_Private, int x)
{
    std::cout << "Private implementation called with value=" << x;
}

DEFINE_PRIVATE_FIELD (Sample, int x);
END_PRIVATE_IMPLEMENTATION (Sample)

BEGIN_DEFAULT_CONSTRUCTOR_IMPLEMENTATION (Sample)
END_DEFAULT_CONSTRUCTOR_IMPLEMENTATION (Sample)

BEGIN_DEFAULT_DESTRUCTOR_IMPLEMENTATION (Sample)
END_DEFAULT_DESTRUCTOR_IMPLEMENTATION (Sample)

void Sample::Test()
{
    ACCESS_PRIVATE_MEMBER (x) = 7357;
    int x = ACCESS_PRIVATE_MEMBER (x);
    ACCESS_PRIVATE_MEMBER (Test_Private (x));
}