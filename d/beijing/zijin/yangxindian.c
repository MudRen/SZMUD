//Cracked by Roath
// Room: /d/beijing/zijincheng/yangxindian.c

inherit ROOM;

void create()
{
	set("short", "���ĵ�");
	set("long", @LONG
�ʵ۶��������ס�ͽ����ճ�����������б���������������
������һ����ܣ����������ʵ��й��ι��ľ��飬��ѵ��������һЩ
��Ա����Σ�����֮ǰ�����쵽��������ʵۡ������ǻʵ��������ۣ�
�Լ�ͬ���������µĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yongshougong",
  "east" : __DIR__"neiyoumen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
