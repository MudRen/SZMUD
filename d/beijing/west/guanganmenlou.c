//Cracked by Roath
// Room: /d/beijing/west/guanganmenlou.c

inherit ROOM;

void create()
{
	set("short", "�㰲�ų�¥");
	set("long", @LONG
���ǹ㰲�ų����ϵ���¥��һ�Ӷ�׳�����سǾ���������
�����ֳִ󵶳�ì��ǿ�������������ע���ų��¹������ˣ�
���������ǳ����ı������ǽ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"chengqiang6",
  "north" : __DIR__"chengqiang4",
  "down" : __DIR__"guanganmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
