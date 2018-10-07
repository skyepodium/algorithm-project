int main()
{
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++){
        queue<Position> Q;    //큐 선언
        Position now;
        Position next;
        int startX;        //시작 x좌표
        int startY;        //시작 y좌표
        int result = -1;    //결과 값
        int x[4] = { -1, 0, 1, 0 };
        int y[4] = { 0, -1, 0, 1 };
        
        scanf("%d", &N);
        for (int i = 1; i <= N; i++){
            scanf("%s", &matrix[i][1]);
        }
        
        //출발점 찾기
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                if (matrix[i][j] == 'S'){
                    startX = i;
                    startY = j;
                }
                
                //중복체크 매트릭스 초기화
                for (int k = 0; k < 4; k++){
                    for (int h = 0; h < 5; h++){
                        checkDuplication[i][j][k][h] = 0;
                    }
                }
            }
        }
        
        //출발점에 인접한 경로 탐색 후 큐에 넣기
        now.x = startX;
        now.y = startY;
        now.curveCondition = 0;
        now.moveNum = 0;
        //인접한 경로 탐색
        for (int i = 0; i < 4; i++){
            int xPos = now.x + x[i];
            int yPos = now.y + y[i];
            //범위 확인
            if (!checkRange(xPos, yPos)) continue;
            
            if (matrix[xPos][yPos] != '1'){
                now.direction = i;
                goFront(now, next);
                if (checkDuplication[next.x][next.y][next.direction][next.curveCondition] == 0){
                    Q.push(next);
                    checkDuplication[next.x][next.y][next.direction][next.curveCondition] = 1;
                }
            }
        }
        //
        while (!Q.empty()){
            now = Q.front();
            Q.pop();
            
            //목적지까지 도달한 경우 루프에서 벗어남
            if (matrix[now.x][now.y] == 'T'){
                result = now.moveNum - 1;
                break;
            }
            
            int tmp = (now.direction + 2) % 4;//유턴하는 방향 뽑기
            
            //인접한 경로 탐색
            for (int i = 0; i < 4; i++){
                if (tmp == i) continue;//유턴인 경우 넘어가기
                
                int xPos = now.x + x[i];
                int yPos = now.y + y[i];
                //범위 확인
                if (!checkRange(xPos, yPos)) continue;
                
                //인접한 경로 탐색
                if (matrix[xPos][yPos] != '1'){
                    //방향이 직진인 경우
                    if (i == now.direction){
                        goFront(now, next);
                        //중복 탄색한 경로인지 확인 후, 큐에 넣기
                        if (checkDuplication[next.x][next.y][next.direction][next.curveCondition] == 0){
                            Q.push(next);
                            checkDuplication[next.x][next.y][next.direction][next.curveCondition] = 1;
                        }
                    }
                    //방향이 좌회전인 경우
                    else if (i == (now.direction + 1) % 4){
                        if (goLeft(now, next)){
                            //중복 탐색한 경로인지 확인 후, 큐에 넣기
                            if (checkDuplication[next.x][next.y][next.direction][next.curveCondition] == 0){
                                Q.push(next);
                                checkDuplication[next.x][next.y][next.direction][next.curveCondition] = 1;
                            }
                        }
                    }
                    //방향이 우회전인 경우
                    else if (i == (now.direction + 3) % 4){
                        if (goRight(now, next)){
                            //중복 탐색한 경로인지 확인 후, 큐에 넣기
                            if (checkDuplication[next.x][next.y][next.direction][next.curveCondition] == 0){
                                Q.push(next);
                                checkDuplication[next.x][next.y][next.direction][next.curveCondition] = 1;
                            }
                        }
                    }
                }
            }
        }
        
        printf("#%d %d\n", t, result);
    }
    
    return 0;
}
