// Jiuer Aug 15, 2001
// /d/jueqing/shanlu1.c

inherit ROOM;

void create()
{
	set("short","ɽ·");

	set("long",@LONG
�����ɽ·�ǳ����ͣ������о������Ṧ��ֻ��һʧ���Ҫˤ��ɽ
ȥ���ߵ������㲻��������Щ���ˡ�ǰ��һ���ͱ�ӭ���ס����ɽ��ȥ
·��
LONG);
	set("exits",([
		"southdown" : __DIR__"shanlu2",
		]));
	set("cost", 1);
	set("outdoors","jueqing");
	setup();
	replace_program(ROOM);
}
