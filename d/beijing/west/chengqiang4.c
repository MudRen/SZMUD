//Cracked by Roath
// Room: /d/beijing/east/chengqiang4.c

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
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"xibianmenlou",
  "south" : __DIR__"guanganmenlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
