// Code of ShenZhou
// Room: /d/dali/southgate.c

inherit ROOM;


void create()
{
	set("short", "˫����");
	set("long", @LONG
����һ����·�ڣ�����������ʯ��������˫���ţ����ſ�������
Ϫ�ϣ��ű����Ǵ���ǣ��ɴ���ȥ��ͨ���Ϸ���ϲ�ݡ����ڵȳ����
�ٵ�����ȥ�Ĳ�·ͨ��������������Ϫ�ϰ����пɴ��廪¥��
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("cost", 1);
        set("fjing", 1);
	
	set("exits", ([
		"north" : __DIR__"southgate.c",
		"south" : __DIR__"minov63",
		"southeast" : __DIR__"tulu4",
		"west" : __DIR__"shanlu8",
		]));

	setup();
}
