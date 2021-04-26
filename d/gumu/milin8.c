// Sep 11,2001
// Code by April
// /gumu/milin8.c

inherit ROOM;

void create()
{
        set("short","树林");

        set("long",@LONG
走在林中，一股股如轻纱般的薄雾带着极甜的花香在你身旁不时地升
腾消散。四周密林深邃，鸟鸣莺莺。各色的山花左一簇、右一簇点缀密林
中，几只乳白色的蜜蜂在你身旁绕了一圈，又飞向山花采蜜去了。你向四
周望去，似乎不论往哪儿走尽是茂密的树林。
LONG);


        set("exits", ([
        "north" : __DIR__"milin9",
        "west" : __DIR__"milin18",
        "south" : __DIR__"milin10",
        "east" : __DIR__"milin7",
                      ]));

          set("cost",2);
          set("outdoors", "gumu");

        setup();
        replace_program(ROOM);
}
