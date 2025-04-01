#include<stdio.h>
#include<string.h>
struct chess{
    int en[3];
};
struct chess s1,s2;
// taking the array size as 10 10 bcz of reducing the boundary checking issues..
void initiation(char arr[10][10]);
void board(char arr[10][10]);
int input(char arr[10][10],int);
int rules(char arr[10][10],int,int,int,int,int);
int pawn(char arr[10][10],int,int,int,int,int);
int elephant(char arr[10][10],int,int,int,int);
int camel(char arr[10][10],int,int,int,int);
int horse(char arr[10][10],int,int,int,int);
int king(char arr[10][10],int,int,int,int);
int check(char arr[10][10],int,int,int);
void changing(char arr[10][10],int,int,int,int);
int check_mate(char arr[10][10],int,int,int,int);
int castling(char arr[10][10],int,int,int,int);
int repeat();

int main(){
    int i,j,k,a;
	char arr[10][10];
    s1.en[0]=s1.en[1]=s1.en[2]=0;
    s2.en[0]=s2.en[1]=s2.en[2]=0;
    printf("\n----------------------- C H E S S -------------------------");
	printf("\n\nRULES :-\n-----------------\nPLAYER_1:CAPITAL\nPLAYER_2:SMALL\n-----------------\nKING:- K,k\nQUEEN:- Q,q\nELEPHANT:- E,e\nCAMEL:- C,c\nHORSE:- H,h\nPAWN:- A,a \n\n");
    printf("FIRST ENTER COLUMN (small letters at bottom)\nTHEN ENTER ROW NUMBER (numbers at left side)\n(row,col)\n\n");
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			arr[i][j]=' ';
		}
	}
    initiation(arr);
    board(arr);
    for(a=1;a<=2;a++){
        if(a==1){
            printf("PLAYER_1 TURN:\n");
        }
        if(a==2){
            printf("PLAYER_2 TURN:\n");
        }
        i=input(arr,a);
        board(arr);
        if(i==20 || i==19){
            if(a==1 && i==20)    printf("\nPLAYER_1 WIN!!!\n");
            if(a==2 && i==20)    printf("\nPLAYER_2 WIN!!!\n");
            break;
        }
        if(a==2){
            a=a-2;
        }
    }
    return 0;
}

int repeat(){
    char c1[100];
    // printf("\n");
    printf("\nDO YOU WANT TO CHANGE anything:(yes-1 or y or Y):");
    scanf(" %[^\n]s",c1);
    if(c1[0]=='1' || c1[0]=='Y' || c1[0]=='y'){
        return 1;
    }
    return 0;
}

void initiation(char arr[10][10]){
    int i,j;
    for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(i==7){
				if(j==0 || j==7)		arr[i][j]='E';
				else if(j==1 || j==6)	arr[i][j]='H';
				else if(j==2 || j==5)	arr[i][j]='C';
				else if(j==3)			arr[i][j]='Q';
				else			        arr[i][j]='K';
			}
			else if(i==0){
				if(j==0 || j==7)		arr[i][j]='e';
				else if(j==1 || j==6)	arr[i][j]='h';
				else if(j==2 || j==5)	arr[i][j]='c';
				else if(j==3)			arr[i][j]='q';
				else			        arr[i][j]='k';
			}
            else if(i==1){
                arr[i][j]='a';
            }
            else if(i==6){
                arr[i][j]='A';
            }
		}
	}
}
// no
void board(char arr[10][10]){
    int i,j;
    printf("   ");
    for(i=0;i<49;i++){
        printf("-");
    }
    printf("\n");
    for(i=0;i<8;i++){
        printf("%d  ",8-i);
        for(j=0;j<8;j++){
            printf("|  %c  ",arr[i][j]);
        }
        printf("|\n   ");
        for(j=0;j<49;j++){
            printf("-");
        }
        printf("\n");
    }
    printf("    "); 
    for(i=0;i<8;i++){
        printf("  %c   ",i+97);
    }
    printf("\n\n");
}

