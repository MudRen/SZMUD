//Cracked by Roath
// Room: /d/beijing/west/yizhan.c

inherit ROOM;

void create()
{
	set("short", "��վ");
	set("long", @LONG
���Ǳ��������һ��Ѱ����վ��רΪ��͢���͹�Ա�����ݹ���
֮�ã����û�й���ż��Ҳ����������Ϊ���������ṩʳ�ޡ�
������ǹ㰲�Ŵ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"guangandajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
