
#include <iostream>

#include <list>

namespace item_1 {

    namespace case_1{

        template<typename T>
        void f(const T& param) 
        {
            std::cout << param << '\n';
        }

        template<typename T>
        void f(T* param)
        {
            std::cout << param << '\n';
        }
    }

    namespace case_2 {
        template<typename T>
        void f(T&& param)
        {
            std::cout << param << '\n';
        }
    }
    
    namespace case_3 {
        template<typename T>
        void f(T param)
        {
            std::cout << param << '\n';
        }

        template <typename T, std::size_t N>
        constexpr std::size_t arraySize(T(&)[N])
        {
            return N;
        }
    }

    int main() {

        int x = 27;
        const int cx = x;
        const int& rx = x;
        const int* px = &x;
        int& pn = x;

        //case_2::f(rx);
        //case_2::f(&rx);
        //case_2::f(px);
        //case_2::f(27);
        
        
        //case_3::f(pn);
        const char* const ptr = "Fun with pointers";
        //case_3::f(ptr);

        const char name[] = "J. P. Briggs";

        const char* ptrToName = name;

        std::cout << name << "  | siz: " << sizeof(name) << '\n';
        std::cout << ptrToName << "  | siz: " << sizeof(ptrToName) << '\n';


        std::cout << case_3::arraySize(name) << '\n';
        int mappedVals[case_3::arraySize(name)];
        std::array<char, case_3::arraySize(name)> *mappedValsBetter;

        return 0;
    }

}

namespace slef_test_1 {

    union unia //tak definiujemy uniê
    {
        float u_zm1;
        short int u_zm2;
    };

    int main() {
        union unia* k = nullptr;

        k = (unia*)malloc(sizeof(union unia));

        k->u_zm2 = 2;

        std::cout << k->u_zm2;

        return 0;
    }
}


int main()
{

    item_1::main();

    return 0;
}
