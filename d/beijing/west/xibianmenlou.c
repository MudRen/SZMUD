//Cracked by Roath
// Room: /d/beijing/west/xibianmenlou.c

inherit ROOM;

void create()
{
	set("short", "�����ų�¥");
	set("long", @LONG
���������ų����ϵ���¥��һ�Ӷ�׳�����سǾ���������
�����ֳִ󵶳�ì��ǿ�������������ע���ų��¹������ˣ�
���������ǳ����ı������ǽ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"chengqiang4",
  "down" : __DIR__"xibianmen",
  "east" : __DIR__"chengqiang3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