int input(char arr[10][10],int a){
    int i,j,row,col,ROW,COL,m;
    char c1[100],r,R;// r,R for taking inputs as characters
    for(i=1;i==1;i++){
        printf("\nEnter Which Piece You Want To Move: ");
        scanf(" %c %d",&r,&row); 
        row=8-row;    col=(int)r-97;
        if(row>7 || col>7 || row<0 || col<0){
            printf("\nEnter Valid Rows and Columns Only:");
            i=i-1;
            continue;
        }
        else if(arr[row][col]==' '){
            printf("\nThere Is Nothing To Move Here...enter valid position");
            i=i-1;
            continue; 
        }
        if(a%2==0){     //PLAYER 2 SMALL....
            if(arr[row][col]>=65 && arr[row][col]<=90){
                printf("\nMove Your Piece... your piece is small letter:");
                i=i-1;
                continue;
            }
            else{
                printf("you selected: %c\n",arr[row][col]);
                for(j=1;j==1;j++){
                    printf("\nwhere you want to move that piece:");
                    scanf(" %c %d",&R,&ROW);
                    ROW=8-ROW;    COL=(int)R-97;

                    if(ROW>7 || COL>7 || ROW<0 || COL<0){
                        printf("\nEnter Valid Rows and Columns Only:");
                        j=j-1;
                        continue;
                    }
                    else if((arr[ROW][COL]>=97 && arr[ROW][COL]<=122) ){
                        printf("\nDont Kill Your Self!...enter valid position:");
                        j=j-1;
                        continue;
                    }
                    i=rules(arr,a,row,col,ROW,COL);
                    // if i==1 then it will come out from the loop 
                    // if i==0 then it will incriment to i++ after ending of the loop so it will again iterate
                    // here i am returning i==0 from the rules function if the user given to change his given input 
                    if(i==20 || i==19)   break;
                }
            }
        }
        else if(a%2!=0){        // PLAYER 1 CAPITAL....
            if(arr[row][col]>=97 && arr[row][col]<=122){
                printf("\nMove Your Piece... your piece is capital letter:");
                i=i-1;
                continue;
            }
            else{
                printf("you selected: %c\n",arr[row][col]);
                for(j=1;j==1;j++){
                    printf("\nwhere you want to move that piece:");
                    scanf(" %c %d",&R,&ROW);
                    ROW=8-ROW;    COL=(int)R-97;

                    if(ROW>7 || COL>7 || ROW<0 || COL<0){
                        printf("\nEnter Valid Rows and Columns Only:");
                        j=j-1;
                        continue;
                    }
                    else if((arr[ROW][COL]>=65 && arr[ROW][COL]<=90) ){
                        printf("\nDont Kill Your Self!...enter valid position:");
                        j=j-1;
                        continue;
                    }
                    i=rules(arr,a,row,col,ROW,COL);
                    // if i==1 then it will come out from the loop 
                    // if i==0 then it will incriment to i++ after ending of the loop so it will again iterate
                    // here i am returning i==0 from the rules function if the user given to change his given input 
                    if(i==20 || i==19)   break;
                }
            }
        }
    }
    return i-1;
}

