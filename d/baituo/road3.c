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
	    "north" : __DIR__"road4",
            "southeast" : "/d/baituo/btgate",
	]));
	set("outdoors","baituo");
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
