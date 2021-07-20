## Cpp 실습 : 고스톱 프로그램

[소스보기](https://github.com/SeoDongWoo1216/StudyCpp2021/blob/main/Chapter13_%EC%8B%A4%EC%8A%B5/%EA%B3%A0%EC%8A%A4%ED%86%B1.cpp)

-------

### intro
여러 가지 객체들이 상호 작용하면서 프로그램이 만들어 지고, 이 프로그램들이 상호 작용하면 하나의 프로젝트가 될 수 있을 것이다. <br>
이 중 여러 객체들의 상호작용을 직접 구현하기위해 고스톱 프로그램을 작성해보았다. <br>

-----

### How to
고스톱의 화투판의 각 실체들을 모델링해서 클래스로 표현하는 추상화 작업을 해야한다. <br>
이 작업을 하려면 실제로 담요위에 화투를 펼쳐 놓고 게임을 하면서 각 사물이 어떤 특성을 가지며, 어떤 행동을 하는지 분석해야할 것이다. <br>
사람이 패를 섞어서 돌리고, 플레이어가 카드를 내고 일치하는 카드를 먹으면서 게임을 진행하는 것을 코드로 구현할 것이다. <br>

------

### 구현
0. 2인용으로 구현
1. 같은 카드 세장이 들어왔을때 흔들어 점수를 두배로 만드는 규칙은 사용자의 선택이 필요하고 한번에 하나의 카드를 내는 규칙에 예외가 생겨 제외
2. 두장의 피로 계산되는 쌍피, 피와 십짜리 양쪽으로 쓸 수 있는 카드, 보너스 카드는 제외
3. 피박, 광박 등 점수를 곱절로 만드는 규칙도 제외
4. 플레이어는 남군, 북군, 몇개의 카드는 펼쳐져있고 뒤집어진 카드는 ???로 표시
5. 오른쪽에 각 플레이어가 먹은 카드와 점수, 고 횟수가 표시된다.
6. 콘솔환경에서는 마우스를 쓸 수 없어서 숫자키로 패를 선택.
    
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
