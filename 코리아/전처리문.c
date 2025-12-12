/*
    전처리문 -> include같은거
    컴파일 과정이 일어나기 전에 전처리기(전처리과정)에서 실행되는 코드
    컴파일 이후 또는 프로그램 실행 도중의 값에는 영향을 끼치지 않는다.
    ---> 컴파일 전에 소스코드를 정리하는 구문

    #include : 파일포함 전처리문
    -> #include <파일명> : 컴파일러에 미리 지정된 폴더 안에 파일이 있는경우
    -> #include "파일명" : 그 밖의 경로에 위치한 파일을 불러올때

    #define : 식별자 저의 전처리문
    #define 이름 데이터

*/

#include <stdio.h>
#include "header.h"
// #include "/Users/kangjua/Desktop/Cstructureknu/코리아/전처리문.c" // 절대경로

#define NAME "홍길동"
#define OUTPUT printf("나의 이름은 %s입니다.\n", NAME)
#define FUNC(x, y) (x * y)

int main()
{
    OUTPUT;
    printf("%d\n", FUNC(10, 15));
    printf("%d\n", FUNC(1 + 1, 3 + 3)); // 7
    //(x*y) ---> 1+1*3+3 괄호붙이기 왜냐하면 그대로 치환되기 때문에
    // printf("%d\n", FUNC("123", "24"));
    // 실행할 때 인수의 데이터를 확인하지 않기 때문에 조심할 필요가 있다.
    return 0;
}

/*
    식별자 해제 전처리문 : #undef
*/

#undef NAME // 이미 존재하는 이름의 식별자 해제 후
// #include // 같은 이름의 식별자가 존재하는 파일 include

/*
    조건 처리 전처리문
    특정 조건을 판별해서 특정 구문을 포함하거나 포한하지 않도록 하는 전처리문
    #if, #ifdef, #ifndef, #else, #elif, #endif

    기본적으로 if문과 사용방법은 동일하다
    #if 조건 1 : 조건1이 참일때 시행
    #elif 조건2 : 조건1이 거짓, 조건2가 참일때 실행
    #else : 위의 모든 조건이 거짓
*/

#define NUM 10
void main()
{
    int num10 = 10;
#if NUM < 10
    printf("NUM은 10보다 작다.\n");
#elif NUM > 10
    printf("NUM은 10보다 크다.\n");
#else
    printf("NUM은 10이다.\n");
#endif
    // #if문에는 프로그램내의 변수를 사용할 수 없다.
    // 전처리문이 실행되는 시간에는 변수가 생성되지 않았기 때문에!
    // 전처리문은 컴파일 전에 실행되고 변수는 컴파일 이후 프로그램이 시작되고 메모리상에 값을 저장하기 때문
}

/*
    메크로 정의되어있을때

    메크로 정의 되어있지 않을때
*/
#define NUM 10
void main()
{
#ifdef NUM
    printf("NUM은 %d입니다.\n", NUM);
#else
    printf("NUM은 저의되지 않았습니다.");
#endif
}
/*
    헤더파일이 여러개 존재할때 헤더 파일을 중복으로 포함시키지 않도록 방지할때 많이 사용된다.
*/
#include "header.h"
