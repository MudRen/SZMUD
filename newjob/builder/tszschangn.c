//room: /newjob/builder/tszschangn.c ̩ɽ��ʯ��������
//Lara 2001/12/09
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
�����ʯͷʮ�ּ�Ӳ�����أ����������൱�Ѿ���һ�������о����
���ִ���һ�������˽��п��ɣ���ұ���ֹ���ȷ�����������������ɡ�
������ǻ���ʯ��������������ʯ�ϣ������õĻ����ܷ�����ʯ��
LONG
        );

        set("exits", ([        
        "south" : __DIR__"tshgslu",
        "west" : __DIR__"tsqschangn",
        ]));
        set("no_clean_up", 0);        
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
