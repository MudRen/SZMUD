// Code of ShenZhou
// AceP

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��ٹȹȿ�");
	set("long", @LONG
������һ��ɽ�ȵĹȿڣ�һ��Ƭƽ̹�Ĳݵأ�����ɽ�ڶ��ͣ�
û�г�·��Զ����ͷ��ȫ��һ���������������һ��(songshu)��
������Щ�ر�
LONG
	);

	set("item_desc", ([
		"songshu" : "���������������˳�����������һƬ�����˰��ᣬд�žŸ����֣�\n���ն�����˹�" RED "ɱ" NOR "���⡱��������ڣ��ǡ�ɱ����ȴ�����ɫ��\n",
	]));

	set("exits", ([
		"out"   : __DIR__"heisenlin.c",
		"north" : __DIR__"wjg2.c",
	]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
