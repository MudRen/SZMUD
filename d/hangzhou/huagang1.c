// Code of ShenZhou
// ���۹���
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   
   	set("short", RED"���۹���"NOR);
   	set("long", @LONG
ֻ��������һС����һ�����ź����档��������Ⱥ����������
Ͷ�������º��㣬��ʳ������л������԰ʱ����ʫһ�ס����Ⱥ����
���࣬����ž��ҷ��㡣��թ������������������˿��˺�����
LONG        );

   	set("exits", ([ /* sizeof() == 1 */ 
                  "east" : __DIR__"suti6", 
                ])
       	);
	set("cost", 2);
        set("fjing", 1);
        set("outdoors", "hangzhou");
   	setup();
//   replace_program(ROOM);
}

void init()
{
        add_action("do_dig", "dig");
}

int do_dig(string arg)
{
	object ni = new("d/gaibang/obj/mud");
	object me = this_player();

	if ( !arg || arg == "" ) 
		return 0;

	if ( arg != "��" || arg != "mud" ) {
		message_vision("$N�Ӻ�������һЩʪ��������\n", me);
		ni->move(me);
		return 1;
	}	

	tell_object( me, "��Ҫ��ʲô��\n" );
        return 1;
}

