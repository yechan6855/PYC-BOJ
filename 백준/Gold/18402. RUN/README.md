# [Gold V] RUN - 18402 

[문제 링크](https://www.acmicpc.net/problem/18402) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2024년 9월 5일 08:34:24

### 문제 설명

<p>An evil gang has decided to free prisoners from their prison. The prison is designed as a spiral and has a number of solitary cells. Prisoners are given a certain time to find their way out of prison. They shall be released if they can find their way out within the given time. Otherwise, the prison doors will be closed again. The prison has N cells that are connected together in a spiral form. Each cell has paths with a number of other cells. The prison has E exit doors. While escaping, each cell can contain as many people as possible.</p>

<p>With the assumption that prisoners know every path, write a program that predicts the number of prisoners that can and can't escape from the prison.</p>

### 입력 

 <p>The first three input lines contain</p>

<ul>
	<li>N, the number of cells in the prison. Cells are numbered 1, 2, ..., N. (N <= 100)</li>
	<li>E, the number of the exit cell. (0 < E < 100)</li>
	<li>T, starting value for the count-down timer (in some arbitrary time unit). (0 < T < 1000)</li>
</ul>

<p>The fourth line contains M the number of connections in the prison. Each next M lines, specify a connection (one-way connection) between cells with three integer numbers: two cell numbers A and B (in the range 1, ..., N) and the number of time units it takes to travel from A to B.</p>

<p>Notice that each connection is one-way, i.e., the prisoner can't travel from B to A unless there is another line specifying that passage. Also, the time required to travel in each direction might be different.</p>

### 출력 

 <p>Output a single line with the number of prisoners that reached the exit cell.</p>

