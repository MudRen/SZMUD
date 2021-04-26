// Code of ShenZhou
// Room: /d/dali/northgate.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ǣ���������ǣ��Ǵ�����Ķ��ǡ�����گ�ڳ�������
�����ϡ�����͹��������ϡ������˹��������ϡ����������������
������Ķ��ϵġ�������������Դ˳�Ϊ�����˴����Ǳ����ţ���÷
"ϪΪ���ӣ���ǽ����Ϫ�ϣ���ʯ������ݳɣ��߶����壬�����ɣ�
��������¥��פ�����ڡ���ʯ�ٵ��ӳ���ֱ�����죬����һ������
��·����ͨȥ��
LONG
	);

	set("outdoors", "dali");
	set("cost", 1);
	set("objects", ([
		__DIR__"npc/dalishibing" : 3,
		__DIR__"npc/wujiang" : 1,
		]));

	set("no_clean_up", 0);

	set("exits", ([
		"north" : __DIR__"gaten1",
		"south" : __DIR__"taihejie5",
		"west" : __DIR__"shanlu1",
		"east" : __DIR__"chhill",
		]));

	setup();
}
