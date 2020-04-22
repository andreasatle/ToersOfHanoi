#include<iostream>
#include<stack>

using std::cout;
using std::endl;
using std::stack;
using std::ostream;

class TowerOfHanoi {
public:
    /// Constructor for TowerOfHanoi
    TowerOfHanoi(size_t n) : counter_{0} {
        for (int i = n; i >= 1; i--) {
            source_.push(i);
        }
    }

    /// Play the game TowerOfHanoi
    void play() {
        print();
        play_rec(source_.size(), source_, work_, target_);
    }

    /// Print the state of the game TowerOfHanoi
    void print() {
        cout << "Move: " << counter_++ << endl;
        cout << "source: ";
        traverse(source_);
        cout << "work  : ";
        traverse(work_);
        cout << "target: ";
        traverse(target_);
        cout << endl;
    }

private:

    /// Recursive gmae TowerOfHanoi with private arguments
    void play_rec(size_t       n,
                  stack<int> & source, 
                  stack<int> & work, 
                  stack<int> & target) {
        if (n > 1) {
            play_rec(n-1, source, target, work  );
            play_rec(1,   source, work,   target);
            play_rec(n-1, work,   source, target);
        } else if (n == 1) {
            move_one(source, target);
            print();
        }
    }

    /// Move top of source to target
    void move_one(stack<int> & source,
                  stack<int> & target) {
        target.push(source.top());
        source.pop();
    }

    /// print one tower in reverse order, used by print
    void traverse(stack<int> ss) {
        stack<int> s;

        // Reverse order of stack
        while (!ss.empty()) {
            s.push(ss.top());
            ss.pop();
        }

        // Output stack to screen (in reverse order)
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    /// private variables
    stack<int> source_, work_, target_;
    int        counter_;
};

/// Initialize and play the TowerOfHanoi
int main(void) {
    TowerOfHanoi tower(4);
    tower.play();
}
