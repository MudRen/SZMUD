// Code of ShenZhou
// Room: /d/newdali/taixueyuan.c

inherit ROOM;

void create()
{
	set("short", "̫ѧԺ");
	set("long", @LONG
�����̫ѧԺ��֮��ԭ�꾩��������Զ��Ϊ�����׹��Ĵ���ʱ����һЩ����
��ѧ������������ִ�̣����ٴ���ĺ�����û��ս��Ĵ�����������Ҳ�ռ���
���������鼮��̫ѧ���Ǵ���ǹ���������֮�����Բ�ѧ�������ٳ���ѧԺ
��ѧ����������֮���н���ذڶ����Դ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"taihejie5",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/teacher" : 1,
]));

	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
