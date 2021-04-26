// Code of ShenZhou
// Room: /d/newdali/quan1.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
������С������ǰ��Լ��ʮ���ߣ�ֻ������������Ũ����죬һ����
ȪǶ����䣬������ʯ��Ȫˮ��������������Ǯ���ڳ��У����仺�����䣬
���������ɸ�£��ص�������˸������Ȫˮ�������ر߾����Լ�����ߵ�
�ط���һ�ֿɺϱ������ɣ����Ȫ�ϣ����Խ���Сͤ��С��������ʮ����
�ġ�
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"quan2",
  "south" : __DIR__"ling",
  "northup" : __DIR__"qingtan",
]));
        set("objects", ([ /* sizeof() == 1 */
  "/d/city/npc/maque" : 2,
]));

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
