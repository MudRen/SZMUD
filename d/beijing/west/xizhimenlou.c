//Cracked by Roath
// Room: /d/beijing/west/xizhimenlou.c

inherit ROOM;

void create()
{
	set("short", "��ֱ�ų�¥");
	set("long", @LONG
������ֱ�ų����ϵ���¥��һ�Ӷ�׳�����سǾ���������
�����ֳִ󵶳�ì��ǿ�������������ע���ų��¹������ˣ�
���������ǳ����ı������ǽ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"chengqiang1",
  "south" : __DIR__"chengqiang2",
  "down" : __DIR__"xizhimen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
