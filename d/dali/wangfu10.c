// Code of ShenZhou
// Room: /d/dali/wangfu10.c

inherit ROOM;

void create()
{
	set("short", "��ɽʯ");
	set("long", @LONG
��ӭ��ͻ������Ĵ�����ɽʯ��������Ⱥ�Ƹ�ʽʯ�飬����
�������з���Ϥ����ס����һ�껨ľҲ�ޣ�ֻ�������ݣ�����
ǣ�ٵģ����������ģ���ɽ�ۣ���ʯ϶������������������
�̽ף�������ƮƮ����������������ʵ�絤ɰ��������
��ζ����𥣬�ǻ���֮�ɱȡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"wangfu9",
]));
	set("no_clean_up", 0);
	set("cost", 1);
set("wangfu", 1);

	setup();
	replace_program(ROOM);
}
