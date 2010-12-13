#include <stdio.h>

template <class _Arg1, class _Arg2, class _Result>
struct binary_function {
  typedef _Arg1 first_argument_type;
  typedef _Arg2 second_argument_type;
  typedef _Result result_type;
};

template <typename S, typename T, typename A>
class mem_fun1_t : public binary_function<T*, A, S> {
public:
        explicit mem_fun1_t(S (T::*pf)(A)) : f(pf) {}
        S operator()(T* p, A x) const { return (p->*f)(x); }
private:
        S (T::*f)(A);
};

template <typename S, typename T, typename A>
mem_fun1_t<S,T,A> mem_fun(S (T::*f)(A)) {
        return mem_fun1_t<S,T,A>(f);
}

template <typename A, typename Function>
void Execute(A a, Function f)
{
        f(*a);
}

class TPolicy {
public:
        void show(int a) {
                printf("I'm TPolicy, %d\n", a);
        }
};

//template <typename T = TPolicy>
//class Daemon : public T {
class Daemon {
public:
        void go(int a) {
//                T::show(a);
                printf("%d\n", a);
        }
};

int main()
{
        Daemon *d;
        d = new Daemon;
        Execute(d, mem_fun(&Daemon::go));
        delete d;
        return 0;
}

