const BOARD_SIZE = 8;
const HUMAN_PLAYER = 'human';
const AI_PLAYER = 'ai';

let board = null;
let turn = HUMAN_PLAYER;
let status = '';
let selectedPiece = null;

function initBoard() {
  board = Array.from({ length: BOARD_SIZE }, () => Array(BOARD_SIZE).fill(null));
  for (let row = 0; row < BOARD_SIZE; row++) {
    for (let col = 0; col < BOARD_SIZE; col++) {
      if (row % 2 === col % 2) {
        if (row < 3) {
          board[row][col] = { color: 'black', king: false };
        } else if (row > 4) {
          board[row][col] = { color: 'white', king: false };
        }
      }
    }
  }
}

function drawBoard() {
  const table = document.getElementById('board');
  table.innerHTML = '';
  for (let row = 0; row < BOARD_SIZE; row++) {
    const tr = document.createElement('tr');
    for (let col = 0; col < BOARD_SIZE; col++) {
      const td = document.createElement('td');
      if (board[row][col] !== null) {
        td.classList.add(board[row][col].color);
        td.textContent = board[row][col].king ? '♔' : '●';
        td.onclick = () => selectPiece(row, col);
      }
      if (row === selectedPiece?.row && col === selectedPiece?.col) {
        td.classList.add('selected');
      }
      tr.appendChild(td);
    }
    table.appendChild(tr);
  }
}

function selectPiece(row, col) {
  const piece = board[row][col];
  if (piece !== null && piece.color === turn) {
    selectedPiece = { row, col };
    drawBoard();
  } else if (selectedPiece !== null && isValidMove(selectedPiece.row, selectedPiece.col, row, col)) {
    movePiece(selectedPiece.row, selectedPiece.col, row, col);
    selectedPiece = null;
  }
}

function isValidMove(fromRow, fromCol, toRow, toCol) {
  const piece = board[fromRow][fromCol];
  const dx = toCol - fromCol;
  const dy = toRow - fromRow;
  if (Math.abs(dx) !== Math.abs(dy)) {
    return false;
  }
  if (!piece.king && ((piece.color === 'white' && dy > 0) || (piece.color === 'black' && dy < 0))) {
    return false;
  }
  if (Math.abs(dx) === 1 && Math.abs(dy) === 1) {
    if (board[toRow][toCol] !== null) {
      return false;
    }
    return true;
  } else if (Math.abs(dx) === 2 && Math.abs(dy) === 2) {
    const capturedPiece = board[fromRow + dy/2][fromCol + dx/2];
    if (capturedPiece === null || capturedPiece.color === piece.color) {
      return false;
    }
    return true;
  }
  return false;
}

function movePiece(fromRow, fromCol, toRow, toCol) {
    const piece = board[fromRow][fromCol];
    board[toRow][toCol] = piece;
    board[fromRow][fromCol] = null;
    if (Math.abs(toRow - fromRow) === 2 && Math.abs(toCol - fromCol) === 2) {
      const capturedRow = (toRow + fromRow) / 2;
      const capturedCol = (toCol + fromCol) / 2;
      board[capturedRow][capturedCol] = null;
    }
    if (toRow === 0 || toRow === BOARD_SIZE - 1) {
      piece.king = true;
    }
    if (!hasValidMoves(turn)) {
      endGame(getOpponent(turn) + ' wins!');
    } else {
      turn = getOpponent(turn);
    }
    selectedPiece = null;
    drawBoard();
  }

  function hasValidMoves(player) {
    for (let row = 0; row < BOARD_SIZE; row++) {
      for (let col = 0; col < BOARD_SIZE; col++) {
        const piece = board[row][col];
        if (piece !== null && piece.color === player) {
          for (let drow = -2; drow <= 2; drow++) {
            for (let dcol = -2; dcol <= 2; dcol++) {
              if (Math.abs(drow) === 2 && Math.abs(dcol) === 2) {
                const toRow = row + drow;
                const toCol = col + dcol;
                if (isValidMove(row, col, toRow, toCol)) {
                  return true;
                }
              }
            }
          }
        }
      }
    }
    return false;
  }

  function getOpponent(player) {
    return player === HUMAN_PLAYER ? AI_PLAYER : HUMAN_PLAYER;
  }
