//room: /newjob/builder/cbrukou.c ����ɽ�ֳ����
//Lara 2001/11/10
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "���");
        set("long", @LONG
�����������Ǳ��ߵ�һ��Сƽ�أ��������ǲ�ͬ������ż���ܿ�����
��С���ˣ�·��һ���Դ�һ������Ϲ���һ������ (board)��
LONG
        );

        set("exits", ([        
        "east" : __DIR__"cbguanmue",
        "south" : "/d/changbai/mantx",
        "west" : __DIR__"cbguanmuw",
        "north" : __DIR__"cbguanmu",
        ]));
        set("no_clean_up", 0);
        set("item_desc", ([
              "board" : HIY"����������������ɽ�ֳ�������������\n"+NOR       
        ]));
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
