// Code of ShenZhou
// ���ոİ�
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
������ƫƧ��С�������ѵ��������ɽ��������Ȼ������ң����
������һ�������ɽ�ȣ�������ɭ���Ǿ��ǰ���ɽ���߹ȡ����ߵĲ�
·ͨ������ɽׯ���߳���
LONG
	);
	set("exits", ([ 
	    "east" : __DIR__"shechang",
	    "north" : __DIR__"shegu1",
	    "southeast" : __DIR__"road4",
	]));
	set("outdoors","baituo");
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
