// Code of ShenZhou
// �۾�԰ ������
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", GRN"������"NOR);
    set("long", @LONG
ÿ��������վ�����ϣ��غ������ڷ���ҡҷ����˷��գ���ݺ��
֦ͷӭ����Ϸ��������ת���ʵ�����������ݺ����
LONG);

    set("exits", ([ /* sizeof() == 1 */ 
                   "southwest" : __DIR__"jujing2", 
                 ])
       );
	set("objects" , ([
                "/d/jiaxing/npc/wuya" : 1,
                "/d/city/npc/maque" : 2,
	]));
set("fjing", 1);
	set("cost", 2);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
