//Cracked by Roath
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", 
"�����������ߣ�������������������ǳ��˵��٣���������
�Կգ�������ף����������ϣ��Բ�����Ŀ��ҡ��������ϣ���
������ָ����ٴ�ʤ�������ؽ�󳩡�\n");
        
set("exits", ([
                "north"  : __DIR__"shenshege",
                "south"   : __DIR__"lingguige",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hengshan");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

