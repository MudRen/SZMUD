// Code of ShenZhou
// Room: /d/heimuya/zongtan.c
// Date: fear 1999/12/08
#include <ansi.h>

inherit ROOM;




void create()
{
        set("short", HIR"���������̳"NOR);
        set("long", @LONG
������������̵���̳����̳�Ĺ㳡�����кܶ���
����̽���վ��������龰�������ࡣ
LONG
        );

        set("exits", ([
                "northeast" : __DIR__"shiji1",
                "south" : __DIR__"hillroad4",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