int rules(char arr[10][10],int a,int row,int col,int ROW,int COL){
    int i,j,d,e,k,l,d2,e2;
    char m,n=' ';
//  here i am using return values from the functions to checking the move is valid or not
//  example     k=pawn(arr,row,col,ROW,COL,0);  here k is storing the value which is return value from the function pawn
    for(i=0;i<=7;i++){
        for(j=0;j<=7;j++){
            if(arr[i][j]=='K')  d=i,e=j;
            if(arr[i][j]=='k')  d2=i,e2=j;
        }
    }
    if(arr[row][col]=='A' || arr[row][col]=='a'){
        k=pawn(arr,row,col,ROW,COL,0);  // going to pawn function
        if(k==1 || k==2){
            if(k==1) printf("\npawn doesnt move like that:\n");   // k==1 means invalid move... k==2 means (trying to promote) but changed after promotion
            return 0;
        }
    }

    else if(arr[row][col]=='E' || arr[row][col]=='e'){
        k=elephant(arr,row,col,ROW,COL);
        if(k==1){
            printf("\nelephant doesnt move like that:\n");
            return 0;
        }
        if(arr[7][0]!='E')  s1.en[0]=1;    if(arr[7][7]!='E')  s1.en[2]=1;
        if(arr[0][0]!='e')  s2.en[0]=1;    if(arr[0][7]!='e')  s2.en[2]=1;
    }

    else if(arr[row][col]=='C' || arr[row][col]=='c'){
        k=camel(arr,row,col,ROW,COL);
        if(k==1){
            printf("\ncamel doesnt move like that:\n");
            return 0;
        }
    }

    else if(arr[row][col]=='Q' || arr[row][col]=='q'){
        k=elephant(arr,row,col,ROW,COL);
        if(k==1){
            k=camel(arr,row,col,ROW,COL);
            if(k==1){
                printf("\nqueen doesnt move like that:\n");
                return 0;
            }
        }
    }

    else if(arr[row][col]=='H' || arr[row][col]=='h'){
        k=horse(arr,row,col,ROW,COL);
        if(k==1){
            printf("\nhorse doesnt move like that:\n");
            return 0;
        }
    }

    if(arr[row][col]=='K' || arr[row][col]=='k'){
        if(arr[row][col]=='K')    d=ROW,e=COL;
        else    d2=ROW,e2=COL;

        k=king(arr,row,col,ROW,COL);
        if(k==1){
            k=castling(arr,row,col,ROW,COL);
            if(k==0){
                k=check(arr,d,e,0);     // verifying is it a check for our king if we move that piece
                l=check(arr,d2,e2,0);   // verifying is it a check for opposite king if we move that piece
                if(k==1)    printf("Check To player_1 king! ....\n\n");
                if(l==1)    printf("Check To player_2 king! ....\n\n");
                return 1;
            }
            if(k==2)    return 0;   
            printf("\nking doesnt move like that");
            return 0;
        }
        if(arr[7][4]!='K')  s1.en[1]=1;  
        if(arr[0][4]!='k')  s2.en[1]=1;  
    }
        k=repeat();
        if(k==1)    return 0;
        m=arr[ROW][COL];
        changing(arr,row,col,ROW,COL);  // first changing the pieces according to the given input
        k=check(arr,d,e,0);     // verifying is it a check for our king if we move that piece
        l=check(arr,d2,e2,0);   // verifying is it a check for opposite king if we move that piece

    //  k and l are the return values coming from the respective functions
    //  a==1 means player 1 turn a==2 means player 2 turn
    //  k==1 means check to player 1    l==1 means check to player 2

        if((k==1 && a%2!=0) || (l==1 && a%2==0)){   // here it is check for the player who is playing
            printf("to your king!..\n");
            changing(arr,ROW,COL,row,col);  // changing again to the normal step
            arr[ROW][COL]=m;    //  after the above step the place where we moved will become blank.. so i am putting the piece which is already present before moving
            if(row==1 && a%2!=0){
                arr[row][col]='A';  // if pawn is promoted before, the value in that box is not pawn..(may be queen horse etc...)
            }                       // so again putting the pawn in that box...
            else if(row==6 && a%2==0){
                arr[row][col]='a';
            }
            return 0;
        }

        if(k==1){   // player 2 moved so player 1 got check...
            printf("To player_1 king! ....\n\n");
            k=check_mate(arr,d,e,a,1);      // checking for check mate for opposite player...
            if(k==20){ 
                printf("\nITS CHECKMATE!!!\n");     
                return k;
            }
        }

        if(l==1){   // player 1 moved so player 2 got check...
            printf("To player_2 king! ....\n\n");
            k=check_mate(arr,d2,e2,a,1);    // checking for check mate for opposite player...
            if(k==20){
                printf("\nITS CHECKMATE!!!\n"); // k==20 means the return value coming from the function
                return k;
            }
        }

    k=check_mate(arr,d,e,a,0);  // checking for stalemate...
    if(k==19){
        printf("\nITS STALEMEATE!!\n");  return k;
    }
    return 1;
}

