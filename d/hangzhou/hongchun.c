// Code of ShenZhou
// �鴺��
// Dong  11/03/1996.
// modified by aln 2 / 98

#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "�鴺��");
    set("long", @LONG
��������Կ�������ʮ��֮һ��˫�����(scenery)�����������  
����������ͨ�������µ�·��
LONG
);

    set("item_desc", 
	   ([
            "scenery" : 
		"˫�壬�ϸ߷�������֮���ϣ����߷�������֮�������ϱ�ңң��ԣ�\n"
		"ֻ��������գ�˫����������籡��֮�У���Ũ�򵭣�ʱ��ʱ�ޣ���\n"
                "��Ʈ�ƣ����������������\n"
           ])
	);
    set("exits", ([ /* sizeof() == 2 */ 
                  "east" : __DIR__"road31", 
                  "west" : __DIR__"road32", 
                ])
       );
	set("cost", 2);
set("fjing",1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
