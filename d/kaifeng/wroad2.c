//Room: /d/kaifeng/wroad2.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "西大街");
        set("long", @LONG
一条青石铺成的大道通向南北。路上行人络绎不绝，只见南面不
远处的古树下有一个简陋的摊子，摊子一角的招牌在风中摇晃着，上
面写着“清风茶亭”，居然也围了一堆人。往西就是西门了，东边是
开封大道。
LONG
        );

        set("exits", ([
                "west" : __DIR__"ximen",
                "south":__DIR__"wroad2s",
                "east":__DIR__"wroad1",
              ]));

        set("objects",([
               "d/taishan/npc/tangzi":1,
              ]));
        set("outdoors", "kaifeng");
        setup();
        replace_program(ROOM);
}

