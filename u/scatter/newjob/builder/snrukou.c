//room: /newjob/builder/snrukou.c ��ũ���ֳ����
//Lara 2001/11/10
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "���");
        set("long", @LONG
��ǰ������ũ���ˣ��������Ǹߴ�ï�ܵ���ľ������������һ����
����Ҷ��������ģ������൱�����·��һ�����˺�Χ�Ĵ����Ϲ���һ��
���� (board)��
LONG
        );

        set("exits", ([        
        "east" : __DIR__"snhongping",
        "west" : "/d/foshan/road2",
        ]));
        set("no_clean_up", 0);
        set("item_desc", ([
              "board" : HIG"�ססס���ũ�ܡססס�\n"+NOR       
        ]));
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
