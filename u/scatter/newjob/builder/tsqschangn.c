//room: /newjob/builder/tsqschangn.c ̩ɽ��ʯ��������
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
        "south" : __DIR__"tsqslu",
        "west" : __DIR__"tssschangn",
        "east" : __DIR__"tszschangn",
        ]));
        set("no_clean_up", 0);        
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