int pawn(char arr[10][10],int row,int col,int ROW,int COL,int j){
    if((arr[ROW][COL]>=65 && arr[ROW][COL]<=90 && arr[row][col]=='A') || (arr[ROW][COL]>=97 && arr[ROW][COL]<=122 && arr[row][col]=='a'))    return 1;
    int i;
    char m;
    // return 1 means invalid move .. return 0 means valid move..
    if(arr[row][col]=='A'){
        // capital pawn A:
        if(row==ROW || !((row==ROW+1 && (col==COL+1 || col==COL-1 || col==COL)) || (row==ROW+2 && col==COL)))    return 1;
    
        else if(row==6){
            if(row==ROW+2 && (arr[ROW][COL]!=' ' || arr[ROW+1][COL]!=' ' || col!=COL))
                return 1;

            else if(ROW==row-1){
                if(!(COL==col && arr[ROW][COL]==' '   ||   ((arr[ROW][COL]>=97) && (arr[ROW][COL]<=122) && (COL==col-1 || COL==col+1))))
                    return 1;
            }
        }
        else if(row!=6) {
            if(ROW==row-1){
                if(!((arr[ROW][COL]>=97 && arr[ROW][COL]<=122 && (COL==col-1 || COL==col+1))  ||  (col==COL && arr[ROW][COL]==' ')))
                    return 1;
            }
            else  return 1;
            if(ROW==0 && j==0){
                for(i=1;i<=1;i++){      
                    printf("your pawn is promoted....enter which piece you want:");
                    scanf(" %c",&m);
                    if(m!='Q' && m!='H' && m!='C' && m!='E'){
                        printf("\nenter correct piece...\n");
                        i=i-1; 
                    }
                }
                j=repeat(); // taking input from the user to change the input if he want
                if(j==1){
                    arr[row][col]='A';
                    return 2;   // here i am changing the promoted piece.. so i am returning 2 to avoid confusion
                }
                arr[row][col]=m;
            }
        }
        else{
            printf("\nenter correct row.. pawn steps only one time\n");
            return 1;
        }
    }
    else if(arr[row][col]=='a'){
        // small pawn a:
        if(row==ROW || !((row==ROW-1 && (col==COL+1 || col==COL-1 || col==COL)) || (row==ROW-2 && col==COL)))    return 1;

        else if(row==1){
            if(ROW==row+2 && (arr[ROW-1][COL]!=' ' || arr[ROW][COL]!=' ' || col!=COL))    
                return 1; 

            if(ROW==row+1){
                if(!(col==COL && arr[ROW][COL]==' '   ||   ((arr[ROW][COL]>=65) && (arr[ROW][COL]<=90) && (COL==col-1 || COL==col+1)) )  )
                    return 1; 
            }
        }
        else if(row!=1){
            if(ROW==row+1){
                if(!((arr[ROW][COL]>=65 && arr[ROW][COL]<=90 && (COL==col-1 || COL==col+1))  ||  (col==COL && arr[ROW][COL]==' ')))
                    return 1;
            }
            else  return 1;
            if(ROW==7 && j==0){
                for(i=1;i<=1;i++){
                    printf("\nyour pawn is promoted....enter which piece you want:");
                    scanf(" %c",&m); 
                    if(!(m=='q' || m=='h' || m=='c' || m=='e')){
                        printf("\nenter correct piece...\n");
                        i=i-1;
                    }
                }
                if(j==1){
                    arr[row][col]='a';
                    return 2;
                }
                arr[row][col]=m;    
            }
        }
    }
    return 0;
}

int elephant(char arr[10][10],int row,int col,int ROW,int COL){
    if(((arr[ROW][COL]>=65 && arr[ROW][COL]<=90)) && (arr[row][col]=='E' || arr[row][col]=='Q'))
        return 1;
    else if(arr[ROW][COL]>=97 && arr[ROW][COL]<=122 && (arr[row][col]=='e' || arr[row][col]=='q'))
        return 1;   

    int count=0,i,j,c,x,y,z;
    if(row!=ROW && col==COL ){ 
        for(i=ROW+1;i<=row-1;i++){
            if((arr[i][col]>=65 && arr[i][col]<=90) || (arr[i][col]>=97 && arr[i][col]<=122)){
                return 1;   
            }
        }
        for(i=ROW-1;i>=row+1;i--){
            if((arr[i][col]>=65 && arr[i][col]<=90) || (arr[i][col]>=97 && arr[i][col]<=122)){
                return 1;
            }
        }
    }
    else if(row==ROW && col!=COL){  
        for(i=COL+1;i<=col-1;i++){
            if((arr[row][i]>=65 && arr[row][i]<=90) || (arr[row][i]>=97 && arr[row][i]<=122)){
                return 1;  
            }
        }
        for(i=COL-1;i>=col+1;i--){
            if((arr[row][i]>=65 && arr[row][i]<=90) || (arr[row][i]>=97 && arr[row][i]<=122)){
                return 1;   
            }
        }
    }
    else if(row!=ROW && col!=COL ){
        return 1;
    }
    return 0;
}

