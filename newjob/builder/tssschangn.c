//room: /newjob/builder/tssschangn.c ̩ɽ��ʯ��������
//Lara 2001/12/08
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
���ﵽ������ɽ�ϲ�ʯ�����������������������µ���ʯ��������
ʯ�����ô�������������ʯԽ��Խ�ࡣ�������µĻ����������������
ʯ�Ѿ��ѻ�����Сɽ�����ж�����ʯ����ɽ֮·�����ơ�
LONG
        );

        set("exits", ([        
        "south" : __DIR__"tsxslu",
        "east" : __DIR__"tsqschangn",
        ]));
        set("no_clean_up", 0);        
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
