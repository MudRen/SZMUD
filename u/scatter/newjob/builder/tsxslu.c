//room: /newjob/builder/tsxslu.c ̩ɽСʯ·
//Lara 2001/12/08
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "Сʯ·");
        set("long", @LONG
С·�������˸�����״��Сʯ�ӣ������������£�ϸϸһ����ԭ����
��߽��ģ���ɫ��Сʯ��Ƕ��ǳɫСʯ�ӵ��м䣬����С·����������
��һ�����Ե��ϵ�������
LONG
        );

        set("exits", ([        
        "west" : __DIR__"tsrukou",
        "east" : __DIR__"tsqslu",
        "north" : __DIR__"tssschangn",
        "south" : __DIR__"tssschangs",
        ]));
        set("no_clean_up", 0);        
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
