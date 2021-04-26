// Code of ShenZhou
// Room: /d/dali/guandao.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
������һ����ʯ�ٵ��ϣ������Ѿ�����گ�����ˣ�·��ʱʱ���Կ�����ɫ��
���������������������䲻����·��վ�˼������λ��޵İ���Ů�ӣ�����һ����
�����µ��Եø�����������ȥ���ϼ��Ǵ�������ؿ�̫�ͳǣ��عٵ��򶫱��ɴ�
��ԭ��
LONG);
	set("objects", ([
		__DIR__"npc/baiyi" : 2,
		]));
	set("exits", ([
		"northeast" : __DIR__"guandao5",
		"southwest" : __DIR__"nanbei",
        "west" : __DIR__"chadao",
	]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
