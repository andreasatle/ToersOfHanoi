#include "tower.h"

// Constructor for the game Tower of Hanoi
TowerOfHanoi::TowerOfHanoi(const size_t n) : counter_{0}, mute_(false) {
    for (int i = n; i >= 1; i--) {
        source_.push(i);
    }
}

// Play the game Tower of Hanoi
void TowerOfHanoi::play() {
    if (!mute_) print();
    play_rec(source_.size(), source_, work_, target_);
}

// Print the state of the game Tower of Hanoi
void TowerOfHanoi::print() {
    std::cout << "Move: " << counter_ << std::endl;
    traverse("source:", source_);
    traverse("work  :", work_);
    traverse("target:", target_);
    std::cout << std::endl;
}

// Mute output
void TowerOfHanoi::mute() {
    mute_ = true;
}

// Unmute output
void TowerOfHanoi::unmute() {
    mute_ = false;
}

// Getter for source stack
const TowerOfHanoi::Tower & TowerOfHanoi::get_source_stack() const {
    return source_;
}

// Getter for work stack
const TowerOfHanoi::Tower & TowerOfHanoi::get_work_stack() const {
    return work_;
}

// Getter for target stack
const TowerOfHanoi::Tower & TowerOfHanoi::get_target_stack() const {
    return target_;
}

// Getter for number of moves so far
const int & TowerOfHanoi::get_num_moves() const {
    return counter_;
}

// Recursive game TowerOfHanoi with private arguments
void TowerOfHanoi::play_rec(size_t                n,
                            TowerOfHanoi::Tower & source, 
                            TowerOfHanoi::Tower & work, 
                            TowerOfHanoi::Tower & target) {
    if (n > 1) {
        play_rec(n-1, source, target, work  ); // Move all but the base from source to work
        play_rec(1,   source, work,   target); // Move base from source to target
        play_rec(n-1, work,   source, target); // Move all from work to target
    } else if (n == 1) {
        move_one(source, target); // Move the single brick from source to target
        if (!mute_) print();
    }
}

// Move top of source to target
void TowerOfHanoi::move_one(TowerOfHanoi::Tower & source,
                            TowerOfHanoi::Tower & target) {
    target.push(source.top());
    source.pop();
    counter_++;
}

// print one tower in reverse order, used by print
void TowerOfHanoi::traverse(std::string         str,
                            TowerOfHanoi::Tower ss) { // Observe ss is a copy

    // Create a local copy
    TowerOfHanoi::Tower s;

    // Reverse order of stack for beauty
    while (!ss.empty()) {
        s.push(ss.top());
        ss.pop();
    }

    // Print name of tower
    std::cout << str;

    // Output stack to screen (in reverse order)
    while (!s.empty()) {
        std::cout << " " << s.top();
        s.pop();
    }
    std::cout << std::endl;
}
