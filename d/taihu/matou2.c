// Code of ShenZhou
//Kane

inherit FERRY;

void create()
{
	set("short", "��ͷ");
	set("long", @LONG
����̫����һ��ˮ�ޣ���ʯ������ͷ��ͣ����һЩС����ֻ��
ǰ��¥��������ټ��һ��ׯԺ������̫������ׯ��
LONG
	);
	 set("exits", ([
		"west" : __DIR__"matou",
	]));
	set("cost", 2);
	set("outdoors", "taihu");

	set("water_name", "��");
	set("boat", __DIR__"duchuan2");
	set("opposite", __DIR__"taihu2");

	setup();
}

#include "ferry.h"
