//
// Created by Liron on 20/05/2021.
//

#include "sources/BinaryTree.hpp"
#include "doctest.h"
#include <sstream>

using namespace std;
using namespace ariel;

TEST_CASE("normal tree with int"){
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(10)
            .add_left(10, 0).add_right(10, 20)
            .add_left(0, 8).add_right(0, 18)
            .add_left(20, 16).add_right(20, 15);
/*
 *                 10
 *            0         20
 *          18  8      16  15
 *
 *          preorder - 10 0 8 18 20 16 15
 *          inorder - 8 0 18 10 16 20 15
 *          postorder - 8 18 0 16 15 20 10
 */
    auto it = tree_of_ints.begin_preorder();
            CHECK(*it == 10);
    stringstream output;
    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
        output << (*it) << " " ;
    }
            CHECK(output.str() == "10 0 8 18 20 16 15 ");

    stringstream output1;
    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
        output1 << (*it) << " " ;
    }
            CHECK(output1.str() == "8 0 18 10 16 20 15 ");

    stringstream output2;
    for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
        output2 << (*it) << " " ;
    }
            CHECK(output2.str() == "8 18 0 16 15 20 10 ");
//after adding another lives
    tree_of_ints.add_left(20,51).add_right(20,32).add_right(0,70);
    /*
 *                 10
 *            0         20
 *          18  70      51  32
 *
 *          preorder - 10 0 8 70 20 51 32
 *          inorder - 8 0 70 10 51 20 32
 *          postorder - 8 70 0 51 32 20 10
 */
    stringstream outputAfter;
    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
        outputAfter << (*it) << " " ;
    }
            CHECK(outputAfter.str() == "10 0 8 70 20 51 32 ");

    stringstream outputAfter1;
    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
        outputAfter1 << (*it) << " " ;
    }
            CHECK(outputAfter1.str() == "8 0 70 10 51 20 32 ");

    stringstream outputAfter2;
    for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
        outputAfter2 << (*it) << " " ;
    }
            CHECK(outputAfter2.str() == "8 70 0 51 32 20 10 ");


            CHECK_THROWS_AS(tree_of_ints.add_left(21, 2), std::invalid_argument);
            CHECK_THROWS_AS(tree_of_ints.add_left(23, 2), std::invalid_argument);
            CHECK_THROWS_AS(tree_of_ints.add_left(90, 2), std::invalid_argument);
}
TEST_CASE("tree with double"){
    BinaryTree<double> tree_of_double;
    tree_of_double.add_root(5.7)
            .add_left(5.7, 3.45).add_right(5.7, 8.97)
            .add_left(3.45, 1.1).add_right(3.45, 6.7)
            .add_left(8.97,2.234).add_right(8.97, 13.1101)
            .add_right(6.7,21.01);
/*
 *                        5.7
 *            3.45                   8.97
 *         1.1    6.7            2.234  13.1101
 *                    21.01
 *          preorder -  5.7 3.45 1.1 6.7 21.01 8.97 2.234 13.1101
 *          inorder - 1.1 3.45 6.7 21.01 5.7 2.234 8.97 13.1101
 *          postorder - 1.1 21.01 6.7 3.45 2.234 13.1101 8.97 5.7
 */

auto it = tree_of_double.begin_preorder();
CHECK(*it == 5.7);

    stringstream output;
    for (auto it=tree_of_double.begin_preorder(); it!=tree_of_double.end_preorder(); ++it) {
        output << (*it) << " " ;
    }
            CHECK(output.str() == "5.7 3.45 1.1 6.7 21.01 8.97 2.234 13.1101 ");

    stringstream output1;
    for (auto it=tree_of_double.begin_inorder(); it!=tree_of_double.end_inorder(); ++it) {
        output1 << (*it) << " " ;
    }
            CHECK(output1.str() == "1.1 3.45 6.7 21.01 5.7 2.234 8.97 13.1101 ");

    stringstream output2;
    for (auto it=tree_of_double.begin_postorder(); it!=tree_of_double.end_postorder(); ++it) {
        output2 << (*it) << " " ;
    }
            CHECK(output2.str() == "1.1 21.01 6.7 3.45 2.234 13.1101 8.97 5.7 ");

    tree_of_double.add_right(2.234,7.8).add_left(7.8,14.2).add_right(14.2,313.52).
    add_right(313.52,2.0);
    /*
 *                        5.7
 *            3.45                       8.97
 *         1.1    6.7            2.234         13.1101
 *                    21.01          7.8
     *                            14.2
     *                                313.52
     *                                       2.0
     *
 *          preorder -  5.7 3.45 1.1 6.7 21.01 8.97 2.234 7.8 14.2 313.52 2 13.1101
 *          inorder - 1.1 3.45 6.7 21.01 5.7 2.234 14.2 313.52 2 7.8 8.97 13.1101
 *          postorder - 1.1 21.01 6.7 3.45 2 313.52 14.2 7.8 2.234 13.1101 8.97 5.7
 */
    stringstream outputAfter;
    for (auto it=tree_of_double.begin_preorder(); it!=tree_of_double.end_preorder(); ++it) {
        outputAfter << (*it) << " " ;
    }
            CHECK(outputAfter.str() == "5.7 3.45 1.1 6.7 21.01 8.97 2.234 7.8 14.2 313.52 2 13.1101 ");

    stringstream outputAfter1;
    for (auto it=tree_of_double.begin_inorder(); it!=tree_of_double.end_inorder(); ++it) {
        outputAfter1 << (*it) << " " ;
    }
            CHECK(outputAfter1.str() == "1.1 3.45 6.7 21.01 5.7 2.234 14.2 313.52 2 7.8 8.97 13.1101 ");

    stringstream outputAfter2;
    for (auto it=tree_of_double.begin_postorder(); it!=tree_of_double.end_postorder(); ++it) {
        outputAfter2 << (*it) << " " ;
    }
            CHECK(outputAfter2.str() == "1.1 21.01 6.7 3.45 2 313.52 14.2 7.8 2.234 13.1101 8.97 5.7 ");


    CHECK_THROWS_AS(tree_of_double.add_left(1874.21, 2), std::invalid_argument);
            CHECK_THROWS_AS(tree_of_double.add_left(1923.0, 2), std::invalid_argument);
            CHECK_THROWS_AS(tree_of_double.add_left(1.0, 2), std::invalid_argument);


}
TEST_CASE("tree of string"){
    BinaryTree<string> tree_of_string;
    tree_of_string.add_root("LOL")
.add_left("LOL", "add_left")
.add_right("LOL", "add_right")
.add_left("add_right","!!!")
.add_right("add_right","!!!")
.add_left("!!!","right").add_right("!!!","left");
    /*
 *                        LOL
 *            add_left           add_right
 *                             !!!        !!!
 *                       right    left
 */
    auto it = tree_of_string.begin_preorder();
    CHECK(*it =="LOL");

    stringstream output;
    for (auto it=tree_of_string.begin_preorder(); it!=tree_of_string.end_preorder(); ++it) {
    output << (*it) << " " ;
}
CHECK(output.str() == "LOL add_left add_right !!! right left !!! ");

stringstream output1;
for (auto it=tree_of_string.begin_inorder(); it!=tree_of_string.end_inorder(); ++it) {
output1 << (*it) << " " ;
}
CHECK(output1.str() == "add_left LOL right !!! left add_right !!! ");

stringstream output2;
for (auto it=tree_of_string.begin_postorder(); it!=tree_of_string.end_postorder(); ++it) {
output2 << (*it) << " " ;
}
CHECK(output2.str() == "add_left right left !!! !!! add_right LOL ");

            CHECK_THROWS_AS(tree_of_string.add_left("100", "123"), std::invalid_argument);
            CHECK_THROWS_AS(tree_of_string.add_left("sdf", "df"), std::invalid_argument);
            CHECK_THROWS_AS(tree_of_string.add_left("jk", "asf"), std::invalid_argument);

   tree_of_string.add_right("left","nomber").add_right("nomber","no").add_right("no","sos")
   .add_right("sos","long tree").add_left("long tree","level")
   .add_right("long tree","over");
    /* after the chang;
 *                        LOL
 *            add_left           add_right
 *                             !!!        !!!
 *                       right    left
     *                                nomber
     *                                       no
     *                                          sos
     *                                              long tree
     *                                            level      over
 */



    stringstream outputAfter;
    for (auto it=tree_of_string.begin_preorder(); it!=tree_of_string.end_preorder(); ++it) {
        outputAfter << (*it) << " " ;
    }
            CHECK(outputAfter.str() == "LOL add_left add_right !!! right left nomber no sos long tree level over !!! ");

    stringstream outputAfter1;
    for (auto it=tree_of_string.begin_inorder(); it!=tree_of_string.end_inorder(); ++it) {
        outputAfter1 << (*it) << " " ;
    }
            CHECK(outputAfter1.str() == "add_left LOL right !!! left nomber no sos level long tree over add_right !!! ");

    stringstream outputAfter2;
    for (auto it=tree_of_string.begin_postorder(); it!=tree_of_string.end_postorder(); ++it) {
        outputAfter2 << (*it) << " " ;
    }
            CHECK(outputAfter2.str() == "add_left right level over long tree sos no nomber left !!! !!! add_right LOL ");
}
TEST_CASE("tree of char - letter and singh"){
    BinaryTree<char> tree_of_char;
    tree_of_char.add_root('s')
    .add_left('s', 'a').add_right('s', 'b')
    .add_left('b','O').add_right('b','*')
    .add_left('a','r').add_right('a','l');

    /*
 *                        s
 *                  b             a
 *                O   *        r    l
 *
 */
    auto it = tree_of_char.begin_preorder();
            CHECK(*it =='s');

    stringstream output;
    for (auto it=tree_of_char.begin_preorder(); it!=tree_of_char.end_preorder(); ++it) {
        output << (*it) << " " ;
    }
            CHECK(output.str() == "s a r l b O * ");

    stringstream output1;
    for (auto it=tree_of_char.begin_inorder(); it!=tree_of_char.end_inorder(); ++it) {
        output1 << (*it) << " " ;
    }
            CHECK(output1.str() == "r a l s O b * ");

    stringstream output2;
    for (auto it=tree_of_char.begin_postorder(); it!=tree_of_char.end_postorder(); ++it) {
        output2 << (*it) << " " ;
    }
            CHECK(output2.str() == "r l a O * b s ");

            CHECK_THROWS_AS(tree_of_char.add_left('L', '!'), std::invalid_argument);
            CHECK_THROWS_AS(tree_of_char.add_left('A', 'e'), std::invalid_argument);
            CHECK_THROWS_AS(tree_of_char.add_left('B', 'A'), std::invalid_argument);

    tree_of_char.add_right('b','H').add_right('H','w').add_right('w','Q').add_left('r','p')
    .add_right('l','j');

    /*
 *                        s
 *                  b             a
 *                O  H        r      l
 *                     w     p         j
     *                   Q
 */
    stringstream outputAfter;
    for (auto it=tree_of_char.begin_preorder(); it!=tree_of_char.end_preorder(); ++it) {
        outputAfter << (*it) << " " ;
    }
            CHECK(outputAfter.str() == "s a r p l j b O H w Q ");

    stringstream outputAfter1;
    for (auto it=tree_of_char.begin_inorder(); it!=tree_of_char.end_inorder(); ++it) {
        outputAfter1 << (*it) << " " ;
    }
            CHECK(outputAfter1.str() == "p r a l j s O b H w Q ");

    stringstream outputAfter2;
    for (auto it=tree_of_char.begin_postorder(); it!=tree_of_char.end_postorder(); ++it) {
        outputAfter2 << (*it) << " " ;
    }
            CHECK(outputAfter2.str() == "p r j l a O Q w H b s ");

            CHECK_THROWS_AS(tree_of_char.add_left('P', 'A'), std::invalid_argument);
            CHECK_THROWS_AS(tree_of_char.add_left('X', 'A'), std::invalid_argument);
}
TEST_CASE("tree of long") {
    BinaryTree<long> tree_of_long;
    tree_of_long.add_root(10023)
            .add_right(10023, 23).add_left(10023, 134578)
            .add_right(134578, 8976432).add_left(134578, 123)
            .add_right(23, 45367).add_left(23, 1673)
            .add_right(1673, 1).add_left(1, 2431);

    /*
   *                           10023
   *                      23                 134578
   *                1673     45367       123      8976432
   *                     1
       *            2431
   */
    auto it = tree_of_long.begin_preorder();
            CHECK(*it == 10023);

    stringstream output;
    for (auto it = tree_of_long.begin_preorder(); it != tree_of_long.end_preorder(); ++it) {
        output << (*it) << " ";
    }
            CHECK(output.str() == "10023 134578 123 8976432 23 1673 1 2431 45367 ");

    stringstream output1;
    for (auto it = tree_of_long.begin_inorder(); it != tree_of_long.end_inorder(); ++it) {
        output1 << (*it) << " ";
    }
            CHECK(output1.str() == "123 134578 8976432 10023 1673 2431 1 23 45367 ");

    stringstream output2;
    for (auto it = tree_of_long.begin_postorder(); it != tree_of_long.end_postorder(); ++it) {
        output2 << (*it) << " ";
    }
            CHECK(output2.str() == "123 8976432 134578 2431 1 1673 45367 23 10023 ");

            CHECK_THROWS_AS(tree_of_long.add_left(12, 12), std::invalid_argument);
            CHECK_THROWS_AS(tree_of_long.add_left(999999, 213), std::invalid_argument);
            CHECK_THROWS_AS(tree_of_long.add_left(-23, 7483), std::invalid_argument);

    tree_of_long.add_left(1673, 1515).add_left(1515, -23).add_left(-23, 7483).add_right(123, 92883);
    /*         after chang;
      *                                 10023
      *                            23                    134578
      *                     1673        45367       123          8976432
      *               1515        1                    92883
          *       -23         2431
      *        7483
      */
    stringstream outputAfter;
    for (auto it = tree_of_long.begin_preorder(); it != tree_of_long.end_preorder(); ++it) {
        outputAfter << (*it) << " ";
    }
            CHECK(outputAfter.str() == "10023 134578 123 92883 8976432 23 1673 1515 -23 7483 1 2431 45367 ");

    stringstream outputAfter1;
    for (auto it = tree_of_long.begin_inorder(); it != tree_of_long.end_inorder(); ++it) {
        outputAfter1 << (*it) << " ";
    }
            CHECK(outputAfter1.str() == "123 92883 134578 8976432 10023 7483 -23 1515 1673 2431 1 23 45367 ");

    stringstream outputAfter2;
    for (auto it = tree_of_long.begin_postorder(); it != tree_of_long.end_postorder(); ++it) {
        outputAfter2 << (*it) << " ";
    }
            CHECK(outputAfter2.str() == "92883 123 8976432 134578 7483 -23 1515 2431 1 1673 45367 23 10023 ");
}
    TEST_CASE("empty"){
    BinaryTree<int> tree_of_nothing;
    stringstream out;
    for (auto it = tree_of_nothing.begin_postorder(); it != tree_of_nothing.end_postorder(); ++it) {
        out << (*it) << " ";
    }
            CHECK(out.str() == "");
    tree_of_nothing.add_root(5);
    for (auto it = tree_of_nothing.begin_postorder(); it != tree_of_nothing.end_postorder(); ++it) {
        out << (*it) << " ";
    }
            CHECK(out.str() == "5 ");

    tree_of_nothing.add_root(9);
    stringstream out1;
    for (auto it = tree_of_nothing.begin_postorder(); it != tree_of_nothing.end_postorder(); ++it) {
        out1 << (*it) << " ";
    }
            CHECK(out1.str() == "9 ");



    //copy tree:
    tree_of_nothing.add_right(9,6).add_left(9,3);
    BinaryTree<int> tree_of_copy;
    tree_of_copy

    }


