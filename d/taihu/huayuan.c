// Code of ShenZhou
//Kane

#include "/d/taihu/guiyun.h"
inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
����һ�����͵Ľ���԰�֣���ģ�䲻�󣬹����ȴ��Ϊ���£�
��ص��꽨԰֮�˺ܷ���һ��������԰�л���Ϯ�ˣ�ݺ�����裬��
����磬�̲�������ֻ����Ƭ�̱��������崺�磬����������
LONG
	);

	set("exits", ([
		"east" : __DIR__"liangong",
		"north" : __DIR__"chufang",
		"south" : __DIR__"huating",
	]));
	set("cost", 1);
	set("outdoors", "taihu");
	set("objects", ([
		"/d/taihu/npc/xiaoju" : 1,
//		"/d/taihu/npc/xiaoping" : 1,
	]));

	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");
	
    if ( (!myfam || myfam["family_name"] != "�һ���") && dir == "east" ) {
//        if ( (!myfam || myfam["family_name"] != "�һ���") && dir != "north" )
           return notify_fail("����ׯ������ͣ��㲻��������ߣ�\n");
    }
    return ::valid_leave(me, dir);
}
