// Code of ShenZhou
// ���ոİ�
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ����ש��ǽ�ĳ��ȣ�һֱ�����������ȥ��������������������
�ߴ������������������ȴ��һƬ�ž���
LONG
	);
	set("exits", ([ 
	    "east" : __DIR__"dating",
	    "west" : __DIR__"changlang2",
	]));
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
