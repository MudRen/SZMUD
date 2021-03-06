// Code by Scatter
// 黑风崖
// gate.c

inherit ROOM;

void create()
{
        set("short", "黑风崖山路");
        set("long", @LONG
这里就是传说中的黑风崖的山脚。到这里你马上感觉到这里的无比的阴气，
以及一种说不出来的邪气。这里有一个牌子写这三个字 - 杀无赦 - 突然你
发现已经没有退路了，只有合力杀掉黑风崖的黑风祭才能回到中原。你往上
一看结果发现看不到山顶，可想而知这座山的路一定不好走。
LONG );

        set("exits", ([
                "northup"  : __DIR__"hill18",
                "southdown"  : __DIR__"hill16",
        ]));

        setup();
        replace_program(ROOM);
}