int camel(char arr[10][10],int row,int col,int ROW,int COL){
    if(arr[ROW][COL]>=65 && arr[ROW][COL]<=90 && (arr[row][col]=='C' || arr[row][col]=='Q'))
        return 1;
    else if(arr[ROW][COL]>=97 && arr[ROW][COL]<=122 && (arr[row][col]=='c' || arr[row][col]=='q'))
        return 1;

    int i,j;
    if(arr[row][col]=='C' || arr[row][col]=='c' || arr[row][col]=='Q' || arr[row][col]=='q' ){
        if(row>ROW && col>COL){
            for(i=row,j=col;i>=ROW && j>=COL;i--,j--);  
            i=i+1;j=j+1;
            if(i==ROW && j==COL){
                for(i=row-1,j=col-1;i>ROW && j>COL;i--,j--){    
                    if((arr[i][j]>=65 && arr[i][j]<=90) || (arr[i][j]>=97 && arr[i][j]<=122))    return 1;
                }
            }
            else    return 1; 
        }
        else if(row>ROW && col<COL){
            for(i=row,j=col;i>=ROW , j<=COL;i--,j++); 
            i=i+1;j=j-1;
            if(i==ROW && j==COL){
                for(i=row-1,j=col+1;i>ROW && j<COL;i--,j++){
                    if((arr[i][j]>=65 && arr[i][j]<=90) || (arr[i][j]>=97 && arr[i][j]<=122))    return 1;
                }
            }
            else    return 1; 
        }
        else if(row<ROW && col>COL){
            for(i=row,j=col;i<=ROW && j>=COL;i++,j--);
            i=i-1;j=j+1;
            if(i==ROW && j==COL){
                for(i=row+1,j=col-1;i<ROW && j>COL;i++,j--){
                    if((arr[i][j]>=65 && arr[i][j]<=90) || (arr[i][j]>=97 && arr[i][j]<=122))    return 1;
                }
            }
            else    return 1;
        }
        else if(row<ROW && col<COL){
            for(i=row,j=col;i<=ROW && j<=COL;i++,j++);
            i=i-1;j=j-1;
            if(i==ROW && j==COL){
                for(i=row+1,j=col+1;i<ROW && j<COL;i++,j++){
                    if((arr[i][j]>=65 && arr[i][j]<=90) || (arr[i][j]>=97 && arr[i][j]<=122))    return 1;
                }
            }
            else    return 1;
        }
        else    return 1;
    }
    return 0;
}

int horse(char arr[10][10],int row,int col,int ROW,int COL){
    if((arr[ROW][COL]>=65 && arr[ROW][COL]<=90 && arr[row][col]=='H') || (arr[ROW][COL]>=97 && arr[ROW][COL]<=122 && arr[row][col]=='h'))    return 1;
    
    int i,j;
    if(arr[row][col]=='h' || arr[row][col]=='H'){
        if(!(((ROW==row+1 || ROW==row-1) && (COL==col+2 || COL==col-2)) || ((COL==col+1 || COL==col-1) && (ROW==row+2 || ROW==row-2)))){
            return 1;
        }
    }
    return 0;
}

int king(char arr[10][10],int row,int col,int ROW,int COL){
    if((arr[ROW][COL]>=65 && arr[ROW][COL]<=90 && arr[row][col]=='K') || (arr[ROW][COL]>=97 && arr[ROW][COL]<=122 && arr[row][col]=='k'))
        return 1;
    if(!((row==ROW+1 || row==ROW-1 || row==ROW) && (col==COL+1 || col==COL-1 || col==COL)))
        return 1;
    return 0;
}

