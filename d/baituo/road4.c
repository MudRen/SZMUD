// Code of ShenZhou
// ���ոİ�
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
������ƫƧ��С�������ѵ��������ɽ��������Ȼ������
LONG
	);
	set("exits", ([ 
	    "northwest" : __DIR__"road5",
	    "south" : __DIR__"road3",
	]));
	set("outdoors","baituo");
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
