//
// Created by wujinxing on 2019/11/11.
//
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review {
    std::string title;
    int rating;
};

bool operator<(const Review &r1, const Review &r2);

bool worseThan(const Review &r1, const Review &r2);

bool FillReview(Review &rr);

void ShowReview(const Review &rr);

int main() {
    using namespace std;

    vector<Review> books;
    Review temp;
    while (FillReview(temp))
        books.push_back(temp);

    if (books.size() > 0) {
        cout << "Thank you. You entered the following "
             << books.size() << " rating:\n"
             << "Rating\tBook\n";

        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end());

        cout << "Sorted by title:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        random_shuffle(books.begin(), books.end());
        cout << "After shuffling:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
    } else {
        cout << "Bye.\n";
        return 0;
    }
}

bool operator<(const Review &r1, const Review &r2) {
    if (r1.title < r2.title)
        return true;
    else return r1.title == r2.title && r1.rating < r2.rating;
}

bool worseThan(const Review &r1, const Review &r2) {
    return r1.rating < r2.rating;
}

bool FillReview(Review &rr) {
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
        return false;
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const Review &rr) {
    std::cout << rr.rating << "\t" << rr.title << std::endl;
}