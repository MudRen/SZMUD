// Code of ShenZhou
// ��̶ӳ��
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "ͤͤͤ");
    set("long", @LONG
ͤ�������һ����׳����Ĵ�ʯ����ʨʯ����������ϸ��������
���ʯ��Ȼ�е���һͷʨ�ӡ����ϴ�����������ͨ�ģ����Ϻ�����
�ֱ���һ���ص�С·��
LONG);

    set("exits", ([ /* sizeof() == 3 */ 
        "south" : __DIR__"santan4", 
	"southeast" : __DIR__"santan2",
	"southwest" : __DIR__"santan7",
                 ])
       );
    setup();
    replace_program(ROOM);
}