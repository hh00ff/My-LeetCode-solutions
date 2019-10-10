//
// Created by hfq on 10/10/19.
//

#include <iostream>
#include <mutex>
#include <condition_variable>

class Foo {
public:
    Foo() {

    }

    void first(std::function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        counter++;
        cv1.notify_one();
    }

    void second(std::function<void()> printSecond) {
        std::unique_lock<std::mutex> lk(mtx);
        cv1.wait(lk, [this](){return counter == 2;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        counter++;
        cv2.notify_one();
    }

    void third(std::function<void()> printThird) {
        std::unique_lock<std::mutex> lk(mtx);
        cv2.wait(lk, [this](){return counter == 3;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        counter++;
    }

private:
    std::mutex mtx;
    int counter = 1;
    std::condition_variable cv1;
    std::condition_variable cv2;
};