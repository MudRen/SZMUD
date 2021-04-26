// Code of ShenZhou
// Room: /d/newdali/riverbank.c

inherit ROOM;

void create()
{
	set("short", "��֭����");
	set("long", @LONG
����λ����֭���ϣ�ԭ������һ���ز��£������Ժ��ϡ�Ψ��һ��
ʯ�̾���(jinzhuang)�������С��˴�Ϊ��׶״���߲�ʯ�񡣸�Լ����ߣ�
����Ϊ�˽��ε���ʯ�����Ͽ��������������֮���н�ʯ�����Ǳ���֮��
�ܣ������ϲ�֮��ʯ��
LONG
	);
	set("cost", 1);
       set("fjing", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"road7",
  "east" : __DIR__"dian2",
  "enter" : __DIR__"tower1",
]));
       set("objects", ([ /* sizeof() == 1 */
  "/d/dali/npc/sengren" : 2,
]));

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
