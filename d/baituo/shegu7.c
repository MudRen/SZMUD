// Code of ShenZhou
// shegu.c �߹�
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�߹�ƽ��");
	set("long", @LONG
�����߹ȵ�һ����ƽ̹�����ĵش����������ǰ�С��Ҷ�����մ�
����С����ʯ��ƽ���ĵ��ƴ�������������Ϊ���죬�����������
�߲�����ľ��
LONG
	);

	set("exits", ([ 
	    "southwest" : __DIR__"shegu8",
	    "east" : __DIR__"shegu6",
	    "northwest" : __DIR__"shegu20",
	]));
	
	set("objects", ([
	    "/d/city/npc/maque" : 2,
	]));
	set("resource/grass", 1);
	set("cost", 1);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}
