# stdexcept

- 2016 11 04

<https://docs.microsoft.com/ko-kr/cpp/standard-library/stdexcept?view=vs-2019>

예외 보고에 사용되는 여러 표준 클래스를 정의합니다. 클래스는 exception 클래스에서 모두 파생된 파생 계층 구조를 형성하고 두 가지 일반 형식의 예외(논리 오류 및 런타임 오류)를 포함합니다. 논리 오류는 프로그래머 실수로 인해 발생합니다. 기본 클래스 logic_error에서 파생되며 다음을 포함합니다.

- domain_error
- invalid_argument
- length_error
- out_of_range

런타임 오류는 라이브러리 함수 또는 런타임 시스템의 실수로 인해 발생합니다. 기본 클래스 runtime_error에서 파생되며 다음을 포함합니다.

- overflow_error
- range_error
- underflow_error

클래스
클래스 Description
domain_error 클래스 : 이 클래스는 도메인 오류를 보고하기 위해 발생하는 모든 예외에 대한 기본 클래스로 사용됩니다.
invalid_argument : 클래스 이 클래스는 잘못된 인수를 보고하기 위해 발생하는 모든 예외에 대한 기본 클래스로 사용됩니다.
length_error 클래스 : 이 클래스는 너무 길어서 지정할 수 없는 개체 생성 시도를 보고하기 위해 발생하는 모든 예외에 대한 기본 클래스로 사용됩니다.
logic_error 클래스 : 이 클래스는 논리적 사전 조건 위반과 같이 프로그램이 실행되기 전에 검색될 수 있는 오류를 보고하기 위해 발생하는 모든 예외에 대한 기본 클래스로 사용됩니다.
out_of_range 클래스 : 이 클래스는 유효 범위를 벗어난 인수를 보고하기 위해 발생하는 모든 예외에 대한 기본 클래스로 사용됩니다.
overflow_error 클래스 : 이 클래스는 산술 오버플로를 보고하기 위해 발생하는 모든 예외에 대한 기본 클래스로 사용됩니다.
range_error 클래스 : 이 클래스는 범위 오류를 보고하기 위해 발생하는 모든 예외에 대한 기본 클래스로 사용됩니다.
runtime_error 클래스 : 이 클래스는 프로그램이 실행되는 경우에만 검색될 수 있는 오류를 보고하기 위해 발생하는 모든 예외에 대한 기본 클래스로 사용됩니다.
underflow_error 클래스 : 이 클래스는 산술 언더플로를 보고하기 위해 발생하는 모든 예외에 대한 기본 클래스로 사용됩니다.
