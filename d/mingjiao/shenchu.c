// Code of ShenZhou
// Room: /d/mingjiao/shenchu.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���⾭��֦Ҷ�Ĺ��ˣ����ʱ�ѱ��ʮ������������������ֹ�����
�������ǽ��»���һ��С·��˭֪�Ⲣ����ӭ������͵������������
ס��һȺ��ľ�ú���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"mguangchang",
  "southwest" : __DIR__"xiaolu37",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
