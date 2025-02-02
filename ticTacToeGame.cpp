#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<vector<char>> board(3 , vector<char>(3,'_'));

    char ch;
    cout<<"Which one to start with O or X?: ";
    cin>>ch;

    if(ch == 'o'){
        ch = 'O';
    }
    if(ch == 'x'){
        ch = 'X';
    } 

    cout<<endl;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<board[i][j]<<" ";
        } cout<<endl;
    }

    cout<<endl;
    
    int moves = 1;
    
    while(moves <= 9){

        int x, y;
        cout<<"Enter "<<ch<<"'s co-ordinate(0-based): ";
        cin>>x>>y;
        
        if(x > 2 || y > 2){
            cout<<"Co-ordinate is out of board.\n";
            continue;  
        }
        if(board[x][y] != '_'){
            cout<<board[x][y]<<" is already at ("<<x<<","<<y<<").\n";
            continue;
        }

        if(ch == 'O'){
            board[x][y] = ch;
            ch = 'X';
        } else{
            board[x][y] = ch;
            ch = 'O';
        }

        cout<<endl;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout<<board[i][j]<<" ";
            } cout<<endl;
        }

        cout<<endl;

        for(int i = 0; i < 3; i++){
            if(board[i][0] != '_' && board[i][0] == board[i][1] && board[i][0] == board[i][2]){
                cout<<board[i][0]<<" is the winner\n\n";
                moves = 10;
                break;
            }
            if(board[0][i] != '_' && board[0][i] == board[1][i] && board[0][i] == board[2][i]){
                cout<<board[0][i]<<" is the winner\n\n";
                moves = 10;
                break;
            }
        }

        if(board[1][1] != '_'){
            if(board[1][1] == board[0][0] && board[1][1] == board[2][2]){
                cout<<board[1][1]<<" is the winner\n\n";
                moves = 10;
            }
            if(board[1][1] == board[0][2] && board[1][1] == board[2][0]){
                cout<<board[1][1]<<" is the winner\n\n";
                moves = 10;
            }
        }

        moves++;
    }

    if(moves == 10){
        cout<<"Match has drawn!\n\n";
    } 

    bool again;
    cout<<"Want to play again(0/1)?: ";
    cin>>again;

    if(again){
        main();
    }

    return 0;
}