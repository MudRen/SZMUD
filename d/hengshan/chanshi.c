//Cracked by Roath
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", 
"һ�䲻������ң�Ϊ��ɽ���Ŷ���ʦ̫�ճ�����֮����
�����ı���Ȼ��ֻ�����и������ţ�����һ�����С�\n");
        
set("exits", ([
                "south"  : __DIR__"wusean",
        ]));
        set("no_clean_up", 0);
	  set("cost", 1);
        setup();
        replace_program(ROOM);
}

