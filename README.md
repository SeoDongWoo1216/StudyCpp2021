# StudyCpp2021
C++ 학습 리포지토리 <br><br>
교재 : C++ 기초 프로그래밍 트레이닝 <br><br>
-------------------

- [1. C언어의 확장](https://andjjip.tistory.com/246?category=949011)
  - [입출력과 레퍼런스](https://andjjip.tistory.com/247?category=949011)
  - [디폴트 인수, 오버로딩, 인라인 함수](https://andjjip.tistory.com/249?category=949011)
- [2. 클래스](https://andjjip.tistory.com/250?category=949011)
- [3. 생성자](https://andjjip.tistory.com/253?category=949011)
   -[여러가지 생성자](https://andjjip.tistory.com/255?category=949011)
- [4. 캡슐화](https://andjjip.tistory.com/259?category=949011)
- [5. 연산자 오버로딩](https://andjjip.tistory.com/260?category=949011)
- [6. 상속](https://andjjip.tistory.com/265?category=949011)
- [7. 다형성](https://andjjip.tistory.com/268?category=949011)
- [8. 템플릿1](https://andjjip.tistory.com/270?category=949011) [, 템플릿2](https://andjjip.tistory.com/294?category=949011)
- [9. 예외 처리](https://andjjip.tistory.com/293?category=949011)
- [10. 타입 정보](https://andjjip.tistory.com/295?category=949011)
- [12. 표준 라이브러리](https://andjjip.tistory.com/296?category=949011)
- [13. C++ 실습 : 고스톱 프로그램](https://github.com/SeoDongWoo1216/StudyCpp2021/tree/main/Chapter13_%EC%8B%A4%EC%8A%B5)

-------------------

## Cpp 실습 : 고스톱 프로그램

[소스보기](https://github.com/SeoDongWoo1216/StudyCpp2021/blob/main/Chapter13_%EC%8B%A4%EC%8A%B5/%EA%B3%A0%EC%8A%A4%ED%86%B1.cpp)

-------

### intro
- 여러 가지 객체들이 상호 작용하면서 프로그램이 만들어 지고, 이 프로그램들이 상호 작용하면 하나의 프로젝트가 될 수 있을 것이다. <br>
- 이 중 여러 객체들의 상호작용을 직접 구현하기위해 고스톱 프로그램을 작성해보았다. <br>
- 고스톱의 화투판의 각 실체들을 모델링해서 클래스로 표현하는 추상화 작업을 해보았다. <br>
- 이 작업을 하려면 실제로 담요위에 화투를 펼쳐 놓고 게임을 하면서 각 사물이 어떤 특성을 가지며, 어떤 행동을 하는지 분석해야할 것이다. <br>
- 사람이 패를 섞어서 돌리고, 플레이어가 카드를 내고 일치하는 카드를 먹으면서 게임을 진행하는 것을 코드로 구현할 것이다. <br>

------

### 구현
0. 2인용으로 구현
1. 같은 카드 세장이 들어왔을때 흔들어 점수를 두배로 만드는 규칙은 사용자의 선택이 필요하고 한번에 하나의 카드를 내는 규칙에 예외가 생겨 제외
2. 두장의 피로 계산되는 쌍피, 피와 십짜리 양쪽으로 쓸 수 있는 카드, 보너스 카드는 제외
3. 피박, 광박 등 점수를 곱절로 만드는 규칙도 제외
4. 플레이어는 남군, 북군, 몇개의 카드는 펼쳐져있고 뒤집어진 카드는 ???로 표시
5. 오른쪽에 각 플레이어가 먹은 카드와 점수, 고 횟수가 표시된다
6. 콘솔환경에서는 마우스를 쓸 수 없어서 숫자키로 패를 선택
    
-----

### 클래스 구성
* CCardSet : 카드 동작 클래스 (카드 목록 삽입, 제거, 같은 숫자 찾기 등)   
  - CDeck (CCardSet 상속) : 카드덱 클래스 (셔플, 드로우 메소드)    

  - CPlayer (CCardSet 상속) : 게임 플레이어 클래스 (가진 손패 표시, 턴 관리)   
    + CBlanket (CPlayer 상속) : 게임판 클래스 (낸 카드와 깔려진 카드 일치 조사)    
    + CPlayerHand (CPlayer 상속) : 손패 클래스 (획득한 패 관리, 점수 계산) 

-----

### 결과 화면
<p align = "center" >
    <img src = https://github.com/SeoDongWoo1216/StudyCpp2021/blob/main/Chapter13_%EC%8B%A4%EC%8A%B5/image/%EA%B3%A0%EC%8A%A4%ED%86%B11.PNG>
    <img src = https://github.com/SeoDongWoo1216/StudyCpp2021/blob/main/Chapter13_%EC%8B%A4%EC%8A%B5/image/%EA%B3%A0%EC%8A%A4%ED%86%B12.PNG>
    <img src = https://github.com/SeoDongWoo1216/StudyCpp2021/blob/main/Chapter13_%EC%8B%A4%EC%8A%B5/image/%EA%B3%A0%EC%8A%A4%ED%86%B13.PNG>
    <img src = https://github.com/SeoDongWoo1216/StudyCpp2021/blob/main/Chapter13_%EC%8B%A4%EC%8A%B5/image/%EA%B3%A0%EC%8A%A4%ED%86%B14.PNG>
    <img src = https://github.com/SeoDongWoo1216/StudyCpp2021/blob/main/Chapter13_%EC%8B%A4%EC%8A%B5/image/%EA%B3%A0%EC%8A%A4%ED%86%B15.PNG>
    <img src = https://github.com/SeoDongWoo1216/StudyCpp2021/blob/main/Chapter13_%EC%8B%A4%EC%8A%B5/image/%EA%B3%A0%EC%8A%A4%ED%86%B16.PNG>
</p>

------
