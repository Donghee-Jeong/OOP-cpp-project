# OOP-cpp-project

## 프로그램 설명

은행계좌 관리 프로그램

### 기능

1. 계좌개설
2. 입금
3. 출금
4. 전체고객 잔액조회

### 가정

- 통장의 계좌번호는 중복되지 아니한다.
- 입금 및 출금액은 무조건 0보다 크다.
- 고객의 계좌정보는 계좌번호, 고객이름, 고객의 잔액, 이렇게 세가지만 저장 및 관리한다.
- 둘 이상의 고객 정보 저장을 위해서 배열을 사용한다.
- 계좌번호는 정수의 형태이다.

---

### 프로젝트 06단계의 도입

- NormalAccount 보통예금계좌 :
  최소한의 이자를 지급하는 자율 입출금식 계좌
- HighCreditAccount 신용신뢰계좌 : 신용도가 높은 고객에게만 개설을 허용하는 높은 이율의 계좌

### 설명

#### NormalAccount 클래스

- 객체의 생성과정에서 이율정보를 등록할 수 있다.

#### HighCreditAccount 클래스

- HighCreditAccount 클래스에서도 객체 생성과정에서 기본이율을 등록할 수 있다.
- 고객의 신용등급을 A, B, C로 나누고 계좌개설 시 이 정보를 등록한다.
- A, B, C 등급별로 각각 기본이율에 7%, 4%, 2%의 이율을 추가로 제공한다.

### 클래스 구성

#### class Account { ... };

#### class NormalAccount : public Account { ... };

#### class HighCreditAccount : public NormalAccount { ... };
