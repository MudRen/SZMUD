//Cracked by Roath
// Room: /d/beijing/east/zhaoyangmenlou.c

inherit ROOM;

void create()
{
	set("short", "�����ų�¥");
	set("long", @LONG
���ǳ����ų����ϵ���¥��һ�Ӷ�׳�����سǾ���������
�����ֳִ󵶳�ì��ǿ�������������ע���ų��¹������ˣ�
���������ǳ����ı������ǽ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"chengqiang4",
  "north" : __DIR__"chengqiang3",
  "down" : __DIR__"zhaoyangmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
