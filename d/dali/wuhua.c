// Code of ShenZhou
// Room: /d/dali/wuhua.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������廪¥�Ĵ��ţ����Ⱥ�ľ���ϵ����˸����Ͻ�������
���ޡ���������گ�����Ӵ����ϸ�������ĵط�������һ����ľ
���ƣ�������������һ�ɰ˳߸ߣ������ý�������������֡�
�廪¥������������گ��Ȱ���ӵ��ּ���
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/weishi4" : 2,
]));
	set("cost", 2);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"droad5",
  "enter" : __DIR__"wuhua1.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
