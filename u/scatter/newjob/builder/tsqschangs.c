//room: /newjob/builder/tsqschangn.c ̩ɽ��ʯ�����ϣ�
//Lara 2001/12/08
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
�����ʯͷ�Ƚ�������Ҳ�Ƚ��ᣬ���������Ƚ����ס�������ɻ�
��һ���Ǿ����ǳ�����Ṥ�ˣ��������ɺͰ���һ����ɡ�������һ�߸�
�һ�߳���ɽ�裬һƬææµµ��
LONG
        );

        set("exits", ([        
        "north" : __DIR__"tsqslu",
        "west" : __DIR__"tssschangs",
        "east" : __DIR__"tszschangs",
        ]));
        set("no_clean_up", 0);        
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
