// Code of ShenZhou
// Room: /d/xixia/dongdajie.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�������ݶ���֣�ͬ���Ŀ�����ɾ����������ֵ�����Ҫ���ֶ�
�ˣ�����������������������������С�����ں�ͬ����ˣ�������в���
��Χ��һ�𣬱��������ţ�·������������׷һֻè��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"jiangjunfu",
  "west" : __DIR__"center",
  "north" : __DIR__"yamen",
  "east" : __DIR__"dongmen",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
