struct Person
{
    int age;
    char name[30];
};

void main()
{
    struct Person p1;

    // 멤버변수에 접근하기 위해서 연산자를 사용한다.

    p1.age = 10;
    printf("%d\n", p1.age);
}
/*
    장점 :  유지보수- 관련된 데이터를 하나에 묶어서 관리가 가능해지므로 유지보수가 쉽고 간결해진다.
    다양한 데이터 관리가 편하다.
    모듈화 ---> 재사용성이 높다.

*/
/*
    typedef
    : 기존에 존재하는 자료형에 새로운 이름을 부여하는 키워드
    -> 별명이 기존 데이터 타입과 똑같이 취급된다.
*/

void main()
{
    typedef char my_char;
    my_char ch = 1;
}

typedef struct Person Person;
Person p2;

typedef struct Person2
{
    int age;
} Person2;

/*
    익명구조체
    구조체를 정의할 때 구조체의 이름을 생략하고 선언하는 것
    1회용으로 변수에 즉시 할당하거나 특정 상황에서 임시로 사용하는 용도
*/

struct
{
    int x;
} temp;

void main()
{
    temp.x = 10;
}

// 구조체 변수와 포인터
typedef struct
{
    int age;
} Person3;

void main()
{
    Person3 person;
    person.age = 25;

    Person3 *ptr = &person;

    (*ptr).age = 30; // 연산자
    printf("%d\n", person.age);
    ptr->age = 10; // 연산자 화살표연산자
    printf("%d\n", person.age);
}

typedef struct
{
    Person3 p1;
    Person3 p2[30];
};