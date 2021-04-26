// Code of ShenZhou
// Room: /d/xixia/jjdayuan.c

inherit ROOM;

void create()
{
	set("short", "��������Ժ");
	set("long", @LONG
�����ǽ������Ĵ�Ժ������һ�¿����İ����ձڣ����顰���ı�����
�ĸ����֣�����ǵ������Ļʵ���Ԫ껡�һɫ����ש�̵أ��м���������
��Ժ����ɨ����������լ���������ʷ��������Ǹ�СԺ��
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/city/npc/jiading" : 2,
]));
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jiangjunfu",
  "east" : __DIR__"zhaiyuan.c",
  "enter" : __DIR__"xiaolou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
