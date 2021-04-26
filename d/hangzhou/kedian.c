// Code of ShenZhou
#include <ansi.h>
inherit ROOM;

string* Banned_id = ({
	"ufk",
	"none",
});	


void create()
{
	set("short", HIC"������͵�"NOR);
	set("long", @LONG
���Ǻ����������Ŀ͵꣬����������ڣ�װ�����繬������������
���������صķ������顣��С����������æ������ת���Ӵ�����ǻ�����Ŀ�
�ˡ�ǽ�Ϲ���һ������(paizi)��
LONG
	);

//	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ����������\n",
	]));

	set("objects", ([
		"/d/city/npc/xiaoer" : 1,
		"/clone/obj/car" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"road24",
		"up" : __DIR__"kedian2",
	]));

	set("cost", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	string id;
	int i;
	
	if(me == present("xiao er"))
		return ::valid_leave(me, dir);
	
	if(objectp(present("xiao er", environment(me)))) {
		if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");

		if ( me->query_temp("rent_paid") && dir == "east" )
		return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");
	}
	
	id = (string)me->query("id");
	for (i = 0; i < sizeof(Banned_id); i++)
	{
	if (id == Banned_id[i])
	{
		me->set("startroom", "/d/death/block");
		me->move("/d/death/block");
		return notify_fail("�ٺ٣��������ܵ�����ȥ����\n");
	}
	}

	return ::valid_leave(me, dir);
}
