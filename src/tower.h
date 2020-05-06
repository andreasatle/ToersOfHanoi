/// @file tower.h
/// @brief The classical game: Tower of Hanoi
///
/// The classical game where n blocks are moved from a source stack to a target stack.
///

#pragma once

#include <iostream>
#include <stack>
#include <string>

/// @brief TowerOfHanoi
///
/// A class implementing the game Towers Of Hanoi.
class TowerOfHanoi {
public:
    
    /// Create alias Tower for a stack of ints.
    typedef std::stack<int> Tower;

    /// Constructor for TowerOfHanoi
    ///
    /// @param n number of blocks
    TowerOfHanoi(const size_t n);

    /// Play the game TowerOfHanoi
    void play();

    /// Print the state of the game TowerOfHanoi
    void print();

    /// Source stack getter
    const Tower & get_source_stack() const;

    /// Work stack getter
    const Tower & get_work_stack() const;

    /// Target stack getter
    const Tower & get_target_stack() const;

    /// Number of moves getter
    const int & get_num_moves() const;

    /// Mute output
    void mute();

    /// Unmute output
    void unmute();

private:

    /// Recursive game TowerOfHanoi with private arguments
    void play_rec(size_t   n,
                  Tower  & source, 
                  Tower  & work, 
                  Tower  & target);

    /// Move top of source to target
    void move_one(Tower & source,
                  Tower & target);

    /// print one tower in reverse order, used by print
    void traverse(std::string str,
                  Tower       ss);

    /// private variables
    Tower source_, work_, target_;
    int   counter_;
    int   mute_;
};
