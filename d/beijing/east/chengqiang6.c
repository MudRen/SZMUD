//Cracked by Roath
// Room: /d/beijing/east/chengqiang6.c

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
  "south" : __DIR__"guangqumenlou",
  "north" : __DIR__"dongbianmenlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
