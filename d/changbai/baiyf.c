// Code of ShenZhou
// Room: baiyf.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "���Ʒ�");
	set("long", @LONG
�����ǳ������壬���ǹ���ĵ�һ�߷壬��������صı��棬�ֽС���
�㡱�����ƴ�ʯ���������ղ�ɢ������ʱȺ���¶�����˷��������ƣ�����
��׳����ɽ���죬������⣬�˳�Ϊ���׵���������ɽ�Ĳοͣ��Ի��ൽ��
��ݼ���أ��Ա�ƽ����
LONG	);
	set("exits", ([ 
              "southdown" : __DIR__"tianchi",
              "southwest" : __DIR__"yuzf",
              "southeast" : __DIR__"longmf",
        ]));
	
        set("outdoors", "changbai");

        set("count", random(3)+1);

	setup();
}
