#include <stdio.h>

template <class _Arg1, class _Arg2, class _Result>
struct binary_function {
  typedef _Arg1 first_argument_type;
  typedef _Arg2 second_argument_type;
  typedef _Result result_type;
};

template <typename S, typename T, typename A, typename B>
class mem_fun2_t {
// : public binary_function<T*, A, S> {
public:
        explicit mem_fun2_t(S (T::*pf)(A, B)) : f(pf) {}
        S operator()(T* p, A x, B y) const { return (p->*f)(x, y); }
private:
        S (T::*f)(A, B);
};

template <typename S, typename T, typename A, typename B>
mem_fun2_t<S,T,A,B> mem_fun(S (T::*f)(A, B)) {
        return mem_fun2_t<S,T,A,B>(f);
}

template <typename A, typename Function, typename X, typename Y>
void Execute(A *a, Function f, X x, Y y)
{
        f(a, x, y);
}

class TPolicy {
public:
        void show(void *b, int a) {
                printf("I'm TPolicy, %d, %d\n", a, *(int*)b);
        }
};

template <typename T = TPolicy>
class Daemon : public T {
//class Daemon {
public:
        void go(void *b, int a) {
//                T::show(a, b);
//                printf("%d\n", a);
		Execute(this, mem_fun(&T::show), b, a);
        }
};

int main()
{
        Daemon<> d;
//        d = new Daemon<>;
//        Execute(&d, mem_fun(&Daemon<>::go), 10, 20);
//        delete d;
	int num = 1234;
	int *buf = &num;
	d.go(buf, 40);
	printf("%s\n", __TIMESTAMP__);
        return 0;
}

