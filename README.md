# Computer-Graphics
2021 Spring, 고려대학교 학점교류 김창헌교수님 컴퓨터그래픽스 수업, 과제

___
## Introduction of Implementation
- "이재형"을 3D shape으로 구현한 object끼리의 Collision, Gravity, Texture, Light, Skybox 을 구현

## File Description
- \*.mp4 : 구현 영상
- name.cpp : 구현 코드

## Libraries
- OpenGL
- C++

## Implementation Details

1. 변환행렬이 많이 들어가는 작업이었던 만큼 처음에는 glLoadIdentity()를 이용해 각 변환간 간섭을 없앴음. 하지만 그러면 한번에 객체들을 뭉탱이로 Rotation하기 많이 지저분해서, glPushMatrix()와Pop을 사용하여 해결함.

2. 원래 Skeleton Code에서 mouse로 조정되었던 ViewPoint를 모든 글자를 Translate시켜서 해결함.

3. 키보드를 통한 movement 구현에 대하여, 예제에서는 glLoadIdentity()를 이용해 각 transform matrix에 대해 간섭을 제거. 하지만 모든 글자를 한번에 움직이기 위해서는 중간중간 항등행렬로 초기화하는것이 구현에 복잡성을 증가시키는 문제발생. 따라서 Push Pop matrix로 대체하여 한번의 tarnsform matrix가 모든 글자에 영향 미칠 수 있게 고안함.

4. x y z를 누르면 각 축에 대해 회전, 이는 해당 입력이 호출될때마다 Rotate()의 각도를 증가시키는 방향으로 진행. 여기서 2번제외 각도는 초기화해주지 않았음. float는 매우 큰 수까지 커버돼 overflow걱정이 없고 굳이 if로 복잡도를 증가시키지 말자는 취지였음.

- 1 번에 대해서는 각 글자마다 Rotation , 전체에 대해 x축 Rotation을 부여해 완전 임의의 회전 느낌을 주었음  
- 2 번에 대해서는 각 글자들이 다른 깊이에서 시작해 앞뒤로 Translation이 되고 각 자리에서 Rotation을 부여하였음	그리고 각도를 일정하지 않고 점진적으로 빠르게 증가시켜 부드러운 움직임을 얻어보았음 또한 max location에 도달하면 다시 reverse하는 모션도 넣어 보기 편한 동작을 만들 수 있었음.  
- 3 번에 대해서는	글자들이 앞뒤로 통통 튀는 느낌을 주고싶었음.	총 17개의 글씨들을 각 다른 위치로 Translation 하고 크기를 다르게 Scale하여 밋밋하지 않은 느낌을 만들려 하였음.  
- 123 그리고 xyz 각 변환은 독립적이기 때문에 여러 변환을 한번에 하여 재미있는 애니메이션을 얻을 수 도 있었음.  
+ 기존 카메라 위치는 처음에는 gluLookAt()을 사용하려 하였으나, 기존 코드와 엉켜서 display()의 처음 부분에 Translatef(0,0,-100) 을 추가해 모든 피사체와 camera의 적정 거리를 만들 수 있게 작성하였다.  
+ 각 글자별로 변환을 주길 원해 우선 음절별로 display하는 함수를 만들고, 이 함수들을 모아 한 글자를 표현하는 함수를 또 만들었다. 이런 분할을 통해 각 글자 혹은 음절별로 Transformation을 용이하게 할 수 있도록 기능을 구현하였다.  
+ 사소하지만 SolidCube 위에 비슷한 색의 WireCube를 겹쳐 눈에 들어오도록 신경을 써 볼 수 있었다.  
