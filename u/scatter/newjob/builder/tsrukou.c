//room: /newjob/builder/tsrukou.c ̩ɽ��ʯ�����
//Lara 2001/12/08
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "���");
        set("long", @LONG
����̩ɽ����һ��ƫƧ��С·��С·�������ۣ���֪ͨ��δ���·��
����һ�鳤����̦������ (board)��
LONG
        );

        set("exits", ([        
        "east" : __DIR__"tsxslu",
        "west" : "/d/taishan/daizong",
        ]));
        set("no_clean_up", 0);
        set("item_desc", ([
              "board" : YEL"�����̩ɽ��ʯ�������\n"+NOR       
        ]));
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