int check(char arr[10][10],int ROW,int COL,int k){
    int c=0,i,j;
    // camel and queen check;
    for(i=ROW+1,j=COL+1;i<=7 && j<=7;i++ , j++){
        if((arr[i][j]>=65 && arr[i][j]<=90) || (arr[i][j]>=97 && arr[i][j]<=122)){
            if((arr[i][j]=='c' && arr[ROW][COL]=='K') || (arr[i][j]=='C' && arr[ROW][COL]=='k')){
                if(k==0)    printf("\ncheck by camel "); return 1;
            }
            else if((arr[i][j]=='q' && arr[ROW][COL]=='K') || (arr[i][j]=='Q' && arr[ROW][COL]=='k')){
                if(k==0)    printf("\ncheck by queen "); return 1;
            }
            break;
        }
    }
    for(i=ROW-1,j=COL-1;i>=0 && j>=0;i-- , j--){ 
        if((arr[i][j]>=65 && arr[i][j]<=90) || (arr[i][j]>=97 && arr[i][j]<=122)){
            if((arr[i][j]=='c' && arr[ROW][COL]=='K') || (arr[i][j]=='C' && arr[ROW][COL]=='k')){
                if(k==0)    printf("\ncheck by camel "); return 1;
            }        
            else if((arr[i][j]=='q' && arr[ROW][COL]=='K') || (arr[i][j]=='Q' && arr[ROW][COL]=='k')){
                if(k==0)    printf("\ncheck by queen "); return 1;
            }
            break;
        }
    }
    for(i=ROW-1,j=COL+1;i>=0 && j<=7;i-- , j++){
        if((arr[i][j]>=65 && arr[i][j]<=90) || (arr[i][j]>=97 && arr[i][j]<=122)){
            if((arr[i][j]=='c' && arr[ROW][COL]=='K') || (arr[i][j]=='C' && arr[ROW][COL]=='k')){
                if(k==0)    printf("\ncheck by camel "); return 1;
            }
            else if((arr[i][j]=='q' && arr[ROW][COL]=='K') || (arr[i][j]=='Q' && arr[ROW][COL]=='k')){
                if(k==0)    printf("\ncheck by queen "); return 1;
            }
            break;
        }
    }
    for(i=ROW+1,j=COL-1;i<=7 && j>=0;i++ , j--){  
        if((arr[i][j]>=65 && arr[i][j]<=90) || (arr[i][j]>=97 && arr[i][j]<=122)){
            if((arr[i][j]=='c' && arr[ROW][COL]=='K') || (arr[i][j]=='C' && arr[ROW][COL]=='k')){
                if(k==0)    printf("\ncheck by camel "); return 1; 
            }        
            else if((arr[i][j]=='q' && arr[ROW][COL]=='K') || (arr[i][j]=='Q' && arr[ROW][COL]=='k')){
                if(k==0)    printf("\ncheck by queen "); return 1;
            } 
            break;
        }
    }
    // elephant and queen check:
    for(i=COL+1;i<=7;i++){
        if((arr[ROW][i]>=65 && arr[ROW][i]<=90) || (arr[ROW][i]>=97 && arr[ROW][i]<=122)){
            if((arr[ROW][i]=='e' && arr[ROW][COL]=='K') || (arr[ROW][i]=='E' && arr[ROW][COL]=='k')){
                if(k==0)    printf("\ncheck by elephant "); return 1;
            }
            else if((arr[ROW][i]=='q' && arr[ROW][COL]=='K') || (arr[ROW][i]=='Q' && arr[ROW][COL]=='k')){
                if(k==0)    printf("\ncheck by queen "); return 1;
            }
            break;
        }
    }
    for(i=COL-1;i>=0;i--){
        if((arr[ROW][i]>=65 && arr[ROW][i]<=90) || (arr[ROW][i]>=97 && arr[ROW][i]<=122)){
            if((arr[ROW][i]=='e' && arr[ROW][COL]=='K') || (arr[ROW][i]=='E' && arr[ROW][COL]=='k')){
                if(k==0)    printf("\ncheck by elephant "); return 1;
            }
            else if((arr[ROW][i]=='q' && arr[ROW][COL]=='K') || (arr[ROW][i]=='Q' && arr[ROW][COL]=='k')){
                if(k==0)    printf("\ncheck by queen "); return 1;
            }
            break;
        }
    }
    for(i=ROW+1;i<=7;i++){
        if((arr[i][COL]>=65 && arr[i][COL]<=90) || (arr[i][COL]>=97 && arr[i][COL]<=122)){
            if((arr[i][COL]=='e' && arr[ROW][COL]=='K') || (arr[i][COL]=='E' && arr[ROW][COL]=='k')){
                if(k==0)    printf("\ncheck by elephant "); return 1;
            }
            else if((arr[i][COL]=='q' && arr[ROW][COL]=='K') || (arr[i][COL]=='Q' && arr[ROW][COL]=='k')){
                if(k==0)    printf("\ncheck by queen "); return 1;
            }
            break;
        }
    }
    for(i=ROW-1;i>=0;i--){
        if((arr[i][COL]>=65 && arr[i][COL]<=90) || (arr[i][COL]>=97 && arr[i][COL]<=122)){
            if((arr[i][COL]=='e' && arr[ROW][COL]=='K') || (arr[i][COL]=='E' && arr[ROW][COL]=='k')){
                if(k==0)    printf("\ncheck by elephant "); return 1;
            }
            else if((arr[i][COL]=='q' && arr[ROW][COL]=='K') || (arr[i][COL]=='Q' && arr[ROW][COL]=='k')){
                if(k==0)    printf("\ncheck by queen "); return 1;
            } 
            break;
        }
    }
    //pawn check:
    if(((arr[ROW+1][COL+1]=='A' &&((ROW+1)<=7 && (COL+1)<=7)) || (arr[ROW+1][COL-1]=='A')&&((ROW+1)<=7 && (COL-1)>=0)) && arr[ROW][COL]=='k'){
        if(k==0)    printf("\ncheck by pawn ");
        return 1;
    }
    if(((arr[ROW-1][COL+1]=='a' &&((ROW-1)>=0 && (COL+1)<=7)) || (arr[ROW-1][COL-1]=='a')&&((ROW+1)>=0 && (COL-1)>=0)) && arr[ROW][COL]=='K'){
        if(k==0)    printf("\ncheck by pawn ");
        return 1;
    }
    //horse check:
    else if((arr[ROW+1][COL+2]=='h' || arr[ROW+1][COL-2]=='h' || arr[ROW-1][COL+2]=='h' || arr[ROW-1][COL-2]=='h') && arr[ROW][COL]=='K'){
        if(k==0)    printf("\ncheck by horse "); 
        return 1;
    }
    else if((arr[ROW+2][COL+1]=='h' || arr[ROW+2][COL-1]=='h' || arr[ROW-2][COL+1]=='h' || arr[ROW-2][COL-1]=='h') && arr[ROW][COL]=='K'){
        if(k==0)    printf("\ncheck by horse ");
        return 1;
    }
    else if((arr[ROW+1][COL+2]=='H' || arr[ROW+1][COL-2]=='H' || arr[ROW-1][COL+2]=='H' || arr[ROW-1][COL-2]=='H') && arr[ROW][COL]=='k'){
        if(k==0)    printf("\ncheck by horse ");   
        return 1;
    }
    else if((arr[ROW+2][COL+1]=='H' || arr[ROW+2][COL-1]=='H' || arr[ROW-2][COL+1]=='H' || arr[ROW-2][COL-1]=='H') && arr[ROW][COL]=='k'){
        if(k==0)    printf("\ncheck by horse ");     
        return 1;
    }
    //king check
    for(i=ROW-1;i<=ROW+1;i++){
        for(j=COL-1;j<=COL+1;j++){
            if(arr[ROW][COL]=='K' && arr[i][j]=='k'){
                if(k==0)    printf("\ninvalid move king check ;( ;(  ");    return 1;
            }
            else if(arr[ROW][COL]=='k' && arr[i][j]=='K'){
                if(k==0)    printf("\ninvalid move king check ;( ;(  ");    return 1;
            }
        }
    }
    return 0;
}

