// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov8.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
������С������ǰ��Լ��ʮ���ߣ�ֻ������������Ũ����죬һ����ȪǶ��
��䣬������ʯ��Ȫˮ��������������Ǯ���ڳ��У����仺�����䣬���������
ɸ�£��ص�������˸������Ȫˮ�������ر߾����Լ�����ߵĵط���һ�ֿɺϱ�
�����ɣ����Ȫ�ϣ����Խ���Сͤ��С��������ʮ�����ġ�
LONG);
	set("objects", ([
		"/d/city/npc/maque" : 2,
		]));
	set("exits", ([
		"northwest" : __DIR__"minov9",
		"northup" : __DIR__"minov6",
		"south" : __DIR__"minov10",
		]));
	set("area", "������");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
