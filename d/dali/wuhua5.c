// Code of ShenZhou
// Room: /d/dali/wuhua5.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ�����ң����ﴰ���������þ߿��������Ǵ���һ��
����������Ǽ�ֵ���ơ�ƾ�������������ڵ���֮�пɼ���ɽ�
��ַ壬ֻ��ɽ�����㣬������Σ������Ŀ�������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"wuhua6.c",
]));
	set("no_clean_up", 0);
set("cost", 1);

	setup();
	replace_program(ROOM);
}
