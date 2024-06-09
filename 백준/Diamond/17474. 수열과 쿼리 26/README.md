# [Diamond II] 수열과 쿼리 26 - 17474 

[문제 링크](https://www.acmicpc.net/problem/17474) 

### 성능 요약

메모리: 150460 KB, 시간: 2680 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리

### 제출 일자

2024년 6월 9일 22:11:03

### 문제 설명

<p>길이가 N인 수열 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오. </p>

<ul>
	<li><code>1 L R X</code>: 모든 L ≤ i ≤ R에 대해서 A<sub>i</sub> = min(A<sub>i</sub>, X) 를 적용한다. </li>
	<li><code>2 L R</code>: max(A<sub>L</sub>, A<sub>L+1</sub>, ..., A<sub>R</sub>)을 출력한다.</li>
	<li><code>3 L R</code>: A<sub>L</sub> + A<sub>L+1</sub> + ... + A<sub>R</sub>을 출력한다.</li>
</ul>

### 입력 

 <p>첫째 줄에 수열의 크기 N이 주어진다. (1 ≤ N ≤ 1,000,000)</p>

<p>둘째 줄에는 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 주어진다. (0 ≤ A<sub>i</sub> < 2<sup>31</sup>)</p>

<p>셋째 줄에는 쿼리의 개수 M이 주어진다. (1 ≤ M ≤ 1,000,000)</p>

<p>넷째 줄부터 M개의 줄에는 쿼리가 한 줄에 하나씩 주어진다. (1 ≤ L ≤ R ≤ N, 0 ≤ X < 2<sup>31</sup>) 2번과 3번 쿼리는 한 번 이상 주어진다.</p>

### 출력 

 <p>2, 3번 쿼리의 결과를 한 줄에 하나씩 출력한다.</p>

