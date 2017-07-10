#pragma once
#include <memory>

#define BEGIN_CLASS_BODY(className) \
public: \
className ## (void); \
className ## (##className##&&); \
~##className ## (void);

#define BEGIN_CLASS_DEFINITION(className, ...) \
\
class className : __VA_ARGS__## \
{ \
BEGIN_CLASS_BODY(className)

// TODO_HIGH This needs to be merged into BEGIN_CLASS_DEFINITION
#define BEGIN_CLASS_DEFINITION_NOPARAMS(className) \
\
class className \
{ \
BEGIN_CLASS_BODY (className)

#define END_CLASS_DEFINITION(className) \
private: \
    struct Pimpl_##className; \
    std::unique_ptr<Pimpl_##className##> pimpl; \
};

#define BEGIN_PRIVATE_IMPLEMENTATION(className) \
struct className##::Pimpl_##className { \

#define DEFINE_PRIVATE_METHOD(className, returnType, methodName, ...) returnType methodName(__VA_ARGS__)

#define DEFINE_PRIVATE_FIELD(className, fieldSignature) fieldSignature

#define END_PRIVATE_IMPLEMENTATION(className) };

#define BEGIN_DEFAULT_CONSTRUCTOR_IMPLEMENTATION(className) \
className##::##className##(void) \
{ \
    this->pimpl = std::make_unique<className##::Pimpl_##className##>();

#define END_DEFAULT_CONSTRUCTOR_IMPLEMENTATION(className) \
}

#define BEGIN_DEFAULT_DESTRUCTOR_IMPLEMENTATION(className) \
className##::~##className##(void) \
{

#define END_DEFAULT_DESTRUCTOR_IMPLEMENTATION(className) \
}

#define ACCESS_PRIVATE_MEMBER(memberName) this->pimpl->##memberName