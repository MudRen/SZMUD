/* /kungfu/class/movie/center.c
** 神州电影院
** created by yujie
** created in 11/2001
*/

inherit ROOM;

void create()
{
        set("short", "电影院");
        set("long", @LONG
这里是神州的电影院，很多经典的、最新的电影都会经常播放。从这
里进去可以到电影院的大厅，两边的通道分别通向一些明星的专场，那里
可以自由点片播放，下面是影迷俱乐部，里面有许多影星资料和最新动态
可以查询，还可以喝杯茶坐下来聊自己喜欢的明星和电影电视剧。
LONG
        );

        set("exits", ([
                "out" : "/d/city/guangchang",
                "enter" : __DIR__"mainroom",
 //               "takako" : __DIR__"takako1",
             //   "down" : __DIR__"talkroom",
        ]));

        set("objects", ([
                "/kungfu/class/movie/npc/waiter" : 1,
                "/kungfu/class/movie/obj/pub_b" : 1,
             "/u/jiuer/huoji": 1,
        ]));

        set("cost", 0);
        setup();
      call_other("/clone/board/movie_b", "???");
}
