#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <limits>
#include "BinaryHeap.hpp"
#include "iostream"

using namespace std;

TEST_CASE("TESTS")
{
    SECTION("Constructer")
    {
        SECTION("1 thing")
        {
            double priorities[1]={1};
            BinaryHeap x(priorities,1);
            REQUIRE(x.getSize()==1);
        }
        SECTION("2 things..no flip")
        {
            double priorities[2]={1,2};
            BinaryHeap x(priorities,2);
            REQUIRE(x.getSize()==2);
        }
        SECTION("2 things..flip")
        {
            double priorities[2]={2,1};
            BinaryHeap x(priorities,2);
            REQUIRE(x.getSize()==2);
        }

        SECTION("3 things..flip")
        {
            double priorities[3]={2,3,1};
            BinaryHeap x(priorities,3);
            REQUIRE(x.getSize()==3);
        }

        SECTION("6 things")
        {
            double priorities[6]={24,31,3,115,65,73};
            BinaryHeap x(priorities,6);
            REQUIRE(x.getSize()==6);
        }

        SECTION("9 things")
        {
            double priorities[9]={1,2,3,4,4,45234,314,2,5345};
            BinaryHeap x(priorities,9);
            REQUIRE(x.getSize()==9);
        }

        SECTION("5 things")
        {
            double priorities[4]={10,9,8,6};
            BinaryHeap x(priorities,4);
            REQUIRE(x.getSize()==4);
        }

        SECTION("10 things")
        {
            double priorities[10]={2,5,45,3,2,6,31,1,35,0};
            BinaryHeap x(priorities,10);
            REQUIRE(x.getSize()==10);
        }

        SECTION("Special Case no subflips")
        {
            double priorities[4]={4,5,10,3};
            BinaryHeap x(priorities,4);
            REQUIRE(x.getSize()==4);
        }

   }
    SECTION("getMin")
    {
        double priorities[6]={24,31,3,115,65,73};
        BinaryHeap x(priorities,6);
        REQUIRE(x.getMin()==2);
    }
    SECTION("CONTAINS")
    {
        double priorities[6]={24,31,3,115,65,73};
        BinaryHeap x(priorities,6);
        REQUIRE(x.contains(2));
    }

    SECTION("getSize")
    {
        double priorities[6]={24,31,3,115,65,73};
        BinaryHeap x(priorities,6);
        REQUIRE(x.getSize()==6);
    }
    SECTION("getItem")
    {
        double priorities[6]={24,31,3,115,65,73};
        BinaryHeap x(priorities,6);
        REQUIRE(x.getItem(0)==2);
    }
    SECTION("getPos")
    {
        double priorities[6]={24,31,3,115,65,73};
        BinaryHeap x(priorities,6);
        REQUIRE(x.getPos(2)==0);
    }

    SECTION("getPriority")
    {
        double priorities[6]={24,31,3,115,65,73};
        BinaryHeap x(priorities,6);
        REQUIRE(x.getPriority(2)==3);
    }

    SECTION("popMin")
    {
        double priorities[6]={24,31,3,115,65,73};
        BinaryHeap x(priorities,6);
        REQUIRE(x.getSize()==6);
                x.popMin();
        REQUIRE(x.getSize()==5);
                x.popMin();
        REQUIRE(x.getSize()==4);
                x.popMin();
        REQUIRE(x.getSize()==3);
                x.popMin();
        REQUIRE(x.getSize()==2);
                x.popMin();
        REQUIRE(x.getSize()==1);
                x.popMin();
        REQUIRE(x.getSize()==0);
    }

    SECTION("popMin and decreasePriority and contains")
    {
        double priorities[4]={0,1,2,3};
        BinaryHeap x(priorities,4);
        x.popMin();
        REQUIRE(x.contains(1));
        REQUIRE(x.contains(2));
        REQUIRE(x.contains(3));
        REQUIRE(!x.contains(0));
        
        x.decreasePriority(3,0);
        x.popMin();

        REQUIRE(x.contains(1));
        REQUIRE(x.contains(2));
        REQUIRE(!x.contains(0));
        REQUIRE(!x.contains(3));

        x.decreasePriority(1,0);
        x.popMin();

        REQUIRE(x.contains(2));
        REQUIRE(!x.contains(1));
        REQUIRE(!x.contains(0));
        REQUIRE(!x.contains(3));

        x.decreasePriority(2,0);
        x.popMin();
        REQUIRE(!x.contains(2));
        REQUIRE(!x.contains(1));
        REQUIRE(!x.contains(0));
        REQUIRE(!x.contains(3));
    }

    SECTION("popMin and decreasePriority and contains")
    {
        double priorities[4]={0,1,2,4};
        BinaryHeap x(priorities,4);
        x.decreasePriority(3,3);
        REQUIRE(x.getItem(0)==0);
        REQUIRE(x.getItem(1)==1);
        REQUIRE(x.getItem(2)==2);
        REQUIRE(x.getItem(3)==3);
    }

    SECTION("DECREASE pRIOIRRTY")
    {
        SECTION("one change..new root from within")
        {
            double priorities[10]={4,6,8,10,12,14,16,18,20,22};
            BinaryHeap x(priorities,10);

            x.decreasePriority(4,0);
            REQUIRE(x.getItem(0)==4);
        }


        SECTION("new prioriry too big")
        {
            double priorities[10]={4,6,8,10,12,14,16,18,20,22};
            BinaryHeap x(priorities,10);

            x.decreasePriority(9,21);
            REQUIRE(x.getItem(9)==9);
        }

        // SECTION("one change..new root from right child")
        // {
        //     double priorities[10]={4,6,8,10,12,14,16,18,20,22};
        //     BinaryHeap x(priorities,10);

        //     x.decreasePriority(2,0);
        //                                     for(int i=0;i<10;i++)
        //     {
        //         cout<<"item "<<x.getItem(i)<<endl;
        //     }

        //     cout<<endl;
        //                     for(int i=0;i<10;i++)
        //     {
        //         cout<<"pos "<<x.getPos(i)<<endl;
        //     }
        //     cout<<endl;
        //                     for(int i=0;i<10;i++)
        //     {
        //         cout<<"pri "<<x.getPriority(x.getItem(i))<<endl;
        //     }                cout<<endl;                cout<<endl;
        // }

        // SECTION("one change..parenent from left child")
        // {
        //     double priorities[10]={4,6,8,10,12,14,16,18,20,22};
        //     BinaryHeap x(priorities,10);

        //     x.decreasePriority(3,5);
        //                                     for(int i=0;i<10;i++)
        //     {
        //         cout<<"item "<<x.getItem(i)<<endl;
        //     }
        //     cout<<endl;

        //                     for(int i=0;i<10;i++)
        //     {
        //         cout<<"pos "<<x.getPos(i)<<endl;
        //     }
        //     cout<<endl;
        //                     for(int i=0;i<10;i++)
        //     {
        //         cout<<"pri "<<x.getPriority(x.getItem(i))<<endl;
        //     }                cout<<endl;                cout<<endl;

        // }

        // SECTION("one change..parenent from right child")
        // {
        //     double priorities[10]={4,6,8,10,12,14,16,18,20,22};
        //     BinaryHeap x(priorities,10);

        //     x.decreasePriority(4,5);
        //                                     for(int i=0;i<10;i++)
        //     {
        //         cout<<"item "<<x.getItem(i)<<endl;
        //     }
        //     cout<<endl;

        //                     for(int i=0;i<10;i++)
        //     {
        //         cout<<"pos "<<x.getPos(i)<<endl;
        //     }
        //     cout<<endl;
        //                     for(int i=0;i<10;i++)
        //     {
        //         cout<<"pri "<<x.getPriority(x.getItem(i))<<endl;
        //     }                cout<<endl;                cout<<endl;
        // }

        // SECTION("one change..new root from last element")
        // {
        //     double priorities[10]={4,6,8,10,12,14,16,18,20,22};
        //     BinaryHeap x(priorities,10);

        //     x.decreasePriority(9,0);

        //                                     for(int i=0;i<10;i++)
        //     {
        //         cout<<"item "<<x.getItem(i)<<endl;
        //     }
        //     cout<<endl;

        //                     for(int i=0;i<10;i++)
        //     {
        //         cout<<"pos "<<x.getPos(i)<<endl;
        //     }
        //     cout<<endl;
        //                     for(int i=0;i<10;i++)
        //     {
        //         cout<<"pri "<<x.getPriority(x.getItem(i))<<endl;
        //     }                cout<<endl;                cout<<endl;
        // }

        // SECTION("a lot of changes")
        // {
        //     SECTION("case 1..mutiple no pop min")
        //     {          

        //         cout<<endl;                cout<<endl;                cout<<endl;                cout<<endl;                cout<<endl;
        //         double priorities[10]={2,5,45,3,2,6,31,1,35,0};
        //         BinaryHeap x(priorities,10);

        //             for(int i=0;i<10;i++)
        //         {
        //             cout<<"item "<<x.getItem(i)<<endl;
        //         }
        //         cout<<endl;


        //             for(int i=0;i<10;i++)
        //         {
        //             cout<<"pri "<<x.getPriority(x.getItem(i))<<endl;
        //         }
        //         cout<<endl;                cout<<endl;


        //         x.decreasePriority(4,0);
        //         x.decreasePriority(6,10);
        //         x.decreasePriority(5,1);

        //             for(int i=0;i<10;i++)
        //         {
        //             cout<<"item "<<x.getItem(i)<<endl;
        //         }
        //         cout<<endl;

        //             for(int i=0;i<10;i++)
        //         {
        //             cout<<"pos "<<x.getPos(i)<<endl;
        //         }
        //         cout<<endl;
        //             for(int i=0;i<10;i++)
        //         {
        //             cout<<"pri "<<x.getPriority(x.getItem(i))<<endl;
        //         }                cout<<endl;                cout<<endl; 
        //    }
        //}
    }
}