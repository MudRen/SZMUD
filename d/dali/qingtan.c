// Code of ShenZhou
// Room: /d/newdali/qingtan.c

inherit ROOM;

void create()
{
	set("short", "��Ϫ��̶");
	set("long", @LONG
��Ϫ��̶����������ˮ�������ڲ�ɽ��������ʥӦ��֮�������
Ͽ���С�ɽȪ�Ҹ�ӿ��������к����Ϫ��أ�׳�����裬��������
ˮ��ʯ������̽��ӣ����׳����Ϫ��
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
        set("fjing", 1);
	set("exits", ([
		"southdown" : __DIR__"quan1",
		"northup" : __DIR__"shilin6",
		"eastup" : __DIR__"minov20",
		]));
	set("no_clean_up", 0);

	setup();
}
