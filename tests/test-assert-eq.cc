#include <lest.h>

#include <chrono>
#include <thread>

template<typename T>
class Foo
{
public:
    Foo()
    {
        x_ = 0;
    }
    Foo(T x): x_(x)
    {
        
    }

    bool operator ==(const Foo<T>& f)
    {
        return x_ == f.x_;
    }

    bool operator !=(const Foo<T>& f) {
        return x_ != f.x_;
    }

    bool operator <(const Foo<T>& f) {
        return x_ < f.x_;
    }

    bool operator <=(const Foo<T>& f) {
        return x_ <= f.x_;
    }

    bool operator >(const Foo<T>& f) {
        return x_ > f.x_;
    }

    bool operator >=(const Foo<T>& f) {
        return x_ >= f.x_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Foo<T>& foo) {
        return os << foo.x_;
    }

private:
    T x_;

};

TEST(LestDogfood, Eq)
{
    AEQ(1, 1);
    AEQ(1.0f, 1.0f);
    AEQ("Fun", "Fun");

    Foo<std::int8_t> foo1_i8, foo2_i8(0);
    Foo<std::int16_t> foo1_i16, foo2_i16(0);
    Foo<std::int32_t> foo1_i32, foo2_i32(0);
    Foo<std::int64_t> foo1_i64, foo2_i64(0);

    Foo<std::uint8_t> foo1_u8, foo2_u8(0);
    Foo<std::uint16_t> foo1_u16, foo2_u16(0);
    Foo<std::uint32_t> foo1_u32, foo2_u32(0);
    Foo<std::uint64_t> foo1_u64, foo2_u64(0);

    AEQ(foo1_i8, foo2_i8);
    AEQ(foo1_i16, foo2_i16);
    AEQ(foo1_i32, foo2_i32);
    AEQ(foo1_i64, foo2_i64);
    
    AEQ(foo1_u8, foo2_u8);
    AEQ(foo1_u16, foo2_u16);
    AEQ(foo1_u32, foo2_u32);
    AEQ(foo1_u64, foo2_u64);
}

TEST(LestDogfood, Ne)
{
    ANE(1, 2);
    ANE(1.0f, 1.0000001f);
    ANE("Fun", "Fun2");

    Foo<std::int8_t> foo1_i8, foo2_i8(42);
    Foo<std::int16_t> foo1_i16, foo2_i16(42);
    Foo<std::int32_t> foo1_i32, foo2_i32(42);
    Foo<std::int64_t> foo1_i64, foo2_i64(42);

    Foo<std::uint8_t> foo1_u8, foo2_u8(42);
    Foo<std::uint16_t> foo1_u16, foo2_u16(42);
    Foo<std::uint32_t> foo1_u32, foo2_u32(42);
    Foo<std::uint64_t> foo1_u64, foo2_u64(42);

    ANE(foo1_i8, foo2_i8);
    ANE(foo1_i16, foo2_i16);
    ANE(foo1_i32, foo2_i32);
    ANE(foo1_i64, foo2_i64);
    
    ANE(foo1_u8, foo2_u8);
    ANE(foo1_u16, foo2_u16);
    ANE(foo1_u32, foo2_u32);
    ANE(foo1_u64, foo2_u64);
}