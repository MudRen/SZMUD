// Code of ShenZhou
// �����
// maco
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "ɽ��ʯ��");
	set("long", @LONG
���ǰ�����е�ʯ�ң�ֻ������ʯ�ڶ��Ǿ�Ө���񣬾�ɫ
��������·��ż������Σ����Ǽ�����̣�ԭ��ɽ���ܱգ���
�ܷ��֣����Զ������²������á�
LONG
	);

	set("exits", ([
		"north" : __DIR__"jaderoad1",
	]));
	set("objects", ([ 
	    "/d/xingxiu/obj/yujian" : 1,
	]) );

	set("cost", 1);
	setup();
}
