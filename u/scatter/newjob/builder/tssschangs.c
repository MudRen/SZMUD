//room: /newjob/builder/tssschangs.c ̩ɽ��ʯ�����ϣ�
//Lara 2001/12/08
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
���ﵽ������ɽ�ϲ�ʯ�����������������������µ���ʯ��������
ʯ�����ô�������������ʯԽ��Խ�ࡣ������ϲ��ʯͷ������ī�͵���
����Ѱ������˵��ʯ���ﾭ�����ҵ���Ѫʯ�����ı�����
LONG
        );

        set("exits", ([        
        "north" : __DIR__"tsxslu",
        "east" : __DIR__"tsqschangs",
        ]));
        set("no_clean_up", 0);        
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
