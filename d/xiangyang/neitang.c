// Code of ShenZhou
// Room: /d/xiangyang/neitang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�˴��ǽӴ����͵����ã����ܲ������ţ�������ľ���ſ�����
�ǵ�������������ֿ������������������ձ��������������ֻ�
�����²Ծ����ϱ߻���ǰ�������ڣ������Ứ԰��·����
LONG
	);
	set("no_clean_up", 0);
	set("coordinates", ([ "x" : 3, "y" : -4 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"dating",
  "east" : __DIR__"shanfang",
  "south" : __DIR__"huajing",
]));

	setup();
	replace_program(ROOM);
}
