//Cracked by Roath
// Room: /d/beijing/east/qianju.c

inherit ROOM;

void create()
{
	set("short", "��ԴǮ��");
	set("long", @LONG
���Ǿ�������һ��Ǯׯ�����м��������ʷ���Ǿ���һ��
������ʵ�����ֺ�Ǯ���ӡ���ȫ�����ض��зֵꡣ�����е���Ʊ
�����ǳ��ã�ͨ��ȫ����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wangfudajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
