import sys
input = sys.stdin.read
output = sys.stdout.write

def hanoi(n, from_pole, to_pole, aux_pole, moves):
    if n == 1:
        moves.append((from_pole, to_pole))
        return
    hanoi(n - 1, from_pole, aux_pole, to_pole, moves)
    moves.append((from_pole, to_pole))
    hanoi(n - 1, aux_pole, to_pole, from_pole, moves)

def main():
    n = int(input().strip())
    total_moves = (1 << n) - 1
    output(f"{total_moves}\n")
    
    if n <= 20:
        moves = []
        hanoi(n, 1, 3, 2, moves)
        for move in moves:
            output(f"{move[0]} {move[1]}\n")

if __name__ == "__main__":
    main()