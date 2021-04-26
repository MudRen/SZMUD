// Code of ShenZhou
// Room: /d/xixia/biaoqiyin.c

inherit ROOM;

void create()
{
	set("short", "����Ӫ");
	set("long", @LONG
�����ǻ��ҽ�������פ�أ������ݳ�����������Ӫռ������Ӵ�
������Ӫ����������СУ������������ų�ǽ��һ����ǣ��ж�Ӫ��
����Ӫ��ͨ��ʹ��ʹ�֡�����Ӫ�ľ�ʿ�������ľ���ǧ����ѡ����
ʿ��ƽʱ����ʳ���Χ�ľ��䣬���ϳ�Ѳʱ�����𿪵�����������
սʱ����һ֧��������
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"majiu",
  "north" : __DIR__"yinfang",
  "south" : __DIR__"xiaochang",
  "east" : __DIR__"xidajie",
]));
	set("objects", ([
		__DIR__"npc/xxbing" : 2,
	]));
	set("cost", 1);
        set("no_fight",1);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
