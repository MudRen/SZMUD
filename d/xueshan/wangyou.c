// Code of ShenZhou

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���ǹ�");
	set("long", @LONG
�������Ǵ�������һ��Ƨ�����ڣ����¾����˼���ǰǰ���ᣬ���
СС���������������׵�ҫ�۵�ѩ�������š�����ɫ��ɽҰ��ѩ������
ҫ�ź�ɫ����ɫ�Ĺ��������ͷף��Թ�һ������¥�ɸ�������ǰ���֡�
����һ��С����֪ͨ���δ���
LONG
	);

	set("exits", ([
		"southup" : __DIR__"shangu1",
		"west" : __DIR__"luyeyuan",
	]));
	set("objects", ([
		__DIR__"npc/zhuoma" : 1,
		__DIR__"npc/yangzong" : 1,
	]));

	setup();
	set("cost", 5);
	set("outdoors","qilian-shan");
}

