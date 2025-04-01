# Chess :

-> Here, I implemented chess in C language with the features listed below:

✔ Move validation (invalid move detection)
✔ Check and checkmate detection
✔ Stalemate detection
✔ Castling
✔ Pawn promotion
✔ Restricting illegal moves when the king is under attack
✔ Legal move generation when the king is under attack

# How to play :

-> It is terminal-based, so you need to enter the row and column details to move a piece.

-> Enter the column letter followed by the row number to give input. For example: a5, b6, g4, etc.

-> First, enter the location of the piece you want to move (the square where the piece is currently placed).

-> Then, enter the location where you want to move it.

-> If it is a legal move, the chessboard will update. If not, it will show an invalid move message, and you must enter both locations again.

-> If it is a legal move, after providing input, the program will ask: "Do you want to change anything?"

-> If you want to undo the move, type yes, Yes, YES, or 1.

-> Otherwise, type any letter, number, or character (except for inputs starting with 'Y', 'y', or '1').

-> To castle your king, use the king's coordinates, not the rook's.

-> Enter the king's position first, then provide the position of the king after castling. If castling is valid at that moment, it will be executed automatically.
