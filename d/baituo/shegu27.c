//Cracked by Roath
// shegu.c �߹�
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	int i;

	set("short", "ɽ��");
	set("long", @LONG
����һ�������εĹ��ȣ������±��ϳ����˱�ֱ�İ������ɼ��
��ľ���ٲ�ֱ�䣬���������´ܣ�ˮ����ɢ��������·�����ʪ�ˡ�
����������Ԩ��ǰ���Ƕ��͵��±ڣ������߹ȵľ�ͷ��û�е�·����
�ˡ�
LONG
	);

	set("exits", ([ 
	    "south" : __DIR__"shegu26",
	]));

	i = random (50);

	if( i < 20 )
	set("objects", ([
	   // "/clone/drug/lingzhi" : 1, 
	   "/clone/drug/danggui" : 1,  

	]));

	else if( i < 30 ) set("objects", ([
	    "/d/city/obj/branch4" : 1,
	    "/d/city/npc/maque" : 1,
	]));

	else if( i < 40 ) set("objects", ([
	    "/d/baituo/npc/bt_snake" : 2,
	]));

	else set("objects", ([
	    "/d/city/obj/branch1" : 1,
	    "/d/baituo/npc/pu_snake" : 1,
	]));

	set("cost", 1);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

void init()
{
	this_player()->set("enter_shegu", 1);
}
