// Code of ShenZhou
 // ��ϼ��
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   set("short", MAG"��ϼ��"NOR);
    set("long", @LONG
��˵վ��ɽͷ���峿�ۿ�ɽ�����ƴ��̣��������������ϼ����
ɫ�������ʳơ���ϼ�������������о����ġ��������͡�������������
�������ڵ���Ȼ��Ѩ���и�����ʯ�̡���������ɽ��·��������ȥ��
����
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
                  "west" : __DIR__"road62", 
                  "eastdown" : __DIR__"road64", 
                ])
       );
	set("cost", 3);
        set("fjing", 1);
    setup();
    replace_program(ROOM);
}
