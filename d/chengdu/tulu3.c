// Room: tulu3.c ��·
// By xuanyuan

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�����������С·����Ϊ�Ĵ��Թž��Ǹ���֮�أ����Է�����ȥ��
���ܵ��������������ࡣ�����Ǵ��У�����ʮ���ﴦ�����������񶼳ɶ��ˡ�
LONG);
        set("outdoors", "chengdu");
        set("cost", 1);
	set("exits", ([
		"east" : __DIR__"wroad2",
		"westup" : __DIR__"tulu2",
	]));

	setup(); 
	replace_program(ROOM);
}
