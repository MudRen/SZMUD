// Code of ShenZhou
// Summer 9/12/96
#include "room.h"
#include <ansi.h>
inherit ROOM;

void create()

{
        set("short", "������");
        set("long", @LONG
������һ����ɳ��̧����ȥ����ããһƬɳĮ�����޾�ͷ��ֱ����ߣ�
һ������̤�룬��ʯţ�뺣����ʧ����Ӱ�����ˣ��ɹ����Ϊ��������
LONG
        );
        set("exits", ([
                "west" : __DIR__"aili",
        ]));


	set("cost", 5);
        setup();
        set("outdoors","qilian-shan");
}
int valid_leave(object me, string dir)
{
	object *inv;
	int i;
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->query("id") == "tie lian")continue;
			if(inv[i]->is_character() ) 
			inv[i]->recieve_wound("qi", 3000, "����ɳ������");
		destruct(inv[i]);
		}
		me->move(__DIR__"xiaolu");
                me->unconcious();
	return notify_fail(HIY"������ӱ���ɳ��ס�������ߣ���о������ˡ� \n"NOR);
} 
