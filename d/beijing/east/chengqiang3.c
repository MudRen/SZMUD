//Cracked by Roath
// Room: /d/beijing/east/chengqiang3.c

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
  "south" : __DIR__"zhaoyangmenlou",
  "north" : __DIR__"dongzhimenlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
