void InsertionSort_DLL(Node** List){
    Node* head = *List; // 더블 링크드 리스트의 헤드값

    Node* current = head; // 리스트의 첫번째 값
    Node* next = current->NextNode; // 다음 값

    Node* sort = head; // 리스트를 탐색하며 정렬할 노드

    Elementype a, b; // 두 노드의 데이터 값

    while(next){
        a = current->Data;
        b = next->Data;

        if(a <= b){ // 두번째 노드의 데이터 값이 더 크다면 다음 노드로 한 칸 전진
            current = next;
            next = next->NextNode;
            continue;
        }
        // 첫번째 노드의 데이터 값이 더 크다면 첫번째 노드의 다음 노드 주소를 변경
        current->NextNode = next->NextNode;
        
        if(next->NextNode != NULL){ // 다음 노드가 할당되어 있다면 다음 노드의 이전 노드 주소가 현재 노드를 가르킨다
            next->NextNode->PrevNode = current;
        }

        while(sort != current->NextNode){ // 노드를 탐색하며 정렬
            a = sort->Data;

            if(a > b){
                next->NextNode = sort;
                next->PrevNode = sort->PrevNode;

                if(sort->PrevNode != NULL){
                    sort->PrevNode->NextNode = next;
                }

                sort->PrevNode = next;

                if(sort == head ){
                    head = next;
                }

                sort = head;
                break;
            }
            sort = sort->NextNode;
        }
        next = current->NextNode;
    }

    *List = head;
}
