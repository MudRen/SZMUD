// Code of ShenZhou
// Room: /d/mingjiao/jiashan.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
�������ȣ����������ۺ�ǽ�⣬�������У�������ɽ֮´������Ϫ
�Ϲȣ�˽����ʯ�ߡ�����ԣ����β��ã���ʯ��䣬�ĵ���Ȥ��������
����ʫ�ƣ�
				��ȴ���鲹ʯ��
				��԰���ȸ�ʫ��
				��������������
				С��̨ͤ���Ϳ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"jiuqu",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
