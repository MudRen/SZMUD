// Room: tulu2.c ��·
// By xuanyuan

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�����������С·����Ϊ�Ĵ��Թž��Ǹ���֮�أ����Է�����ȥ��
���ܵ��������������ࡣ
LONG);
        set("outdoors", "chengdu");
        set("cost", 1);
	set("exits", ([
		"eastdown" : __DIR__"tulu3",
		"westup" : __DIR__"chuanxi1",
	]));

	setup(); 
	replace_program(ROOM);
}
