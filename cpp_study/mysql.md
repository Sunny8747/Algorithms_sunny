use database_name
show tables // 테이블자체
show table status //정보
desc city // 테이블의 속성정보

select from
select name, population from city; // select 열이름 -> 열만 가져오기
select _ from city // _ : all

select from where // where : 조건
ex : select \* from city where population >= 80000;

관계연산자
OR AND NOT != 등등 일반 코딩과비슷

between a and b
between 7000 and 7800 // 연속된 숫자 사이

like // 문자열검색
like 'k%' // %뒤에 아무거나
like 'ko*' // *갯수만큼 아무거나

// 결과가 둘이상되면 에러발생

- SUB QUERY
  select \*
  from city
  where countrycode = ( select countrycode
  form city
  where name = 'seoul' );

- IN // 일치되는거 찾기 OR문
  select \*
  from city
  where countrycode IN ( 'A'
  'B'
  'C' );

- ALL // 다만족 And문

- ANY (some 도 같음 = any는 in과 같음)
  // 어떤것들 중보다 큰 인
  select \*
  from city
  where population > any ( select population
  form city
  where name = 'seoul' );

- order by
  //결과출력순서
  select \*
  from city
  order by population desc; // default = asc, descending = desc

- distinct
  // 중복된것 한개씩만
  select distinct countrycode
  from city;

- limit
  // 출력개수 제한
  // 상위 N개만 출력하는 limit N
  // work bench 자체기능 있음

- group by
  // 그룹화
  // avg(), min(), max, count(), count(distinct)// 중복제외된 행갯수
  , stdev(), variance()
  select Countrycode, max(population) AS 'col'
  from city
  group by CountryCode

- having
  // where 비슷함
  // 반드시 group by 뒤에
  select Countrycode
  from city
  group by CountryCode
  having max(population) > 800000

- rollup
  // 중간합계
  select Countrycode, name, sum(Population)
  from city
  group by CountryCode, name with rollup

- join
  // 여러개 테이블 조인
  select \*
  from city
  join country on city.CountryCode = country.Code
  join countrylanguage on city.CountryCode = countrylanguage.CountryCode

- 내장함수
  length() // 문자열길이
  concat() // concatonation
  locate() // 문자열내 위치반환 없으면 0 시작을 1부터
  left()
  right() // 왼쪽부터 몇개 오른쪽부터 몇개
  lower(), upper() // 소문자 대문자
  replace() // 대체
  trim() // 문자열 지우기 default : both, option : both leading trailing
  ex : trim(leading '#' from '###asdf##')// 앞에있는거 지우기
  format() // format변경
  floor()
  ceil()
  round() // 내림 올림 반올림
  sqrt()
  pow(밑수, 지수)
  exp()
  log()
  sin()
  cos()
  tan()
  pi()
  abs() // 절대값
  rand() //

- 시간
  44:14 부터

- 테이블
  47:00
  인덱스 55:20
  뷰 59:00
