// Code of ShenZhou
// Room: /d/newdali/tusi1.c

inherit ROOM;

void create()
{
	set("short", "��˾��");
	set("long", @LONG
��˾���ǵ��ش�����Ϯ��˾���ϵ����ţ�һ�����ϵ�שľ�������ͥ
�Ӹ����£�ׯ�ϼ�ʵ����ǰ�ǿ���ʯ�ף��е����������ƣ����ݹ���̨��
ռ��Լ�˰�Ķ���������������������������᷿��
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dahejie",
  "enter" : __DIR__"tusi2",
]));

set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/datusi" : 1,
__DIR__"npc/shicong2" : 1,
__DIR__"npc/shicong3" : 1,

]));

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
