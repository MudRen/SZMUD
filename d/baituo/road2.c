// Code of ShenZhou
// ���ոİ�
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
һ������ɳʯ��С��������ͨ��ɽׯ��ǰԺ�����ϱ���һ��С�ݣ���
��Ʈ������Ʋ�������
LONG
	);
	set("exits", ([ 
	    "southwest" : __DIR__"kitchen",
		"north" : "/d/baituo/road1b",
		"southeast" :__DIR__"kongdi1",
	]));

	set("outdoors","baituo");
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
