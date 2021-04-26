// Code of ShenZhou
// shegu.c �߹�
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;
string look_bush();

void create()
{
	set("short", "�߹�����");
	set("long", @LONG
���ǰ���ɽ���߹�֮�У����������ŴԴ԰���(bush)�����ض���
�ӲݺͿ�֦��Ҷ����ζ������š�С·���۵ش������ԣ���֪��ͨ��
���
LONG
	);

	set("exits", ([ 
	    "southeast" : __DIR__"shegu21",
	    "northwest" : __DIR__"shegu23",
	]));

	set("item_desc", ([
	"bush" : (: look_bush :),
	]));

	set("hide_snake", random(3));
	set("grass", 1);
	set("bush", 1);

	set("cost", 2);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

#include "snake_room.h"
