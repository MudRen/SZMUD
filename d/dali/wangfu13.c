// Code of ShenZhou
// Room: /d/dali/wangfu13.c

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
���е��ط���һ�Ż������ʯ�󰸣����϶����������˷�����
��ʮ�������⣬��ɫ��Ͳ���ʺ��ڲ�ı�������һ�㣻��һ����
�������һ����Ҥ���ң�����������ˮ����İ׾ջ������ڵ���
����һ������������ͼ�������ҹ���һ��������������³��ī��
�������ƣ���ϼ���Ǹ�ȪʯҰ���ġ����������󶦣������̴
��һ�������Ŀ���࣬���߹���С鳡�
LONG
	);
	set("cost", 1);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wangfu12",
]));
	set("no_clean_up", 0);
set("wangfu", 1);

	setup();
	replace_program(ROOM);
}