void changing(char arr[10][10],int row,int col,int ROW,int COL){   // changing
    arr[ROW][COL]=arr[row][col];
    arr[row][col]=' ';
}

int castling(char arr[10][10],int row,int col,int ROW,int COL){
    // checking castling...
    int i,j,k;
    char m;
    if(!((COL==6 || COL==2) && ( (ROW==0 && arr[row][col]=='k') || (ROW==7 && arr[row][col]=='K') )))    return 1;
    
    if(arr[row][col]=='K'){
        if((COL==6 && !(s1.en[2]==0 && s1.en[1]==0)) || (COL==2 && !(s1.en[0]==0 && s1.en[1]==0) ))
            return 1;
    }
    else{
        if((COL==6 && !(s2.en[2]==0 && s2.en[1]==0)) || (COL==2 && !(s2.en[0]==0 && s2.en[1]==0) ))
            return 1;
    }
    k=repeat();
    if(k==1)    return 2;   // returning 2 bcz user giving to change the input he gave... so to avoid confusion, instead of returning 1 i am returning 2..
    //e2e4e7e5g1f3b8c6d2d4e5d4f3g5h7h6g5f7e8f7f1c4f7e8e1g1
    if(COL==6){
        for(i=col;i<6;i++){
            m=arr[ROW][i];
            changing(arr,row,col,ROW,COL);
            k=check(arr,ROW,i,0);
            changing(arr,ROW,COL,row,col);
            arr[ROW][COL]=m;
            if(arr[row][i+1]!=' ' || k==1)    return 1;
        }
        arr[row][6]=arr[row][col];
        arr[row][5]=arr[row][7];
        arr[row][col]=arr[row][7]=' ';
    }
    else{
        for(i=col;i>1;i--){
            m=arr[ROW][i];
            changing(arr,row,col,ROW,COL);
            k=check(arr,ROW,i,0);
            changing(arr,ROW,COL,row,col);
            arr[ROW][COL]=m;
            if(arr[row][i+1]!=' ' || k==1)    return 1;
        }
        arr[row][2]=arr[row][col];
        arr[row][3]=arr[row][0];
        arr[row][col]=arr[row][0]=' ';
    }
    return 0;
}

