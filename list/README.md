# Linked List와 ArrayList의 장단점

|| LinkedList | ArrayList |
| --- | --- | --- |
| 장점 | 동적으로 자료를 다룰 수 있다. <br /> 리스트 내에서 자료의 이동이 필요하지 않다. <br /> 사용 후 기억 장소의 재사용이 가능하다. | Index를 이용해서 빠르게 접근할 수 있다. (시간복잡도 O(1)) <br /> LinkedList에 비해서 고려할 사항이 적다. <br /> 데이터 개수가 확실하게 정해져 있고, 접근이 빈번한 경우 배열이 효율적이다.
| 단점 | 탐색이 느리다. <br /> 구현이 어렵다. <br /> 포인터의 사용으로 인해 저장 공간의 낭비 우려가 있다. | 동적으로 자료를 다룰 수 없다. <br /> LinkedList에 비해서 자료의 추가 삭제가 느리다. <br /> 연속적인 형태 유지를 위해 shift 연산을 해야하므로 (O(N))이 된다.


#	
	10개 생성 삭제 test

	linked [time : 0.000215]

	array [time : 0.000136]

	100000개 생성 삭제 test

	linked [time : 24.915581]

	array [time : 0.087308]

	순차적으로 원소를 넣고 빼는 작업을 하는 것은 array가 빠르지만, 배열의 크기가 클 때 중간의 원소를 삭제하는 작업은 linked가 빠르다. 

# 
<br />

## ArrayList

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/arraylist/array.c">array.c</a>
<br />

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/arraylist/array_elem.c">array_elem.c</a>
<br />

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/arraylist/array_utils.c">array_utils.c</a>
<br />

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/arraylist/arraylist.h">arraylist.h</a>
<br />

## LinkedList

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/list.c">list.c</a>
<br />

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/list_node.c">list_node.c</a>
<br />

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/list_utils.c">list_utils.c</a>
<br />

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/list.c">linkedlist.h</a>
<br />

#

## CircularList

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2F80fBj%2Fbtrz3kJsm7r%2FJnjgrIMyeRrV6h01fNHc90%2Fimg.png" />

원형 연결 리스트는 일반적인 연결 리스트에 마지막 노드와 처음 노드를 연결시켜 원형으로 만든 구조이다.  


<br />

## 특징

-   head와 tail이 연결되어 있어서 탐색할 때 편하다.
-   head와 tail의 상태가 바뀔 때를 고려해야 한다.

## CircularList

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/circularlist/circularlist.c">Circular List.c</a>
<br />

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/circularlist/circularlist.h">Circular List.h</a>
<br />

#

## DoublyList

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fbv1k5W%2FbtrzYiUrMjt%2FXJN1rAQgCeFkeoDmuy9a0k%2Fimg.png" />

이중 연결 리스트의 구조는 단일 연결 리스트와 비슷하지만,  
포인터 공간이 두 개가 있고 각각의 포인터는 앞의 노드와 뒤의 노드를 가리킨다.

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FYwiWI%2FbtrzS2daX1c%2FuToz7rrRRElhP1vRb4C32K%2Fimg.png" />

탐색에서는 단일 연결 리스트보다 시간적 우위를 지닌다.  
기준에 따라 Head에서 출발하거나, Tail에서 출발하는 것이 가능하다.  
단, 각 노드의 관리에 유의해야 하기 때문에, 작업량이 많아지고 자료구조의 크기와 사용 메모리가 증가한다.

## 특징

-   탐색에 용이하다.
-   자료구조의 크기가 증가한다.
-   단일 연결 리스트보다 메모리 관리가 어렵다.

## DoublyList

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/doublylist/addDLElement.c">addDLElement.c</a>
<br />

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/doublylist/removeDLElement.c">removeDLElement.c</a>
<br />

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/doublylist/getDLElement.c">getDLElement.c</a>
<br />

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/doublylist/clearDoublyList.c">clearDoublyList.c</a>
<br />

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/doublylist/createDoublyList.c">createDoublyList.c</a>
<br />

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/doublylist/deleteDoublyList.c">deleteDoublyList.c</a>
<br />

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/doublylist/getDoublyListLength.c">getDoublyListLength.c</a>
<br />

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/doublylist/displayDoublyList.c">displayDoublyList.c</a>
<br />

<a href="https://github.com/MingueKim/DataStructure-Study/blob/main/list/doublylist/doublylist.h">doublylist.h</a>
<br />

#

응용한 다항식 문제 풀이.
## [Polynomial](https://github.com/MingueKim/DataStructure-Study/tree/main/list/polynomial)
<br />