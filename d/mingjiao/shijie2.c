// Code of ShenZhou
// Room: /d/mingjiao/shijie2.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ����������ʯ�ף�����վ�ż������̵Ļ�����ÿ�˵������϶�
����һѪ��Ļ��档��ʯ�׵ľ�ͷ����������������ʮ�̵ļ�¥��������
�˴�������� ¥�ϵĹ����ֽ��ᷢ�������� 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yongdao2",
  "southwest" : __DIR__"shanmentongdao",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