int check_mate(char arr[10][10],int row,int col,int a,int d){
    int i,j,k,i1,j1,l=0,count=0,c=0;
    char b;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if((arr[i][j]>=65 && arr[i][j]<=90) || (arr[i][j]>=97 && arr[i][j]<=122)){
                for(i1=0;i1<8;i1++){
                    for(j1=0;j1<8;j1++){
                        
                        if((arr[i][j]=='a' && a==1) || (arr[i][j]=='A' && a!=1))
                            k=pawn(arr,i,j,i1,j1,1);
                        
                        else if((arr[i][j]=='h' && a==1) || (arr[i][j]=='H' && a!=1))
                            k=horse(arr,i,j,i1,j1);
                        
                        else if((arr[i][j]=='c' && a==1) || (arr[i][j]=='C' && a!=1))
                            k=camel(arr,i,j,i1,j1);
                        
                        else if((arr[i][j]=='e' && a==1) || (arr[i][j]=='E' && a!=1))
                            k=elephant(arr,i,j,i1,j1);
                        
                        else if((arr[i][j]=='q' && a==1) || (arr[i][j]=='Q' && a!=1)){
                            k=camel(arr,i,j,i1,j1); if(k==1)    k=elephant(arr,i,j,i1,j1);
                        }
                        else if((arr[i][j]=='k' && a==1) || (arr[i][j]=='K' && a!=1))
                            k=king(arr,i,j,i1,j1);

                        if(k==1)    continue;
                        b=arr[i1][j1];
                        changing(arr,i,j,i1,j1);
                        (arr[i1][j1]=='k' || arr[i1][j1]=='K') ? k=check(arr,i1,j1,1) : k=check(arr,row,col,1);
                        changing(arr,i1,j1,i,j);
                        arr[i1][j1]=b;
                        if(k==0 && count<5){
                            if(d==1) printf("possible move: %c%d to %c%d\n",j+97,8-i,j1+97,8-i1);
                            if(count==4 && d==1)    printf("And Many...\n");   count++;   c=1;
                        }
                    }
                }
            }
        }
    }
    if(!c){
        k=check(arr,row,col,1);
        k==1 ? k=20 : k=19;     return k;
    }
    return 0;
}
