//Cracked by Roath
// Room: /d/beijing/east/chengqiang8.c

inherit ROOM;

void create()
{
	set("short", "��ǽ");
	set("long", @LONG
���Ǳ�����ǵ�һ�γ�ǽ�������Ϊ�����Զ����֮ս�����
�����������ưܣ�����ǽʮ�ֿ��������������ƥ���Ŷ��У���ʱ
��һ�Ӷӹٱ�Ѳ�߶�����ƽ���˼��ֽ������ա�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/beijing/west/yonganmenlou",
  "east" : __DIR__"zuoanmenlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
