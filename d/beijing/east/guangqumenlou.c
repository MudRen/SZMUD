//Cracked by Roath
// Room: /d/beijing/east/guangqumenlou.c

inherit ROOM;

void create()
{
	set("short", "�����ų�¥");
	set("long", @LONG
���ǹ����ų����ϵ���¥��һ�Ӷ�׳�����سǾ���������
�����ֳִ󵶳�ì��ǿ�������������ע���ų��¹������ˣ�
���������ǳ����ı������ǽ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"chengqiang7",
  "north" : __DIR__"chengqiang6",
  "down" : __DIR__"guangqumen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
