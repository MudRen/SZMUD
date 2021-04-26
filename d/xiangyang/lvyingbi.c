// Code of ShenZhou
// Room: /d/xiangyang/lvyingbi.c

inherit ROOM;

void create()
{
	set("short", "[1;32m��Ӱ��[2;37;0m");
	set("long", @LONG
��ǰһ�¾޴���ձ��汱������ȫ��������ɫʯ�Ͽ������ɡ��ڷ����£���
����ߣ�����ʮһ���������ʯ��Ƕ���ɣ��ϵ����Ϸ�����ˮ֮�䣻��������
��������(dragon)���裬ֱ���ж£����ж���֮�ơ������ð���ʯ��ߣ�����С
����ʮ����״̬���죬�������������׺ͱڶ����ɾ�ʯ��Ƕ���ϵ���ֻ��ݡ���
��ͼ��������ϸ�壬���ɶ��ء�
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "dragon" : "����ϸ����һ�£�����ʯ�ڵ�����ʮ���������ֻ�Ȼһ�壬���ƻֺ���硣
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"huating",
]));

	setup();
	replace_program(ROOM);
}
