// Code of ShenZhou
// Room: /d/dali/hongshengt.c

inherit ROOM;

void create()
{
	set("short", "��ʥ����");
	set("long", @LONG
��ʥ����������һ�����������ڲ�ɽ֮´�����������
Ϊ������������֮һ����ʥ����Ϊ�ķ��ο���שʯ��������
����֮����ש������ɬ����ʹ���ĽǷ��̡���������������
�����ߣ�����������
LONG
	);
	set("no_clean_up", 0);
	set("cost", 2);
	set("exits", ([ /* sizeof() == 3 */
  "enter" : __DIR__"hongtj.c",
//  "southup" : __DIR__"chhill1.c",
 "northup" : __DIR__"tianls1.c",
  "west" : __DIR__"cangshan",
]));

	setup();
	replace_program(ROOM);
}
