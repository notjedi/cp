use std::collections::HashMap;
use std::io::{self, Read};

fn part1(input: String) {
    // -1    => 0    => -2       => -1
    // paper => rock => scissors => paper

    let mut scores = HashMap::new();
    scores.insert('A', 1); // rock
    scores.insert('B', 2); // paper
    scores.insert('C', 3); // scissors
    scores.insert('X', 1); // rock
    scores.insert('Y', 2); // paper
    scores.insert('Z', 3); // scissors

    let score = input
        .lines()
        .map(|line| {
            let moves = line.split_whitespace().collect::<Vec<&str>>();
            let (op, me) = (
                moves[0].chars().next().unwrap(),
                moves[1].chars().next().unwrap(),
            );
            let (s1, s2) = (scores.get(&op).unwrap(), scores.get(&me).unwrap());
            let mut round_score = 0;

            if s1 == s2 {
                round_score = 3;
            } else if (me == 'X' && op == 'C')
                || (me == 'Y' && op == 'A')
                || (me == 'Z' && op == 'B')
            {
                round_score = 6;
            }
            *s2 + round_score
        })
        .sum::<i32>();
    println!("Part 1: {}", score);
}

fn part2(input: String) {
    let mut round_scores = HashMap::new();
    round_scores.insert('X', 0); // lose
    round_scores.insert('Y', 3); // draw
    round_scores.insert('Z', 6); // win

    let mut move_scores = HashMap::new();
    move_scores.insert('A', 1); // rock
    move_scores.insert('B', 2); // paper
    move_scores.insert('C', 3); // scissors

    let score = input
        .lines()
        .map(|line| {
            let moves = line.split_whitespace().collect::<Vec<&str>>();
            let (op, outcome) = (
                moves[0].chars().next().unwrap(),
                moves[1].chars().next().unwrap(),
            );
            let mut move_score = 0;

            if outcome == 'X' {
                // lose
                if op == 'A' {
                    move_score = 3;
                } else {
                    move_score = move_scores.get(&op).unwrap() - 1;
                }
            } else if outcome == 'Y' {
                // draw
                move_score = *move_scores.get(&op).unwrap();
            } else if outcome == 'Z' {
                // win
                if op == 'C' {
                    move_score = 1;
                } else {
                    move_score = move_scores.get(&op).unwrap() + 1;
                }
            }
            move_score + *round_scores.get(&outcome).unwrap()
        })
        .sum::<i32>();

    println!("Part 2: {}", score);
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    part1(input.clone());
    part2(input.clone());
}
