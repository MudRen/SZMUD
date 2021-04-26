// Code of ShenZhou
// Room: /d/dali/guandao.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
������һ����ʯ�ٵ��ϣ������Ѿ�����گ�����ˣ�·��ʱʱ����
������ɫ�����������������������䲻����·��վ��Щ�����λ��޵�
����Ů�ӣ�����һ�������µ��Եø�����������ȥ���ϼ��Ǵ����
���ؿ�̫�ͳǣ��عٵ��򶫱��ɴ���ԭ��
LONG
	);
	set("outdoors", "dali");
	set("no_clean_up", 0);
	set("cost", 2);
	set("objects", ([
		__DIR__"npc/baiyi" : 1,
		]));

	set("exits", ([
		"northeast" : "/d/dali/guandao5",
		"south" : __DIR__"nanbei",
		]));

	setup();
}
