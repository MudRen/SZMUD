// Code of ShenZhou
// jiuer 6/17/2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��ǰ��һ����ש��ǽ�ĳ��ȣ�����ͨ�������������ǰ���ɽׯ�ڼҶ�
��ס�ķ��䡣���ϱ�����һ��С�ţ����ǼҶ����Ů����������Ϣ�����ڡ�
���ϱߵ�����Ʈ��������ζ���ǰ���ɽׯ�ĳ�����
LONG
	);
	set("exits", ([ 
	    "north" : __DIR__"changlang4",
	    "southwest" : __DIR__"bedroom3",
	    "southeast" : __DIR__"kitchen",
	]));
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
